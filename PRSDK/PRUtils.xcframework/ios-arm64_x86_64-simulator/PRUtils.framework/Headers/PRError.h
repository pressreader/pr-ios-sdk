//
//  PRError.h
//  PRiphone
//
//  Created by Jackie Cane on 27/07/15.
//  Copyright (c) 2015 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSErrorDomain kPRErrorDomainSocialLoginFacebook;
extern NSErrorDomain kPRErrorDomainSocialLoginTwitter;

typedef NS_ENUM(NSInteger, PRSocialLoginError) {
    PRSocialLoginErrorAccessNotGranted = 1,
    PRSocialLoginErrorAccessTokenNotFound,
    PRSocialLoginErrorReverseAuthFailed,
    PRSocialLoginErrorExternalAuthRequired,
    PRSocialLoginErrorCancelled
};

typedef NS_ERROR_ENUM(kPRErrorDomainSocialLoginFacebook, PRSocialLoginErrorFacebook) {
    PRSocialLoginErrorFacebookAccessNotGranted = PRSocialLoginErrorAccessNotGranted,
    PRSocialLoginErrorFacebookAccessTokenNotFound = PRSocialLoginErrorAccessTokenNotFound,
    PRSocialLoginErrorFacebookReverseAuthFailed = PRSocialLoginErrorReverseAuthFailed,
    PRSocialLoginErrorFacebookExternalAuthRequired = PRSocialLoginErrorExternalAuthRequired,
};

typedef NS_ERROR_ENUM(kPRErrorDomainSocialLoginTwitter, PRSocialLoginErrorTwitter) {
    PRSocialLoginErrorTwitterAccessNotGranted = PRSocialLoginErrorAccessNotGranted,
    PRSocialLoginErrorTwitterAccessTokenNotFound = PRSocialLoginErrorAccessTokenNotFound,
    PRSocialLoginErrorTwitterReverseAuthFailed = PRSocialLoginErrorReverseAuthFailed,
    PRSocialLoginErrorTwitterExternalAuthRequired = PRSocialLoginErrorExternalAuthRequired,
};

extern NSErrorDomain kPRErrorDomainExtAuthError;

typedef NS_ERROR_ENUM(kPRErrorDomainExtAuthError, PRExtAuthError) {
    PRExtAuthErrorUnexpected = 500,
    PRExtAuthErrorAccessTokenExpired = 1,
    PRExtAuthErrorAccountIsUsedForSingIn = 2,
    PRExtAuthErrorUserNameInUse = 4,
    PRExtAuthErrorAccessTokenFromDiffAccount = 5,
    PRExtAuthErrorLinkedToAnotherAccount = 6
};

NS_ASSUME_NONNULL_END
