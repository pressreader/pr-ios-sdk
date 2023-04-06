//
//  PRConfig+ScreenshotProtection.h
//  PRSharedData
//
//  Created by Vitali Bounine on 2020-05-31.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import <PRConfiguration/PRConfig.h>

NS_ASSUME_NONNULL_BEGIN

#define ScreenShieldKitLicenseKey       _PRCONFIG_STRING_(@"ScreenShieldKitLicenseKey", @"")

#define SCREENSHOT_DISABLED_CID         _PRCONFIG_STRING_(@"SCREENSHOT_DISABLED_CID", @"")

typedef NS_ENUM(NSInteger, PRScreenshotProtectionLevel) {
    PRScreenshotProtectionLevelNoProtection = 0,
    PRScreenshotProtectionLevelRegular = 1,
    PRScreenshotProtectionLevelEnhanced = 2
};

@interface PRConfig (ScreenshotProtection)

@property (class, nonatomic, readonly) BOOL canUseScreenShieldKit;

@property (class, nonatomic, readonly) BOOL isScreenshotProtectionDisabled;
@property (class, nonatomic, readonly) BOOL isScreenCaptureProtectionDisabled;
@property (class, nonatomic, readonly) BOOL isScreenCaptureProtectionStartImmediately;
@property (class, nonatomic, readonly) PRScreenshotProtectionLevel defaultScreenshotProtectionLevel;
@property (class, nonatomic, readonly) BOOL isScreenshotCounterPerIssue;
@property (class, nonatomic, readonly) NSUInteger sessionScreenshotCounterPersistThreshold;
@property (class, nonatomic, readonly) NSUInteger screenshotWarning1StartCounter;
@property (class, nonatomic, readonly) NSUInteger screenshotWarning2StartCounter;
@property (class, nonatomic, readonly) NSUInteger screenshotBlockStartCounter;
@property (class, nonatomic, readonly) NSUInteger screenshotEnhancedProtectionBlockStartCounter;
@property (class, nonatomic, readonly) NSUInteger screenshotWarning1MaxPerSession;
@property (class, nonatomic, readonly) NSUInteger screenshotWarning2MaxPerSession;
@property (class, nonatomic, readonly) NSUInteger screenshotEnhancedProtectionWarning1MaxPerSession;
@property (class, nonatomic, readonly) NSUInteger screenshotEnhancedProtectionWarning2MaxPerSession;

+ (BOOL)isScreenshotEnhancedProtectedForCID:(NSString *)cid;

@end

NS_ASSUME_NONNULL_END
