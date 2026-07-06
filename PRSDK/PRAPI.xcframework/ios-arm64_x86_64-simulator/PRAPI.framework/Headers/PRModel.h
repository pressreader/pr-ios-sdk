//
//  PRModel.h
//  PRiphone
//
//  Created by Jackie Cane on 6/9/12.
//  Copyright (c) 2012 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <PRUtils/PRUtils.h>
@import PRConfiguration.PRNSBundle;

@class PRAccountItem;
@class PRMyLibrary;
@class PRAnalyticsProfileManager;
@class PRStoreKitManager;
@class PRThumbnailsManager;
@class PRPushNotificationsManager;

typedef NS_ENUM(NSInteger, PRModelStatus) {
    PRModelStatusStarted = -1,
    PRModelStatusReady = 0,
    PRModelStatusPaused,
    PRModelStatusStopped,
};

NS_ASSUME_NONNULL_BEGIN

extern NSNotificationName const PRModelDismissNotification;

@interface PRModel : NSObject

- (void)updateLastActiveTime;
- (void)updateLastActiveInterval;
- (void)enableScreenSaver;
- (void)postponeScreenSaver:(NSTimeInterval)delay;

- (void)cleanup;
- (void)stop;

@property (nonatomic, strong, nullable, readonly) NSDictionary<UIApplicationLaunchOptionsKey, id> *launchOptions;

@property (nonatomic, getter = isLibraryInitRequested) BOOL libraryInitRequested;;
@property (nonatomic, strong) CLLocation *currentLocation;

@property (nonatomic) PRModelStatus status;

@property (nonatomic, readonly) BOOL isOffline;

/** @brief date of installation or last update of the app */
@property (nonatomic, readonly) NSDate * appLastUpdateDate;
@property (nonatomic, readonly) BOOL probablyCrashedBefore;
@property (nonatomic, readonly) NSDate * dateOfStartAfterProbableCrash;

@property (nonatomic, readonly) BOOL firstAppLaunch;
@property (nonatomic, readonly) BOOL firstAppLaunchAfterUpdate;

@end

@interface PRModel (ConvenienceAPI)
id DebugConfig(NSString *key);

@end

@interface PRModel (/*LAUNCH_OPTIONS*/)
@property (nonatomic, strong) UIApplication *application;
@property (nonatomic) BOOL firstAppLaunch;
@property (nonatomic) BOOL firstAppLaunchAfterUpdate;
@property (nonatomic, strong, nullable, readwrite) NSDictionary *launchOptions;

@end

NS_ASSUME_NONNULL_END
