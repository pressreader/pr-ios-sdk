//
//  PRConfig+Networking.h
//  PRSharedData
//
//  Created by berec on 20/05/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import <PRConfiguration/PRConfig.h>

NS_ASSUME_NONNULL_BEGIN

/// When this parameter is YES, we show alert each time when user tries download some title via WWAN
#define SHOW_ALERT_BEFORE_DOWNLOAD_VIA_WWAN     _PRCONFIG_BOOL_(@"SHOW_ALERT_BEFORE_DOWNLOAD_VIA_WWAN", NO)

#define newsstand_download_inactivity_period _PRCONFIG_INT_(@"newsstand_download_inactivity_period", 3) //days

#pragma mark - iOS 7 Background Download

#define IOS7_DONWLOAD_IN_BACKGROUND_ONLY _PRCONFIG_BOOL_(@"IOS7_DONWLOAD_IN_BACKGROUND_ONLY", YES)
#define IOS7_BACKGROUND_DOWNLOAD_MULTISESSION _PRCONFIG_BOOL_(@"IOS7_BACKGROUND_DOWNLOAD_MULTISESSION", YES)

#pragma mark - Partial download options
#define DOWNLOAD_FULL_PDN_IN_FOREGROUND  _PRCONFIG_BOOL_(@"DOWNLOAD_FULL_PDN_IN_FOREGROUND", YES)
#define DOWNLOAD_IMGPACK_IN_FOREGROUND   _PRCONFIG_BOOL_(@"DONWLOAD_IMGPACK_IN_FOREGROUND", YES)

#define NOTIFY_ON_NEW_ISSUE_AVAILABLE_IN_DQ     _PRCONFIG_BOOL_(@"NOTIFY_ON_NEW_ISSUE_AVAILABLE_IN_DQ", YES)
#define NOTIFY_ON_XML_UPDATE_AVAILABLE_IN_DQ    _PRCONFIG_BOOL_(@"NOTIFY_ON_XML_UPDATE_AVAILABLE_IN_DQ", NO)
#define NOTIFY_ON_ISSUE_UPDATE_AVAILABLE_IN_DQ  (_PRCONFIG_BOOL_(@"NOTIFY_ON_ISSUE_UPDATE_AVAILABLE_IN_DQ", NO) || NOTIFY_ON_XML_UPDATE_AVAILABLE_IN_DQ)
#define NOTIFY_ON_XML_UPDATE_DELIVERY           (NOTIFY_ON_XML_UPDATE_AVAILABLE_IN_DQ || _PRCONFIG_BOOL_(@"NOTIFY_ON_XML_UPDATE_DELIVERY", NO))
#define NOTIFY_ON_ISSUE_DOWNLOAD_FINISHED     _PRCONFIG_BOOL_(@"NOTIFY_ON_ISSUE_DOWNLOAD_FINISHED", NO)

#define APP_LOGO_DOWNLOAD_URL _PRCONFIG_OBJ_(@"APP_LOGO_DOWNLOAD_URL", nil)

@interface PRConfig (Networking)
@property (class, nonatomic, readonly) NSString *testServiceURL;
@property (class, nonatomic, readonly) NSString *devServiceURL;
@property (class, nonatomic) NSString *imageDownloadURL;
@property (class, nonatomic) NSString *imageUploadURL;
@property (class, nonatomic, readonly) NSString *manageAccountURL;
@property (class, nonatomic) BOOL shouldDownloadOnWiFiOnly;

@end

NS_ASSUME_NONNULL_END
