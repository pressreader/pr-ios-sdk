//
//  PRNotifications.h
//  PRiphone
//
//  Created by Jackie Cane on 3/25/11.
//  Copyright 2011 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSNotificationName const PRTestServerChangedNotification;
extern NSNotificationName const PRTestRefreshPublicationsNotification;

extern NSNotificationName const PRThumnailHasBeenLoadedNotification;

extern NSNotificationName const PRShowSFCustomSubsInvalidNotification;
extern NSNotificationName const PRStorePaymentTransactionNotification;
extern NSNotificationName const PRStoreProductInfoNotification;
extern NSNotificationName const PRStorePurchaseConfirmationDismissedNotification;
extern NSNotificationName const PRProcessGetBundlesResponseCompleteNotification;
extern NSNotificationName const PRProcessGetUserBundlesResponseCompleteNotification;
extern NSNotificationName const PRUserBundleUpdatedNotification;
extern NSNotificationName const PRUpdateProductsWithSKProductsResponseCompleteNotification;
extern NSNotificationName const PRLoadBrandResourcesNotification;
extern NSNotificationName const PRBrandResourcesLoadedNotification;
extern NSNotificationName const PRHideSmartViewNotification;
extern NSNotificationName const PRStoreCatalogueWillAppearNotification;
extern NSNotificationName const PRStoreTitleThumbnailTouchNotification;
extern NSNotificationName const PRObtainThumbnailImageCompleteNotification;
extern NSNotificationName const PRShowStoreCatalogueNotification;
extern NSNotificationName const PRShowSettingsNotification;
extern NSNotificationName const PRDownloadExternalGraphicCompletedNotification;
extern NSNotificationName const PRGetOrderScreenAdOperationCompletedNotification;
extern NSNotificationName const PRNewerIssueAvailableInCatalogNotification;
extern NSNotificationName const PRIssueDatesUpdatedNotification;
extern NSNotificationName const PRAppPanelCurrentDidChangeNotification;
extern NSNotificationName const PRTextViewUpdatedNotification;
extern NSNotificationName const PRProfilePhotoIconDidChangeNotification;

extern NSNotificationName const PRGetTextViewAdOperationCompletedNotification;

extern NSNotificationName const PRApplySettingsNotification;
extern NSNotificationName const PRPerformSmartSearchNotification;

extern NSNotificationName const PRDownloadedOrderByValueChangedNotification;
extern NSNotificationName const PRPurchaseAdvicesDidRefreshNotification;
extern NSNotificationName const PRMyLibraryInitializationDone;

extern NSNotificationName const PRImageURLUpdateNotification;

extern NSNotificationName const PRPrintOperationStartedNotification;
extern NSNotificationName const PRPrintOperationCompletedNotification;
extern NSNotificationName const PRSharingStartedNotification;
extern NSNotificationName const PRSharingCompletedNotification;
extern NSNotificationName const PRListenStartedNotification;
extern NSNotificationName const PRBookmarkSavedNotification;
extern NSNotificationName const PRFinalizePageReadingMapNotification;
extern NSNotificationName const PRShowSendFeedbackNotification;
extern NSNotificationName const PRBaseServiceURLsUpdatedNotification;

extern NSNotificationName const PRConfigHasBeenUpdatedNotification;
extern NSNotificationName const PRConfigUnableToUpdatedNotification;
extern NSNotificationName const PRFirebaseRemoteConfigRefreshedNotification;
extern NSNotificationName const PRModelDidResumeNotification;

extern NSNotificationName const PRUserDefaultstateRefreshedNotification;

extern NSNotificationName const PRCommentPostNotification;

extern NSNotificationName const PRMainViewSizeChangedNotification;
extern NSNotificationName const PRMainViewTraitCollectionChangedNotification;

extern NSNotificationName const PRPremiumTrialStateUpdatedNotification;
extern NSNotificationName const PRRremiumProductUpdatedNotification;
extern NSNotificationName const PRPremiumTrialEligibilityUpdatedNotification;

extern NSNotificationName const PRBookmarkCollectionDeletedNotification;

extern NSNotificationName const PRAccountAuthorizationCancelled;
extern NSNotificationName const PRAccountAuthorizationCompleted;
extern NSNotificationName const PRAccountExternalAuthorizationCancelled;

extern NSNotificationName const PRDismissPopoverNotification;

extern NSNotificationName const PRLaunchCommandDidExecuteNotification;

extern NSNotificationName const PRInterestsChangedNotification;

extern NSNotificationName const PROnboardingCompletedNotification;
extern NSNotificationName const PROnboardingStatusReceivedNotification;
extern NSNotificationName const PROnboardingFailedToReceiveStatusNotification;

extern NSNotificationName const PRPushNotificationsAccessWasRequestedNotification;

extern NSNotificationName const PRServiceHostDidUpdate;

extern NSNotificationName const PRLaunchCommandNotification;
extern NSNotificationName const PRActionCommandNotification;

extern NSNotificationName const PRUpdateHZStatus;

#define PRSmartProcessed @"PRSmartProcessed"
#define PRSFIsReady   @"PRSFIsReady"

