//
//  PRAPI.h
//  PRAPI
//
//  Created by berec on 14/11/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

//! Project version number for PRAPI.
FOUNDATION_EXPORT double PRAPIVersionNumber;

//! Project version string for PRAPI.
FOUNDATION_EXPORT const unsigned char PRAPIVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <PRAPI/PublicHeader.h>

#pragma mark - PressFeed
#import <PRAPI/NTFSession+CoreDataClass.h>
#import <PRAPI/NTFFeedItem+CoreDataClass.h>
#import <PRAPI/NTFFeed+CoreDataClass.h>
#import <PRAPI/NTFDataItem+CoreDataClass.h>
#import <PRAPI/NTFContact+CoreDataClass.h>
#import <PRAPI/Interest+CoreDataClass.h>
#import <PRAPI/ArticleLink+CoreDataClass.h>
#import <PRAPI/NTFGiftedIssueItem+CoreDataClass.h>
#import <PRAPI/NTFGiftedIssueItem+Service.h>

#pragma mark - Protocols
#import <PRAPI/SynthesizeSingleton.h>
#import <PRAPI/PRSubscriptionCatalogProtocol.h>
#import <PRAPI/PRWebServerBookRegister.h>
#import <PRAPI/PRAppUIReadyDelegate.h>
#import <PRAPI/OpenedItem.h>

#pragma mark - Consts
#import <PRAPI/PRAPIRequests.h>
#import <PRAPI/PRDictionaryKeys.h>
#import <PRAPI/PRNotifications.h>
#import <PRAPI/PRUserDefaultsKeys.h>
#import <PRAPI/PRConstants.h>
#import <PRAPI/PRAccountNotifications.h>
#import <PRAPI/PRTitleItemNestedTypes.h>
#import <PRAPI/PRService_Constants.h>

#pragma mark - Model

#import <PRAPI/PRLinkedServicesProvider.h>
#import <PRAPI/PRLinkedServiceInfo.h>

#import <PRAPI/PRAccountItemNestedTypes.h>
#import <PRAPI/PRSubscriptionItem.h>

#import <PRAPI/PROptions.h>
#import <PRAPI/PROptions+Speech.h>
#import <PRAPI/PROptions+Downloaded.h>
#import <PRAPI/PROptions+NewsFeed.h>
#import <PRAPI/PROptions+UserDefaults.h>

#import <PRAPI/PRCountry.h>

#import <PRAPI/PRCountableValue.h>
#import <PRAPI/PRCountableDictionary.h>
#import <PRAPI/PRCountableCountry.h>
#import <PRAPI/PRCountableString.h>
#import <PRAPI/PRCountableNumber.h>

#import <PRAPI/PRSourceListFilter.h>

#import <PRAPI/NTFCollectionItem+CoreDataProperties.h>
#import <PRAPI/Channel+CoreDataProperties.h>
#import <PRAPI/PublicationChannel+CoreDataClass.h>
#import <PRAPI/Publication+CoreDataClass.h>

#import <PRAPI/PRBundle.h>

#import <PRAPI/PRObservableObject.h>
#import <PRAPI/PRObservableObject_Protected.h>
#import <PRAPI/PRArrayModel.h>
#import <PRAPI/PRWeakLink.h>
#import <PRAPI/PRLink.h>

#import <PRAPI/PRCollectionsModel.h>

#import <PRAPI/PRTitleObject.h>

#import <PRAPI/PRSourceItem.h>

#import <PRAPI/PRTitleItem.h>
#import <PRAPI/PRTitleItem+Favorites.h>
#import <PRAPI/NSDate+TitleItem.h>

#import <PRAPI/PRTitleItemExemplar.h>
#import <PRAPI/PRTitleGroup.h>

#import <PRAPI/PRSubscription.h>
#import <PRAPI/PRSubscription+Back2ObjC.h>
#import <PRAPI/PRSubscription+Service.h>
#import <PRAPI/PRSubscription+Error.h>
#import <PRAPI/PRSubscription+Store.h>

#import <PRAPI/PRAccountItem.h>
#import <PRAPI/PRAccountItem+Service.h>
#import <PRAPI/PRAccountItem+KYM.h>

#import <PRAPI/PRSourceList.h>
#import <PRAPI/PRSourceList_Protected.h>
#import <PRAPI/PRSourceList+Info.h>

#import <PRAPI/PRLatestIssuesList.h>

#import <PRAPI/PRCatalogFilter.h>
#import <PRAPI/PRCatalogFilterItem.h>

#import <PRAPI/PRModel.h>
#import <PRAPI/PRModel+Settings.h>

#import <PRAPI/PRHost+Service.h>

#import <PRAPI/PRLibraryProfile.h>
#import <PRAPI/PRLibraryProfile+Service.h>

#import <PRAPI/NTFDataService.h>
#import <PRAPI/NTFDataService+Filter.h>
#import <PRAPI/NTFSearchDataService.h>
#import <PRAPI/NTFCategoryFeedDataService.h>
#import <PRAPI/NTFSimilarArticlesDataService.h>

#import <PRAPI/NTFCoreDataController.h>

#import <PRAPI/NTFFeed+Config.h>

#import <PRAPI/NTFSmartDataItem.h>
#import <PRAPI/NTFArticleItem.h>
#import <PRAPI/NTFPageSetItem.h>
#import <PRAPI/NTFPageSetItem+CoreDataProperties.h>
#import <PRAPI/NTFPageSetItem+Images.h>

#import <PRAPI/NTFRelatedStoriesItem.h>
#import <PRAPI/NTFMoreItem.h>
#import <PRAPI/NTFAdBlockItem.h>
#import <PRAPI/PRNavMenuFilter.h>

#import <PRAPI/PRUserProfile.h>
#import <PRAPI/PRUserProfile+Service.h>
#import <PRAPI/NTFUserItem.h>

#import <PRAPI/PRMyLibraryItem.h>
#import <PRAPI/PRMyLibrary+Store.h>
#import <PRAPI/PRMyLibrary+Notification.h>
#import <PRAPI/PRMyLibraryItem+Service.h>
#import <PRAPI/PRMyLibrary+Sorting.h>
#import <PRAPI/PRAggregatedLibraryItem.h>

#import <PRAPI/PRSmartArticle+Bookmarks.h>
#import <PRAPI/PRSmartArticle+NTF.h>
#import <PRAPI/PRSmartArticle+Service.h>

#import <PRAPI/PRSmartMediaRegion+MediaContent.h>

#import <PRAPI/PRProduct.h>

#import <PRAPI/PRExpunge.h>

#import <PRAPI/PRPage.h>

#import <PRAPI/PRHotSpotAnnotation.h>
#import <PRAPI/MapKitUtil.h>

#import <PRAPI/PRCatalogSection.h>

#import <PRAPI/PDFDoc.h>

#pragma mark - Controllers / Managers

#import <PRAPI/PRCoreDataController.h>
#import <PRAPI/PROperationController.h>

#import <PRAPI/PRSocialSignInManager.h>
#import <PRAPI/PRSocialSignInManager+Providers.h>
#import <PRAPI/_PRSocialManager.h>
#import <PRAPI/PRFacebookSignInManager.h>
#import <PRAPI/PRGoogleSignInManager.h>

#import <PRAPI/PRAccountManager.h>
#import <PRAPI/PRAccountManager+ExternalAuth.h>
#import <PRAPI/PRAccountManager+Service.h>
#import <PRAPI/PRAccountManager+Error.h>

#import <PRAPI/PRStoreKitManager.h>
#import <PRAPI/PRPushNotificationsManager.h>

#import <PRAPI/PRBackgroundDownloadManager.h>

#pragma mark - Utils

#import <PRAPI/PRPromise+Service.h>
#import <PRAPI/NSURL+Service.h>

#import <PRAPI/PRGeneralUIInfo.h>

#import <PRAPI/PRArticleImageGenerator.h>
#import <PRAPI/PRGenerateImageForPDFOperation.h>

#import <PRAPI/PRLNS.h>

#import <PRAPI/PdfPrintRenderer.h>

#import <PRAPI/NTFFeedSectionItem.h>

#import <PRAPI/NTFBannersItem.h>

#import <PRAPI/NTFSocialInfoItem.h>

#import <PRAPI/PRDownloadedSourceList.h>

#import <PRAPI/PRAskReviewUtil.h>

#import <PRAPI/PRBrazeAnalytics.h>
#import <PRAPI/PRFirebaseAnalytics.h>
#import <PRAPI/BranchAnalytics.h>

#import <PRAPI/NSArray+TitleObject.h>

#import <PRAPI/NSObject+PRAPINotifications.h>
#import <PRAPI/NTFArticleUtil.h>

#import <PRAPI/NTFContentRestrictions.h>
#import <PRAPI/NTFContentRestrictionsCache.h>

#import <PRAPI/PRSmartCommentPost.h>

#import <PRAPI/PRArticleTextProvider.h>
#import <PRAPI/PRFirebasePushNotificationsManager.h>

#import <PRAPI/PRHost.h>
#import <PRAPI/PRMyLibrary.h>
#import <PRAPI/PRCatalog.h>
#import <PRAPI/PROptions.h>
#import <PRAPI/PROptions+NewsFeed.h>
#import <PRAPI/PROnlineContentUpdater.h>
#import <PRAPI/PRCoreUtil.h>

#import <PRAPI/PRTitleItemsManager.h>
#import <PRAPI/PRCoreGlobalImpl.h>
#import <PRAPI/PRWebServer.h>
#import <PRAPI/PRSocialSignInManager.h>
#import <PRAPI/PRHotSpotStatus.h>
#import <PRAPI/PRSuggestionsManager.h>
#import <PRAPI/PRImageLoader.h>

#pragma mark - PROTECTED

#import <PRAPI/PRService.h>
#import <PRAPI/PRNSBundle+Updatable.h>
#import <PRAPI/PRAnalyticsProfileManager.h>
#import <PRAPI/ConsoleAnalytics.h>
#import <PRAPI/GoogleAnalytics.h>
#import <PRAPI/GeoHasher.h>
#import <PRAPI/NTFHomeFeedDataService.h>
