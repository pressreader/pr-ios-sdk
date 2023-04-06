//
//  PRiphoneAppDelegate+Command.h
//  PRiphone
//
//  Created by Vitali Bounine on 3/24/15.
//  Copyright (c) 2012 NewspaperDirect. All rights reserved.
//

#import "PRiphoneAppDelegate.h"

@import PRAPI.PRCatalogSection;
@import PRAccessibility.PRLaunchCommand;

@protocol NTFArticle;
@class NTFArticleItem;
@class PRWeakLink;
@class Catalog;

NS_ASSUME_NONNULL_BEGIN

@interface PRiphoneAppDelegate (LaunchCommand)

- (void)observeLaunchCommands;

- (BOOL)launchCommand:(PRLaunchCommand)command
           parameters:(nullable NSDictionary *)params
           completion:(void (^_Nullable)(BOOL success))completion;
- (BOOL)launchCommand:(PRLaunchCommand)command parameters:(nullable NSDictionary *)params;
- (BOOL)launchCommand:(PRLaunchCommand)command withParametersFromURL:(NSURL *)url;

@end


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

- (BOOL)openArticleWithId:(nullable NSString *)articleId;

- (BOOL)openArticle:(nullable id<NTFArticle>)article
             parent:(nullable NTFArticleItem *)parent
          presenter:(nullable UIViewController *)presenter;

- (BOOL)openCatalogItemWithId:(NSString *)itemId
                        class:(Class)itemClass
                      catalog:(Catalog *)catalog;

- (BOOL)orderTitleWithCID:(nullable NSString *)cid
                     date:(nullable NSDate *)date
    preferableServiceName:(nullable NSString *)preferableServiceName
            forceDownload:(BOOL)forceDownload;

- (BOOL)signInWithUserName:(nullable NSString *)username
                  password:(nullable NSString *)password
               serviceName:(nullable NSString *)serviceName
                    signup:(BOOL)signup //mode
      navigationController:(nullable PRWeakLink *)navigationController
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

- (BOOL)openCatalogWithSection:(PRCatalogSectionType)section
                   restorePath:(BOOL)restorePath
                 pathToRestore:(nullable NSString *)pathToRestore
                       pathURL:(nullable NSURL *)url
                    filterText:(nullable NSString *)filterText
                     popToRoot:(BOOL)popToRoot;

- (BOOL)openCatalogWithSection:(PRCatalogSectionType)section;
- (BOOL)openCatalog:(BOOL)popToRoot;

- (BOOL)openDownloaded;
- (BOOL)openHomeFeed;

@end


@interface PRiphoneAppDelegate (Shortcuts)
- (void)setupApplicationShortcutItems;

@end

NS_ASSUME_NONNULL_END
