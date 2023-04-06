//
//  PRRuntimeEnvironment.h
//  PRSharedData
//
//  Created by Vitali Bounine on 2020-06-09.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PRRuntimeEnvironment : NSObject

+ (BOOL) isAppReceiptSandbox;
+ (BOOL) hasEmbeddedMobileProvision;
+ (BOOL) isRunningInTestFlightEnvironment;
+ (BOOL) isRunningInAppStoreEnvironment;
+ (BOOL) isRunningInAppExtension;
+ (BOOL) isBackgroundSupported;
+ (BOOL) isBackgroundFetchSupported;
+ (BOOL) isRemoteNotificationSupported;
+ (BOOL) inDebugger;
+ (BOOL) isViewControllerBasedStatusBarAppearance;

@end

NS_ASSUME_NONNULL_END
