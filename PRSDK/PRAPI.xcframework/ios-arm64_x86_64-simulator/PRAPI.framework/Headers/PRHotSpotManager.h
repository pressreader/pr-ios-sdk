//
//  PRHotSpotManager.h
//  PRiphone
//
//  Created by Oleg Stepanenko on 20.10.15.
//  Copyright © 2015 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSNotificationName const PRHotSpotStatusUpdatedNotification;

typedef NS_ENUM(int, PRHotSpotServicesStatus) {
    // User has not yet made a choice about HotSpot services
    kPRHotSpotServicesStatusNotDetermined = 0,
    // User has explicitly denied HotSpot services
    kPRHotSpotServicesStatusDenied,
    // User has granted authorization to use HotSpot services
    kPRHotSpotServicesStatusAuthorized
};

typedef struct {
    CLLocationCoordinate2D ne;
    CLLocationCoordinate2D sw;
} PRLocationRect;

typedef NS_ENUM(uint8_t, PRHotSpotStatus) {
    PRHotSpotStatusEnabled = 0,
    PRHotSpotStatusDisabled,
    PRHotSpotStatusRestricted
};

@interface PRHotSpotManager : NSObject

- (BOOL)isUserShouldBeNotifiedAboutGeoHotSpotRegion:(nullable NSString *)hotspotID;
- (BOOL)isGeoFencingPermissionsPromptRequired;
- (void)requestHotSpotServicesOnView;
- (void)activateHotSpotServices;
- (void)setServicesAllowed;
- (void)setGeoFencingServicesAllowed;
- (void)setLastTimeUserPostponedResponse;
- (void)setUserResponseEnableGift;
- (BOOL)needRemindUserAboutLocationService;
- (void)stopMonitoring;
- (void)notifyAboutGeoHotSpotRegionWithMessage:(nullable NSString *)message;
- (void)resetAllNotifications;

@property (nonatomic, readonly, getter=isGeoFencingRequired) BOOL geoFencingRequired;
@property (nonatomic, readonly, getter=isLocationServiceEnabled) BOOL locationServiceEnabled;
@property (nonatomic, readonly, getter=isLocationServiceEnabledWhileInUse) BOOL locationServiceEnabledWhileInUse;
@property (nonatomic, readonly, getter=isLocationServiceFullAccuracyEnabled) BOOL locationServiceFullAccuracyEnabled;
@property (nonatomic, getter=isActivatingHotSpotServices) BOOL activatingHotSpotServices;
@property (nonatomic) BOOL geoFencingOptedOut;
@property (nullable, nonatomic, strong, readonly) CLRegion *geoHotSpotRegion;
@property (nonatomic, readonly) PRHotSpotServicesStatus hotSpotServicesStatus;
@property (nonatomic, getter=isHotSpotServicesBannerClosed) BOOL hotSpotServicesBannerClosed;

@property (nonatomic, readonly) PRHotSpotStatus currentHotspotStatus;

@end

NS_ASSUME_NONNULL_END
