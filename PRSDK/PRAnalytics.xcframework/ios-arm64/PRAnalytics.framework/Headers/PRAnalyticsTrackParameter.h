//
//  PRAnalyticsTrackParameter.h
//  PRAnalytics
//
//  Created by Vitalii Hudenko on 26.10.2023.
//  Copyright © 2023 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NSInteger PRAnalyticsOperationState NS_TYPED_ENUM NS_SWIFT_NAME(OperationState);
static PRAnalyticsOperationState const PRAnalyticsOperationStateCompleted = 0;
static PRAnalyticsOperationState const PRAnalyticsOperationStateStarted = 1;
static PRAnalyticsOperationState const PRAnalyticsOperationStateFailed = 2;

/// `rawValue` must be equal to the last part of the case name.
/// `camelCase` is preferable.
///
/// Valid name example:
///
///     PRAnalyticsTrackParameter const PRAnalyticsTrackParameterItemId = @"itemId";
///     PRAnalyticsTrackParameter const PRAnalyticsTrackParameterOtherItemId = @"OtherItemId";
///
/// Invalid name example:
///
///     PRAnalyticsTrackParameter const PRAnalyticsTrackParameterItemId = @"I wanna_use-this!";
///
typedef NSString * PRAnalyticsTrackParameter NS_TYPED_ENUM;


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
NS_SWIFT_NAME(pageName) extern PRAnalyticsTrackParameter const PRAnalyticsParameterPageName; // NSString
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

extern PRAnalyticsTrackParameter const PRAnalyticsTrackParameterItemPosition; // Int
extern PRAnalyticsTrackParameter const PRAnalyticsTrackParameterCatalogItem; // catalogItem

extern PRAnalyticsTrackParameter const PRAnalyticsTrackParameterSearchAllTab; // SearchAllTab

extern PRAnalyticsTrackParameter const PRAnalyticsTrackParameterSearchArticlesCount; // SearchArticlesCount

extern PRAnalyticsTrackParameter const PRAnalyticsTrackParameterPhotoIndex;
extern PRAnalyticsTrackParameter const PRAnalyticsTrackParameterPhotosCount;
extern PRAnalyticsTrackParameter const PRAnalyticsTrackParameterError;
extern PRAnalyticsTrackParameter const PRAnalyticsTrackParameterContext;
extern PRAnalyticsTrackParameter const PRAnalyticsTrackParameterOperationState;
extern PRAnalyticsTrackParameter const PRAnalyticsTrackParameterDigestInfo;
extern PRAnalyticsTrackParameter const PRAnalyticsTrackParameterAccountActivationNumber;

extern PRAnalyticsTrackParameter const PRAnalyticsTrackParameterWidgetType; // String: TopStories, etc
extern PRAnalyticsTrackParameter const PRAnalyticsTrackParameterWidgetSize; // String: small, medium, large
extern PRAnalyticsTrackParameter const PRAnalyticsTrackParameterWidgetKinds; // [WidgetKind]

extern PRAnalyticsTrackParameter const PRAnalyticsTrackParameterDuration; // Int
