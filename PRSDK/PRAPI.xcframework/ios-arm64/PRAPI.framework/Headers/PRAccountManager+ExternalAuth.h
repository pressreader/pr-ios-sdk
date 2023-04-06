//
//  PRAccountManager+ExternalAuth.h
//  PRiphone
//
//  Created by Jackie Cane on 24/07/15.
//  Copyright (c) 2015 NewspaperDirect. All rights reserved.
//

#import "PRAccountManager.h"

@import PRUtils.PRSignInOption;

@class PRLinkedService;

NS_ASSUME_NONNULL_BEGIN

#ifndef SignInCompletion
typedef void (^SignInCompletion)(BOOL success, BOOL isNewUser, NSError *_Nullable error);
#endif

#ifndef ExternalAuthCompletion
typedef void (^ExternalAuthCompletion)(NSString *_Nullable authKey, BOOL isNewUser, NSError *_Nullable error);
#endif

@class SignInResult;

@interface PRAccountManager (ExternalAuth)

+ (NSArray<PRSignInOption *> *)allSignInOptionsFromArray:(NSArray *)array;
+ (NSArray<PRSignInOption *> *)supportedSignInOptionsFromOptions:(NSArray<PRSignInOption *> *)array;

+ (NSArray<PRLinkedService *> *)linkedServicesFromArray:(NSArray *)array;
   
- (void)requestExternalAuthSocialNetworks:(void(^_Nullable)(NSArray *networks, NSError *error))onComplete;

/** Authorization of auth token obtained during native login and sign in via auth key
 @param token access (oauth) token obtained during native login
 @param provider facebook, twitter, google, yahoo, linkedin, openid
 */
- (void)signInWithExternalAuthToken:(NSString *)token
                           provider:(NSString *)provider
                  completionHandler:(SignInCompletion)completionHandler;

/** Authorization of auth token obtained during native login and sign in via auth key
 @param token access (oauth) token obtained during local aggregate framework provider login
 @param provider third party aggreate provider (for example "PIANOID")
 */
- (void)signInWithExternalAuthToken:(NSString *)token
                        extProvider:(NSString *)provider
                  completionHandler:(SignInCompletion)completionHandler;

- (void)signInWithInfo:(SignInResult *)info
              provider:(PRAuthProviderName)provider
     completionHandler:(SignInCompletion)completionHandler NS_SWIFT_NAME(signIn(info:provider:completion:));

- (void)signInWithExternalAuthPerson:(NSString *)userId
                               email:(nullable NSString *)email
                           firstName:(nullable NSString *)firstName
                            lastName:(nullable NSString *)lastName
                        displayName:(nullable NSString *)displayName
                     profileImageUrl:(nullable NSString *)profileImageUrl
                            provider:(NSString *)provider
                   completionHandler:(SignInCompletion)completionHandler;

/** Authorization of auth token obtained during native login
 @param token access (oauth) token obtained during native login
 @param account account used for external auth: default or linked service in case of sharing from title downloaded with that account
 @param provider facebook, twitter, google, yahoo, linkedin, openid
 @param authType signup, sharing
 */
- (void)authorizeExternalAuthToken:(NSString *)token
                           account:(nullable PRAccountItem *)account
                          provider:(NSString *)provider
                          authType:(NSString *)authType 
                 completionHandler:(ExternalAuthCompletion)completionHandler;


- (void)authorizeExternalAuthPersonWithAccount:(nullable PRAccountItem *)ai
                                      provider:(PRAuthProviderName)provider
                                    signInInfo:(SignInResult *)info
                          linkToCurrentAccount:(BOOL)linkToCurrentAccount
                                    completion:(ExternalAuthCompletion)completion NS_SWIFT_NAME(authorizeExternalAuthPerson(account:provider:info:linkToCurrentAccount:completion:));

- (void)authorizeExternalAuthPersonWithAccount:(nullable PRAccountItem *)ai
                                      provider:(NSString *)provider
                                        userId:(NSString *)userId
                                         email:(nullable NSString *)email
                                     firstName:(nullable NSString *)firstName
                                      lastName:(nullable NSString *)lastName
                                  displayName:(nullable NSString *)displayName
                               profileImageUrl:(nullable NSString *)profileImageUrl
                          linkToCurrentAccount:(BOOL)linkToCurrentAccount
                             completionHandler:(ExternalAuthCompletion)completionHandler;

- (void)authorizeExternalAuthToken:(NSString *)token
                           account:(PRAccountItem *)ai
                          provider:(NSString *)provider
                          authType:(NSString *)authType
              linkToCurrentAccount:(BOOL)linkToCurrentAccount
                 completionHandler:(ExternalAuthCompletion)completionHandler;

- (void)requestLinkedServicesWithAccount:(PRAccountItem *)ai
                         completionBlock:(void(^_Nullable)(BOOL updated))completionBlock;
- (void)unlinkServiceWithAccount:(PRAccountItem *)ai
                        provider:(NSString *)provider
                 completionBlock:(void(^)(NSError *error))completionBlock;

@end

NS_ASSUME_NONNULL_END
