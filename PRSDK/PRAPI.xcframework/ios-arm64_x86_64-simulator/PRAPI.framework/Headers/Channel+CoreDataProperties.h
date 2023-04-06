//
//  Channel+CoreDataProperties.h
//  PRAPI
//
//  Created by berec on 12/02/2020.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//
//

#import "Channel+CoreDataClass.h"


NS_ASSUME_NONNULL_BEGIN

@interface Channel (CoreDataProperties)

+ (NSFetchRequest<Channel *> *)fetchRequest;

@property (nonatomic, copy) NSString *id;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *displayName;
@property (nullable, nonatomic, retain) NSOrderedSet<NTFCollectionItem *> *collections;
@property (nullable, nonatomic, retain) NTFFeed *feed;
@property (nullable, nonatomic, retain) NTFSession *session;

@end

@interface Channel (CoreDataGeneratedAccessors)

- (void)insertObject:(NTFCollectionItem *)value inCollectionsAtIndex:(NSUInteger)idx;
- (void)removeObjectFromCollectionsAtIndex:(NSUInteger)idx;
- (void)insertCollections:(NSArray<NTFCollectionItem *> *)value atIndexes:(NSIndexSet *)indexes;
- (void)removeCollectionsAtIndexes:(NSIndexSet *)indexes;
- (void)replaceObjectInCollectionsAtIndex:(NSUInteger)idx withObject:(NTFCollectionItem *)value;
- (void)replaceCollectionsAtIndexes:(NSIndexSet *)indexes withCollections:(NSArray<NTFCollectionItem *> *)values;
- (void)addCollectionsObject:(NTFCollectionItem *)value;
- (void)removeCollectionsObject:(NTFCollectionItem *)value;
- (void)addCollections:(NSOrderedSet<NTFCollectionItem *> *)values;
- (void)removeCollections:(NSOrderedSet<NTFCollectionItem *> *)values;

@end

NS_ASSUME_NONNULL_END
