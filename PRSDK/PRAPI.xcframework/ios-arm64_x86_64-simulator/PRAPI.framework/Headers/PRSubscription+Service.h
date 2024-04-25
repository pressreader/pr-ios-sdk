//
//  PRSubscription+Service.h
//  PRiphone
//
//  Created by Jackie Cane on 6/27/12.
//  Copyright (c) 2012 NewspaperDirect. All rights reserved.
//

@import UIKit;

#import "PRSubscription.h"
#import "PRService_Constants.h"

NS_ASSUME_NONNULL_BEGIN

@class AFHTTPRequestOperation;
@class SPNode;
@class SKPaymentTransaction;

extern NSString *const PRClientVerificationHeaderEncodingSecretKey;
extern NSString *const PRSubscriptionUserDataKey;

typedef NS_ENUM(NSInteger, BookmarkType) {
    BookmarkTypeArticle = 1,
    BookmarkTypePage = 2
};

@interface PRSubscription (Service)

- (void) postRequest:(NSString *)requestType
             options:(NSDictionary *)options
             success:(BOOL (^)(AFHTTPRequestOperation *, SPNode *))success;

- (void) postRequest:(NSString *)requestType options:(NSDictionary *)options;

- (void)postRequest:(NSString *)requestType
        requestData:(nullable NSString *)xmlFragment
            options:(nullable NSDictionary *)options
         completion:(void(^ _Nullable)(SPNode * _Nullable response, NSError * _Nullable error))completion;

- (void) RequestOnlineServiceWithPath:(nullable NSString *)resourcePath
                               isPost:(BOOL)methodIsPost
                           parameters:(nullable NSDictionary *)params
              useMultipartFormRequest:(BOOL)useMultipartFormRequest
                              success:(nullable void (^)(id _Nullable responseObject))success
                              failure:(nullable void (^)(NSError *_Nullable error))failure;


// calls `RequestOnlineServiceWithPath` with method = "GET", parameters = nil, options = defaultServiceOptions
- (void)requestOnlineServiceWithPath:(NSString *)resourcePath
             useMultipartFormRequest:(BOOL)useMultipartFormRequest
                             success:(void (^_Nullable)(id _Nullable responseObject))successBlock
                             failure:(void (^_Nullable)(NSError *_Nullable error))failureBlock;

- (PRPromise *)requestOnlineServiceWithPath:(NSString *)resourcePath
                                 parameters:(nullable NSDictionary *)params;

- (PRPromise *)requestOnlineServiceWithPath:(NSString *)resourcePath
                                     method:(NSString *)method
                                 parameters:(nullable NSDictionary *)params
                                    options:(NSDictionary *)options
                    useMultipartFormRequest:(BOOL)useMultipartFormRequest;

- (void) RequestOnlineServiceWithPath:(NSString *)resourcePath
                               method:(NSString *)method
                           parameters:(nullable NSDictionary *)params
                              options:(nullable NSDictionary<PRServiceRequestOption, id> *)options
              useMultipartFormRequest:(BOOL)useMultipartFormRequest
                              success:(void (^_Nullable)(id _Nullable responseObject))success
                              failure:(void (^_Nullable)(NSError *_Nullable error))failure;

- (nullable NSDictionary *)updateRequestParameters:(nullable NSDictionary *)parameters token:(NSString *)token;
- (void)requestOnlineConfig;
- (void) SendReadingStatistics;
- (void) changeSubscription:(PRSubscriptionItem *)si delete:(BOOL)doDelete includeSupplements:(BOOL)include keepParent:(BOOL)keep successBlock:(void(^)(void))successBlock failureBlock:(void(^)(NSError *))failureBlock;

- (void)requestIssueDatesForCID:(NSString *)CID
                          limit:(NSInteger)limit
              lastAvailableDate:(nullable NSDate *)lastAvailableDate
                     completion:(PRServiceCompletion)completion;
- (void)requestIssueDatesForCID:(NSString *)CID
                          limit:(NSInteger)limit
              lastAvailableDate:(nullable NSDate *)lastAvailableDate
                requestFullInfo:(BOOL)reqestFullInfo
                     completion:(PRServiceCompletion)completion;
- (void)requestIssueDatesForCIDs:(NSArray<NSString *> *)CIDs
                        pagesize:(NSInteger)pagesize
                            skip:(NSInteger)skip
               lastAvailableDate:(nullable NSDate *)lastAvailableDate
                      completion:(void(^ _Nullable)(NSArray<PRTitleItemExemplar *> * _Nullable))completion;

- (void) RequestIssueVersionsIntForCID:(NSString*)CID issueDate:(NSDate *)issueDate;
- (void) RequestAudioUrlsForCID:(NSString *)CID issueDate:(NSDate *)issueDate;

- (void)requestDownloadLicenseForCID:(NSString *)CID
                                date:(NSDate *)date
                          completion:(void(^)(NSDictionary * _Nullable, NSError * _Nullable))completion;
- (void)requestTrackingOptionsWithCompletion:(void(^)(NSDictionary * _Nullable, NSError * _Nullable))completion;

- (void)requestBundles;
- (void)RequestUserBundles;
- (void)RequestUserBundlesForCID:(NSString *)CID issueDate:(NSDate *)issueDate;
- (void)requestBackIssuesForCID:(NSString *)CID
                          dates:(NSArray*)dates
             includeSupplements:(BOOL)includeSupplements
        purchaseConfirmedByUser:(BOOL)confirmed
                   skipDownload:(BOOL)skipDownload
               orderDescription:(NSDictionary *)orderDescription;
- (void)requestPaymentInfoForCID:(NSString *)CID
                            date:(NSDate *)date;

- (void) RequestTemplateInfoInt:(NSString *)locale;
- (void) RequestNewspaperRadioListIntWithCID:(NSString *)CID issueDate:(NSDate *)issueDate onCompletion:(void(^_Nullable)(BOOL success))completionBlock;
- (void) SendVoteInt:(BOOL)hateVote article:(NSDictionary *)article CID:(NSString *)CID issueDate:(NSDate *)issueDate;

/// completionBlock returns list of those titles which dates were updated (changed)
- (void)requestLatestAvailableIssueDatesForTitles:(NSArray*)titles
                                           forced:(BOOL)forced
                                       completion:(void(^_Nullable)(NSArray *_Nullable updatedTitleList, NSError *_Nullable error))completion;
- (void)resetTitleItemsAvailableDatesUpdateDate;

- (void)requestCIDsInUsersSubscriptions:(void(^)(NSArray<NSString *> *_Nullable, NSError *_Nullable))completion;

- (void) RequestClientList;
- (void) RequestSubscriptions;
- (void) RequestImagesUrl;
- (void) RequestThumbnailUrls;
- (void) RequestMediaUrls;
- (void)requestPublisherConfigUrl;
- (void)requestCatalogForced:(BOOL)forced completion:(PRSimpleResult)handler;
- (void)requestCustomCatalog:(nullable PRSimpleResult)handler;
- (void)requestAppConfig;
- (void)requestClientConfig;
- (void)getManageBehaviourForProvider:(NSString *)provider
                           completion:(void(^_Nullable)(NSString *_Nullable url, NSString *_Nullable title, NSError *_Nullable error))completion;
- (void) RequestValidatePayments:(nullable NSDictionary<NSString*,SKPaymentTransaction *> *)paymentTransactions;
- (void) RequestSmartArticleInfo:(NSString *) artID
                         success:(void (^_Nullable)(NSDictionary *_Nullable artInfo))success
                         failure:(void (^_Nullable)(NSError *_Nullable error))failure;
- (void)requestDataForArticleWithId:(NSString *)artKey language:(nullable NSString *)lngIsoCode repeatOnTimeout:(BOOL)repeadOnTimeout completion:(void (^_Nullable)(NSDictionary *_Nullable artInfo, NSError *_Nullable error))completion;
- (PRPromise *)requestOnlineToken;
- (void) requestPremiumTrialEligibility:(void(^_Nullable)(BOOL isEligibleForPremiumTrial, NSError *_Nullable error))completionBlock;

- (void) requestVoteForArticleInt:(NSString *)artId completed:(void(^_Nullable)(NSDictionary *_Nullable result, NSError *_Nullable error))completionBlock;
- (void) sendVoteInt:(NSInteger)userVote forArticle:(NSString *)artId completed:(void(^_Nullable)(NSDictionary *_Nullable result, NSError *_Nullable error))completionBlock;

- (void) requestPagesetsForIssue:(NSString *)issueId completed:(void(^_Nullable)(NSArray<NSDictionary<NSString *, id> *> *_Nullable pagesets, NSError *_Nullable error))completionBlock;
- (void) addPages:(NSArray<NSNumber *> *)pages toIssue:(NSString *)issueId completed:(void(^_Nullable)(NSDictionary<NSString *, id> *_Nullable pageset, NSError *_Nullable error))completionBlock;
- (void) requestPageset:(NSString *)pagesetId completed:(void(^_Nullable)(NSDictionary<NSString *, id> *_Nullable pageset, NSError *_Nullable error))completionBlock;
- (void) updatePages:(NSArray<NSNumber *> *)pages inPageset:(NSString *)pagesetId completed:(void(^_Nullable)(NSError *_Nullable error))completionBlock;

extern NSString * const kBookmarkCollectionId;
extern NSString * const kBookmarkCollectionName;
extern NSString * const kBookmarkCollectionType;
extern NSString * const kBookmarkCollectionIsPublic;
extern NSString * const kBookmarkCollectionContentCount;
extern NSString * const kBookmarkCollectionWebName;

- (void)requestCollectionForUser:(NSString *)userName
                       completed:(void(^_Nullable)(NSArray<NSDictionary *> *_Nullable collections, NSError *_Nullable error))completionBlock;
- (void) requestCollectionsForArticle:(NSString *)articleId
                            completed:(void (^_Nullable) (NSArray<NSDictionary<NSString *, id> *> *_Nullable collectionInfo, NSError *_Nullable error))completionBlock;
- (void) requestCollectionsForPageset:(NSString *)pagesetId
                            completed:(void (^_Nullable) (NSArray<NSDictionary<NSString *, id> *> *_Nullable collectionInfo, NSError *_Nullable error))completionBlock;
- (void) requestListOfBookmarkCollections:(void (^) (NSArray<NSDictionary *> *_Nullable collectionItems, NSError *_Nullable error))completionBlock;
- (void) createBookmarkCollectionWithNameInt:(NSString *)name
                                    isPublic:(BOOL)isPublic
                                   completed:(void (^_Nullable) (NSDictionary *_Nullable newCollection, NSError *_Nullable error))completionBlock;
- (void) updateBookmarkCollectionWithIdInt:(NSString *)collectionId
                                      name:(NSString *)name
                                  isPublic:(BOOL)isPublic
                                 completed:(void (^_Nullable) (NSError *_Nullable error))completionBlock;
- (void) deleteCollectionInt:(NSString *)collectionId
                   completed:(void (^_Nullable) (NSError *_Nullable error))completionBlock;

- (void) assignArticle:(NSString *)articleId
         toCollections:(nullable NSArray<NSString *> *)collectionIds
             completed:(void (^_Nullable) (NSError *_Nullable error))completionBlock;
- (void) assignPageset:(NSString *)pagesetId
         toCollections:(NSArray<NSString *> *)collectionIds
             completed:(void (^_Nullable) (NSError *_Nullable error))completionBlock;

- (void) assignArticle:(NSString *)articleId
          toCollection:(NSString *)collectionId
             completed:(void (^_Nullable) (NSError *_Nullable error))completionBlock;
- (void) assignPageset:(NSString *)pagesetId
          toCollection:(NSString *)collectionId
             completed:(void (^_Nullable) (NSError *_Nullable error))completionBlock;

- (void) removeFromAllCollectionArticle:(NSString *)articleId completed:(void (^_Nullable) (NSError *_Nullable error))completionBlock;
- (void) removeFromAllCollectionPageset:(NSString *)pagesetId completed:(void (^_Nullable) (NSError *_Nullable error))completionBlock;

- (void) requestDirectLinkForArticle:(NSString *)articleId
                             success:(void (^_Nullable)(NSString *articleUrl))success
                             failure:(void (^_Nullable)(NSError *_Nullable error))failure;
- (void) requestDirectLinkForPageSet:(NSString *)pagesetId
                             success:(void (^_Nullable)(NSString *pagesetUrl))success
                             failure:(void (^_Nullable)(NSError *_Nullable error))failure;

- (void) requestCommentsForArticleWithId:(NSString *)artId
                         completed:(void(^_Nullable)(NSDictionary *_Nullable commentsData, NSError *_Nullable error))completionBlock;
- (void) createCommentPostForArticle:(NSString *)artId
                               issue:(NSString *)issueId
                          parentPost:(NSInteger)parentPostId
                             subject:(NSString *)subject
                                body:(NSString *)body
                           artifacts:(NSArray<NSString *> *)artifactIds
                       completed:(void(^_Nullable)(NSDictionary *_Nullable commentsData, NSError *_Nullable error))completionBlock;
- (void) editCommentPost:(PRSmartCommentPost *)post
                 article:(NSString *)artId
                   issue:(NSString *)issueId
                    body:(NSString *)body
               artifacts:(NSArray<NSString *> *)artifactIds
               completed:(void(^_Nullable)(NSDictionary *_Nullable postData, NSDictionary *_Nullable commentsData, NSError *_Nullable error))completionBlock;
- (void) deleteCommentPost:(NSInteger)postId
                   article:(NSString *)articleId
                     issue:(NSString *)issueId
                 completed:(void(^_Nullable)(NSDictionary *_Nullable commentsData, NSError *_Nullable error))completionBlock;
- (void) reportCommentPost:(NSInteger)postId
                   article:(NSString*)artId
                    reason:(NSString*)reason
                 completed:(void(^_Nullable)(NSError *_Nullable error))completionBlock;
- (void) sendVote:(NSInteger)vote
   forCommentPost:(NSInteger)postId
            issue:(NSString *)issueId
        completed:(void(^_Nullable)(NSInteger currentVote, NSInteger likeItVotes, NSInteger hateItVotes, NSError *_Nullable error))completionBlock;

typedef NSString * PRVideoLinkType NS_STRING_ENUM;
extern PRVideoLinkType const PRVideoLinkTypeYoutube;
extern PRVideoLinkType const PRVideoLinkTypeVimeo;

- (void) uploadImageAttachment:(UIImage *)image
                     completed:(void(^_Nullable)(NSString *_Nullable artifactId, NSString *_Nullable url, NSError *_Nullable error))completionBlock;
- (void) addVideoLink:(NSString *)videoUrl
                 type:(PRVideoLinkType)videoType
            completed:(void(^_Nullable)(NSString *_Nullable artifactId, NSString *_Nullable previewUrl, NSError *_Nullable error))completionBlock;

@end

NS_ASSUME_NONNULL_END

#import "PRSubscription+Favorites.h"
