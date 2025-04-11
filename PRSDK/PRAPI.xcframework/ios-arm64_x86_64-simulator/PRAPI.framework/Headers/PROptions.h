//
//  PROptions.h
//  PRiphone
//
//  Created by Dmitry Melnik on 02/09/08.
//  Copyright 2008 NewspaperDirect. All rights reserved.
//

#import <CoreGraphics/CoreGraphics.h>

@import PRConfiguration;
@import PRCatalogModel.PRSourceItem_Basics;

@class PRSharedPreferences;
@class TranslateOptions;

NS_ASSUME_NONNULL_BEGIN

extern NSNotificationName const PROptionsPresentationStyleChangedNotification;
extern NSNotificationName const PROptionsLocalServiceDeactivatedNotification;

// option's keys
extern NSString *const kSmartMediaContentPath;
extern NSString *const kRSSDir;
extern NSString *const kRSSImagesCacheDir;
extern NSString *const kPRJWT;
extern NSString *const kPRGiftCommand;
extern NSString *const kPRTextPushAuthorized;
extern NSString *const kMLIThumbnailPath;

// File path
extern NSString *const kThumbCacheDir;
extern NSString *const kMastheadDir;
extern NSString *const kAppLogoDir;
extern NSString *const kHTMLBannerDir;

extern NSString *const kDocPath;
extern NSString *const kCachePath;
extern NSString *const kProtectedCachePath;
extern NSString *const kStoragePath;
extern NSString *const kTempPath;
extern NSString *const kQueuePath;
extern NSString *const kBooksPath;
extern NSString *const kDocumentsPath;
extern NSString *const kDefaultConfigPath;

extern NSString *const kExternalServicesKey;
extern NSString *const kManagedExternalServicesKey;
extern NSString *const kExternalSignInTemplateIdKey;
extern NSString *const kAnonymousUserCategoriesKey;
extern NSString *const kAnalyticsEventsConfigurationKey;
extern NSString *const kAuthentificationAuth0SSOConfigurationKey;
extern NSString *const kAuthentificationAuth0SSOScopeConfigurationKey;
extern NSString *const kAuthentificationAuth0SSOAudienceConfigurationKey;

extern CGFloat const kIPad_MaxZoomLevel;
extern CGFloat const kIPhone_MaxZoomLevel;

#define MAX_ZOOM_SCALE  (UIDevice.isUserIntefaceIdiomPad ? kIPad_MaxZoomLevel : kIPhone_MaxZoomLevel)

typedef NS_ENUM(uint32_t, PRLayoutType) {
    PRLayoutTypeNone = 0,
    PRLayoutTypeCarousel,
    PRLayoutTypeGrid
};

typedef NS_ENUM(NSInteger, PRPresentationStyle) {
    PRPresentationStyleNotDefined = 0,
    PRPresentationStyleList,
    PRPresentationStyleSmallGrid,
    PRPresentationStyleMicroGrid,
    PRPresentationStyleGrid
};

typedef NS_ENUM (NSInteger, PROpinionSortOrder) {
    PROpinionSortOrderPopular = 0,
    PROpinionSortOrderNewest,
    PROpinionSortOrderGrowing
};

@class PRPromise;

@interface PROptions : NSObject

- (NSString *)deviceUserName;

- (nullable id)getOptionWithName:(NSString*)name;
- (void)setOptionWithName:(NSString*)name value:(nullable id)value;
- (void)removeOptionWithName:(NSString *)key;

- (nullable id)objectForKeyedSubscript:(NSString *)key;
- (void)setObject:(id)object forKeyedSubscript:(NSString *)key;

- (void) storePreferences;

- (NSArray *) supportEmails;
- (NSString *)crashReportEmail;
- (NSString *) supportEmailSubject;
- (NSInteger) titlesPopupWidth;

- (BOOL)setServiceHost:(NSString *)serviceHost;

- (NSString *) testServiceUrlKey;
- (NSArray *) testServiceUrlKeys;
- (void) setTestServiceUrlKey:(NSString *)index;
- (void) selectTestServer:(BOOL)test;
- (BOOL) isTestServer;

- (BOOL) isDQServerReached;
- (void) setDQServerReached:(BOOL)success;


- (NSString *)uniqueIdentifier;
- (NSData *)appDeviceKey;

- (BOOL) isRemoteNotificationSupported;
- (BOOL) isBackgroundFetchSupported;
- (BOOL) isBackgroundDownloadSupported;
- (BOOL) isViewControllerBasedStatusBarAppearance;

- (NSString*) resVersion;
- (NSString*) bundleResVersion;
- (void) setResVersion: (NSString *) value;
- (NSString*) prevResVersion;
- (void) setPrevResVersion: (NSString *) value;

- (void) setValue:(nullable id)value inPrefDictionary:(NSString*)dictName forKey:(NSString*)key;
- (id) valueInPrefDictionary:(NSString*)dictName forKey:(NSString*)key;
- (NSArray *) allKeysInPrefDictionary:(NSString *)dictName;

// translation service ------------------
// use language ISO code as parameters
- (BOOL)canTranslateFrom:(NSString *)langFrom to:(NSString *)langTo;
// return the list of language names not iso codes
- (nullable NSArray<NSString *> *)sourceTranslateLanguageNames;
- (nullable NSArray<NSString *> *)destinationTranslateLanguageNames;
// converting language names to iso codes
- (nullable NSString *) translationLanguageISOCodeByName:(NSString *)language;
- (NSDictionary *) languageISOCodesByNames;

// titles preferences
- (nullable id)defaultValueForKey:(NSString*)key CID:(NSString*)CID;
- (void)setDefaultValue:(nullable id)value forKey:(NSString*)key CID:(NSString*)CID;
- (nullable id)defaultValueForKey:(NSString*)key issue:(NSString*)issueKey;
- (void)setDefaultValue:(nullable id)value forKey:(NSString*)key issue:(NSString*)issueKey;

- (CGFloat) defaultZoom;
- (void) setDefaultZoom:(CGFloat)zoom;
- (CGFloat) defaultZoomForCID:(NSString*)CID isSpread:(BOOL)isSpread;
- (void) setDefaultZoom:(CGFloat)zoom forCID:(NSString*)CID isSpread:(BOOL)isSpread;
- (CGFloat) initialZoomForCID:(NSString*)CID;
- (void) setInitialZoom:(CGFloat)zoom forCID:(NSString*)CID;
- (CGFloat) thumbHeightForCID:(NSString*)CID;
- (void) setThumbHeight:(CGFloat)height forCID:(NSString*)CID;
- (NSInteger)screenshotCounterForIssue:(NSString *)issueKey;
- (void)setScreenshotCounter:(NSInteger)counter forIssue:(NSString *)issueKey;

- (nullable NSArray<NSDictionary<NSString *, id> *> *)publicationPath;
- (void)setPublicationPath:(nullable NSArray<NSDictionary<NSString *, id> *> *)value;

// base service urls and vesions
- (void) updateBaseServices:(NSDictionary *)baseInfo;
- (NSString *)versionForBaseService:(NSString *)serviceName;

- (void)setDebugConfigValue:(nullable id)value forKey:(NSString *)key;

- (NSMutableDictionary *)getBaseServices;

- (void)clearApplicationCache;

@property (class, nonatomic, readonly) BOOL isBackgroundSupported;

@property (class, nonatomic, readonly) PRAppMode appMode;
@property (nonatomic, readonly) PRAppMode appMode;

@property (nonatomic, readonly) NSString *serviceName;
@property (nullable, nonatomic, readonly) NSString *displayServiceName;

@property (nonatomic, strong, nullable) NSString *deviceToken;
@property (nullable, nonatomic, strong) NSString *fcmToken;
@property (nonatomic, readonly) NSDictionary *config;

@property (nonatomic, readonly) NSString *installationVersion;

@property (nonatomic, assign, nullable) NSString *localServiceName;
@property (nonatomic, assign, nullable) NSString *localServiceURL;

@property (nonatomic, assign) NSUInteger minItemsInGroup;
@property (nonatomic, assign) PROpinionSortOrder opinionSortOrder;
@property (nonatomic, assign) PROpinionSortOrder suggestedOpinionsSortOrder;
@property (nonatomic, assign) PRPresentationStyle downloadedPresentationStyle;
@property (nonatomic) PRAppPanelID defaultAppPanel;
@property (nonatomic, getter = isConfigRefreshedAfterAppUpdated) BOOL configRefreshedAfterAppUpdated;
@property (nonatomic, assign) UIUserInterfaceStyle appTheme;

@property (nonatomic, strong, readonly) PRSharedPreferences *sharedPreferences;

@property (nonatomic, readonly) BOOL showUnsupportedBlocksInTextFlow;

@property (nonatomic, strong, readonly) NSDictionary *defaultBaseServiceInfo;

@property (nullable, nonatomic, readonly) NSString *appDocumentDir;
@property (nonatomic, readonly) BOOL isJustInstalled;

@property (nonatomic, readonly) TranslateOptions *translation;

@end

NS_ASSUME_NONNULL_END

#define IS_SDK  (PROptions.appMode == PRAppModeFramework)

#import "PROptions+Paths.h"
#import "PROptions+URLs.h"
#import "PROptions+Promise.h"
