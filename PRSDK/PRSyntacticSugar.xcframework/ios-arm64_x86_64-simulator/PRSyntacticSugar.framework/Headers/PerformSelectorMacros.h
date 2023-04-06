//
//  PerformSelectorMacros.h
//  PR-API
//
//  Created by berec on 20/08/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#ifndef PerformSelectorMacros_h
#define PerformSelectorMacros_h

#define PerformSelector(target, selector) \
((void(*)(id, SEL))[target methodForSelector:selector])(target, selector)
#define PerformSelectorWithObject(target, selector, obj1) \
((void(*)(id, SEL, id))[target methodForSelector:selector])(target, selector, obj1)
#define PerformSelectorWithObjects(target, selector, obj1, obj2) \
((void(*)(id, SEL, id, id))[target methodForSelector:selector])(target, selector, obj1, obj2)

#define PerformSelectorSafe(target, selector) \
([target respondsToSelector:selector] ? PerformSelector(target, selector) : nil)
#define PerformSelectorWithObjectSafe(target, selector, obj1) \
([target respondsToSelector:selector] ? PerformSelectorWithObject(target, selector, obj1) : nil)
#define PerformSelectorWithObjectsSafe(target, selector, obj1, obj2) \
([target respondsToSelector:selector] ? PerformSelectorWithObjects(target, selector, obj1, obj2) : nil)

#define PerformSelectorWithResultType(target, selector, ResultType) \
((ResultType(*)(id, SEL))[target methodForSelector:selector])(target, selector)
#define PerformSelectorWithResultTypeWithObject(target, selector, ResultType, obj1) \
((ResultType(*)(id, SEL, id))[target methodForSelector:selector])(target, selector, obj1)
#define PerformSelectorWithResultTypeWithObjects(target, selector, ResultType, obj1, obj2) \
((ResultType(*)(id, SEL, id, id))[target methodForSelector:selector])(target, selector, obj1, obj2)

#define PerformSelectorWithResultTypeSafe(target, selector) \
([target respondsToSelector:selector] ? PerformSelectorWithResultType(target, selector) : nil)
#define PerformSelectorWithResultTypeWithObjectSafe(target, selector, obj1) \
([target respondsToSelector:selector] ? PerformSelectorWithResultTypeWithObject(target, selector, obj1) : nil)
#define PerformSelectorWithResultTypeWithObjectsSafe(target, selector, obj1, obj2) \
([target respondsToSelector:selector] ? PerformSelectorWithResultTypeWithObjects(target, selector, obj1, obj2) : nil)

#endif /* PerformSelectorMacros_h */
