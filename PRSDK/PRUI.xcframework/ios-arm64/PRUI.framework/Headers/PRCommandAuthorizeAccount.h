//
//  PRCommandAuthorizeAccount.h
//  PRiphone
//
//  Created by Oleg Stepanenko on 11.01.13.
//  Copyright (c) 2013 NewspaperDirect. All rights reserved.
//

@import PRCommands.PRCommand;

@class PRAccountItem;

NS_ASSUME_NONNULL_BEGIN

typedef NSString * PRCommandAuthorizeAccountOption NS_EXTENSIBLE_STRING_ENUM;

extern PRCommandAuthorizeAccountOption const PRCommandAuthorizeAccountOptionNavigationController;
extern PRCommandAuthorizeAccountOption const PRCommandAuthorizeAccountOptionHideBackButton;
extern PRCommandAuthorizeAccountOption const PRCommandAuthorizeAccountOptionShowSkipButton;
extern PRCommandAuthorizeAccountOption const PRCommandAuthorizeAccountOptionIsMandatory;
extern PRCommandAuthorizeAccountOption const PRCommandAuthorizeAccountOptionMode;
extern PRCommandAuthorizeAccountOption const PRCommandAuthorizeAccountOptionUsername;
extern PRCommandAuthorizeAccountOption const PRCommandAuthorizeAccountOptionUsername_;
extern PRCommandAuthorizeAccountOption const PRCommandAuthorizeAccountOptionServiceName;
extern PRCommandAuthorizeAccountOption const PRCommandAuthorizeAccountOptionServiceName_;
extern PRCommandAuthorizeAccountOption const PRCommandAuthorizeAccountOptionPassword;
extern PRCommandAuthorizeAccountOption const PRCommandAuthorizeAccountOptionLinkToCurrentAccount;
extern PRCommandAuthorizeAccountOption const PRCommandAuthorizeAccountOptionAuthNetwork;
extern PRCommandAuthorizeAccountOption const PRCommandAuthorizeAccountOptionAuthNetwork_;
extern PRCommandAuthorizeAccountOption const PRCommandAuthorizeAccountOptionOnSuccessCommand;
extern PRCommandAuthorizeAccountOption const PRCommandAuthorizeAccountOptionOnSuccessCommandParameters;
extern PRCommandAuthorizeAccountOption const PRCommandAuthorizeAccountOptionIgnoreExternalAuthProvider;

typedef NSDictionary<PRCommandAuthorizeAccountOption, id> *_Nullable SignInOptions;

@interface PRCommandAuthorizeAccount : PRCommand

+ (BOOL)isAuthorizationRequiredForAccountWithName:(NSString *_Nullable)accountName;

+ (void)authorizeAccountWithName:(NSString *_Nullable)accountName
                     parameteres:(SignInOptions)parameters
                      completion:(void(^_Nullable)(PRAccountItem *_Nullable account))completion;

+ (void)authorizeAccountWithName:(NSString *_Nullable)accountName
                     parameteres:(SignInOptions)parameters
                  successHandler:(void(^ _Nullable)(void))onSuccess;

+ (void)authorizeAccountWithParameters:(SignInOptions)parameters
                        successHandler:(void(^ _Nullable)(void))successHandler;

+ (void)authorizeAccountWithName:(NSString *_Nullable)accountName
                      completion:(void(^_Nullable)(PRAccountItem *_Nullable account))completion;

+ (void)authorizeAccountWithCompletion:(void(^_Nullable)(PRAccountItem *_Nullable account))completion;

+ (void)authorizeAccountWithName:(NSString *_Nullable)accountName
                  successHandler:(void(^_Nullable)(void))successHandler;

+ (void)authorizeAccountWithName:(NSString *_Nullable)accountName;

+ (void)authorizeAccount:(void(^_Nullable)(void))successHandler;

@end

NS_ASSUME_NONNULL_END
