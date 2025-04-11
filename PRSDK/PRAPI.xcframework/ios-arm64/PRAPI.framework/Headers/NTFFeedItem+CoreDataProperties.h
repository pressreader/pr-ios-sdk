//
//  NTFFeedItem+CoreDataProperties.h
//  PRAPI
//
//  Created by berec on 14/11/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//
//

#import "NTFFeedItem+CoreDataClass.h"

@class Interest;

NS_ASSUME_NONNULL_BEGIN

@interface NTFFeedItem (CoreDataProperties)

+ (NSFetchRequest<NTFFeedItem *> *)fetchRequest;

@property (nonatomic) BOOL hidden;
@property (nonatomic) int32_t orderId;
@property (nonatomic, retain) NTFFeed *feed;
@property (nullable, nonatomic, retain) NSOrderedSet<Interest *> *interests;

@end

@interface NTFFeedItem (CoreDataGeneratedAccessors)

- (void)insertObject:(Interest *)value inInterestsAtIndex:(NSUInteger)idx;
- (void)removeObjectFromInterestsAtIndex:(NSUInteger)idx;
- (void)insertInterests:(NSArray<Interest *> *)value atIndexes:(NSIndexSet *)indexes;
- (void)removeInterestsAtIndexes:(NSIndexSet *)indexes;
- (void)replaceObjectInInterestsAtIndex:(NSUInteger)idx withObject:(Interest *)value;
- (void)replaceInterestsAtIndexes:(NSIndexSet *)indexes withInterests:(NSArray<Interest *> *)values;
- (void)addInterestsObject:(Interest *)value;
- (void)removeInterestsObject:(Interest *)value;
- (void)addInterests:(NSOrderedSet<Interest *> *)values;
- (void)removeInterests:(NSOrderedSet<Interest *> *)values;

@end

NS_ASSUME_NONNULL_END
