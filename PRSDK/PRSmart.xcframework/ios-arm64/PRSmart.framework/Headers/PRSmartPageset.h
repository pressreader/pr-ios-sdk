//
//  PRSmartPageset.h
//  PRiphone
//
//  Created by Vitali Bounine on 2017-05-18.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

#import "PRSmartBaseObject.h"

NS_ASSUME_NONNULL_BEGIN

extern NSNotificationName const PRSmartPagesetUpdatedNotification;

@interface PRSmartPageset : PRSmartBaseObject

@property (nonatomic, readonly) NSString *pagesetId;
@property (nonatomic, readonly) NSString *encryptedOwnerId;
@property (nonatomic, readonly) NSInteger issueId;
@property (nonatomic, readonly) NSInteger issueVer;
@property (nonatomic, readonly) NSString *issue;
@property (nonatomic, readonly) NSArray<NSNumber *> * pagesArray;

+ (instancetype)pagesetWithRoot:(nullable PRSmartBaseObject *)root attributes:(NSDictionary *)attributes;

- (void) addPage:(NSUInteger)pageNo;
- (void) setPages:(NSSet<NSNumber *> *)pages;
- (BOOL) containsPage:(NSUInteger)pageNo;
- (BOOL) consistOfPage:(NSUInteger)pageNo;

- (BOOL) containsPages:(NSSet<NSNumber *> *)pages;
- (BOOL) consistOfPages:(NSSet<NSNumber *> *)pageSet;
- (BOOL) containsAnyOfPages:(NSSet<NSNumber *> *)pageSet;

- (BOOL) isEqualToPageset:(PRSmartPageset *)pageset;

+ (NSArray<PRSmartPageset *> *)filteredPagesets:(NSArray<PRSmartPageset *> *)pagesets withPages:(NSSet<NSNumber *> *)pageSet;
+ (NSArray<PRSmartPageset *> *)filteredPagesets:(NSArray<PRSmartPageset *> *)pagesets containingPages:(NSSet<NSNumber *> *)pageSet;
+ (NSArray<PRSmartPageset *> *)filteredPagesets:(NSArray<PRSmartPageset *> *)pagesets containingAnyOfPages:(NSSet<NSNumber *> *)pageSet;
+ (NSArray<PRSmartPageset *> *)filteredPagesets:(NSArray<PRSmartPageset *> *)pagesets withPage:(NSUInteger)pageNo;
+ (NSArray<PRSmartPageset *> *)filteredPagesets:(NSArray<PRSmartPageset *> *)pagesets containingPage:(NSUInteger)pageNo;
+ (nullable PRSmartPageset *)firstPagesetFrom:(NSArray<PRSmartPageset *> *)pagesets withPages:(NSSet<NSNumber *> *)pageSet;
+ (nullable PRSmartPageset *)firstPagesetFrom:(NSArray<PRSmartPageset *> *)pagesets withPage:(NSUInteger)pageNo;

- (void) setAssignedCollections:(nullable NSArray<NSDictionary<NSString *, id> *> *)assignedCollections;
- (NSUInteger) numOfAssignedCollections;
- (nullable NSArray<NSString *> *) assignedCollectionIds;
- (nullable NSDate *) collectionsAssignmentDate;
- (void) removeAssignedCollectionsExcept:(NSArray<NSString *> *)collectionIds;
- (BOOL)hasVisibleCollections;

- (void)postUpdateNote;

@end

NS_ASSUME_NONNULL_END
