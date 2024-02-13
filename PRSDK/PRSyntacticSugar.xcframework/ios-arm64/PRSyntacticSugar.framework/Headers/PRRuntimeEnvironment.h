//
//  PRRuntimeEnvironment.h
//  PRSharedData
//
//  Created by Vitali Bounine on 2020-06-09.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSUInteger, PRRuntimeEnvironmentType) {
    PRRuntimeEnvironmentTypeAppStore = 1 << 0,
    PRRuntimeEnvironmentTypeTestFlight = 1 << 1,
    PRRuntimeEnvironmentTypeDebugger = 1 << 2
};

@interface PRRuntimeEnvironment : NSObject

+ (BOOL)isAppReceiptSandbox;
+ (BOOL)hasEmbeddedMobileProvision;
+ (BOOL)isRunningInTestFlightEnvironment;
+ (BOOL)isRunningInAppStoreEnvironment;
+ (BOOL)isRunningInAppExtension;
+ (BOOL)isBackgroundSupported;
+ (BOOL)isBackgroundFetchSupported;
+ (BOOL)isRemoteNotificationSupported;
+ (BOOL)inDebugger;
+ (BOOL)isViewControllerBasedStatusBarAppearance;

+ (PRRuntimeEnvironmentType)type;

@end

NS_ASSUME_NONNULL_END
