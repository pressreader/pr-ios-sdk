//
//  PRFacebookSignInManager.h
//  PRSocialManagers
//
//  Created by Viacheslav Soroka on 2022-03-01.
//  Copyright © 2022 NewspaperDirect. All rights reserved.
//

#import "_PRSocialManager.h"

NS_ASSUME_NONNULL_BEGIN

@class FacebookSignInResult;

typedef void(^PRExtAuthTokenSignInResult)(BOOL success, BOOL isNewUser, NSError * _Nullable error);
typedef void(^PRExtAuthTokenPermissionResult)(NSString * _Nullable authKey,
                                              BOOL isNewUser,
                                              NSError * _Nullable error);
typedef void(^PRExtAuthTokenSignInHandler)(NSString *token, PRExtAuthTokenSignInResult result);
typedef void(^PRExtAuthTokenPermissionHandler)(NSString *token, PRExtAuthTokenPermissionResult result);

@interface PRFacebookSignInManager : _PRSocialManager

+ (instancetype)shared;

- (void)signIn:(void(^)(FacebookSignInResult *))completion NS_SWIFT_NAME(signIn(_:));
- (void)signInWithExtAuthTokenHandler:(PRExtAuthTokenSignInHandler)extAuthHandler
                           completion:(void(^)(FacebookSignInResult *))completion;

- (void)requestPublishPermissionAndLinkToCurrentAccount:(BOOL)linkToCurrentAccount
                                             completion:(void(^)(FacebookSignInResult *))completion;
- (void)requestPublishPermissionAndLinkToCurrentAccount:(BOOL)linkToCurrentAccount
                                    extAuthTokenHandler:(PRExtAuthTokenPermissionHandler)extAuthHandler
                                             completion:(void(^)(FacebookSignInResult *))completion;

@end

NS_ASSUME_NONNULL_END
