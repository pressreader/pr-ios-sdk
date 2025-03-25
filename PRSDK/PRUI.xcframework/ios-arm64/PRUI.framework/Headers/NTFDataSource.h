//
//  NTFDataSource.h
//  PRiphone
//
//  Created by Vitali Bounine on 2016-07-04.
//  Copyright © 2016 NewspaperDirect. All rights reserved.
//

@import PRAPI;

#import <PRUI/NTFCommentsDataSource.h>
#import <PRUI/PRFeedLayoutManager.h>

@import PRConfiguration.PRFeedConfig;
@import PRThumbnail;

NS_ASSUME_NONNULL_BEGIN

@protocol NTFDataSourceDelegate <NSObject>

- (void)loadMoreItemsToTheEnd:(void(^_Nullable)(void))completionBlock NS_SWIFT_NAME(loadMoreItemsToTheEnd(completion:));
- (void)loadMoreItemsAtTheBeginning:(void(^_Nullable)(void))completionBlock NS_SWIFT_NAME(loadMoreItemsAtTheBeginning(completion:));
- (void)currentItemDidChange:(id)currentItem;

@property (nonatomic, readonly) CGFloat contentWidth;

@end

@class PRMenu, PRSmartCommentPost, PRSmartArtifact, PRSmartPageset;

@interface NTFDataSource : NSObject<NTFCommentsDataSource>

- (void)resetSelectedIndex;

- (nullable id)itemAtIndex:(NSInteger)idx;
- (nullable id)itemAtRow:(NSInteger)row;
- (nullable id)unwrappedItemAtRow:(NSInteger)row;

- (NSInteger)indexForItem:(id)item;
- (NSInteger)rowForItem:(id)item;
- (BOOL)containsItem:(id)item;

/// DEPRECATED: use typeForItem instead
- (NTFDataItemType)typeForItemAtIndex:(NSInteger)idx;
- (NTFDataItemType)typeForRow:(NSInteger)row;
- (NTFDataItemType)typeForItem:(id)item;

- (nullable id<FlowArticle>)articleAtIndex:(NSInteger)idx;
- (nullable id<FlowArticle>)articleAtRow:(NSInteger)row;
- (id<NTFArticle>)getCurrentArticle;
- (void)getCurrentArticleWithCompletion:(void(^_Nullable)(id<NTFArticle> _Nullable))completion;
- (nullable id<NTFArticle>)getCurrentArticleWithLoadingHandler:(void(^_Nullable)(id<NTFArticle>))completion;

- (void)refreshData:(void(^)(void))completion;
- (void)loadMoreItemsToTheEnd:(void(^)(NSInteger deleteAtBegininng, NSInteger appendAtTheEnd, NSError * _Nullable error))completion;
- (void)loadMoreItemsAtTheBeginning:(void(^)(NSInteger deleteAtEnd, NSInteger insertedAtBeginning, NSError * _Nullable error))completion;

- (nullable NSDate *) issueDateForItem:(id)item;
- (nullable NSString *) issueTitleForItem:(id)item;
- (NSUInteger) numberOfPagesInIssueForItem:(id)item;
- (BOOL)isAllItemsRightToLeft;
- (BOOL) isRightToLeftInIssueForItem:(id)item;
- (NSInteger) pageIndexForItemAtIndex:(NSInteger)idx;
- (NSInteger) pageNumberForItemAtIndex:(NSInteger)idx;
- (nullable NSString *) pageNameForItemAtIndex:(NSInteger)idx;
- (nullable NSArray<NSNumber *> *)pageNumbersForItem:(id)item;

- (nullable NSString *)tagForItem:(id)item;
- (nullable UIColor *)tagColorForItem:(id)item;
- (nullable NSString *)titleForItemAtRow:(NSInteger)row;
- (nullable NSString *)titleForItemAtIndex:(NSInteger)idx;
- (nullable NSString *)languageForItemAtIndex:(NSInteger)idx;
- (nullable NSString *)originalLanguageForItemAtIndex:(NSInteger)idx;
- (BOOL)updateInfoForItem:(id)item completion:(nullable void(^)(void))completionBlock;
- (BOOL) hasCollectionsForItemAtIndex:(NSInteger)idx;
- (nullable NSArray<NSString *> *)collectionsForItemAtIndex:(NSInteger)idx;
- (void) deleteFromCollectionsItem:(id)item completed:(nullable void (^)(NSError * _Nullable error))completionBlock;
- (nullable NSDate *) collectionAssignmentDateForItemAtIndex:(NSInteger)idx;
- (void) requestCollectionsForItem:(id)item completed:(CollectionsResponse)completionBlock;
- (void) saveItemToBookmarks:(id)item collections:(nullable NSArray<NSString *> *)collectionIds completed:(nullable void (^) (NSError * _Nullable error))completionBlock;
- (void) savePages:(NSSet<NSNumber *> *)pages forItem:(id)item toCollections:(nullable NSArray<NSString *> *)collectionIds completed:(void (^ _Nullable) (NSError * _Nullable error))completionBlock;
- (void) savePages:(NSSet<NSNumber *> *)pages toCollections:(nullable NSArray<NSString *> *)collectionIds completed:(void (^ _Nullable) (NSError * _Nullable error))completionBlock;

- (void) createUserCollection:(NSString *)name isPublic:(BOOL)isPublic completed:(void(^_Nullable)(NSString *collectionId, NSError *_Nullable))completionBlock;
- (void) updateUserCollection:(NSString *)collectionId name:(NSString *)name isPublic:(BOOL)isPublic completed:(void(^_Nullable)(NSError *_Nullable))completionBlock;
- (void) deleteUserCollection:(NSString *)collectionId completed:(void(^_Nullable)(NSError *_Nullable))completionBlock;
- (nullable NSDictionary *)collectionWithId:(NSString *)collectionId;
- (nullable NSDictionary *)userCollectionWithIndex:(NSInteger)index;
- (NSDictionary *)sharingCollectionWithIndex:(NSInteger)index filteredByIds:(NSArray<NSString *> *)ids;

- (void) trackTextFlow;
- (void) trackBookmarkingArticleItem:(id<NTFArticle>) articleItem wasPreviouslyBookmarked:(BOOL)wasBookmarked;

/// Recompiles fetched objects into aggregated layout items.
- (void)recompileData;

/// Must be set prior `layoutType` to take an effect.
@property (nonatomic) NTFLayoutOption layoutOptions;
@property (nonatomic) NTFLayoutType layoutType;

@property (nonatomic) NSInteger preferredColumnsCount;

@property (nonatomic) BOOL analizeNumberOfReadArticles;
@property (nonatomic, readonly) BOOL shouldHideSimilarStories;

- (NSDictionary *)actionConfigForItemAtIndex:(NSInteger)idx; // see action key section above

// Page thumbnails

- (CGSize)sizeOfThumbnailForPageNo:(NSUInteger)pageNo item:(id)item height:(CGFloat)height;

- (CGSize)loadThumbnailForPageNo:(NSUInteger)pageNo
                             item:(id)item
                             size:(CGSize)size
                    fromCacheOnly:(BOOL)cacheOnly
                      completion:(nullable PRThumbnailHandler) completionBlock;

- (void)cancelLoadingThumbnailForPageNo:(NSUInteger)pageNo
                                    item:(id)item
                                  height:(CGFloat)height;
/**
 @warning Use this method only if you know that there is only one item with the same itemId.
 Otherwise use indexForItem: method.
 */
- (nullable NSObject<NTFArticle> *)articleWithUid:(NSString *)itemId index:(nullable NSInteger *)index;

@property (nonatomic, weak) id<NTFDataSourceDelegate> delegate;

@property (nonatomic, readonly) NSInteger rowsCount;
@property (nonatomic, readonly) NSInteger itemsCount;
@property (nullable, nonatomic, strong) id currentFeedItem;
@property (nonatomic, readonly) NSInteger selectedIndex;

/// see action key section above
@property (nonatomic, readonly) NSDictionary *actionConfig;
/// used for action commands controller context
@property (nonatomic, readonly) NSDictionary *context;

@property (nonatomic, readonly) BOOL isRefreshable;
@property (nonatomic, readonly) BOOL hasMoreItemsAtTheEnd;
@property (nonatomic, readonly) BOOL hasMoreItemsAtTheBeginning;
@property (nonatomic, readonly) BOOL isBusy;
@property (nonatomic, readonly) BOOL isReady;

@end


@interface NTFDataSource (/*PROTECTED*/)

- (nullable NSArray<id<NTFItem>> *)itemsInLayoutItem:(id)item;
- (id)unwrapLayoutItem:(id)item;
- (void)resetItemsTranslation;

@property (class, nonatomic, readonly) Class itemType;

@property (null_resettable, nonatomic, strong) id<PRFeedLayoutManager> layoutManager;
@property (nullable, nonatomic, strong) NSArray *dataProvider;

@end

NS_ASSUME_NONNULL_END

#import <PRUI/NTFDataSource+Analytics.h>
