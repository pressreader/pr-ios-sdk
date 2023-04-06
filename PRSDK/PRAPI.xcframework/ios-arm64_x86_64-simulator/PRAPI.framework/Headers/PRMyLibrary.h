//
//  PRMyLibrary.h
//  PRiphone
//
//  Created by Dmitry Melnik on 02/09/08.
//  Copyright 2008 NewspaperDirect. All rights reserved.
//

@import UIKit;

@class PRSmartObject;
@class PRCountableValue;
@class PRSourceItem;

@class PRMyLibraryItem;
@class PRDownload;
@class PRBackgroundDownloadSession;
@class BGTask;

@protocol LibraryItemProtocol;
@protocol PRCatalogItem;

NS_ASSUME_NONNULL_BEGIN

@interface PRMyLibrary : NSObject {
@public
	NSMutableDictionary<NSString *, PRMyLibraryItem *>*	m_mibymid;
    NSMutableDictionary*    m_mibytitle;
    NSMutableArray*         m_mibydate;
	NSMutableArray*			m_sortedTitles;
	NSArray*				mliSortDescriptors;
	NSArray*				mliIssueSortDescriptors;
	
	BOOL                    m_loaded;
    BOOL                    m_isNetworkChanedAlertShown;
	
	NSOperationQueue*		m_pdfRenderingQueue;
	
	id						drawSem;
	NSUInteger				dnlCounter;
}

- (void)initMyLibrary;
- (void)loadMliByMID:(NSString *)MID;

- (PRMyLibraryItem *)itemWithCID:(NSString *)cid date:(NSDate *)date preprocess:(BOOL)preprocess;
- (nullable PRMyLibraryItem *)itemWithCID:(NSString *)cid date:(NSDate *)date;
- (nullable PRMyLibraryItem *)itemWithMID:(NSString*)MID;

- (NSArray*) GetSortedMIDs:(BOOL)descending;
- (NSArray*) GetSortedMIDs:(BOOL)descending filteredByTitle:(NSString *)titleContains;
- (NSUInteger) numberOfOpenedItems;

- (BOOL)deleteItemFromLibrary:(NSString*)MID;
- (void)deleteLibraryItem:(id<LibraryItemProtocol>)item;
- (void) PauseItem:(NSString*)MID;
- (void) ResumeItem:(NSString*)MID;
- (void) PauseResumeItem:(NSString*)MID;

- (void) ShowNetworkChangedAlert: (BOOL)isWifiEnabled;
- (id) drawSem;
//proto end

- (BOOL)addItem:(PRMyLibraryItem*)mli doMerge:(BOOL)doMerge;
- (BOOL)updateItem:(PRMyLibraryItem*)mli;
- (void)insertItem:(PRMyLibraryItem*)mli;
- (void)removeItem:(NSString*)MID;
- (nullable NSArray<PRCatalogItem> *)libraryItemsByCID:(NSString *)cid;
- (nullable PRSourceItem *)purchaseAdviceByCID:(NSString *)cid;

- (nullable PRMyLibraryItem*)findIssueItemEqualTo:(PRMyLibraryItem*)mli;
- (BOOL)isLatestForTitleItem:(PRMyLibraryItem*)mli;
- (BOOL)isLatestOrNewerTitleItem:(PRMyLibraryItem*)mli;

- (void)refresh;
- (void)refreshAfterDelay:(NSTimeInterval)delay;
- (void)update;
- (void)deleteExpiredItemsIfNeeded;
- (void)UpdateDownloads;
- (void)updateNewItemsBadgeNumber;
- (void)DidDownloadMli:(PRMyLibraryItem *)mli;

- (NSArray *)sortedItemsIncludingPurchaseAdvises:(BOOL)includeAdvises;

@property (nonatomic, readonly) NSArray *allMids;
@property (nonatomic, readonly) NSUInteger downloadedUnreadItemsCount;
@property (nonatomic, readonly) NSUInteger newItemsCount;
@property (nonatomic, readonly) BOOL isLoaded;
@property (nonatomic, readonly, strong) PRBackgroundDownloadSession * sharedDownloadSession;
@property (nullable, nonatomic, copy) void (^fetchCompletionHandler)(UIBackgroundFetchResult);
@property (nonatomic, assign) UIBackgroundFetchResult backgroundFetchResult;
@property (nullable, strong) BGTask *bgAppRefreshTask;
@property BOOL bgAppRefreshTaskResult;
@property (nonatomic) BOOL deleteContentOnInit;
@property (nonatomic) BOOL updateWithContentPush;
@property (nonatomic) NSUInteger decDnlCounter;
@property (nonatomic) NSUInteger incDnlCounter;
@property (nonatomic, readonly) NSArray<PRMyLibraryItem *> *mliItems;
@property (nonatomic, readonly) NSArray<id<LibraryItemProtocol>> *downloadedItems;
@property (nonatomic, strong, readonly) NSDictionary *aggregatedLibraryItemsByCID;
@property (nonatomic, copy, readonly) NSDictionary *purchaseAdvicesByCID;
@property (nonatomic, strong, readonly) NSArray *aggregatedLibraryItems;
@property (nonatomic, getter=arePurchaseAdvicesTakenInAccount) BOOL purchaseAdvicesTakenInAccount;
@property (nonatomic, strong) NSMutableArray *orderedItems;

@end

@interface PRMyLibrary (/*PROTECTED*/)
- (void)releaseAggregatedCollections;
@end

NS_ASSUME_NONNULL_END
