//
//  PRConfig+Settings.h
//  PRSharedData
//
//  Created by KeithC on 2020-03-17.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import <PRConfiguration/PRConfig.h>

NS_ASSUME_NONNULL_BEGIN

@interface PRConfig (Settings)

@property (class, nonatomic, readonly) BOOL showMySubscriptions;
@property (class, nonatomic, readonly) BOOL showAboutBrandEdition;
@property (class, nonatomic, readonly) BOOL showAccountForDeviceAccount;
@property (class, nonatomic, readonly) BOOL subscribeButtonEnabled;
@property (class, nonatomic, readonly) BOOL showOnlineView;
@property (class, nonatomic, readonly) BOOL disableOnboardingResetOnTestflight;
@property (class, nullable, nonatomic, readonly) NSString *onlineViewURLString;
@property (class, nullable, nonatomic, readonly) NSString *onlineViewTitle;
@property (class, nonatomic, readonly) BOOL showTimeLimitedLicenseDialog;

@end

NS_ASSUME_NONNULL_END
