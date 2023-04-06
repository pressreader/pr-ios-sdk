//
//  PRSynchronizedMutableArray.h
//  PRUtils
//
//  Created by Ivan Berezin on 21/04/2022.
//  Copyright © 2022 NewspaperDirect. All rights reserved.
//

#import <PRUtils/PRSynchronizedCollection.h>

NS_ASSUME_NONNULL_BEGIN

@interface PRSynchronizedMutableArray<ObjectType> : PRSynchronizedCollection
    
- (instancetype)initWithLabel:(nullable NSString *)label;

- (void)addObject:(ObjectType)anObject;
- (void)removeObject:(ObjectType)anObject;

- (ObjectType)objectAtIndex:(NSUInteger)index;
- (void)setObject:(ObjectType)object atIndex:(NSUInteger)index;

// Subscriptable
- (ObjectType)objectAtIndexedSubscript:(NSUInteger)index;
- (void)setObject:(ObjectType)obj atIndexedSubscript:(NSUInteger)index;

@property (nonatomic, readonly) NSUInteger count;
@property (nullable, nonatomic, readonly) ObjectType lastObject;
@property (nullable, nonatomic, readonly) ObjectType firstObject;

@end

NS_ASSUME_NONNULL_END
