//
//  NTFMyLibraryItemDataSource.h
//  PRiphone
//
//  Created by Vitali Bounine on 2016-07-05.
//  Copyright © 2016 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NTFDataSource.h"

NS_ASSUME_NONNULL_BEGIN

@class PRMyLibraryItem, NTFSmartDataItem;

extern const NSInteger kNTFMyLibraryDataSourcePagesetIndexBase;

/**
 @class NTFMyLibraryItemDataSource
 @abstact NTFMylibraryItemDataSoure class is concrete implemetation of NDFDataSource protocol
          used for providing Native SmartFlow views with Smart Layout info of localy downloaded title
 */
@interface NTFMyLibraryItemDataSource : NTFDataSource

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithMLI:(PRMyLibraryItem *)mli NS_DESIGNATED_INITIALIZER;

- (NSUInteger)numberOfSections;
- (NSInteger)itemIndexForSectionIndex:(NSInteger)sectionIndex;

- (void)updatePageset:(PRSmartPageset *)pageset withPages:(NSSet<NSNumber *> *)pages completed:(void (^ _Nullable) (NSError * _Nullable error))completionBlock;
- (void)deleteFromCollectionsPageset:(PRSmartPageset *)pageset completed:(void (^)(NSError *error))completionBlock;
- (void)requestCollectionsForPageset:(nullable PRSmartPageset *)pageset
                            completed:(void(^)(NSUInteger userCollectionsCount,
                                               NSUInteger sharingCollectionsCount,
                                               NSArray<NSString *> * _Nullable collectionIds,
                                               NSError * _Nullable error))completionBlock;
- (void)savePageset:(PRSmartPageset *)pageset toCollections:(nullable NSArray<NSString *> *)collectionIds
           completed:(void (^ _Nullable) (NSError * _Nullable error))completionBlock;

@property (nonatomic, unsafe_unretained, readonly) PRMyLibraryItem *mli;

@property (nonatomic, readonly, nullable) NSString *title;
@property (nonatomic, readonly, nullable) NSDate *issueDate;
@property (nonatomic) NSUInteger currentPageIndex;
@property (nonatomic) BOOL forceUseCurrentPageIndex;

@property (nullable, nonatomic, strong) NSString *currentArtID;
@property (nullable, nonatomic, strong) NSString *selectedArtID;
@property (nullable, nonatomic, strong) NSArray<PRSmartPageset *> *pagesets;

@property (nonatomic, readonly) NSArray<__kindof NTFSmartDataItem *> *allItems;

@end

NS_ASSUME_NONNULL_END
