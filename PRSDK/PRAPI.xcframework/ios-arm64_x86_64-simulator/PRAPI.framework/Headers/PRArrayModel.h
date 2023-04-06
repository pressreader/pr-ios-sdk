//
//  PRArrayModel.h
//  PR-API
//
//  Created by Viacheslav Soroka on 12/3/18.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import "PRObservableModel.h"

#import "ModelObserver.h"

NS_ASSUME_NONNULL_BEGIN

@class PRArrayModel;

@protocol PRArrayModelObserver <ModelObserver>

@optional
- (void)arrayModel:(PRArrayModel *)arrayModel didDeleteObjectAtIndex:(NSNumber *)index;
- (void)arrayModel:(PRArrayModel *)arrayModel didAddObjectAtIndex:(NSNumber *)index;

@end

@protocol PRArrayModelSpecific <NSObject>
- (void)addObserver:(id<PRArrayModelObserver>)observer;

@end

@interface PRArrayModel <__covariant ObjectType> : PRObservableModel <PRArrayModelSpecific>

- (void)addObject:(ObjectType)object;
- (void)insertObject:(ObjectType)object atIndex:(NSUInteger)index;

- (void)removeObject:(ObjectType)object;
- (void)removeObjectAtIndex:(NSUInteger)index;

- (ObjectType)objectAtIndex:(NSUInteger)index;
- (NSUInteger)indexOfObject:(ObjectType)object;
- (BOOL)containsObject:(ObjectType)object;

- (void)moveObjectWithIndex:(NSUInteger)index atIndex:(NSUInteger)targetIndex;

- (void)fillWithObjects:(NSArray<ObjectType> *)objects;
- (void)removeAllObjects;

- (ObjectType)objectAtIndexedSubscript:(NSUInteger)index;

@property (nonatomic, readonly) NSArray<ObjectType> *objects;
@property (nonatomic, readonly) NSUInteger count;

@end

NS_ASSUME_NONNULL_END
