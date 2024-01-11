//
//  PRAPIRequests.h
//  PRiphone
//
//  Created by Jackie Cane on 4/8/11.
//  Copyright 2011 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NSString * PRAPIRequest NS_EXTENSIBLE_STRING_ENUM;

extern PRAPIRequest const PRAPIRequestRegisterDevice;

extern PRAPIRequest const PRAPIRequestGetBaseURLs;
extern PRAPIRequest const PRAPIRequestGetAuthTicket;
extern PRAPIRequest const PRAPIRequestValidatePayments;
extern PRAPIRequest const PRAPIRequestValidateAppPayments;
extern PRAPIRequest const PRAPIRequestGetIssues;
extern PRAPIRequest const PRAPIRequestGetIssueDates;
extern PRAPIRequest const PRAPIRequestGetMultipleIssueDates;
extern PRAPIRequest const PRAPIRequestGetTitles;
extern PRAPIRequest const PRAPIRequestGetCustomCatalog;
extern PRAPIRequest const PRAPIRequestGetLatestIssueInfo;
extern PRAPIRequest const PRAPIRequestRenewDownloadLicense;
extern PRAPIRequest const PRAPIRequestManageFavorites;

extern PRAPIRequest const PRAPIRequestGetSubscriptionStatus;
extern PRAPIRequest const PRAPIRequestGetBundles;
extern PRAPIRequest const PRAPIRequestGetUserBundles;
extern PRAPIRequest const PRAPIRequestGetUserBundlesTitles;
extern PRAPIRequest const PRAPIRequestGetUserBundlesByCid;
extern PRAPIRequest const PRAPIRequestRegister;
extern PRAPIRequest const PRAPIRequestUnregister;
extern PRAPIRequest const PRAPIRequestGetMediaURL;
extern PRAPIRequest const PRAPIRequestGetPublisherConfigURL;
extern PRAPIRequest const PRAPIRequestGetConfig;
extern PRAPIRequest const PRAPIRequestGetTemplateURL;
extern PRAPIRequest const PRAPIRequestAttachIPhoneUser;
extern PRAPIRequest const PRAPIRequestAuthorizeUserByExternalAuthTicket;
extern PRAPIRequest const PRAPIRequestGetTrackingConfig;

// AdDisplay API
extern PRAPIRequest const PRGetAdSplashScreenRequest;
extern PRAPIRequest const PRGetAdPlasticBagRequest;
extern PRAPIRequest const PRGetInterstitialAdsRequest;
extern PRAPIRequest const PRGetAdPopUpBannersRequest;
extern PRAPIRequest const PRGetTextViewAdRequest;
extern PRAPIRequest const PRGetOrderScreenAdRequest;
