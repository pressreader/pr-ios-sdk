//
//  PRAnalyticsService.h
//  PRAPI
//
//  Created by OlegB on 11-02-25.
//  Copyright 2011 NewspaperDirect. All rights reserved.
//

#import <PRAPI/PRAnalyticsProto.h>
#import <PRAPI/PRAnalyticsProfile.h>
#import <PRAnalytics/PRAnalytics.h>

NS_ASSUME_NONNULL_BEGIN

/// type of value is NSArray<id<AnalyticsTracker>>
NS_SWIFT_NAME(prAnalyticsTrackers) extern UIApplicationLaunchOptionsKey const UIApplicationLaunchOptionsPRAnalyticsTrackersKey;

typedef NSString *RMTAction NS_TYPED_ENUM;
extern RMTAction const RMTActionPauseNRestart;
extern RMTAction const RMTActionFirstStart;
extern RMTAction const RMTActionComplete;
extern RMTAction const RMTActionView;

extern NSString *const RMTTypeVideo;
extern NSString *const RMTTypeAudio;
extern NSString *const RMTTypeGallery;

#pragma mark - track parameter types

typedef NSString *PRAnalyticsMainMenu NS_TYPED_ENUM;
extern PRAnalyticsMainMenu const PRAnalyticsMainMenuSignIn;
extern PRAnalyticsMainMenu const PRAnalyticsMainMenuMyChannel;
extern PRAnalyticsMainMenu const PRAnalyticsMainMenuForYou;
extern PRAnalyticsMainMenu const PRAnalyticsMainMenuBrowse;
extern PRAnalyticsMainMenu const PRAnalyticsMainMenuDownloaded;
extern PRAnalyticsMainMenu const PRAnalyticsMainMenuMyLibrary;
extern PRAnalyticsMainMenu const PRAnalyticsMainMenuBookmarks;
extern PRAnalyticsMainMenu const PRAnalyticsMainMenuMyTopics;
extern PRAnalyticsMainMenu const PRAnalyticsMainMenuHotSpots;
extern PRAnalyticsMainMenu const PRAnalyticsMainMenuAccounts;
extern PRAnalyticsMainMenu const PRAnalyticsMainMenuSettings;
extern PRAnalyticsMainMenu const PRAnalyticsMainMenuAboutUs;
extern PRAnalyticsMainMenu const PRAnalyticsMainMenuHelp;
extern PRAnalyticsMainMenu const PRAnalyticsMainMenuMore;
extern PRAnalyticsMainMenu const PRAnalyticsMainMenuMySubscriptions;
extern PRAnalyticsMainMenu const PRAnalyticsMainMenuCustomerSupport;
extern PRAnalyticsMainMenu const PRAnalyticsMainMenuOnlineView;
extern PRAnalyticsMainMenu const PRAnalyticsMainMenuSendFeedback;

//typedef NS_ENUM(NSInteger, PRAnalyticsTextFlowType) {
//    PRAnalyticsTextFlowTypeUnknown = 0,
//    PRAnalyticsTextFlowTypeWeb,
//    PRAnalyticsTextFlowTypeNative,
//    PRAnalyticsTextFlowTypeSimplified,
//};
typedef NSInteger PRAnalyticsTextFlowType NS_TYPED_ENUM;
static PRAnalyticsTextFlowType const PRAnalyticsTextFlowTypeUnknown = 0;
static PRAnalyticsTextFlowType const PRAnalyticsTextFlowTypeWeb = 1;
static PRAnalyticsTextFlowType const PRAnalyticsTextFlowTypeNative = 2;
static PRAnalyticsTextFlowType const PRAnalyticsTextFlowTypeSimplified = 3;

//typedef NS_ENUM(NSInteger, PRAnalyticsTextFlowSource) {
//    PRAnalyticsTextFlowSourceUnknown = 0,
//    PRAnalyticsTextFlowSourceIssue,
//    PRAnalyticsTextFlowSourceHomeFeed,
//    PRAnalyticsTextFlowSourceProfile,
//    PRAnalyticsTextFlowSourceBookmarks,
//    PRAnalyticsTextFlowSourceMonitors,
//    PRAnalyticsTextFlowSourceSearchResult,
//};
typedef NSInteger PRAnalyticsTextFlowSource NS_TYPED_ENUM;
static PRAnalyticsTextFlowSource const PRAnalyticsTextFlowSourceUnknown = 0;
static PRAnalyticsTextFlowSource const PRAnalyticsTextFlowSourceIssue = 1;
static PRAnalyticsTextFlowSource const PRAnalyticsTextFlowSourceHomeFeed = 2;
static PRAnalyticsTextFlowSource const PRAnalyticsTextFlowSourceProfile = 3;
static PRAnalyticsTextFlowSource const PRAnalyticsTextFlowSourceBookmarks = 4;
static PRAnalyticsTextFlowSource const PRAnalyticsTextFlowSourceMonitors = 5;
static PRAnalyticsTextFlowSource const PRAnalyticsTextFlowSourceSearchResult = 6;

typedef NSString *PRAnalyticsContentType NS_TYPED_ENUM;
extern PRAnalyticsContentType const PRAnalyticsContentTypeIssue;
extern PRAnalyticsContentType const PRAnalyticsContentTypePageSet;
extern PRAnalyticsContentType const PRAnalyticsContentTypeArticle;
extern PRAnalyticsContentType const PRAnalyticsContentTypeComment;

typedef NSString *PRAnalyticsAccountView NS_TYPED_ENUM;
extern PRAnalyticsAccountView const PRAnalyticsAccountViewList; // iPhone only
extern PRAnalyticsAccountView const PRAnalyticsAccountViewInfo;
extern PRAnalyticsAccountView const PRAnalyticsAccountViewEdit;
extern PRAnalyticsAccountView const PRAnalyticsAccountViewPassword;
extern PRAnalyticsAccountView const PRAnalyticsAccountViewProducts;
extern PRAnalyticsAccountView const PRAnalyticsAccountViewAutoDeliveries;

typedef NSInteger PRAnalyticsAuthView NS_TYPED_ENUM;
static PRAnalyticsAuthView const PRAnalyticsAuthViewUnknown = 0;
static PRAnalyticsAuthView const PRAnalyticsAuthViewSignIn = 1;
static PRAnalyticsAuthView const PRAnalyticsAuthViewSignUp = 2;
static PRAnalyticsAuthView const PRAnalyticsAuthViewExternalList = 3;
static PRAnalyticsAuthView const PRAnalyticsAuthViewExternal = 4;

typedef NSInteger PRAnalyticsAuthType NS_TYPED_ENUM;
static PRAnalyticsAuthType const PRAnalyticsAuthTypeUnknown = 0;
static PRAnalyticsAuthType const PRAnalyticsAuthTypeSignIn = 1;
static PRAnalyticsAuthType const PRAnalyticsAuthTypeSignUp = 2;
static PRAnalyticsAuthType const PRAnalyticsAuthTypeLink = 3;

typedef NSInteger PRAnalyticsAuthMethod NS_TYPED_ENUM;
static PRAnalyticsAuthMethod const PRAnalyticsAuthMethodUnkonwn = 0;
static PRAnalyticsAuthMethod const PRAnalyticsAuthMethodDirect = 1;
static PRAnalyticsAuthMethod const PRAnalyticsAuthMethodLocalProvider = 2;
static PRAnalyticsAuthMethod const PRAnalyticsAuthMethodExternalProvider = 3;

typedef NSString *PRAnalyticsProductOfferSource NS_TYPED_ENUM;
extern PRAnalyticsProductOfferSource const PRAnalyticsProductOfferSourceAppStore;
extern PRAnalyticsProductOfferSource const PRAnalyticsProductOfferSourcePremiumTrialBanner;
extern PRAnalyticsProductOfferSource const PRAnalyticsProductOfferSourceDeepLink;
extern PRAnalyticsProductOfferSource const PRAnalyticsProductOfferSourceConfirmationDialog;

typedef NSString *PRAnalyticsPurchaseRestoreSource NS_TYPED_ENUM;
extern PRAnalyticsPurchaseRestoreSource const PRAnalyticsPurchaseRestoreSourceSelectProductView;
extern PRAnalyticsPurchaseRestoreSource const PRAnalyticsPurchaseRestoreSourcePremiumTrialBanner;
extern PRAnalyticsPurchaseRestoreSource const PRAnalyticsPurchaseRestoreSourceDeepLink;

typedef NSString *PRAnalyticsBannerType NS_TYPED_ENUM;
extern PRAnalyticsBannerType const PRAnalyticsBannerTypePremiumTrial;
extern PRAnalyticsBannerType const PRAnalyticsBannerTypeHotSpotServices;
extern PRAnalyticsBannerType const PRAnalyticsBannerTypePersonalization;
extern PRAnalyticsBannerType const PRAnalyticsBannerTypePersonalizationCompleted;
extern PRAnalyticsBannerType const PRAnalyticsBannerTypeBooks;
extern PRAnalyticsBannerType const PRAnalyticsBannerTypeBrazeContentCard;
extern PRAnalyticsBannerType const PRAnalyticsBannerTypeEmailNotifications;

typedef NSString *PRAnalyticsBannerContext NS_TYPED_ENUM;
extern PRAnalyticsBannerContext const PRAnalyticsBannerContextForYou;
extern PRAnalyticsBannerContext const PRAnalyticsBannerContextPublications;
extern PRAnalyticsBannerContext const PRAnalyticsBannerContextAccounts;
extern PRAnalyticsBannerContext const PRAnalyticsBannerContextOnboarding;
extern PRAnalyticsBannerContext const PRAnalyticsBannerContextUnknown;

typedef NSString *PRAnalyticsBannerAction NS_TYPED_ENUM;
extern PRAnalyticsBannerAction const PRAnalyticsBannerActionClose;
extern PRAnalyticsBannerAction const PRAnalyticsBannerActionProceed;

typedef NSString *PRAnalyticsAppState NS_TYPED_ENUM;
extern PRAnalyticsAppState const PRAnalyticsAppStateStart;
extern PRAnalyticsAppState const PRAnalyticsAppStateResume;
extern PRAnalyticsAppState const PRAnalyticsAppStatePause;
extern PRAnalyticsAppState const PRAnalyticsAppStateStop;

typedef NSString *PRAnalyticsOrderViewAction NS_TYPED_ENUM;
extern PRAnalyticsOrderViewAction const PRAnalyticsOrderViewActionPresented;
extern PRAnalyticsOrderViewAction const PRAnalyticsOrderViewActionTitleChanged;
extern PRAnalyticsOrderViewAction const PRAnalyticsOrderViewActionDateChanged;
extern PRAnalyticsOrderViewAction const PRAnalyticsOrderViewActionAutoDownloadOn;
extern PRAnalyticsOrderViewAction const PRAnalyticsOrderViewActionAutoDownloadOff;

typedef NSString *PRAnalyticsEditAction NS_TYPED_ENUM;
extern PRAnalyticsEditAction const PRAnalyticsEditActionAdded;
extern PRAnalyticsEditAction const PRAnalyticsEditActionRemoved;
extern PRAnalyticsEditAction const PRAnalyticsEditActionChanged;

typedef NSString *PRAnalyticsPrintType NS_TYPED_ENUM;
extern PRAnalyticsPrintType const PRAnalyticsPrintTypeIssue;
extern PRAnalyticsPrintType const PRAnalyticsPrintTypePage;
extern PRAnalyticsPrintType const PRAnalyticsPrintTypeScreen;
extern PRAnalyticsPrintType const PRAnalyticsPrintTypeArticleText;
extern PRAnalyticsPrintType const PRAnalyticsPrintTypeArticleImage;

typedef NSString *PRAnalyticsSearchItemType NS_TYPED_ENUM;
extern PRAnalyticsSearchItemType const PRAnalyticsSearchItemTypeTitleItem;
extern PRAnalyticsSearchItemType const PRAnalyticsSearchItemTypeSuggestion;
extern PRAnalyticsSearchItemType const PRAnalyticsSearchItemTypeHistory;
extern PRAnalyticsSearchItemType const PRAnalyticsSearchItemTypeInterest;
extern PRAnalyticsSearchItemType const PRAnalyticsSearchItemTypeHotspot;

typedef NSString *PRAnalyticsEmailNotificationPermissionType NS_TYPED_ENUM;
extern PRAnalyticsEmailNotificationPermissionType const PRAnalyticsEmailNotificationPermissionTypeEmail;
extern PRAnalyticsEmailNotificationPermissionType const PRAnalyticsEmailNotificationPermissionTypePromo;
extern PRAnalyticsEmailNotificationPermissionType const PRAnalyticsEmailNotificationPermissionTypeService;
extern PRAnalyticsEmailNotificationPermissionType const PRAnalyticsEmailNotificationPermissionTypeNewsDigest;

typedef NSString *PRAnalyticsAutoTranslationZoneType NS_TYPED_ENUM;
extern PRAnalyticsAutoTranslationZoneType const PRAnalyticsAutoTranslationZoneDownloadedArticle;
extern PRAnalyticsAutoTranslationZoneType const PRAnalyticsAutoTranslationZoneFeedArticle;
extern PRAnalyticsAutoTranslationZoneType const PRAnalyticsAutoTranslationZoneDownloadedIssue;
extern PRAnalyticsAutoTranslationZoneType const PRAnalyticsAutoTranslationZoneFeed;
extern PRAnalyticsAutoTranslationZoneType const PRAnalyticsAutoTranslationZoneSettings;
extern PRAnalyticsAutoTranslationZoneType const PRAnalyticsAutoTranslationZoneNA;

typedef NSString *PRAnalyticsAutoTranslationPopUpAction NS_TYPED_ENUM;
extern PRAnalyticsAutoTranslationPopUpAction const PRAnalyticsAutoTranslationPopUpActionPresented;
extern PRAnalyticsAutoTranslationPopUpAction const PRAnalyticsAutoTranslationPopUpActionAllowed;
extern PRAnalyticsAutoTranslationPopUpAction const PRAnalyticsAutoTranslationPopUpActionDenied;
extern PRAnalyticsAutoTranslationPopUpAction const PRAnalyticsAutoTranslationPopUpActionSettings;

@interface PRAnalyticsService : NSObject<AnalyticsService, PRPageViewTracker, PRGATracker>

- (instancetype)initWithApplication:(nullable UIApplication *)application
                      launchOptions:(nullable NSDictionary *)launchOptions;

- (nullable id<PRPageViewTracker>)analyticsServiceWithType:(PRAnalyticsProfileType)type;

- (BOOL)isConsoleAnalyticsEnabled;
- (BOOL)isGoogleAnalyticsEnabled;
- (BOOL)isFirebaseAnalyticsEnabled;
- (BOOL)isBrazeAnalyticsEnabled;

- (void)track:(PRAnalyticsTrackName)name
   parameters:(nullable NSDictionary<PRAnalyticsTrackParameter, id> *)parameters;

@end

NS_ASSUME_NONNULL_END
