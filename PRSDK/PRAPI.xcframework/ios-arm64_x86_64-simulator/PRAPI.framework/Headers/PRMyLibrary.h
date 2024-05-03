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
	NSMutableDictionary<NSString *, PRMyLibraryItem *>*	m_mibymid;
	
	BOOL                    m_loaded;
    BOOL                    m_isNetworkChanedAlertShown;
	
	NSOperationQueue*		m_pdfRenderingQueue;
}

- (void)initMyLibrary;
- (void)loadMliByMID:(NSString *)MID;

- (PRMyLibraryItem *)itemWithCID:(NSString *)cid date:(NSDate *)date preprocess:(BOOL)preprocess;
- (nullable PRMyLibraryItem *)itemWithCID:(NSString *)cid date:(NSDate *)date;
- (nullable PRMyLibraryItem *)itemWithMID:(NSString*)MID;

- (NSArray*) GetSortedMIDs:(BOOL)descending;
- (NSArray*) GetSortedMIDs:(BOOL)descending filteredByTitle:(NSString *)titleContains;
- (NSUInteger) numberOfOpenedItems;

- (void)deleteItem:(PRMyLibraryItem *)mli;
- (void)deleteLibraryItem:(id<LibraryItemProtocol>)item;
- (void)pauseItem:(NSString *)MID;
- (void)resumeItem:(NSString *)MID;

- (void) ShowNetworkChangedAlert: (BOOL)isWifiEnabled;

- (BOOL)addItem:(PRMyLibraryItem *)mli doMerge:(BOOL)doMerge;
- (BOOL)updateItem:(PRMyLibraryItem *)mli;
- (void)insertItem:(PRMyLibraryItem *)mli;
- (nullable NSArray<PRCatalogItem> *)libraryItemsByCID:(NSString *)cid;
- (nullable id<PRCatalogItem>)purchaseAdviceByCID:(NSString *)cid;

- (nullable PRMyLibraryItem *)findIssueItemEqualTo:(PRMyLibraryItem *)mli;

- (void)getReady;
- (void)refresh;
- (void)refreshAfterDelay:(NSTimeInterval)delay;
- (void)update;
- (void)deleteExpiredItemsIfNeeded;
- (void)updateDownloadsIfReady;
- (void)updateDownloads;
- (void)updateNewItemsBadgeNumber;
- (void)DidDownloadMli:(PRMyLibraryItem *)mli;

- (void)decDnlCounter;
- (void)incDnlCounter;

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
@property (nonatomic, readonly) NSArray<PRMyLibraryItem *> *mliItems;
@property (nonatomic, readonly) NSArray<id<LibraryItemProtocol>> *downloadedItems;
@property (nonatomic, strong, readonly) NSDictionary *aggregatedLibraryItemsByCID;
@property (nonatomic, copy, readonly) NSDictionary<NSString *, id<PRCatalogItem>> *purchaseAdvicesByCID;
@property (nonatomic, strong, readonly) NSArray *aggregatedLibraryItems;
@property (nonatomic) BOOL purchaseAdvicesTakenInAccount;
@property (nonatomic, strong) NSMutableArray<NSDictionary<NSString *, id> *> *orderedItems;

@end

@interface PRMyLibrary (/*PROTECTED*/)
- (void)releaseAggregatedCollections;
@property (nonatomic, readonly) NSArray<id<LibraryItemProtocol>> *libItems;
@end

NS_ASSUME_NONNULL_END
