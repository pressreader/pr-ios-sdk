//
//  PRDynamicSubclassing.h
//  ExternalSources
//
//  Created by Vitali Bounine on 2016-11-21.
//  Copyright © 2016 ND. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <objc/runtime.h>
#import <objc/message.h>

typedef void *(* PRIMP)(__unsafe_unretained id, SEL, ...);
#define IMP_BLOCK_CAST (id (^)(id, ...))
typedef id (^__unsafe_unretained ImpBlock) (id, ...);
typedef ImpBlock (^ImpProvider)(SEL selector, PRIMP originalImp);
typedef void (^ValueTypeIvarsSetupBlock) (Class newClass);

#define DEFINE_SEND_SUPER(superclass, obj, rettype, ...) \
struct objc_super _sss_ = {\
.receiver = obj,\
.super_class = superclass\
};\
rettype (*objc_superAllocTyped)(struct objc_super *, SEL, ##__VA_ARGS__) = (void *)&objc_msgSendSuper
#define CALL_SEND_SUPER(selector, ...) (*objc_superAllocTyped)(&_sss_, selector, ##__VA_ARGS__)

// Used in case of [super somemethod...]
#define ORIGINAL_SEL_IMP(returntype, originalclass, sel, ...) ((typeof(returntype (*)(typeof(self), SEL, ...)))class_getMethodImplementation(originalclass, sel))(self, sel, ##__VA_ARGS__)
// USE when arguments are primitive types or structs
#define ORIGINAL_SEL_IMP_1(returntype, originalclass, sel, arg, ...) ((typeof(returntype (*)(typeof(self), SEL, typeof(arg))))class_getMethodImplementation(originalclass, sel))(self, sel, arg, ##__VA_ARGS__)
#define ORIGINAL_SEL_IMP_2(returntype, originalclass, sel, arg1, arg2, ...) ((typeof(returntype (*)(typeof(self), SEL, typeof(arg1), typeof(arg2))))class_getMethodImplementation(originalclass, sel))(self, sel, arg1, arg2, ##__VA_ARGS__)

#define IMPLEMENTATION_PROVIDER(returntype, ...) (ImpProvider) ^ ImpBlock (SEL _cmd, returntype(* originalImp)(__unsafe_unretained id, SEL, ##__VA_ARGS__))
#define IMPLEMENT_BLOCK(returntype, selftype, ...) IMP_BLOCK_CAST ^ returntype (__unsafe_unretained selftype self, ##__VA_ARGS__)

#if __has_feature(objc_arc)
    #define BEGIN_IMPLEMENTATION(returntype, ...) IMPLEMENTATION_PROVIDER(returntype, ##__VA_ARGS__) {\
        return IMPLEMENT_BLOCK(returntype, typeof(self), ##__VA_ARGS__)
    #define END_IMPLEMENTATION ; }
#else
    #define BEGIN_IMPLEMENTATION(returntype, ...) IMPLEMENTATION_PROVIDER(returntype, ##__VA_ARGS__) {\
        return [[IMPLEMENT_BLOCK(returntype, typeof(self), ##__VA_ARGS__)
    #define END_IMPLEMENTATION copy] autorelease]; }
#endif

#define ORIGINAL_IMP(...) originalImp(self, _cmd, ##__VA_ARGS__)

#define ADD_VALUETYPE_IVAR(cls, ivarName, ivarType) class_addIvar(cls, #ivarName, sizeof(ivarType), log2(sizeof(ivarType)), @encode(ivarType))

#define VALUETYPE_IVAR(obj, ivarName, ivarType) *(ivarType *)((__bridge void *)obj + ivar_getOffset(class_getInstanceVariable(obj.class, #ivarName)))
#define GET_VALUETYPE_IVAR(obj, ivarName, ivarType, defaultVal) (class_getInstanceVariable(obj.class, #ivarName) ? VALUETYPE_IVAR(obj, ivarName, ivarType) : defaultVal)
#define SET_VALUETYPE_IVAR(obj, ivarName, ivarType, newVal) if (class_getInstanceVariable(obj.class, #ivarName)) memcpy((__bridge void *)obj + ivar_getOffset(class_getInstanceVariable(obj.class, #ivarName)), &newVal, sizeof(newVal))

#define SELF_VALUETYPE_IVAR(ivarName, ivarType) VALUETYPE_IVAR(self, ivarName, ivarType)
#define SELF_GET_VALUETYPE_IVAR(ivarName, ivarType, defaultVal) GET_VALUETYPE_IVAR(self, ivarName, ivarType, defaultVal)
#define SELF_SET_VALUETYPE_IVAR(ivarName, ivarType, newVal) SET_VALUETYPE_IVAR(self, ivarName, ivarType, newVal)

#define ADD_VALUETYPE_PROPERTY(cls, propType, propName) \
do { \
char *ivarName = "_" #propName; \
class_addIvar(cls, ivarName, sizeof(propType), log2(sizeof(propType)), @encode(propType)); \
\
IMP propGetter = imp_implementationWithBlock(^ propType (id self) { return *(propType *)((__bridge void *)self + ivar_getOffset(class_getInstanceVariable(cls, ivarName))); }); \
const char *getterSignature = [[NSString stringWithFormat:@"%s%s%s", @encode(propType), @encode(id), @encode(SEL)] UTF8String]; \
class_addMethod(c, sel_registerName(#propName), propGetter, getterSignature); \
\
IMP propSetter = imp_implementationWithBlock(^ (id self, propType val) { memcpy((__bridge void *)self + ivar_getOffset(class_getInstanceVariable(cls, ivarName)), &val, sizeof(val)); }); \
const char *setterSignature = [[NSString stringWithFormat:@"%s%s%s%s", @encode(void), @encode(id), @encode(SEL), @encode(propType)] UTF8String]; \
char selName[strlen(#propName)+5]; strcpy(selName, "set"); strcat(selName, #propName); selName[3]=toupper(selName[3]); strcat(selName, ":"); \
class_addMethod(c, sel_registerName(selName), propSetter, setterSignature); \
} while (0)

@interface NSObject (PRDynamicSubclassing)

#pragma mark helper methods to redefine/override mehods of current instance

- (BOOL) isSubclassedWihtContext:(NSString *)context;
- (void) subsclassWithContext:(NSString *)context;
- (void) subsclassWithContext:(NSString *)context valueTypeIvarsSetup:(ValueTypeIvarsSetupBlock)valueTypeIvarsSetupBlock;

- (void) overrideSelector:(SEL)selector
        inSubclassContext:(NSString *)context
           implementation:(ImpBlock)implementationBlock;

/*!
 *
 * @param selector selector to override
 * @param context subsclass @cnaming context
 * @param impProvider provided implementation
 *
 * @code
 *  // 1. Reimplementing -(void *)setFrame for UITableViewCell
 *  [self overrideSelector:@selector(setFrame:)
 *       inSubclassContext:@"PRRoundedTableViewCell"
 *  ipmlementationProvider:BEGIN_IMPLEMENTATION(void, CGRect frame)
 *  {
 *      if (!self.superview)
 *          ORIGINAL_IMP(frame);
 *      else {
 *          frame = CGRectInset(frame, self.horizontalPadding, 0);
 *          frame.size.width = self.superview.bounds.size.width - self.horizontalPadding * 2;
 *          frame.origin.x = self.horizontalPadding;
 *          BOOL isChanged = !CGSizeEqualToSize(self.frame.size, frame.size);
 *          ORIGINAL_IMP(frame);
 *          if (isChanged) {
 *              [self invalidateLayers];
 *          }
 *      }
 *  } END_IMPLEMENTATION];
 *
 *  // 2. Reimplementing -(UILabel *)textLabel for UITableViewCell
 *  [self overrideSelector:@selector(textLabel)
 *       inSubclassContext:@"PRTextLabelWithAttachedSubview"
 *  implementationProvider:BEGIN_IMPLEMENTATION(UILabel *)
 *  {
 *      return [self textLabelReplacement] ?: ORIGINAL_IMP();
 *  } END_IMPLEMENTATION];
 * @endcode
 */
- (void) overrideSelector:(SEL)selector
        inSubclassContext:(NSString *)context
   ipmlementationProvider:(ImpProvider)impProvider;

- (void) overrideSelector:(SEL)selector
   ipmlementationProvider:(ImpProvider)impProvider;

-(id)superClass:(Class)class performSelector:(SEL)selector;

@end
