//
//  PRSubscription.h
//  PRiphone
//
//  Created by Dmitry Melnik on 29/08/08.
//  Copyright 2008 NewspaperDirect. All rights reserved.
//

@import PRUtils.PRNotification;

//@import PRAPI.PRSubscriptionCatalogProtocol;
//@import PRAPI.PRBundle;

#import "PRSubscriptionCatalogProtocol.h"
#import "PRBundle.h"

@class PRTitleItemExemplar;
@class PRSourceItem;
@class PRPromise;

NS_ASSUME_NONNULL_BEGIN

extern NSNotificationName const PRSubscriptionUpdatedNotification;
extern NSNotificationName const PRSubscriptionLatestReadExemplarsUpdatedNotification;
extern NSNotificationName const PRSubscriptionSourcesStatusChangedNotification;
extern NSNotificationName const PRTitlesDidLoadNotification;
extern NSNotificationName const PRSubscriptionFavouritesDidUpdate;
extern NSNotificationName const PRSubscriptionIssuesOrderCompleted;

extern NSNotificationName const PRUserPostUpdatedNotification;
extern NSNotificationName const PRUserPostDeletedNotification;
extern NSNotificationName const PRFollowUpdatedNotification;

typedef NS_OPTIONS(uint32_t, PRSubscriptionSourcesStatus) {
    PRSubscriptionSourcesStatusInitialized = 1 << 0,
    PRSubscriptionSourcesStatusRestoredFromCache = 1 << 1,
    PRSubscriptionSourcesStatusWaitingForUpdateFromNetwork = 1 << 2,
    PRSubscriptionSourcesStatusUpdatingFromNetwork = 1 << 3,
    PRSubscriptionSourcesStatusUpdatedFromNetwork = 1 << 4,
    PRSubscriptionSourcesStatusFailedToUpdate = 1 << 5,
};

typedef NS_OPTIONS(NSUInteger, PRSubscriptionResourceStatus) {
    PRSubscriptionResourceStatusDefault = 0,
    PRSubscriptionResourceStatusImageURLsUpdated = 1 << 0,
    PRSubscriptionResourceStatusThumbURLsUpdated = 1 << 1,
    PRSubscriptionResourceStatusMediaURLsUpdated = 1 << 2
};

typedef NS_ENUM(NSUInteger, PRSmartSearchArea) {
    PRSmartSearchAreaNotDefined = 0,
    PRSmartSearchAreaArticles,
    PRSmartSearchAreaHotSpots,
};

typedef void(^_Nullable PRSimpleResult)(NSError *_Nullable error);

@class PRSmartPageset, PRSmartArticle, PRSmartCommentPost, PRAnalyticsProfile, PRAnalyticsProfileBase;

@interface PRSubscription : PRNotification <PRSubscriptionCatalogProtocol>
{
    NSMutableDictionary<NSString *, PRTitleItem *> *allTitles;
    dispatch_queue_t        _allTitlesAccessQ;
    
    NSMutableDictionary    *subscribed;
    BOOL                   subscribedUpdated;
    
    NSDateFormatter        *latestAvDateFormatter;
    NSDateFormatter        *activationTimeFormatter;
    
    // cids available for download for current subscription
    NSMutableArray<NSString *> *accessibleCids;
    
    NSArray<PRTitleItem *> *m_titlesSortedByParentName;
    NSMutableDictionary    *onProcessBackgroundResponseActions;
    
    NSMutableDictionary    *readingStatistics;  // key is view source: "Articles", "Newsfeed", "Search" or "Pages", value is array of reading stat frames
    NSInteger               statisticsSendingCount;
    BOOL                    statisticsRestored;

    NSMutableDictionary<NSString *, NSMutableArray<NSMutableDictionary<NSString *, id> *> *> *bookReadingStatistics; // key session and userContext
}

@property (class, nonatomic, readonly) PRSubscription *defaultSubscription;
@property (nullable, class, nonatomic, readonly) PRSubscription *defaultOnlineSubscription;

@property (nullable, nonatomic, weak) PRAccountItem *account;
@property (nonatomic, readonly) BOOL sourceDatesObtained;
@property (nullable, nonatomic, strong) NSMutableArray *accessibleCids;
@property (nullable, nonatomic, readonly) id updateLaterObserver;
@property (nonatomic, readonly) BOOL sourcesUpToDate;

// candidates for being replaced with NS_OPTIONS
@property (nonatomic) BOOL requestingHotSpotStatus;
@property (nonatomic) BOOL hotSpotStatusUpdated;
@property (nonatomic) BOOL requestingClientConfig;
@property (nonatomic) BOOL requestingOnlineConfig;

@property (nonatomic, strong, readonly) NSString *name;
@property (null_resettable, nonatomic, strong) PRPromise *onlineTokenRequest;
@property (nonatomic, readonly) BOOL hasOnlineToken;
@property (nullable, nonatomic, strong) NSString *deviceAccountOnlineToken;
@property (nullable, nonatomic, strong) NSString *preloadToken;
@property (nullable, nonatomic, strong) NSDate *onlineTokenExpiration;
@property (nullable, nonatomic, copy) NSString *activationId;
@property (nonatomic, readonly, getter = isValid) BOOL valid;
@property (nonatomic, readonly) BOOL isDefaultOnline;

@property (nullable, nonatomic, strong) NSArray *contentCategories;
@property (nullable, nonatomic, strong) NSArray *groups;
@property (nullable, nonatomic, strong) NSArray *contentRegions;
@property (nullable, nonatomic, strong) NSArray *featuredTitles;

/// nil or array (can be empty) in case of info was retrieved
@property (nullable, nonatomic, strong, readonly) NSArray<PRTitleItemExemplar *> *latestReadExemplars;

@property (nullable, nonatomic, strong, readonly) NSSet<NSString *> *latestReadCIDs;
@property (nonatomic) PRSubscriptionSourcesStatus sourcesStatus;
@property (nonatomic) PRSubscriptionResourceStatus resourceStatus;

@property (nullable, nonatomic, strong) NSCache *channelSearchResults;
@property (nullable, nonatomic, strong) NSCache *sourcesSearchResults;

@property (nullable, nonatomic, strong) NSArray<PRBundle *> *bundlesWithCIDs;
- (NSArray<PRBundle *> *)bundlesWithCIDs:(NSSet<NSString *> *)cids
                              bundleType:(PRBundleProductType)type;
- (NSArray<NSString *> *)appStoreProductIDsFromBundlesWithCIDs:(nullable NSSet<NSString *> *)cids
                                                    bundleType:(PRBundleProductType)type;

+ (NSString *)localizedSubscriptionResult:(nullable NSString *)resultCode
                       defaultErrorString:(nullable NSString *)defaultErrorString;

- (instancetype)initWithAccount:(PRAccountItem *)accountItem
                   activationId:(nullable NSString *)activationId;
- (void)restoreFromCache;
- (BOOL)isCatalogCacheAvailable;
- (void)removeTitleItem:(PRSourceItem *)ti;
- (void)getSmartSearchSuggestions:(NSString *)searchText
                            count:(NSUInteger)count
                          success:(void(^ _Nullable)(NSArray * _Nullable suggestions))success
                          failure:(PRSimpleResult)failure;
- (void)getSmartSearchHistory:(nullable NSString *)searchText
                         area:(PRSmartSearchArea)area
                        count:(NSUInteger) count
                      success:(void(^ _Nullable)(NSArray * _Nullable suggestions))success
                      failure:(PRSimpleResult)failure;
- (void)clearSmartSearchHistory:(PRSmartSearchArea)area
                        success:(void(^ _Nullable)(void))success
                        failure:(void(^ _Nullable)(NSError *error))failure;

- (void)getCommentsForArticle:(PRSmartArticle *)article
                    completed:(void(^)(NSArray<PRSmartCommentPost*> * _Nullable comments,
                                       NSError * _Nullable error))completionBlock;

- (void)newCommentPostForArticle:(PRSmartArticle *)article
                           issue:(nullable NSString *)issueId
                      parentPost:(NSInteger)parentPostId
                         subject:(nullable NSString *)subject
                            body:(nullable NSString *)body
                       artifacts:(nullable NSArray<NSString *> *)artifactIds
                       completed:(void(^ _Nullable)(NSArray<PRSmartCommentPost *> *  _Nullable posts,
                                                    NSError * _Nullable error))completionBlock;

- (void)updateCommentPost:(PRSmartCommentPost *)post
                  article:(PRSmartArticle *)article
                    issue:(nullable NSString *)issueId
                     body:(nullable NSString *)body
                artifacts:(nullable NSArray<NSString *> *)artifactIds
                completed:(void(^ _Nullable)(NSDictionary * _Nullable postData,
                                             NSArray<PRSmartCommentPost *> * _Nullable posts,
                                             NSError * _Nullable error))completionBlock;

- (void)removeCommentPost:(NSInteger)postId
                  article:(PRSmartArticle *)article
                    issue:(nullable NSString *)issueId
                completed:(void(^ _Nullable)(NSArray<PRSmartCommentPost *> * _Nullable posts,
                                             NSError * _Nullable error))completionBlock;

- (void)updateVote:(NSInteger)vote
    forCommentPost:(PRSmartCommentPost *)post
             issue:(nullable NSString *)issueId
         completed:(void(^ _Nullable)(NSInteger currentVote,
                                      NSInteger likeItVotes,
                                      NSInteger hateItVotes,
                                      NSError * _Nullable error))completionBlock;

- (void)getListOfBookmarkCollections:(void(^ _Nullable)(NSArray<NSDictionary *> * _Nullable collectionItems,
                                                        NSError * _Nullable error))completionBlock;
- (nullable NSDictionary *)bookmarkCollectionWithId:(NSString *)collectionId;
@property (nullable, nonatomic, strong, readonly) NSMutableArray<NSMutableDictionary *> *bookmarkCollections;

- (void)createBookmarkCollectionWithName:(NSString *)name
                                isPublic:(BOOL)isPublic
                               completed:(void (^ _Nullable)(NSDictionary * _Nullable newCollection,
                                                             NSError * _Nullable error))completionBlock;
- (void)updateBookmarkCollectionWithId:(NSString *)collectionId
                                  name:(NSString *)name
                              isPublic:(BOOL)isPublic
                             completed:(PRSimpleResult)completionBlock;
- (void)deleteCollection:(NSString *)collectionId
               completed:(PRSimpleResult)completionBlock;

- (void)getCollectionsForArticle:(PRSmartArticle *)article
                       completed:(void(^ _Nullable)(NSArray<NSString *> * _Nullable collectionIds,
                                                    NSError * _Nullable error))completionBlock;

- (void)addArticle:(PRSmartArticle *)article
      toCollection:(NSString *)collectionId
         completed:(PRSimpleResult)completionBlock;

- (void)addArticle:(PRSmartArticle *)article
     toCollections:(nullable NSArray<NSString *> *)collectionIds
         completed:(PRSimpleResult)completionBlock;

- (void)removeFromAllCollectionsArticle:(PRSmartArticle *)article completed:(PRSimpleResult)completionBlock;


- (void)addPageset:(PRSmartPageset *)pageset
      toCollection:(NSString *)collectionId
           success:(void(^ _Nullable)(void))success
           failure:(PRSimpleResult)failure;

- (void)addPages:(NSSet<NSNumber *> *)pageSet
        forIssue:(NSString *)issue
   toCollections:(NSArray<NSString *> *)collectionIds
         success:(void(^ _Nullable)(void))success
         failure:(PRSimpleResult)failure;

- (void)removeFromAllCollectionsPages:(NSSet<NSNumber *> *)pageSet
                             forIssue:(NSString *)issue
                              success:(void(^ _Nullable)(void))success
                              failure:(PRSimpleResult)failure;

- (void)getCopyLinksInfoForArticle:(NSString *)artID
                           success:(void(^ _Nullable)(NSDictionary *copyLinkInfo))success
                           failure:(PRSimpleResult)failure;

- (void)getPagesetById:(NSString *)pagesetID
          completetion:(void(^ _Nullable)(PRSmartPageset * _Nullable,
                                          NSError * _Nullable))completionBlock;
- (void)getPagesetsForIssue:(NSString *)issue
                  completed:(void(^ _Nullable)(NSArray<PRSmartPageset *> * _Nullable pagesets,
                                               NSError * _Nullable error))completionBlock;
- (void)newPagesetForIssue:(NSString *)issue
                 withPages:(NSSet<NSNumber *> *)pageSet
                completion:(void(^ _Nullable)(PRSmartPageset * _Nullable pageset,
                                              NSError * _Nullable error))completionBlock;
- (void)updatePageset:(PRSmartPageset *)pageset
            withPages:(NSSet<NSNumber *> *)pageSet
           completion:(void(^ _Nullable)(NSError * _Nullable error))completionBlock;
- (void)getPagesetsForIssue:(NSString *)issue
                  withPages:(NSSet<NSNumber *> *)pageSet
                 completion:(void(^ _Nullable)(NSArray<PRSmartPageset *> * _Nullable pagesets,
                                               NSError * _Nullable error))completionBlock;
- (void)getPagesetsForIssue:(NSString *)issue
            containingPages:(NSSet<NSNumber *> *)pageSet
                 completion:(void(^ _Nullable)(NSArray<PRSmartPageset *> * _Nullable pagesets,
                                               NSError * _Nullable error))completionBlock;
- (void)getPagesetsForIssue:(NSString *)issue
                   withPage:(NSUInteger)pageNo
                 completion:(void(^ _Nullable)(NSArray<PRSmartPageset *> * _Nullable pagesets,
                                               NSError * _Nullable error))completionBlock;
- (void)getPagesetsForIssue:(NSString *)issue
             containingPage:(NSUInteger)pageNo
                 completion:(void(^ _Nullable)(NSArray<PRSmartPageset *> * _Nullable pagesets,
                                               NSError * _Nullable error))completionBlock;
- (void)getCollectionsForPageset:(PRSmartPageset *)pageset
                      completion:(void(^ _Nullable)(NSArray<NSString *> * _Nullable collectionIds,
                                                    NSError * _Nullable error))completionBlock;
- (void)addPageset:(PRSmartPageset *)pageset
     toCollections:(NSArray<NSString *> *)collectionIds
        completion:(PRSimpleResult)completionBlock;
- (void)deleteFromAllCollectionsPageset:(PRSmartPageset *)pageset
                             completion:(PRSimpleResult)completionBlock;

- (void)getFirstPagesetForIssue:(NSString *)issue withPages:(NSSet<NSNumber *> *)pageSet
                     completion:(void(^ _Nullable)(PRSmartPageset * _Nullable pageset,
                                                   NSError * _Nullable error))completionBlock;
- (void)getFirstPagesetForIssue:(NSString *)issue
                       withPage:(NSUInteger)pageNo
                     completion:(void(^ _Nullable)(PRSmartPageset * _Nullable pageset,
                                                   NSError * _Nullable error))completionBlock;
- (void)getDirectLinkForIssue:(NSString *)issue
                    withPages:(NSSet<NSNumber *> *)pageSet
                   completion:(void(^ _Nullable)(PRSmartPageset * _Nullable pageset,
                                                 NSString * _Nullable pagesetUrl,
                                                 NSError * _Nullable error))completionBlock;
- (void)getDirectLinkForIssue:(NSString *)issue
                     withPage:(NSUInteger)pageNo
                   completion:(void(^ _Nullable)(PRSmartPageset * _Nullable pageset,
                                                 NSString * _Nullable pagesetUrl,
                                                 NSError * _Nullable error))completionBlock;
- (void)getPagesetAndDirectLinkById:(NSString *)pagesetID
                            success:(void(^ _Nullable)(PRSmartPageset *, NSString *))success
                            failure:(void(^ _Nullable)(NSError *))failure;
- (void)getCollectionsForIssue:(NSString *)issue
                     withPages:(NSSet<NSNumber *> *)pageSet
                    completion:(void(^ _Nullable)(NSArray<NSString *> * _Nullable collectionIds,
                                                  NSError * _Nullable error))completionBlock;
- (void)getCollectionsForIssue:(NSString *)issue
                      withPage:(NSUInteger)pageNo
                    completion:(void(^ _Nullable)(NSArray<NSString *> * _Nullable collectionIds,
                                                  NSError * _Nullable error))completionBlock;

- (void)optoutHotzone:(BOOL)optout
              success:(void(^ _Nullable)(void))success
              failure:(PRSimpleResult)failure;
- (void)getHotZoneLocationsWithZoomLevel:(long)zoomLevel
                            northEastLat:(double)northEastLat
                            northEastLng:(double)northEestLng
                            southWestLat:(double)southWestLat
                            southWestLng:(double)southWestLng
                              currentLat:(double)myLat
                              currentLng:(double)myLng
                                 pattern:(NSString *)pattern
                                 success:(void(^ _Nullable)(NSArray * _Nullable hotSpots))success
                                 failure:(PRSimpleResult)failure;
- (void)getGeoFencingHotZoneLocationsAtNorthEastLat:(double)northEastLat
                                       northEastLng:(double)northEestLng
                                       southWestLat:(double)southWestLat
                                       southWestLng:(double)southWestLng
                                            success:(void (^ _Nullable)(NSArray * _Nullable hotSpots))success
                                            failure:(PRSimpleResult)failure;

- (void)searchForHotZoneLocations:(NSString *)searchString
                            count:(NSUInteger)count
                       completion:(void(^ _Nullable)(NSArray * _Nullable hotSpots,
                                                     NSError * _Nullable error))completion;

- (void)getRegionOfHotZonesWithPattern:(NSString *)searchString
                            currentLat:(double)myLat
                            currentLng:(double)myLng
                      currentZoomLevel:(int)myZoomLevel
                               success:(void (^ _Nullable)(NSDictionary *regionOfHotZones))success
                               failure:(PRSimpleResult)failure;

- (void)getCurrentLocationByIPAddress:(void(^ _Nullable)(NSDictionary * _Nullable items,
                                                         NSError * _Nullable error))completionBlock;

- (void)recoverPasswordForUsername:(NSString *)username
                        onComplete:(void(^ _Nullable)(BOOL success,
                                                      NSError * _Nullable error))onComplete;

- (void)requestAnalyticsProfilesConfigurationAndCompleted:(void(^ _Nullable)(NSArray * _Nullable,
                                                                             NSError * _Nullable error))completionBlock;
- (void)requestAnalyticsProfileWithId:(NSString *)profileId
                            completed:(void(^ _Nullable)(PRAnalyticsProfile * _Nullable analyticsProfile,
                                                         NSError * _Nullable error))completionBlock;
- (void)requestAnaliticsIssueConfigWithCID:(NSString *)cid
                                 issueDate:(NSString *)issueDateString
                                 completed:(void(^ _Nullable)(NSArray<PRAnalyticsProfileBase *> * _Nullable profiles,
                                                              NSError * _Nullable error))completionBlock;

- (void)titlesDidLoad:(nullable NSDictionary *)userInfo;
- (void)updateRadioInfoForTitleItem:(PRTitleItem *)titleItem
                               date:(NSDate *)date
                       onCompletion:(void(^ _Nullable)(BOOL success))completionBlock;
- (void)resetCaches;
- (void)unlinkTitles;
- (void)updateCatalog;
- (void)updateCatalogForced:(NSNumber * _Nullable)forced;
- (void)setNeedsUpdateCatalog;
- (void)setNeedsUpdateResourceURLs;
- (void)setNeedsUpdatePressCatalog;
- (void)updateCatalogAfterDelay:(NSTimeInterval)delay;
- (void)updateCustomCatalog:(void(^ _Nullable)(BOOL))completion;
- (void)updateTitlesSpotlight;
- (void)updateAll;
- (void)updateLatestReadExemplars;
- (void)updateLatestAvailableDates:(BOOL)force completion:(void(^_Nullable)(void))completion;
- (void)updateRemainingCredits;
- (void)updateConfigsIfNeeded;

@end

NS_ASSUME_NONNULL_END

#import "PRSubscription+Back2ObjC.h"
#import "PRSubscription+Titles.h"
#import "PRSubscription+Promise.h"
