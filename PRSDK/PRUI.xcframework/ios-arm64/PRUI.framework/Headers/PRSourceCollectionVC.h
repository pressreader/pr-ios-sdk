//
//  PRSourcesCollectionVC.h
//  
//
//  Created by Jackie Cane on 8/21/13.
//
//

#import "PRFilterableCollectionVC.h"

@import PRAPI.PROptions;
@import PRUIKit;

@class PRSourceCollectionVC;
@class PRIssuesGroup;
@class PRTitleItemExemplar;
@class PRSubscription;
@class PRTitleItem;
@class PRCatalogSection;
@class PRSourceList;

@protocol PRCatalogItem;
@protocol CatalogItemDataSourceProtocol;
@protocol ItemSelectionDelegate;

typedef NS_ENUM(NSUInteger, PRTitleItemsCollectionDataProviderType) {
    PRTitleItemsCollectionDataProviderTypeSourceList = 0,
    /// When exemplars mode is enabled sourceList isn't used for populating rawDataProvider.
    /// In this mode it's up to controller to fill rawDataProvider properly.
    PRTitleItemsCollectionDataProviderTypeExemplars,
    /// ExemplarsBySections type supposed array of dictionaries as data provider with  keys:
    /// name:NSString; data:NSArray.
    PRTitleItemsCollectionDataProviderTypeGroupedExemplars,
    PRTitleItemsCollectionDataProviderTypeCatalogItems
};

typedef NS_OPTIONS(NSInteger, PRSourceCollectionOption) {
    PRSourceCollectionOptionDisableTitleMultiplicity = 1 << 0,
    PRSourceCollectionOptionDisplayOnlySupplementName = 1 << 1,
    PRSourceCollectionOptionEnableLongTap = 1 << 2,
    PRSourceCollectionOptionAllowLibraryItemDeletion = 1 << 3,
    /// Product Backlog Item 49462:iOS: Publications hub - show yesterday's thumb while loading today's.
    PRSourceCollectionOptionShowLatestAvailableThumbIfCurrentNotLoaded = 1 << 4,
    PRSourceCollectionOptionProcessInfoBarTapAsThumbnailTap = 1 << 5,
    PRSourceCollectionOptionDisplayEmptySections = 1 << 6
};

NS_ASSUME_NONNULL_BEGIN

@protocol PRSourceCollectionControllerDelegate <NSObject>
- (void)collectionController:(PRSourceCollectionVC *)controller
                  selectItem:(PRTitleItemExemplar *)item
                    userInfo:(NSDictionary *)userInfo;
@end


@interface PRSourceCollectionVC : PRFilterableCollectionVC <DataSourceObserver>

/// dataProviderType: PRTitleItemsCollectionDataProviderTypeSourceList
- (instancetype)initWithSourceList:(PRSourceList *)sourceList
                          delegate:(nullable id<PRSourceCollectionControllerDelegate>)delegate;
- (instancetype)initWithSourceList:(PRSourceList *)sourceList;

/// dataProviderType: PRTitleItemsCollectionDataProviderTypeExemplars
- (instancetype)initWithExemplars:(NSArray<PRTitleItemExemplar *> *)tExemplars
                         delegate:(nullable id<PRSourceCollectionControllerDelegate>)delegate;

/// dataProviderType: PRTitleItemsCollectionDataProviderTypeGroupedExemplars
- (instancetype)initWithGroups:(NSArray<PRIssuesGroup *> *)tExemplars
                      delegate:(nullable id<PRSourceCollectionControllerDelegate>)delegate;

/// dataProviderType: PRTitleItemsCollectionDataProviderTypeCatalogItems
- (instancetype)initWithItems:(NSArray<id<PRCatalogItem>> *)items
                     delegate:(nullable id<PRSourceCollectionControllerDelegate>)delegate;

/// dataProviderType: PRTitleItemsCollectionDataProviderTypeExemplars
- (instancetype)initWithDataSource:(id<CatalogItemDataSourceProtocol>)dataSource
                          delegate:(nullable id<PRSourceCollectionControllerDelegate>)delegate;

- (NSUInteger)groupCountForItem:(id)item;
- (NSString *)accessoryTextForItem:(id)item;

- (void)fillWithTitleItemExemplars:(NSArray<PRTitleItemExemplar *> *)tExemplars NS_SWIFT_NAME(fill(with:));
- (void)fillWithSourceList:(PRSourceList *)list NS_SWIFT_NAME(fill(with:));
- (void)fillWithDataSource:(id<CatalogItemDataSourceProtocol>)dataSource NS_SWIFT_NAME(fill(with:));

- (void)setNeedsReloadDataAndScrollToCid:(NSString *)cid date:(NSDate *)date;
- (void)loadAndScrollToTarget;

- (void)completeDataLoading:(id)source;

@property (nonatomic, readonly) PRTitleItemsCollectionDataProviderType dataProviderType;

@property (nullable, nonatomic, strong, readonly) PRSourceList *sourceList;

@property (nonatomic) BOOL prefersOpeningReaderView;

@property (nullable, nonatomic, strong, readonly) id<CatalogItemDataSourceProtocol> loadableDataSource;

/// IMPORTANT: do not retain `section` as section itself might have strong reference to controller.
@property (nullable, nonatomic, weak) PRCatalogSection *catalogSection;

@property (nullable, nonatomic, weak) id<PRSourceCollectionControllerDelegate> delegate;
@property (nullable, nonatomic, weak) id<ItemSelectionDelegate> itemSelectionDelegate;

@property (nonatomic) PRSourceCollectionOption options;

@property (nonatomic, readonly) PRCatalogSortingOrder sortingOrder;
@property (nullable, nonatomic, weak) PRSubscription *preferableSubscription;

@property (nonatomic) CGFloat collectionViewHorizontalPadding;

/// Shows loading view until `sourceList` is ready.
@property (nonatomic) BOOL shouldWaitForSourceList;
@property (nonatomic) BOOL showActivityIndicator;

@property (nonatomic, readonly) NSArray<id<PRCatalogItem>> *visibleItems;

@end

@interface PRSourceCollectionVC (/*Protected*/)
/// Contains raw data without banners, etc.
@property (nullable, nonatomic, strong) NSArray *rawDataProvider;

/// A formatted data provider with all the necessary additional elements (such as banners). Should be used as a data source for collection view
@property (nullable, nonatomic, strong) NSArray *dataProvider;

@end

NS_ASSUME_NONNULL_END
