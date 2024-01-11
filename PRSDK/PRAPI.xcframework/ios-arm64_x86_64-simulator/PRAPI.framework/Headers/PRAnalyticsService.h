//
//  PRAnalyticsService.h
//  PRAPI
//
//  Created by OlegB on 11-02-25.
//  Copyright 2011 NewspaperDirect. All rights reserved.
//

#import <PRAPI/PRAnalyticsProto.h>
#import "PRAnalyticsProfile.h"

NS_ASSUME_NONNULL_BEGIN

/// type of value is NSArray<id<AnalyticsTracker>>
NS_SWIFT_NAME(prAnalyticsTrackers) extern UIApplicationLaunchOptionsKey const UIApplicationLaunchOptionsPRAnalyticsTrackersKey;

#pragma mark - track names

extern PRAnalyticsTrackName const PRAnalyticsTrackDownloadedView;
extern PRAnalyticsTrackName const PRAnalyticsTrackReplicaView; // parameters: MyLibraryItem
extern PRAnalyticsTrackName const PRAnalyticsTrackReplicaPage; // parameters: MyLibraryItem and page
extern PRAnalyticsTrackName const PRAnalyticsTrackCatalogView; // parameter: CatalogPath and CatalogFilter
extern PRAnalyticsTrackName const PRAnalyticsTrackOrderView; // paramerters TitleItemExemplar, OrderViewAction
extern PRAnalyticsTrackName const PRAnalyticsTrackTextFlowView; // parameters: TextFlowSource, TextFlowType, MyLibraryItem for Source .issue, SearchTerm for source .searchResults
extern PRAnalyticsTrackName const PRAnalyticsTrackArticleView; // parameters: ArticleItem and TextFlowType
extern PRAnalyticsTrackName const PRAnalyticsTrackArticleViewClose; // parameters: ArticleItem and TextFlowType
extern PRAnalyticsTrackName const PRAnalyticsTrackCommentsView; // parameters: ArticleItem and TextFlowType, CommentsCount
extern PRAnalyticsTrackName const PRAnalyticsTrackCommentPostView; // parameters: ArticleItem and TextFlowType, EditAction
extern PRAnalyticsTrackName const PRAnalyticsTrackRadioView;
extern PRAnalyticsTrackName const PRAnalyticsTrackFeaturedAudio;
extern PRAnalyticsTrackName const PRAnalyticsTrackHotspotMapView;
extern PRAnalyticsTrackName const PRAnalyticsTrackWebView; // parameter: WebUrl
extern PRAnalyticsTrackName const PRAnalyticsTrackAccountView; // parameter AccountView
extern PRAnalyticsTrackName const PRAnalyticsTrackAboutBrandEditionView; // parameter:
extern PRAnalyticsTrackName const PRAnalyticsTrackSettingsView; // parameter SettingsSection
extern PRAnalyticsTrackName const PRAnalyticsTrackAuthorizeView; // parameter: AuthorizeViewMode
extern PRAnalyticsTrackName const PRAnalyticsTrackPaymentProductsView; // parameters: PaymentProducts and optional TitleItemExemplar
extern PRAnalyticsTrackName const PRAnalyticsTrackPurchaseConfirmationView;
extern PRAnalyticsTrackName const PRAnalyticsTrackBannerView; // parameters: BannerType, BannerContext
extern PRAnalyticsTrackName const PRAnalyticsTrackOnboardingGetStartedView;
extern PRAnalyticsTrackName const PRAnalyticsTrackOnboardingIntroView;
extern PRAnalyticsTrackName const PRAnalyticsTrackOnboardingChooseInterestsView;
extern PRAnalyticsTrackName const PRAnalyticsTrackOnboardingSearchInterestsView;
extern PRAnalyticsTrackName const PRAnalyticsTrackOnboardingFollowPublicationsView;
extern PRAnalyticsTrackName const PRAnalyticsTrackOnboardingSearchPublicationsView;

extern PRAnalyticsTrackName const PRAnalyticsTrackPDV;
extern PRAnalyticsTrackName const PRAnalyticsTrackPDVLatestIssues;
extern PRAnalyticsTrackName const PRAnalyticsTrackPDVOnlineStories;
extern PRAnalyticsTrackName const PRAnalyticsTrackPDVSupplements;

extern PRAnalyticsTrackName const PRAnalyticsTrackMySubscriptionsView;
extern PRAnalyticsTrackName const PRAnalyticsTrackSplashSignInView;
extern PRAnalyticsTrackName const PRAnalyticsTrackTrialSubscriptionIntroView;
extern PRAnalyticsTrackName const PRAnalyticsTrackSourceNFeedView;
extern PRAnalyticsTrackName const PRAnalyticsTrackNewsChannelsSelectionView;
extern PRAnalyticsTrackName const PRAnalyticsTrackFeedCollectionsSelectionView;
extern PRAnalyticsTrackName const PRAnalyticsTrackSearchResultsView;

extern PRAnalyticsTrackName const PRAnalyticsTrackSplashScreenView;

extern PRAnalyticsTrackName const PRAnalyticsTrackHomeLatestIssues;
extern PRAnalyticsTrackName const PRAnalyticsTrackHomeHamburder;

extern PRAnalyticsTrackName const PRAnalyticsTrackSignInButton;
extern PRAnalyticsTrackName const PRAnalyticsTrackSignUpButton;
extern PRAnalyticsTrackName const PRAnalyticsTrackSocialSignInButton;

extern PRAnalyticsTrackName const PRAnalyticsTrackMainMenu; // parameter MainMenu;
extern PRAnalyticsTrackName const PRAnalyticsTrackWebLink; // parameter: WebUrl
extern PRAnalyticsTrackName const PRAnalyticsTrackSFAction; // parameter SFAction
extern PRAnalyticsTrackName const PRAnalyticsTrackAuthorizeOperation; // parameter : AuthType, ServiceName, OperationResult
extern PRAnalyticsTrackName const PRAnalyticsTrackSeeAllPaymentOptions;
extern PRAnalyticsTrackName const PRAnalyticsTrackProductOffer; // PaymentProduct, ProductOfferSource
extern PRAnalyticsTrackName const PRAnalyticsTrackPurchaseStarted; // PaymentProduct and TitleItemExemplar
extern PRAnalyticsTrackName const PRAnalyticsTrackPurchaseCompleted; // PaymentProduct, PRTitleItemExemplar, SKPaymentTransaction and OperationResult
extern PRAnalyticsTrackName const PRAnalyticsTrackPurchaseRestoreStarted; // PurchaseRestoreSource
extern PRAnalyticsTrackName const PRAnalyticsTrackPurchaseRestoreCompleted; // OperationResult, PRTitleItemExemplar, SKProduct
extern PRAnalyticsTrackName const PRAnalyticsTrackBannerAction; // parameters: BannerType, BannerContext, BannerAction
extern PRAnalyticsTrackName const PRAnalyticsTrackAskForAppReview;
extern PRAnalyticsTrackName const PRAnalyticsTrackAppState; // parameter: AppState
extern PRAnalyticsTrackName const PRAnalyticsTrackDeepLink; // parameters: DeepLinkCommand and DeepLinkQuery
extern PRAnalyticsTrackName const PRAnalyticsTrackDownload; // parameters: OperationResult,PRMyLibraryItem and Speed
extern PRAnalyticsTrackName const PRAnalyticsTrackFavourites; // parameters: EditAction, TitleItem
extern PRAnalyticsTrackName const PRAnalyticsTrackBookmark; // parameters: EditAction, ArticleItem or PageSetItem
extern PRAnalyticsTrackName const PRAnalyticsTrackSkipOnboarding;
extern PRAnalyticsTrackName const PRAnalyticsTrackInterestChanged; // parameters: EditAction, Interest
extern PRAnalyticsTrackName const PRAnalyticsTrackShareActivity; // parameters: ContentType, OperationResult, myLibraryItem or titleItemExemplar, article, ShareActivityType, Title(user post owner name
extern PRAnalyticsTrackName const PRAnalyticsTrackTranslated; // parameters: Article, LanguageFrom, LanguageTo, OperationResult
extern PRAnalyticsTrackName const PRAnalyticsTrackPrint; // parameters: PrintType, MyLibraryItem or TitleItemExemplar, Article
extern PRAnalyticsTrackName const PRAnalyticsTrackSearchBar; // parameter: SearchTerm
extern PRAnalyticsTrackName const PRAnalyticsTrackSearchItemSelected; // parameters: SearchItemType, TitleItem or Title
extern PRAnalyticsTrackName const PRAnalyticsTrack10ArticlesInHomeFeedOpened;
extern PRAnalyticsTrackName const PRAnalyticsTrack30ArticlesInHomeFeedOpened;
extern PRAnalyticsTrackName const PRAnalyticsTrack10IssuesOpened;
extern PRAnalyticsTrackName const PRAnalyticsTrackSubscribeToReadTap;  // parameter: Copy
extern PRAnalyticsTrackName const PRAnalyticsTrackArticleNavigationSwipe; // parameters: "direction", "section name"
extern PRAnalyticsTrackName const PRAnalyticsTrackArticleNavigationNavigate; // parameters: "direction", "section name"
extern PRAnalyticsTrackName const PRAnalyticsTrackRichMedia; // parameters: "action"
extern PRAnalyticsTrackName const PRAnalyticsTrackEmailNotificationPermissionChange; // PRAnalyticsEmailNotificationPermissionParameter,
extern PRAnalyticsTrackName const PRAnalyticsTrackATTPermissionRequest;
extern PRAnalyticsTrackName const PRAnalyticsTrackATTPermissionGranted; // parameter PermissionGranted

extern PRAnalyticsTrackName const PRAnalyticsTrackTapOnItemInSponsoredCatalogSection; // parameters: catalogItem, listPosition
extern PRAnalyticsTrackName const PRAnalyticsTrackTapOnItemInWelcomMessageCarousel; // parameters: catalogItem or TitleItemExemplar, listPosition
extern PRAnalyticsTrackName const PRAnalyticsTrackDeleteAccount; // parameters: operationResult

extern PRAnalyticsTrackName const PRAnalyticsTrackSearchResultsDismissed;
extern PRAnalyticsTrackName const PRAnalyticsTrackSearchHistoryTermClicked; //parameter: SearchAllTab
extern PRAnalyticsTrackName const PRAnalyticsTrackSearchPublicationClick;
extern PRAnalyticsTrackName const PRAnalyticsTrackSearchPublicationsSeeAll;
extern PRAnalyticsTrackName const PRAnalyticsTrackSearchPublicationsTabClick;
extern PRAnalyticsTrackName const PRAnalyticsTrackSearchBookClick;
extern PRAnalyticsTrackName const PRAnalyticsTrackSearchBookSeeAll;
extern PRAnalyticsTrackName const PRAnalyticsTrackSearchBookTabClick;
extern PRAnalyticsTrackName const PRAnalyticsTrackSearchInterestClick;
extern PRAnalyticsTrackName const PRAnalyticsTrackSearchInterestsSeeAll;
extern PRAnalyticsTrackName const PRAnalyticsTrackSearchInterestsTabClick;
extern PRAnalyticsTrackName const PRAnalyticsTrackSearchStoryClick;
extern PRAnalyticsTrackName const PRAnalyticsTrackSearchStoriesSeeAll;
extern PRAnalyticsTrackName const PRAnalyticsTrackSearchStoriesTabClick;
extern PRAnalyticsTrackName const PRAnalyticsTrackSearchArticlesLoaded; // parameters: SearchArticlesCount, SearchAllTab

extern PRAnalyticsTrackName const PRAnalyticsTrackIssueTranslated; // parameters: languageFrom, .languageTo, myLibraryItem
extern PRAnalyticsTrackName const PRAnalyticsTrackAutoTranslationOn; // parameters: result
extern PRAnalyticsTrackName const PRAnalyticsTrackAutoTranslationPair; // parameters: languageFrom, .languageTo, result, autoTranslationFlow
extern PRAnalyticsTrackName const PRAnalyticsTrackAutoTranslationPairRemoved; // parameters: languageFrom, .languageTo, autoTranslationFlow
extern PRAnalyticsTrackName const PRAnalyticsTrackAutoTranslationPairPopUp;

extern PRAnalyticsTrackName const PRAnalyticsTrackBookDownloadLimitExceeded;

extern PRAnalyticsTrackName const PRAnalyticsTrackBookRead;
extern PRAnalyticsTrackName const PRAnalyticsTrackBookOrder;

#pragma mark - track parameters

NS_SWIFT_NAME(mainMenu) extern PRAnalyticsTrackParameter const PRAnalyticsMainMenuParameter; // MainMenu
NS_SWIFT_NAME(myLibraryItem) extern PRAnalyticsTrackParameter const PRAnalyticsMyLibraryItemParameter; // PRMylibaryItem
NS_SWIFT_NAME(catalogPath) extern PRAnalyticsTrackParameter const PRAnalyticsCatalogPathParameter; // Array of PRSourceListFilter
NS_SWIFT_NAME(titleItem) extern PRAnalyticsTrackParameter const PRAnalyticsTitleItemParameter; // PRTitleItem
NS_SWIFT_NAME(titleItemExemplar) extern PRAnalyticsTrackParameter const PRAnalyticsTitleItemExemplarParameter; // PRTitleItemExemplar
NS_SWIFT_NAME(article) extern PRAnalyticsTrackParameter const PRAnalyticsArticleParameter; // id<NTFArticle>(NTFArticleItem or NTFArticleDataItem) or PRSmartArticle
NS_SWIFT_NAME(previousArticle) extern PRAnalyticsTrackParameter const PRAnalyticsPreviousArticleParameter; // id<NTFArticle>(NTFArticleItem or NTFArticleDataItem) or PRSmartArticle
NS_SWIFT_NAME(articleSource) extern PRAnalyticsTrackParameter const PRAnalyticsArticleSourceParameter;
NS_SWIFT_NAME(articleSection) extern PRAnalyticsTrackParameter const PRAnalyticsArticleSectionParameter;
NS_SWIFT_NAME(direction) extern PRAnalyticsTrackParameter const PRAnalyticsDirectionParameter; // String
NS_SWIFT_NAME(pageSet) extern PRAnalyticsTrackParameter const PRAnalyticsPageSetParameter; // NTFPageSetItem;
NS_SWIFT_NAME(pageNumber) extern PRAnalyticsTrackParameter const PRAnalyticsPageNumberParameter; // NSUInteger (one-based)
NS_SWIFT_NAME(title) extern PRAnalyticsTrackParameter const PRAnalyticsTitleParameter; // String
NS_SWIFT_NAME(date) extern PRAnalyticsTrackParameter const PRAnalyticsDateParameter;
NS_SWIFT_NAME(textFlowType) extern PRAnalyticsTrackParameter const PRAnalyticsTextFlowTypeParameter; // PRAnalyticsTextFlowType
NS_SWIFT_NAME(textFlowSource) extern PRAnalyticsTrackParameter const PRAnalyticsTextFlowSourceParameter; // PRAnalyticsTextFlowSource
NS_SWIFT_NAME(contentType) extern PRAnalyticsTrackParameter const PRAnalyticsContentTypeParameter; //ContentType
NS_SWIFT_NAME(commentsCount) extern PRAnalyticsTrackParameter const PRAnalyticsCommentsCountParameter; // integer
NS_SWIFT_NAME(searchTerm) extern PRAnalyticsTrackParameter const PRAnalyticsSearchTermParameter; // String
NS_SWIFT_NAME(searchItemType) extern PRAnalyticsTrackParameter const PRAnalyticsSearchItemTypeParameter; // SearchItemType
NS_SWIFT_NAME(webUrl) extern PRAnalyticsTrackParameter const PRAnalyticsWebUrlParameter; // URL
NS_SWIFT_NAME(sfAction) extern PRAnalyticsTrackParameter const PRAnalyticsSFActionParameter; // String
NS_SWIFT_NAME(accountView) extern PRAnalyticsTrackParameter const PRAnalyticsAccountViewParameter; //PRAnalyticsAccountView
NS_SWIFT_NAME(settingsSection) extern PRAnalyticsTrackParameter const PRAnalyticsSettingSectionParameter; // String
NS_SWIFT_NAME(authView) extern PRAnalyticsTrackParameter const PRAnalyticsAuthViewParameter; // PRAnalyticsAuthView
NS_SWIFT_NAME(authType) extern PRAnalyticsTrackParameter const PRAnalyticsAuthTypeParameter; // PRAnalyticsAuthType
NS_SWIFT_NAME(authMethod) extern PRAnalyticsTrackParameter const PRAnalyticsAuthMethodParameter; // AuthMethod
NS_SWIFT_NAME(authProvider) extern PRAnalyticsTrackParameter const PRAnalyticsAuthProviderParameter; // String (social network or external provider name like library
NS_SWIFT_NAME(serviceName) extern PRAnalyticsTrackParameter const PRAnalyticsServiceNameParameter; // String (SE linked service or "PressDisplay.com" for base service
NS_SWIFT_NAME(operationResult) extern PRAnalyticsTrackParameter const PRAnalyticsOperationResultParameter; // Boolean: false:fail, true:success
NS_SWIFT_NAME(paymentProducts) extern PRAnalyticsTrackParameter const PRAnalyticsPaymentProductsParameter; // Array of SKProduct objects
NS_SWIFT_NAME(paymentProduct) extern PRAnalyticsTrackParameter const PRAnalyticsPaymentProductParameter; // SKProduct
NS_SWIFT_NAME(paymentTransactionIdentifier) extern PRAnalyticsTrackParameter const PRAnalyticsPaymentTransactionIdentifierParameter; // String
NS_SWIFT_NAME(productOfferSource) extern PRAnalyticsTrackParameter const PRAnalyticsProductOfferSourceParameter; // OfficeSource
NS_SWIFT_NAME(purchaseRestoreSource) extern PRAnalyticsTrackParameter const PRAnalyticsPurchaseRestoreSourceParameter; // PurchaseRestoreSource
NS_SWIFT_NAME(bannerType) extern PRAnalyticsTrackParameter const PRAnalyticsBannerTypeParameter; // BannerType
NS_SWIFT_NAME(bannerContext) extern PRAnalyticsTrackParameter const PRAnalyticsBannerContextParameter; // BannerContext
NS_SWIFT_NAME(bannerAction) extern PRAnalyticsTrackParameter const PRAnalyticsBannerActionParameter; // BannerAction
NS_SWIFT_NAME(appState) extern PRAnalyticsTrackParameter const PRAnalyticsAppStateParameter; // AppState
NS_SWIFT_NAME(deepLinkCommand) extern PRAnalyticsTrackParameter const PRAnalyticsDeepLinkCommandParameter; // String
NS_SWIFT_NAME(deepLinkQuery) extern PRAnalyticsTrackParameter const PRAnalyticsDeepLinkQueryParameter; // String
NS_SWIFT_NAME(downloadAsset) extern PRAnalyticsTrackParameter const PRAnalyticsDownloadAssetParameter; // String
NS_SWIFT_NAME(speed) extern PRAnalyticsTrackParameter const PRAnalyticsSpeedParameter; // Double
NS_SWIFT_NAME(orderViewAction) extern PRAnalyticsTrackParameter const PRAnalyticsOrderViewActionParameter; // OrderViewAction
NS_SWIFT_NAME(editAction) extern PRAnalyticsTrackParameter const PRAnalyticsEditActionParameter; // EditAction
NS_SWIFT_NAME(interest) extern PRAnalyticsTrackParameter const PRAnalyticsInterestParameter; // String
NS_SWIFT_NAME(shareActivityType) extern PRAnalyticsTrackParameter const PRAnalyticsShareActivityTypeParameter; // UIActivityType / String
NS_SWIFT_NAME(languageTo) extern PRAnalyticsTrackParameter const PRAnalyticsLanguageToParameter; // String
NS_SWIFT_NAME(languageFrom) extern PRAnalyticsTrackParameter const PRAnalyticsLanguageFromParameter; // String
NS_SWIFT_NAME(printType) extern PRAnalyticsTrackParameter const PRAnalyticsPrintTypeParameter; // PrintType
NS_SWIFT_NAME(price) extern PRAnalyticsTrackParameter const PRAnalyticsPriceParameter; // NSDecimalNumber
NS_SWIFT_NAME(priceCurrencyCode) extern PRAnalyticsTrackParameter const PRAnalyticsPriceCurrencyCodeParameter; // String
NS_SWIFT_NAME(copy) extern PRAnalyticsTrackParameter const PRAnalyticsCopyParameter; // String
NS_SWIFT_NAME(richMediaType) extern PRAnalyticsTrackParameter const  PRAnalyticsRichMediaTypeParameter; // String
NS_SWIFT_NAME(richMediaAction) extern PRAnalyticsTrackParameter const PRAnalyticsRichMediaActionParameter; // String
NS_SWIFT_NAME(emailNotificationPermissionType) extern PRAnalyticsTrackParameter const PRAnalyticsEmailNotificationPermissionTypeParameter; // PRAnalyticsEmailNotificationPermissionType
NS_SWIFT_NAME(permissionGranted) extern PRAnalyticsTrackParameter const PRAnalyticsPermissionGrantedParameter; // Boolean
NS_SWIFT_NAME(state) extern PRAnalyticsTrackParameter const PRAnalyticsStateParameter; // Boolean on/off
NS_SWIFT_NAME(autoTranslationZone) extern PRAnalyticsTrackParameter const PRAnalyticsAutoTranslationZoneParameter; // PRAnalyticsAutoTranslationFlowType
NS_SWIFT_NAME(autoTranslationPopUpAction) extern PRAnalyticsTrackParameter const PRAnalyticsAutoTranslationPopUpActionParameter; // PRAnalyticsAutoTranslationPopUpAction
extern PRAnalyticsTrackParameter const PRAnalyticsTrackParameterBookId; // Int
extern PRAnalyticsTrackParameter const PRAnalyticsTrackParameterBookAuthor; // String
extern PRAnalyticsTrackParameter const PRAnalyticsTrackParameterBookTitle; // String
extern PRAnalyticsTrackParameter const PRAnalyticsTrackParameterBookGenres; // String
extern PRAnalyticsTrackParameter const PRAnalyticsTrackParameterBookSlug; //String

extern PRAnalyticsTrackParameter const PRAnalyticsTrackParameterAction;
extern PRAnalyticsTrackParameter const PRAnalyticsTrackParameterPublication;
extern PRAnalyticsTrackParameter const PRAnalyticsTrackParameterAudioLength;
extern PRAnalyticsTrackParameter const PRAnalyticsTrackParameterSection;

extern NSString *const RMTActionPauseNRestart;
extern NSString *const RMTActionFirstStart;
extern NSString *const RMTActionComplete;
extern NSString *const RMTTypeVideo;
extern NSString *const RMTTypeAudio;
extern NSString *const RMTTypeGallery;

extern PRAnalyticsTrackParameter const PRAnalyticsTrackParameterItemPosition; // Int
extern PRAnalyticsTrackParameter const PRAnalyticsTrackParameterCatalogItem; // catalogItem

extern PRAnalyticsTrackParameter const PRAnalyticsTrackParameterSearchAllTab; // SearchAllTab

extern PRAnalyticsTrackParameter const PRAnalyticsTrackParameterSearchArticlesCount; // SearchArticlesCount

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

@interface PRAnalyticsService : NSObject<PRAnalytics>

- (instancetype)initWithApplication:(nullable UIApplication *)application
                      launchOptions:(nullable NSDictionary *)launchOptions;

- (nullable id<PRAnalyticsBaseService>)analyticsServiceWithType:(PRAnalyticsProfileType)type;

- (BOOL)isConsoleAnalyticsEnabled;
- (BOOL)isGoogleAnalyticsEnabled;
- (BOOL)isFirebaseAnalyticsEnabled;
- (BOOL)isFlurryAnalyticsEnabled;
- (BOOL)isBrazeAnalyticsEnabled;

@end

NS_ASSUME_NONNULL_END
