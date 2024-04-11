/*
 *  PRConfig.h
 *  PRiphone
 *  Created by Vitali Bounine on 12/24/10.
 *  Copyright 2010 NewspaperDirect. All rights reserved.
 *
 */

#import <Foundation/Foundation.h>
#import <PRConfiguration/PRBaseConfig.h>

#pragma mark - General

#define USE_PUBLISHER_EXTERNAL_CONFIG   _PRCONFIG_BOOL_(@"USE_PUBLISHER_EXTERNAL_CONFIG", NO)
// if YES then VideoView.html will automatically enter to full screen mode after load video content
#define VIDEO_VIEW_AUTO_ENTER_FULL_SCREEN    _PRCONFIG_BOOL_(@"VIDEO_VIEW_AUTO_ENTER_FULL_SCREEN", NO)
#define VIDEO_VIEW_STARTS_IN_FULL_SCREEN    _PRCONFIG_BOOL_(@"VIDEO_VIEW_STARTS_IN_FULL_SCREEN", YES)

#define PUBLISHER_SHARING_NOTE				_PRCONFIG_STRING_(@"PUBLISHER_SHARING_NOTE", @"Shared via <a href='http://www.pressreader.com' target='_blank'>PressReader.com</a> &ndash; Connecting People Through News")

#define mylib_sorting_by_issuedate      _PRCONFIG_BOOL_(@"mylib_sorting_by_issuedate", NO)
#define mylib_recalculate_size_on_start _PRCONFIG_BOOL_(@"mylib_recalculate_size_on_start", NO)

#define delivery_auto_include_suppls        _PRCONFIG_BOOL_(@"delivery_auto_include_suppls", NO)
#define autodelivery_on_subs_purchase       _PRCONFIG_BOOL_(@"autodelivery_on_subs_purchase", NO)
#define auto_reset_on_invalid_activation    _PRCONFIG_BOOL_(@"auto_reset_on_invalid_activation", NO)

#define sample_issue_cids				_PRCONFIG_STRING_(@"sample_issue_cids", @"")

#ifdef DEBUG
#   define show_test_server                _PRCONFIG_BOOL_(@"show test server", YES)
#else
#   define show_test_server                _PRCONFIG_BOOL_(@"show test server", NO)
#endif

#define show_save_money                     _PRCONFIG_BOOL_(@"show_save_money", NO)
#define ALWAYS_SHOW_SAVE_MONEY              _PRCONFIG_BOOL_(@"ALWAYS_SHOW_SAVE_MONEY", NO)
#define show_auto_delivery_alert         _PRCONFIG_BOOL_(@"show_auto_delivery_alert", NO)

#define show_alert_if_no_wifi                 _PRCONFIG_BOOL_(@"show_alert_if_no_wifi", NO)

#define LIBRARY_DISPLAY_NAME		_PRCONFIG_STRING_(@"Library display name", nil)
#define LIBRARY_STORE_BUTTON_TITLE  _PRCONFIG_STRING_(@"Library Store Button", @"PR.iPad.Store")

#pragma mark - Settings

#define SETTINGS_SHOW_INSTRUCTIONS		_PRCONFIG_BOOL_(@"SETTINGS_SHOW_INSTRUCTIONS", NO)

#define SETTINGS_SHOW_FORHOTSPOTSPONSORS _PRCONFIG_BOOL_(@"SETTINGS_SHOW_FORHOTSPOTSPONSORS", NO)
#define SETTINGS_SHOW_BUNDLES           _PRCONFIG_BOOL_(@"SETTINGS_SHOW_BUNDLES", YES)
#define SETTINGS_ORIGINAL_USER_NAME		_PRCONFIG_BOOL_(@"SETTINGS_ORIGINAL_USER_NAME", NO)
#define SETTINGS_SHOW_CLEANUP			_PRCONFIG_BOOL_(@"SETTINGS_SHOW_CLEANUP", YES)
#define SETTINGS_SUPPORT_EMAIL_FOR_PUBLISHERS			_PRCONFIG_STRING_(@"SETTINGS_SUPPORT_EMAIL_FOR_PUBLISHERS", @"publishing@pressreader.com")
#define SETTINGS_SUPPORT_EMAIL_FOR_HOTSPOT_SPONSORS		_PRCONFIG_STRING_(@"SETTINGS_SUPPORT_EMAIL_FOR_HOTSPOT_SPONSORS", @"hotspot@pressreader.com")
#define HOTSPOT_SETTINGS_HELP_URL                       _PRCONFIG_STRING_(@"HOTSPOT_SETTINGS_HELP_URL", @"http://www.pressreader.com/mobilesettings")

#pragma mark - Reader

#define TEXTVIEW_PLAIN					_PRCONFIG_BOOL_(@"TEXTVIEW_PLAIN", NO)
#define RIGHT_TO_LEFT                    _PRCONFIG_BOOL_(@"RIGHT_TO_LEFT", NO)
#define SHOW_FIRST_TIME_READ_HINT		_PRCONFIG_BOOL_(@"SHOW_FIRST_TIME_READ_HINT", NO)
#define	DOUBLE_PAGE_VIEW_ENABLED		_PRCONFIG_BOOL_(@"DOUBLE_PAGE_VIEW_ENABLED", YES)
#define ALWAYS_USE_DOUBLE_PAGE_VIEW		_PRCONFIG_BOOL_(@"ALWAYS_USE_DOUBLE_PAGE_VIEW", NO)
//This enables small advertisement view in the bottom of PDFveiw
#define SHOW_ADVERTISEMENT_IN_READINGVIEW _PRCONFIG_BOOL_(@"SHOW_ADVERTISEMENT_IN_READINGVIEW", NO)
#define enable_pageset_actions          _PRCONFIG_BOOL_(@"enable_pageset_actions", YES)

#pragma mark - Store/Catalog

#define THUMBCLICK_CATALOGITEM_OPENREAD                 _PRCONFIG_BOOL_(@"THUMBCLICK_CATALOGITEM_OPENREAD", NO)
#define THUMBCLICK_ORDER_LATESTISSUESITEM_OPENREAD      _PRCONFIG_BOOL_(@"THUMBCLICK_ORDER_LATESTISSUESITEM_OPENREAD", NO)
#define THUMBCLICK_ORDER_SUPPLEMENTSITEM_OPENREAD       _PRCONFIG_BOOL_(@"THUMBCLICK_ORDER_SUPPLEMENTSITEM_OPENREAD", NO)
#define ORDER_BUTTON_OPENREAD                           _PRCONFIG_BOOL_(@"ORDER_BUTTON_OPENREAD", YES)

// This parameter is used to show/hide a search bar in store catalog and means the minimum amount of titles required to display search bar. It may be useful for SE apps with one or two titles, where showing search bar just does not make sense.
// 0 - display always
#define STORE_REQUIRED_QUANTITY_OF_TITLES_TO_DISPLAY_SEARCH_BAR  _PRCONFIG_INT_(@"STORE_REQUIRED_QUANTITY_OF_TITLES_TO_DISPLAY_SEARCH_BAR", 0)

// NO - use SPINNER animation, YES - use logo image "logo-loader.png"
#define PLACEHOLDER_USES_IMAGE    _PRCONFIG_BOOL_(@"PLACEHOLDER_USES_IMAGE", NO)

#define inapppurchase_show_always_list    _PRCONFIG_BOOL_(@"inapppurchase_show_always_list", NO)
#define enable_store_sorting			_PRCONFIG_BOOL_(@"enable_store_sorting", YES)

#define store_subtitles_showdate        _PRCONFIG_BOOL_(@"store_subtitles_showdate", YES)
#define store_show_selectdatelabel      _PRCONFIG_BOOL_(@"store_show_selectdatelabel", NO)

/**
 * PDF-renderer's configurations
 **/

#pragma mark - PDF-renderer's configurations
 
#define PDF_SCROLL_VIEW_SHOW_SPREAD_SHADOW_ON_DOUBLE_PAGE  _PRCONFIG_BOOL_(@"PDF_SCROLL_VIEW_SHOW_SPREAD_SHADOW_ON_DOUBLE_PAGE", YES)


#pragma mark - Smart Content's configurations

#define SMART_VIDEO_MARKER_SHOWS_BACKGROUND _PRCONFIG_BOOL_(@"SMART_VIDEO_MARKER_SHOWS_BACKGROUND", NO)
#define SMART_VIDEO_PLAY_DURING_INTERFACE_ROTATION _PRCONFIG_BOOL_(@"SMART_VIDEO_PLAY_DURING_INTERFACE_ROTATION", NO)

#pragma mark - AdWords
#define AD_WORDS_CONVERSION_ID                  _PRCONFIG_STRING_(@"AD_WORDS_CONVERSION_ID", nil)
#define AD_WORDS_CONVERSION_LABEL               _PRCONFIG_STRING_(@"AD_WORDS_CONVERSION_LABEL", nil)

#pragma mark - Bundles

// determines whether bundles will be presented 
#define isBundlesEnabled				_PRCONFIG_BOOL_(@"isBundlesEnabled", NO) 

// Allows for bundles to restrict visible titles
#define SHOW_ONLY_TITLES_FROM_BUNDLES 	_PRCONFIG_BOOL_(@"SHOW_ONLY_TITLES_FROM_BUNDLES", NO) 

#define UPLOAD_USER_BUNDLES 	_PRCONFIG_BOOL_(@"UPLOAD_USER_BUNDLES", NO)

#define FILTER_STORE_PRODUCTS_BY_APP_ID     _PRCONFIG_BOOL_(@"FILTER_STORE_PRODUCTS_BY_APP_ID", NO)



#pragma mark - Sorting

// Possible values are provided by PRTitleListSortingOrder enum.
// Default value is sortNotEstablished (-1)
//#define DEFAULT_SORTING_ORDER			_PRCONFIG_INT_(@"DEFAULT_SORTING_ORDER", -1)

// Possible values are provided by PRTitleListSortingOrder enum.
// Default value is sortNotEstablished (-1).
// sortAlphabetically = 0, sortByRating = 1, sortByActivation = 2
#define SUPPLEMENTS_SORTING_ORDER		_PRCONFIG_INT_(@"SUPPLEMENTS_SORTING_ORDER", -1)

// Possible values are provided by PRTitleListSortingOrder enum.
// Default value is sortNotEstablished (-1).
// sortAlphabetically = 0, sortByRating = 1, sortByActivation = 2
#define OTHER_EDITIONS_SORTING_ORDER		_PRCONFIG_INT_(@"OTHER_EDITIONS_SORTING_ORDER", -1)


#pragma mark - External API Keys

// Twitter Consumer Key
#define TWITTER_CONSUMER_KEY    _PRCONFIG_STRING_(@"TWITTER_CONSUMER_KEY", @"MiQSaDwkC0Ykr56GQ4el4w")
// Twitter Consumer Secret
#define TWITTER_CONSUMER_SECRET _PRCONFIG_STRING_(@"TWITTER_CONSUMER_SECRET", @"m3aCawHmMI1OdibLDUBU5QgxRbXnPK6SHxS3UJICUI")

// Evernote Consumer Key
#define EVERNOTE_CONSUMER_KEY    _PRCONFIG_STRING_(@"EVERNOTE_CONSUMER_KEY", @"ndadp-7209")
// Evernote Consumer Secret
#define EVERNOTE_CONSUMER_SECRET _PRCONFIG_STRING_(@"EVERNOTE_CONSUMER_SECRET", @"3e8d387a74badcc5")

// Instapaper Consumer Key
#define INSTAPAPER_CONSUMER_KEY    _PRCONFIG_STRING_(@"INSTAPAPER_CONSUMER_KEY", @"K7W2qJuJjOkJzMAWDTLtUCt25CcRVB0g0XQDxRV0Of2cxzrwg7")
// Instapaper Consumer Secret
#define INSTAPAPER_CONSUMER_SECRET _PRCONFIG_STRING_(@"INSTAPAPER_CONSUMER_SECRET", @"WhfParB23WQYvBkJokWvAZlvHwcH0cyeIWuGvzLDyXD0nT6ZPS")

#define GOOGLE_PLAY_SERVICE_KEY _PRCONFIG_STRING_(@"GOOGLE_PLAY_SERVICE_KEY", @"AIzaSyCpy5SXGk_1UAeEgcqllCxp_u5xwY4sRlM")


// You need to set this if using OAuth.The callback url doesn't have to be an actual existing url.  
// The user will never get to it because app intercepts it before the user is redirected.  
#define TWITTER_CALLBACK_URL    _PRCONFIG_STRING_(@"TWITTER_CALLBACK_URL", @"http://twitauthsuccess.pressdisplay.com")


#pragma mark - Notifications

#define notification_badge_visible              _PRCONFIG_BOOL_(@"notification_badge_visible", YES)
#define notification_badge_show_unread_issues   _PRCONFIG_BOOL_(@"notification_badge_show_unread_issues", NO)

#define APN_DISABLED                            _PRCONFIG_BOOL_(@"APN_DISABLED", NO)

#pragma mark - Free issues

#define free_issue_cids                 _PRCONFIG_STRING_(@"free_issue_cids", @"")

#pragma mark - Order View

// We show authorize button if current subscription doesn't cover current publication
#define ORDER_VIEW_SHOW_AUTHORIZE_BUTTON_WHEN_BUYING_REQUIRED  _PRCONFIG_BOOL_(@"ORDER_VIEW_SHOW_AUTHORIZE_BUTTON_WHEN_BUYING_REQUIRED", YES)
#define Order_Status_DeviceTrial_ZeroIssues     _PRCONFIG_STRING_(@"Order_Status_DeviceTrial_ZeroIssues", @"")
#define SHOW_OTHER_ISSUES_IN_ORDER_VIEW         _PRCONFIG_BOOL_(@"SHOW_OTHER_ISSUES_IN_ORDER_VIEW", YES)
#define ORDER_SHOW_SELL_INSEPARABLY_ALERT       _PRCONFIG_BOOL_(@"ORDER_SHOW_SELL_INSEPARABLY_ALERT", NO)
#define order_show_include_suppls               _PRCONFIG_BOOL_(@"order_show_include_suppls", YES)
#define ORDER_VIEW_SHOW_RELATED_PUBLICATIONS    _PRCONFIG_BOOL_(@"ORDER_VIEW_SHOW_RELATED_PUBLICATIONS", YES)

#pragma mark - Online View 

#define SHOW_ONLINE_VIEW				_PRCONFIG_BOOL_(@"SHOW_ONLINE_VIEW", NO)
#define ONLINE_VIEW_BUTTON_ON_THE_RIGHT _PRCONFIG_BOOL_(@"ONLINE_VIEW_BUTTON_ON_THE_RIGHT", NO)
#define ONLINE_VIEW_DISABLE_CACHING     _PRCONFIG_BOOL_(@"ONLINE_VIEW_DISABLE_CACHING", NO)
#define onlineview_url					_PRCONFIG_STRING_(@"onlineview_url", @"")

#pragma mark - Radio

#define RADIO_FOR_PURCHASED_ITEMS_ONLY  _PRCONFIG_BOOL_(@"RADIO_FOR_PURCHASED_ITEMS_ONLY", YES)
#define RADIO_SHOWS_VOTE_CONTROL        _PRCONFIG_BOOL_(@"RADIO_SHOWS_VOTE_CONTROL", YES)
#define RADIO_USE_SPEECH_SYNTHESIZER    _PRCONFIG_BOOL_(PRRadioUseSpeechSynthesizer, NO)
#define RADIO_SHOW_ISSUE_COPYRIGHT_LABEL      _PRCONFIG_BOOL_(@"RADIO_SHOW_ISSUE_COPYRIGHT_LABEL", YES)
#define RADIO_SHOW_IMAGE_BYLINE_COPYRIGHT_LABEL      _PRCONFIG_BOOL_(@"RADIO_SHOW_IMAGE_BYLINE_FOR_COPYRIGHT_LABEL", NO)

// This flag enables smart search functionality on iPad devices.

#define DISPLAY_SMARTSEARCH_ON_IPHONE   _PRCONFIG_BOOL_(@"DISPLAY_SMARTSEARCH_ON_IPHONE", NO)
// This setting's purpose is to enable/disable smart search display on iPhone later via config update

/** 
 * Sets time interval in monthes for issue dates in order view from the latest issue (or current day if unavailable).
 **/
#define ISSUE_DATES_MONTH_INTERVAL          _PRCONFIG_INT_(@"order_issue_dates_month_interval", 6)

/*
 This is for chatanooga big advertisement banners
 */
#define RSSVIEW_FULLSCREEN_BANNERS      _PRCONFIG_BOOL_(@"RSSVIEW_FULLSCREEN_BANNERS", NO)

/**
 Enables Kooaba service.
 */
#define KOOABA_ENABLED                  _PRCONFIG_BOOL_(@"KOOABA_ENABLED", NO)


#pragma mark - Hot Zone
#define SHOW_HOTZONE_BUTTON             (PRConfig.isHotspotEnabled && _PRCONFIG_BOOL_(@"SHOW_HOTZONE_BUTTON", YES))
#define SHOW_HOTZONE_OPTOUT             _PRCONFIG_BOOL_(@"SHOW_HOTZONE_OPTOUT", NO)
#define HOTSPOT_PROXIMITY_UUID          _PRCONFIG_STRING_(@"HOTSPOT_PROXIMITY_UUID", @"beb2d30a-0906-4066-84d0-0c65958814c1")
#define HOTSPOT_GEOFENCING_ENABLED      (PRConfig.isHotspotEnabled && _PRCONFIG_BOOL_(@"HOTSPOT_GEOFENCING_ENABLED", NO))

#define HOTSPOT_ALERT_ENABLED                   _PRCONFIG_BOOL_(@"HOTSPOT_ALERT_ENABLED", YES)
#define HOTSPOT_WELCOME_POPUP_INTERVAL          _PRCONFIG_INT_(@"HOTSPOT_WELCOME_POPUP_INTERVAL", 60*60*1)
#define HOTSPOT_NOTIFICATION_INTERVAL           _PRCONFIG_INT_(@"HOTSPOT_NOTIFICATION_INTERVAL", 60*60*3)
#define HOTSPOT_LOCATION_ENABLE_REMINDER_INTERVAL _PRCONFIG_INT_(@"HOTSPOT_LOCATION_ENABLE_REMINDER_INTERVAL", 60*60*24*14)
#define HOTSPOT_WELCOME_POPUP_SHOW_ON_START     _PRCONFIG_BOOL_(@"HOTSPOT_WELCOME_POPUP_SHOW_ON_START", YES)
#define HOTSPOT_WELCOME_POPUP_SHOW_ON_SWITCH    _PRCONFIG_BOOL_(@"HOTSPOT_WELCOME_POPUP_SHOW_ON_SWITCH", YES)
#define HOTSPOT_NOTIFICATION_SHOW_ON_SWITCH     _PRCONFIG_BOOL_(@"HOTSPOT_NOTIFICATION_SHOW_ON_SWITCH", NO)

#pragma mark - APP REVIEW POLICY
#define APPREVIEW_MINIMUM_DAYS_SINCE_CURRENT_VERSION_INSTALLED   _PRCONFIG_INT_(@"APPREVIEW_MINIMUM_DAYS_SINCE_CURRENT_VERSION_INSTALLED", 7)
#define APPREVIEW_MINIMUM_DAYS_SINCE_CURRENT_VERSION_CRASHED     _PRCONFIG_INT_(@"APPREVIEW_MINIMUM_DAYS_SINCE_CURRENT_VERSION_CRASHED", 90)
#define APPREVIEW_MINIMUM_MINS_SINCE_APP_IS_ACTIVE               _PRCONFIG_INT_(@"APPREVIEW_MINIMUM_MINS_SINCE_APP_IS_ACTIVE", 5)

#define APPMENU_MOREITEM_USE_ACTIONMENUSTYLE    _PRCONFIG_BOOL_(@"APPMENU_MOREITEM_USE_ACTIONMENUSTYLE", YES)

#define allow_registration				_PRCONFIG_BOOL_(@"allow_registration", NO)
#define DISPLAY_ACCOUNT_QUICK_ACCESS_BUTTON   _PRCONFIG_BOOL_(@"MY_LIBRARY_SHOW_AUTHORIZE_BUTTON", YES)

#define BUNDLE_IMAGE_RESOURCE_VERSION         _PRCONFIG_STRING_(@"BUNDLE_IMAGE_RESOURCE_VERSION",@"0")

#define IAP_ONLINE_DECODE_RECEIPT       _PRCONFIG_BOOL_(@"PRIAP_ONLINE_DECODE_RECEIPT", YES)
#define IAP_SHARED_SECRET               _PRCONFIG_STRING_(@"PRIAP_SHARED_SECRET", @"c6b0e09072364f99b20a85afcba9a093")

#define USE_ARTICLE_CONTAINER           _PRCONFIG_BOOL_(@"USE_ARTICLE_CONTAINER", YES)

#define UPLOAD_LOG_TENANTID             _PRCONFIG_STRING_(@"UPLOAD_LOG_TENANTID", @"56beaddc-cbd1-410a-8692-80c39bd1f57e")
#define UPLOAD_LOG_CLIENTID             _PRCONFIG_STRING_(@"UPLOAD_LOG_CLIENTID", @"54da9ca1-c005-4d5f-b958-c708e22766c3")
#define UPLOAD_LOG_CLIENTKEY            _PRCONFIG_STRING_(@"UPLOAD_LOG_CLIENTKEY", @"M3C7Pvom4kVlvG0k0zi3VxCrf6rJ7ur25DskW2UJgFE=")

#define ENABLE_WATERMARK            _PRCONFIG_BOOL_(@"ENABLE_WATERMARK", YES)
#define WATERMARK_FORMAT            _PRCONFIG_STRING_(@"WATERMARK_FORMAT", @"5_{account_id}")
#define SF_HOMEFEED_LOAD_DELAY         _PRCONFIG_DOUBLE_(@"SF_HOMEFEED_LOAD_DELAY", 0.35)

#define DATE_FORMATTER_TEMPLATE     _PRCONFIG_STRING_(@"DATE_FORMATTER_TEMPLATE", @"EEEdMMMyyyy")

@class LocalServerConfig;
@class AnalyticsConfig;
@class CoreDataConfig;
@class PRSDKConfig;
@class PRAuthorizationConfig;
@class AppMenuConfig;
@class CustomerSupportConfig;
@class ContentAccessConfig;
@class UserInterfaceStyleConfig;

NS_ASSUME_NONNULL_BEGIN

@interface PRConfig: NSObject

+ (BOOL)boolForKey:(NSString *)key defaultValue:(BOOL)defaultValue;
+ (void)setBoolForKey:(NSString *)key value:(BOOL)value;

+ (NSInteger)integerForKey:(NSString *)key defaultValue:(NSInteger)defaultValue;
+ (void)setIntegerForKey:(NSString *)key value:(NSInteger)value;

+ (double)doubleForKey:(NSString *)key defaultValue:(double)defaultValue;
+ (void)setDoubleForKey:(NSString *)key value:(double)value;

+ (nullable NSString *)stringForKey:(NSString *)key defaultValue:(nullable NSString *)defaultValue;
+ (void)setStringForKey:(NSString *)key value:(nullable NSString *)value;

+ (nullable id)valueForKey:(NSString *)key defaultValue:(nullable id)defaultValue;
+ (void)setValueForKey:(NSString *)key value:(nullable id)value;

@property (class, nonatomic, readonly) BOOL isBrandEdition;
/// If HotSpot is disabled then in the app there should not be any reference to HotSpots (cup, HotSpot in settings, etc) .
@property (class, nonatomic, readonly) BOOL isHotspotEnabled;
/// If HotSpot Map is disabled then in the app remove all references to Map like on Select Product dialog, etc.
@property (class, nonatomic, readonly) BOOL isHotspotMapEnabled;
@property (class, nonatomic, readonly) BOOL isStoreProductWithPrefixAppId;

@property (class, nonatomic, readonly) NSString *serviceName;
@property (class, nonatomic, readonly) NSString *defaultServiceName;
@property (class, nonatomic, readonly) NSString *publisherCopyright;

@property (class, nonatomic, readonly) PRSDKConfig *sdkConfig NS_SWIFT_NAME(sdk);
@property (class, nonatomic, readonly) LocalServerConfig *localServerConfig NS_SWIFT_NAME(localServer);
@property (class, nonatomic, readonly) AnalyticsConfig *analyticsConfig NS_SWIFT_NAME(analytics);
@property (class, nonatomic, readonly) CoreDataConfig *coreDataConfig NS_SWIFT_NAME(coreData);
@property (class, nonatomic, readonly) PRAuthorizationConfig *authConfig NS_SWIFT_NAME(auth);
@property (class, nonatomic, readonly) AppMenuConfig *appMenuConfig NS_SWIFT_NAME(appMenu);
@property (class, nonatomic, readonly) CustomerSupportConfig *customerSupportConfig NS_SWIFT_NAME(customerSupport);
@property (class, nonatomic, readonly) UserInterfaceStyleConfig *userInterfaceStyleConfig NS_SWIFT_NAME(userInterfaceStyle);

@property (class, nonatomic, readonly) BOOL deepLinkCommandUseHost;
@property (class, nonatomic, readonly) BOOL areTooltipsEnabled;
@property (class, nonatomic, readonly) NSTimeInterval newAppVersionAlertTimeInterval;

@property (nullable, class, nonatomic, readonly) NSDictionary<NSString *, id> *configDefaults;
@property (class, nonatomic, readonly) NSDictionary<NSString *, id> *debugConfig;

@end

NS_ASSUME_NONNULL_END
