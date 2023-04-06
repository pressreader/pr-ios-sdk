//
//  PRLaunchCommand.h
//  PRAccessibility
//
//  Created by berec on 19/08/2020.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString * PRLaunchCommand NS_EXTENSIBLE_STRING_ENUM;

extern PRLaunchCommand const PRLaunchCommandRegisterOfflineServer;
extern PRLaunchCommand const PRLaunchCommandRegisterGiftedAccess;
extern PRLaunchCommand const PRLaunchCommandActivateGift;
extern PRLaunchCommand const PRLaunchCommandOrderTitle;
extern PRLaunchCommand const PRLaunchCommandOpen;
extern PRLaunchCommand const PRLaunchCommandSignIn;
extern PRLaunchCommand const PRLaunchCommandOpenPublications;
extern PRLaunchCommand const PRLaunchCommandOpenBooks;
extern PRLaunchCommand const PRLaunchCommandOpenDownloaded;
extern PRLaunchCommand const PRLaunchCommandOpenProfile;
extern PRLaunchCommand const PRLaunchCommandOpenHomeFeed;
extern PRLaunchCommand const PRLaunchCommandOpenHotSpotsMap;
extern PRLaunchCommand const PRLaunchCommandOpenUrl;
extern PRLaunchCommand const PRLaunchCommandDownload;

extern PRLaunchCommand const PRLaunchCommandNotify;
extern PRLaunchCommand const PRLaunchCommandGiftCampaign;
extern PRLaunchCommand const PRLaunchCommandPremiumTrialDetails;
extern PRLaunchCommand const PRLaunchCommandPremiumTrialTry;

typedef PRLaunchCommand KYMLaunchCommand;

extern KYMLaunchCommand const KYMLaunchCommandPurchase;
extern KYMLaunchCommand const KYMLaunchCommandPurchaseAndOpen;

NS_ASSUME_NONNULL_END
