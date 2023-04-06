//
//  PRSocialSignInManager+Providers.h
//  PRiphone
//
//  Created by Vitali Bounine on 2021-05-12.
//  Copyright (c) 2021 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

@import PRAPI.PRSocialSignInManager;
@class ACAccount;
@class PRAccountItem;

NS_ASSUME_NONNULL_BEGIN

@protocol PRSocialSignInDelegate <NSObject>
- (void)chooseTwitterAccountForAuth:(NSArray<ACAccount *> *)accounts
                         onComplete:(void(^)(NSUInteger selectedIndex))onComplete;
@end

#ifndef SignInCompletion
typedef void (^SignInCompletion)(BOOL success, BOOL isNewUser, NSError *_Nullable error);
#endif

#ifndef ExternalAuthCompletion
typedef void (^ExternalAuthCompletion)(NSString *_Nullable authKey, BOOL isNewUser, NSError *_Nullable error);
#endif

@interface PRSocialSignInManager ()
@end

@interface PRSocialSignInManager (Twitter)
@property (nonatomic, weak) id<PRSocialSignInDelegate> delegate;

- (void)twitterLogin:(id<PRSocialSignInDelegate>)delegate
          completion:(SignInCompletion)completionHandler;
- (void)twitterRequestPublishPermission:(PRAccountItem *)ai
                               delegate:(id<PRSocialSignInDelegate>)delegate
                             completion:(ExternalAuthCompletion)completionHandler;
- (void)twitterRequestPublishPermission:(PRAccountItem *)ai
                               delegate:(id<PRSocialSignInDelegate>)delegate
                   linkToCurrentAccount:(BOOL)linkToCurrentAccount
                             completion:(ExternalAuthCompletion)completionHandler;
@end

@interface PRSocialSignInManager (Facebook)

- (void)facebookLogin:(SignInCompletion)completionHandler;
- (void)facebookRequestPublishPermission:(PRAccountItem *)ai
                              completion:(ExternalAuthCompletion)completionHandler;
- (void)facebookRequestPublishPermission:(PRAccountItem *)ai
                    linkToCurrentAccount:(BOOL)linkToCurrentAccount
                              completion:(ExternalAuthCompletion)completionHandler;

@end

@interface PRSocialSignInManager (Google)
- (void)googleLoginWithCompletion:(SignInCompletion)completionHandler;
- (void)googleRequestPublishPermission:(PRAccountItem *)ai
                  linkToCurrentAccount:(BOOL)linkToCurrentAccount
                            completion:(ExternalAuthCompletion)completionHandler;
@end

NS_ASSUME_NONNULL_END
