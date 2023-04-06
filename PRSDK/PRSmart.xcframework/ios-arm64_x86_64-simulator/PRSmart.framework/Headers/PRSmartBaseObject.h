//
//  PRSmartBaseObject.h
//  PRiphone
//
//  Created by Jackie Cane on 26/08/15.
//  Copyright (c) 2015 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString *PRSmartObjectAttribute NS_TYPED_EXTENSIBLE_ENUM;

extern NSString * const kPRDefaultLanguage;

@interface PRSmartBaseObject : NSObject

- (instancetype)initWithRoot:(nullable PRSmartBaseObject *)root
                  attributes:(nullable NSDictionary<PRSmartObjectAttribute, id> *)attributes
         originalISOLanguage:(nullable NSString *)language NS_DESIGNATED_INITIALIZER;
- (instancetype)initWithRoot:(nullable PRSmartBaseObject *)root;

- (void)setAttribute:(nullable id)attr forKey:(PRSmartObjectAttribute)key;
- (void)setAttribute:(nullable id)attr forKey:(PRSmartObjectAttribute)key isoLanguage:(nullable NSString *)language;
- (nullable NSString *)attributeForKey:(PRSmartObjectAttribute)key isoLanguage:(nullable NSString *)language;

- (void)addAttributesFromDict:(nullable NSDictionary<PRSmartObjectAttribute, id> *)dict;
- (void)addAttributesFromDict:(nullable NSDictionary<PRSmartObjectAttribute, id> *)dict isoLanguage:(NSString *)language;

@property (nonatomic, strong) NSString *originalLanguage;
@property (nonatomic, readonly) NSDictionary<PRSmartObjectAttribute, id> *attributes;
@property (nonatomic, readonly) NSDictionary<NSString *, NSDictionary<PRSmartObjectAttribute, id> *> *attributesForLanguage;
@property (nullable, nonatomic, weak) PRSmartBaseObject *root;
@property (nonatomic, readonly) PRSmartBaseObject *rootOrSelf;
@property (nonatomic, readonly) NSUInteger Id;
@property (nonatomic, readonly) NSString *smartObjectId;

- (nullable id)objectForKeyedSubscript:(PRSmartObjectAttribute)key;

NS_ASSUME_NONNULL_END

@end
