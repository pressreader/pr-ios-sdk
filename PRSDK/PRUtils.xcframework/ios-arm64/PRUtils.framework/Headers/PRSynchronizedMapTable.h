//
//  PRSynchronizedMapTable.h
//  PRUtils
//
//  Created by Ivan Berezin on 21/04/2022.
//  Copyright © 2022 NewspaperDirect. All rights reserved.
//

#import <PRUtils/PRSynchronizedCollection.h>

NS_ASSUME_NONNULL_BEGIN

@interface PRSynchronizedMapTable<KeyType, ObjectType> : PRSynchronizedCollection

- (instancetype)initWithKeyOptions:(NSPointerFunctionsOptions)keyOptions
                      valueOptions:(NSPointerFunctionsOptions)valueOptions
                             label:(nullable NSString *)label NS_DESIGNATED_INITIALIZER;

/// Returns an instance with `.copyIn` key and `.strongMemory` value options which corresponds to Dictionary's default behaviour.
- (instancetype)initWithLabel:(nullable NSString *)label;

- (nullable ObjectType)objectForKey:(nullable KeyType)key;
- (void)removeObjectForKey:(nullable KeyType)key;
- (void)setObject:(nullable ObjectType)object forKey:(nullable KeyType)key;

- (void)removeAllObjects;

// Subscriptable
- (id)objectForKeyedSubscript:(KeyType)key;
- (void)setObject:(ObjectType)object forKeyedSubscript:(KeyType)key;

@property(readonly, copy) NSArray<ObjectType> *allValues;

@end

NS_ASSUME_NONNULL_END
