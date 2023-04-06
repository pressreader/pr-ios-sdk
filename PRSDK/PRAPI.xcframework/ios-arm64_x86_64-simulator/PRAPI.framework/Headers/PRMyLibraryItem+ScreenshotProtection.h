//
//  PRMyLibraryItem+ScreenshotProtection.h
//  PR-API
//
//  Created by Vitali Bounine on 2020-06-01.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import "PRMyLibraryItem.h"

@import PRConfiguration.PRConfig_ScreenshotProtection;

NS_ASSUME_NONNULL_BEGIN

@interface PRMyLibraryItem (ScreenshotProtection) <ReadingViewItemScreenshotProtectionProtocol>

@property (nonatomic, readonly) PRScreenshotProtectionLevel screenshotProtectionLevel;

@property (nonatomic, readonly) BOOL requiresScreenshotProtection;
@property (nonatomic, readonly) BOOL shouldPresentScreenshotWarning1;
@property (nonatomic, readonly) BOOL shouldPresentScreenshotWarning2;
@property (nonatomic, readonly) BOOL shouldBlockScreenshot;

@property (nonatomic, readonly) NSInteger screenshotCounter;
- (void)incrementScreenshotCounter;

/// Optional property. Returns -1 if no value defined.
@property (nonatomic, readonly) NSInteger maxNumberOfScreenshots;

@end

NS_ASSUME_NONNULL_END
