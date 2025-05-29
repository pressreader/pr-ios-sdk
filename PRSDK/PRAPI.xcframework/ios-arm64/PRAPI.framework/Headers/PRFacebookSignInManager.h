//
//  PRFacebookSignInManager.h
//  PRSocialManagers
//
//  Created by Viacheslav Soroka on 2022-03-01.
//  Copyright © 2022 NewspaperDirect. All rights reserved.
//

#import "_PRSocialManager.h"

NS_ASSUME_NONNULL_BEGIN

@class SignInResult;
@class FacebookSignInResult;

typedef void(^PRExtAuthSignInResult)(BOOL success, BOOL isNewUser, NSError * _Nullable error);
typedef void(^PRExtAuthPermissionResult)(NSString * _Nullable authKey,
                                         BOOL isNewUser,
                                         NSError * _Nullable error);
typedef void(^PRExtAuthSignInHandler)(SignInResult *signInResult, PRExtAuthSignInResult result);
typedef void(^PRExtAuthPermissionHandler)(SignInResult *signInResult, PRExtAuthPermissionResult result);

@interface PRFacebookSignInManager : _PRSocialManager

+ (instancetype)shared;

- (void)signIn:(void(^)(FacebookSignInResult *))completion NS_SWIFT_NAME(signIn(_:));
- (void)signInWithExtAuthHandler:(PRExtAuthSignInHandler)extAuthHandler
                      completion:(void(^)(FacebookSignInResult *))completion;

- (void)requestPublishPermissionAndLinkToCurrentAccount:(BOOL)linkToCurrentAccount
                                             completion:(void(^)(FacebookSignInResult *))completion;
- (void)requestPublishPermissionAndLinkToCurrentAccount:(BOOL)linkToCurrentAccount
                                         extAuthHandler:(PRExtAuthPermissionHandler)extAuthHandler
                                             completion:(void(^)(FacebookSignInResult *))completion;

@end

NS_ASSUME_NONNULL_END
