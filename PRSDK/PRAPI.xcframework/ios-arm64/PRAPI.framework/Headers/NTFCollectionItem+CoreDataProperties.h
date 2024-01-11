//
//  NTFCollectionItem+CoreDataProperties.h
//  PRAPI
//
//  Created by Vitalii Hudenko on 15.11.2023.
//  Copyright © 2023 NewspaperDirect. All rights reserved.
//
//

#import "NTFCollectionItem+CoreDataClass.h"


NS_ASSUME_NONNULL_BEGIN

@interface NTFCollectionItem (CoreDataProperties)

+ (NSFetchRequest<NTFCollectionItem *> *)fetchRequest NS_SWIFT_NAME(fetchRequest());

@property (nonatomic) int32_t contentCount;
@property (nonatomic) BOOL isPublic;
@property (nullable, nonatomic, copy) NSString *itemId;
@property (nullable, nonatomic, copy) NSString *name;
@property (nonatomic) int16_t type;
@property (nullable, nonatomic, copy) NSString *webName;
@property (nullable, nonatomic, retain) Channel *channel;
@property (nullable, nonatomic, retain) NTFCollectionItem *parent;
@property (nullable, nonatomic, retain) NSOrderedSet<NTFCollectionItem *> *subCollections;

@end

@interface NTFCollectionItem (CoreDataGeneratedAccessors)

- (void)insertObject:(NTFCollectionItem *)value inSubCollectionsAtIndex:(NSUInteger)idx;
- (void)removeObjectFromSubCollectionsAtIndex:(NSUInteger)idx;
- (void)insertSubCollections:(NSArray<NTFCollectionItem *> *)value atIndexes:(NSIndexSet *)indexes;
- (void)removeSubCollectionsAtIndexes:(NSIndexSet *)indexes;
- (void)replaceObjectInSubCollectionsAtIndex:(NSUInteger)idx withObject:(NTFCollectionItem *)value;
- (void)replaceSubCollectionsAtIndexes:(NSIndexSet *)indexes withSubCollections:(NSArray<NTFCollectionItem *> *)values;
- (void)addSubCollectionsObject:(NTFCollectionItem *)value;
- (void)removeSubCollectionsObject:(NTFCollectionItem *)value;
- (void)addSubCollections:(NSOrderedSet<NTFCollectionItem *> *)values;
- (void)removeSubCollections:(NSOrderedSet<NTFCollectionItem *> *)values;

@end

NS_ASSUME_NONNULL_END
