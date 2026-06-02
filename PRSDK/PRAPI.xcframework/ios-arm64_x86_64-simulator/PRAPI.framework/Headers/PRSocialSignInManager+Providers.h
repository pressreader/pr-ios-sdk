//
//  PRSocialSignInManager+Providers.h
//  PRiphone
//
//  Created by Vitali Bounine on 2021-05-12.
//  Copyright (c) 2021 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AuthenticationServices/AuthenticationServices.h>
#import <PRAPI/PRSocialSignInManager.h>

@class PRAccountItem;

NS_ASSUME_NONNULL_BEGIN

@interface PRSocialSignInManager (ASWebAuthenticationPresentationContextProviding) <ASWebAuthenticationPresentationContextProviding>
@end

@interface PRSocialSignInManager (Twitter)
- (void)twitterLoginWithCompletion:(SignInCompletion)completionHandler;
- (void)twitterRequestPublishPermission:(PRAccountItem *)ai
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
