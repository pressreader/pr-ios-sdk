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
#import "NTFSession+CoreDataClass.h"
#import "NTFFeedItem+CoreDataClass.h"
#import "NTFFeed+CoreDataClass.h"
#import "NTFDataItem+CoreDataClass.h"
#import "NTFContact+CoreDataClass.h"
#import "Interest+CoreDataClass.h"
#import "ArticleLink+CoreDataClass.h"
#import "NTFGiftedIssueItem+CoreDataClass.h"
#import "NTFGiftedIssueItem+Service.h"

#pragma mark - Protocols
#import "PRAnalyticsProto.h"
#import "SynthesizeSingleton.h"
#import "PRSubscriptionCatalogProtocol.h"
#import "PRMastheadProvider.h"
#import "PRWebServerBookRegister.h"
#import "PRAppUIReadyDelegate.h"
#import "OpenedItem.h"

#pragma mark - Consts
#import "PRAPIRequests.h"
#import "PRDictionaryKeys.h"
#import "PRNotifications.h"
#import "PRUserDefaultsKeys.h"
#import "PRConstants.h"
#import "PRAccountNotifications.h"
#import "PRTitleItemNestedTypes.h"
#import "PRService_Constants.h"

#pragma mark - Model

#import "PRLinkedServicesProvider.h"
#import "PRLinkedServiceInfo.h"

#import "PRAccountItemNestedTypes.h"
#import "PRSubscriptionItem.h"

#import "PROptions.h"
#import "PROptions+Speech.h"
#import "PROptions+Downloaded.h"
#import "PROptions+NewsFeed.h"
#import "PROptions+UserDefaults.h"

#import "PRCountry.h"

#import "PRCountableValue.h"
#import "PRCountableDictionary.h"
#import "PRCountableCountry.h"
#import "PRCountableString.h"
#import "PRCountableNumber.h"

#import "PRSourceListFilter.h"

#import "NTFCollectionItem+CoreDataProperties.h"
#import "Channel+CoreDataProperties.h"
#import "PublicationChannel+CoreDataClass.h"
#import "Publication+CoreDataClass.h"

#import "PRBundle.h"

#import "PRObservableObject.h"
#import "PRObservableObject_Protected.h"
#import "PRArrayModel.h"
#import "PRWeakLink.h"
#import "PRLink.h"

#import "PRCollectionsModel.h"

#import "PRTitleObject.h"

#import "PRSourceItem.h"
#import "PRSourceItem+Masthead.h"

#import "PRTitleItem.h"
#import "PRTitleItem+Favorites.h"
#import "NSDate+TitleItem.h"

#import "PRTitleItemExemplar.h"
#import "PRTitleGroup.h"

#import "PRSubscription.h"
#import "PRSubscription+Back2ObjC.h"
#import "PRSubscription+Service.h"
#import "PRSubscription+Error.h"
#import "PRSubscription+Store.h"

#import "PRAccountItem.h"
#import "PRAccountItem+Service.h"
#import "PRAccountItem+KYM.h"

#import "PRSourceList.h"
#import "PRSourceList_Protected.h"
#import "PRSourceList+Equality.h"
#import "PRSourceList+Info.h"

#import "PRLatestIssuesList.h"

#import "PRModel.h"
#import "PRModel+Settings.h"

#import "PRHost+Service.h"

#import "PRLibraryProfile.h"
#import "PRLibraryProfile+Service.h"

#import "NTFDataService.h"
#import "NTFSearchDataService.h"
#import "NTFCategoryFeedDataService.h"
#import "NTFSimilarArticlesDataService.h"
#import "NTFCoreDataController.h"

#import "NTFFeed+Config.h"

#import "NTFSmartDataItem.h"
#import "NTFArticleItem.h"
#import "NTFArticleItem+Service.h"
#import "NTFPageSetItem.h"
#import "NTFPageSetItem+CoreDataProperties.h"
#import "NTFPageSetItem+Images.h"

#import "NTFRelatedStoriesItem.h"
#import "NTFMoreItem.h"
#import "PRNavMenuFilter.h"

#import "PRUserProfile.h"
#import "PRUserProfile+Service.h"
#import "NTFUserItem.h"

#import "PRMyLibraryItem.h"
#import "PRMyLibrary+Store.h"
#import "PRMyLibrary+Notification.h"
#import "PRMyLibraryItem+Service.h"
#import "PRMyLibrary+Sorting.h"
#import "PRAggregatedLibraryItem.h"

#import "PRSmartArticle+Bookmarks.h"
#import "PRSmartArticle+NTF.h"
#import "PRSmartArticle+Service.h"

#import "PRProduct.h"

#import "PRExpunge.h"

#import "PRPage.h"

#import "PRHotSpotAnnotation.h"
#import "MapKitUtil.h"

#import "PRCatalogSection.h"

#import "PDFDoc.h"

#pragma mark - Controllers / Managers

#import "PRCoreDataController.h"
#import "PROperationController.h"

#import "PRSocialSignInManager.h"

#import "PRAccountManager.h"
#import "PRAccountManager+ExternalAuth.h"
#import "PRAccountManager+Service.h"
#import "PRAccountManager+Error.h"

#import "PRStoreKitManager.h"
#import "PRPushNotificationsManager.h"

#import "PRBackgroundDownloadManager.h"

#pragma mark - Utils

#import "PRPromise+Service.h"
#import "NSURL+Service.h"

#import "PRGeneralUIInfo.h"

#import "PRArticleImageGenerator.h"
#import "PRGenerateImageForPDFOperation.h"

#import "PRLNS.h"

#import "PdfPrintRenderer.h"

#import "UIAlertController+Common.h"

#import "NTFFeedSectionItem.h"

#import "NTFBannersItem.h"

#import "NTFSocialInfoItem.h"

#import "PRDownloadedSourceList.h"

#import "PRAskReviewUtil.h"

#import "PRBrazeAnalytics.h"
#import "PRFirebaseAnalytics.h"
#import "PRFlurryAnalytics.h"
#import "BranchAnalytics.h"

#import "NSArray+TitleObject.h"

#import "PRCoreUtil+ClassExtending.h"
#import "NSObject+PRAPINotifications.h"
#import "NTFArticleUtil.h"

#import "NTFContentRestrictions.h"
#import "NTFContentRestrictionsCache.h"

#import "PRSmartCommentPost.h"

#import "UIViewController+AppSingletons.h"
#import "PRArticleTextProvider.h"
#import "PRFirebasePushNotificationsManager.h"

#pragma mark - PROTECTED

#import "PRService.h"
#import "PRNSBundle+Updatable.h"
#import "PRAnalyticsProfileManager.h"
#import "PRSchemeProvider.h"
#import "ConsoleAnalytics.h"
#import "GoogleAnalytics.h"
