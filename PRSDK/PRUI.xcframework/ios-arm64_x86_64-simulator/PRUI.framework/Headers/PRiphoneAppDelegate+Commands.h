//
//  PRiphoneAppDelegate+Command.h
//  PRiphone
//
//  Created by Vitali Bounine on 3/24/15.
//  Copyright (c) 2012 NewspaperDirect. All rights reserved.
//

#import "PRiphoneAppDelegate.h"

@protocol NTFArticle;
@class NTFArticleItem;
@class PRWeakLink;
@class Catalog;

NS_ASSUME_NONNULL_BEGIN

@interface PRiphoneAppDelegate (Commands)

- (BOOL)registerLocalServerURL:(nullable NSString *)serverUrl
                      username:(nullable NSString *)username
                      password:(nullable NSString *)password;

- (BOOL)openIssueWithCID:(NSString *)cid
                    date:(nullable NSDate *)date
           forceDownload:(BOOL)forceDownload
         waitForPurchase:(BOOL)waitForPurchase
              pageNumber:(nullable NSNumber *)pageNumber
               articleId:(nullable NSString *)articleId;

- (BOOL)openArticleWithId:(NSString *)articleId
               parameters:(nullable NSDictionary *)parameters
        completionHandler:(void(^_Nullable)(void))completionHandler
NS_SWIFT_NAME(openArticle(id:parameters:completionHandler:));

- (void)openArticleWithId:(NSString *)articleId
        completionHandler:(void(^_Nullable)(void))completionHandler
NS_SWIFT_NAME(openArticle(id:completionHandler:));

- (BOOL)openArticle:(nullable id<NTFArticle>)article
             parent:(nullable NTFArticleItem *)parent
          presenter:(nullable UIViewController *)presenter;

- (BOOL)openCatalogItemWithId:(NSString *)itemId
                        class:(Class)itemClass
                      catalog:(nullable Catalog *)catalog;

- (BOOL)signInWithUserName:(nullable NSString *)username
                  password:(nullable NSString *)password
               serviceName:(nullable NSString *)serviceName
                    signup:(BOOL)signup //mode
                 presenter:(nullable PRWeakLink *)presenter
            hideBackButton:(BOOL)hideBackButton
            showSkipButton:(BOOL)showSkipButton
          onSuccessCommand:(nullable NSString *)onSuccessCommand
onSuccessCommandParameters:(nullable NSDictionary *)onSuccessCommandParameters
                  onLaunch:(BOOL)onLaunch;

- (BOOL)signInWithUserName:(nullable NSString *)username
                  password:(nullable NSString *)password
               serviceName:(nullable NSString *)serviceName;

- (BOOL)signInWithExternalNetwork:(nullable NSString *)externalAuthNetwork
             linkToCurrentAccount:(BOOL)linkToCurrentAccount;

- (BOOL)openCatalog;
- (BOOL)openDownloaded;
- (BOOL)openHomeFeed;

@end


@interface PRiphoneAppDelegate (RawCommands)
- (BOOL)registerGiftedAccessWithParameters:(nullable NSDictionary *)params otherCommand:(nullable NSString *)command;
- (BOOL)signInWithParameters:(nullable NSDictionary *)params;
- (BOOL)openHotSpotsMapWithParameters:(nullable NSDictionary *)params;
- (BOOL)openArticle:(id<NTFArticle>)article parameters:(nullable NSDictionary *)params;
- (BOOL)openPublicationsWithParameters:(nullable NSDictionary *)parameters;
- (BOOL)openBooksWithParameters:(nullable NSDictionary *)parameters;
- (BOOL)openUrlWithParameters:(nullable NSDictionary *)params;
- (BOOL)downloadItemWithParameters:(nullable NSDictionary *)parameters;
- (BOOL)openGiftCampaignWithParameters:(nullable NSDictionary *)params;
- (BOOL)notifyWithParameters:(nullable NSDictionary *)params;
- (BOOL)openPublicationDetailsWithParameters:(nullable NSDictionary *)params;
@end


@interface PRiphoneAppDelegate (LaunchCommand)
- (void)observeLaunchCommands;
@end


@interface PRiphoneAppDelegate (Utils)
+ (nullable NSDate *)issueDateFromDictionary:(nullable NSDictionary *)info;
+ (nullable NSString *)cidFromDictionary:(nullable NSDictionary *)params;
+ (NSDictionary *)normaliseParameters:(NSDictionary *)params;

- (void)waitForAPanel:(void(^_Nonnull)(void))completion;

@end

NS_ASSUME_NONNULL_END
