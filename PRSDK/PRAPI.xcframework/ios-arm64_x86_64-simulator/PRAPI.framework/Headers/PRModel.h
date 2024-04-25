//
//  PRModel.h
//  PRiphone
//
//  Created by Jackie Cane on 6/9/12.
//  Copyright (c) 2012 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@import PRUtils.PRNSBundle;

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

typedef NS_OPTIONS(uint8_t, PRModelResetOption) {
    PRModelResetOptionNone = 0,
    PRModelResetOptionCache = 1 << 0,
    PRModelResetOptionLibrary = 1 << 1,
    PRModelResetOptionAccounts = 1 << 2,
    PRModelResetOptionAll = PRModelResetOptionCache | PRModelResetOptionLibrary | PRModelResetOptionAccounts
};

NS_ASSUME_NONNULL_BEGIN

extern NSNotificationName const PRModelDismissNotification;

@interface PRModel : NSObject

- (void)updateLastActiveTime;
- (void)updateLastActiveInterval;
- (void)enableScreenSaver;
- (void)postponeScreenSaver:(NSTimeInterval)delay;
- (void)enableLocalServiceMode:(BOOL)enable serviceName:(nullable NSString *)serviceName;

- (nullable NSString *)helpCenterUrlWithSection:(NSString *_Nullable)section
                                       isOnline:(BOOL *_Nullable)isOnline;

- (void)cleanup;
- (void)stop;

@property (nonatomic, strong, nullable, readonly) NSDictionary<UIApplicationLaunchOptionsKey, id> *launchOptions;

@property (nonatomic, getter = isLibraryInitRequested) BOOL libraryInitRequested;;
@property (nonatomic, strong) CLLocation *currentLocation;

@property (nonatomic) PRModelStatus status;

@property (nonatomic, readonly) BOOL isOffline;

@property (nonatomic, readonly) NSString *appDisplayName;
@property (nonatomic, readonly) NSString *appServiceDisplayName;

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
@property (class, nonatomic) PRModelResetOption removeContentOnStartOptions;
@property (nonatomic, strong) UIApplication *application;
@property (nonatomic) BOOL firstAppLaunch;
@property (nonatomic) BOOL firstAppLaunchAfterUpdate;
@property (nonatomic, strong, nullable, readwrite) NSDictionary *launchOptions;

@end

NS_ASSUME_NONNULL_END
