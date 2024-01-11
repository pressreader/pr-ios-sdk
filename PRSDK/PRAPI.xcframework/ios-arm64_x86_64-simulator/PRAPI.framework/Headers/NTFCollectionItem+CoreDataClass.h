//
//  NTFCollectionItem+CoreDataClass.h
//  PRAPI
//
//  Created by berec on 11/02/2020.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class Channel;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(uint8_t, NTFCollectionType) {
    NTFCollectionTypeSystem = 1,
    NTFCollectionTypeUser = 2,
    NTFCollectionTypeSharing = 3
};

extern NSString * const NTFCollectionIDReadLater;
extern NSString * const NTFCollectionIDLatestNews;
extern NSString * const NTFCollectionWebNameFeaturedStories;
extern NSString * const NTFCollectionIDAll;

@interface NTFCollectionItem : NSManagedObject

+ (NSComparator)comparatorWithCollectionType:(NSArray<NSNumber *> *)typeOrder;
+ (NSComparator)comparatorWithCollectionItemsCount:(BOOL)descending;
+ (NSComparator)comparatorWithDisplayName:(BOOL)descending;
+ (NSComparator)comparatorWithWebName:(BOOL)descending;

+ (NSArray<NTFCollectionItem *> *)sortedWithCollections:(NSArray<NTFCollectionItem *> *)collections
                                            comparator1:(nullable NSComparator NS_NOESCAPE)comparator1
                                            comparator2:(nullable NSComparator NS_NOESCAPE)comparator2
                                            comparator3:(nullable NSComparator NS_NOESCAPE)comparator3;

- (BOOL)isEqualToCollection:(NTFCollectionItem *)collection;

@property (nonatomic, readonly) NSString *displayName;

@property (nonatomic, readonly, getter=isEditable) BOOL editable;
@property (nonatomic, readonly, getter=isRemoveable) BOOL removeable;
@property (nonatomic, readonly, getter=isSystemAll) BOOL systemAll;
@property (nonatomic, readonly, getter=isRoot) BOOL root;

@end

NS_ASSUME_NONNULL_END

#import "NTFCollectionItem+CoreDataProperties.h"
#import "NTFCollectionItem+Compatibility.h"
