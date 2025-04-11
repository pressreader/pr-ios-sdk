//
//  PRAnalyticsTrackName.h
//  PRAnalytics
//
//  Created by Vitalii Hudenko on 26.10.2023.
//  Copyright © 2023 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

/// `rawValue` must be equal to the last part of the case name with exception of underscore characters.
///
/// Valid name example:
///
///     PRAnalyticsTrackName const PRAnalyticsTrackSomeEvent = @"SomeEvent";
///     PRAnalyticsTrackName const PRAnalyticsTrackSomeOtherEvent = @"Some_Other_Event";
///
/// Invalid name example:
///
///     PRAnalyticsTrackName const PRAnalyticsTrackSomeEvent = @"Who CaresThose-Names!";
///
typedef NSString * PRAnalyticsTrackName NS_TYPED_ENUM;


extern PRAnalyticsTrackName const PRAnalyticsTrackDownloadedView;
extern PRAnalyticsTrackName const PRAnalyticsTrackReplicaView; // parameters: MyLibraryItem
extern PRAnalyticsTrackName const PRAnalyticsTrackReplicaPage; // parameters: MyLibraryItem and page
extern PRAnalyticsTrackName const PRAnalyticsTrackCatalogView; // parameter: CatalogPath and CatalogFilter
extern PRAnalyticsTrackName const PRAnalyticsTrackOrderView; // paramerters TitleItemExemplar, OrderViewAction
extern PRAnalyticsTrackName const PRAnalyticsTrackTextFlowView; // parameters: TextFlowSource, TextFlowType, MyLibraryItem for Source .issue, SearchTerm for source .searchResults
extern PRAnalyticsTrackName const PRAnalyticsTrackArticleView; // parameters: ArticleItem and TextFlowType
extern PRAnalyticsTrackName const PRAnalyticsTrackArticleViewClose;
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
extern PRAnalyticsTrackName const PRAnalyticsTrackPaymentProductSelected;
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
extern PRAnalyticsTrackName const PRAnalyticsTrackAuthorize; // parameter : AuthType, ServiceName, OperationResult
extern PRAnalyticsTrackName const PRAnalyticsTrackSeeAllPaymentOptions;
extern PRAnalyticsTrackName const PRAnalyticsTrackProductOffer; // PaymentProduct, ProductOfferSource
extern PRAnalyticsTrackName const PRAnalyticsTrackPurchase; // PaymentProduct, PRTitleItemExemplar, SKPaymentTransaction and OperationResult
extern PRAnalyticsTrackName const PRAnalyticsTrackPurchaseRestore; // PurchaseRestoreSource
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
extern PRAnalyticsTrackName const PRAnalyticsTrackSubscribeTap;
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

extern PRAnalyticsTrackName const PRAnalyticsTrackExternalLinkAccount;
extern PRAnalyticsTrackName const PRAnalyticsTrackCancelRegistration;
extern PRAnalyticsTrackName const PRAnalyticsTrackRegistrationAlertPresented;
extern PRAnalyticsTrackName const PRAnalyticsTrackDigestNotificationReceived;

extern PRAnalyticsTrackName const PRAnalyticsTrackAutodelivery;
extern PRAnalyticsTrackName const PRAnalyticsTrackWidget;
extern PRAnalyticsTrackName const PRAnalyticsTrackWidgetInstallation;

extern PRAnalyticsTrackName const PRAnalyticsTrackHomeFeedOpened;
extern PRAnalyticsTrackName const PRAnalyticsTrackGiftedIssueAdget;
extern PRAnalyticsTrackName const PRAnalyticsTrackGiftedIssueVideoPlayed;
