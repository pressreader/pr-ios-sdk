//
//  PRAuthorizationConfig.h
//  PRConfiguration
//
//  Created by Viacheslav Soroka on 2022-06-16.
//  Copyright © 2022 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

// This flag enables next functionality
// 1. Enable registration throught Device. User Name is equal to Device UDID
// 2. Enable purchase via iTunes store
// 3. Disable user login\registation (Authorization option removed from Settins)
#define DEVICE_ACCOUNT_ONLY                _PRCONFIG_BOOL_(@"DEVICE_ACCOUNT_ONLY", NO)

#define MULTIPLE_ACCOUNTS                _PRCONFIG_BOOL_(@"MULTIPLE_ACCOUNTS", NO)

#define SHOW_ACCOUNT_FOR_DEVICE_ONLY    _PRCONFIG_BOOL_(@"SHOW_ACCOUNT_FOR_DEVICE_ONLY", NO)

#define SUPPORTED_EXTERNAL_AUTH_PROVIDERS @[@"apple", @"facebook", @"google", @"twitter", @"email", @"library", @"piano", @"gigya"]

// #118035 Designated external auth provider to trigger sign-in immediately
// without displaying external sign-in options
#define DEFAULT_EXT_AUTH_PROVIDER    _PRCONFIG_STRING_(@"DEFAULT_EXT_AUTH_PROVIDER", nil)

NS_ASSUME_NONNULL_BEGIN

@interface PRAuthorizationConfig : NSObject
@property (nonatomic, readonly) BOOL isDeviceAccountOnly;
@property (nonatomic, readonly) BOOL isDeviceAccountAllowed;
@property (nonatomic, readonly) BOOL isExternalAuthEnabled;
@property (nonatomic, readonly) BOOL multipleAccounts;
@property (nullable, nonatomic, readonly) NSString *defaultExternalAuthProvider;
@property (nonatomic, readonly) BOOL resetDeviceWithDifferentServiceOnUpdate;

/// Additionally to Sign In
@property (nonatomic, readonly) BOOL showSignUp;
@property (nonatomic, readonly) BOOL showForgotPassword;
@property (nonatomic, readonly) BOOL showChangePassword;
@property (nonatomic, readonly) BOOL isDeleteAccountEnabled;
@property (nonatomic, readonly) BOOL useAuthorizationCodeForLoginWithApple;
@property (nullable, nonatomic, readonly) NSString *customForgotPasswordURLString;

@property (nullable, nonatomic, readonly) NSString *pianoAID;
@property (nullable, nonatomic, readonly) NSString *pianoBaseURL;

@property (nullable, nonatomic, readonly) NSString *gigyaAPIKey;
@property (nullable, nonatomic, readonly) NSString *gigyaLanguage;
@property (nullable, nonatomic, readonly) NSString *gigyaScreenSet;
@property (nullable, nonatomic, readonly) NSString *gigyaStartScreen;

@end

NS_ASSUME_NONNULL_END
