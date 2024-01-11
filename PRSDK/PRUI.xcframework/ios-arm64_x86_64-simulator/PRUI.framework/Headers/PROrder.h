//
//  PROrder.h
//  PRiphone
//
//  Created by Oleg Stepanenko on 29.08.13.
//  Copyright (c) 2013 NewspaperDirect. All rights reserved.
//

#import <PRThumbnail/PRThumbnail.h>
#import "PROrderDelivery.h"

@class PRSubscription;
@class PRTitleItem;
@class PRTitleItemExemplar;
@class PRMyLibraryItem;

NS_ASSUME_NONNULL_BEGIN

extern NSNotificationName const PROrderUpdatedPaymentInfoNotification;

typedef void(^ _Nullable PROrderCompletion)(BOOL success);

@interface PROrder : NSObject

/// @param subscriptions set nil to make all linked services available for order
- (_Nullable instancetype)initWithCID:(NSString *)cid
                                 date:(NSDate *)date
                        subscriptions:(NSArray<PRSubscription *> *)subscriptions
                    thumbnailSizeType:(PRThumbnailSourceSizeType)thumbnailSizeType;

- (void)orderIssue:(PROrderCompletion)orderCompletion;
- (void)orderIssueWithOptions:(PROrderDeliveryOption)deliveryOptions completion:(PROrderCompletion)orderCompletion;
- (void)downloadIssue;
- (void)downloadIssueWithOptions:(PROrderDeliveryOption)deliveryOptions;
- (void)downloadIssue:(PROrderCompletion)downloadCompletion;
- (void)downloadIssueWithOptions:(PROrderDeliveryOption)deliveryOptions completion:(PROrderCompletion)downloadCompletion;

- (void)downloadSupplementsIfNeeded;

- (void)setupAutoDelivery:(BOOL)isAutoDelivery
              supplements:(BOOL)isSupplementsIncluded
             successBlock:(void(^ _Nullable)(void))successBlock
             failureBlock:(void(^ _Nullable)(NSError * _Nullable))failureBlock;
- (void)updateThumbnail;
- (void)resetBackIssueRequested;

- (void)getPaymenInfo:(void(^ _Nullable)(NSString *, NSDate *, NSArray * _Nullable))completion;

- (void)updateWithDate:(NSDate *)date;
- (void)updateWithCID:(NSString *)cid date:(NSDate *)date;

- (void)setupCID;

@property (nonatomic, strong, readonly) NSString *CID;
@property (nonatomic, strong, readonly) NSDate *date;
@property (nonatomic) BOOL forceDownload;
@property (nonatomic, strong, readonly) NSArray<PRSubscription *> *subscriptions;
@property (nonatomic, weak, readonly) PRSubscription *selectedSubscription;
@property (nonatomic, strong, readonly) NSArray *acceptableServiceNames;

@property (nonatomic, strong, readonly) NSString *mainCID;
@property (nonatomic, strong, readonly) PRTitleItem *titleItem;
@property (nonatomic, strong, readonly) PRTitleItemExemplar *titleExemplar;
@property (nullable, nonatomic, weak, readonly) PRMyLibraryItem *mli;
@property (nullable, nonatomic, copy, readonly) NSArray<NSDate *> *availableDates;
@property (nonatomic, copy, readonly) NSDictionary *availableVersions;
@property (nonatomic, assign) BOOL dontVerifyDateWithAvailableDates;
@property (nonatomic, strong, readonly) UIImage *image;
@property (nonatomic, strong, readonly) UIImage *imagePlaceholder;
@property (nonatomic, readonly) BOOL isIncludeSupplementsAllowed;
@property (nonatomic, readonly) NSInteger supplementsCount;
@property (nonatomic, strong, readonly) NSArray<PRTitleItem *> *supplements;
@property (nonatomic, readonly) BOOL supplementsDownloaded;
@property (nonatomic, readonly) BOOL supplementsRequested;

@property (nonatomic, readonly) BOOL latestIssuesExists;

@property (nonatomic, readonly) BOOL isAutoDelivery;
@property (nonatomic, readonly) BOOL isSupplementsIncluded;
@property (nonatomic) BOOL favorite;
@property (nonatomic, getter=isFavoritesManagementSupported, readonly) BOOL favoritesManagementSupported;
@property (nonatomic, readonly) BOOL downloaded;
@property (nonatomic, readonly) BOOL mainIssueDownloaded;
@property (nonatomic, readonly) BOOL readyToOpen;
@property (nonatomic, readonly) PROrderAction selectedAction;
@property (nonatomic, readonly) NSInteger downloadProgress;
@property (nonatomic, readonly) BOOL isValid;
@property (nonatomic, getter=isBackIssueRequested, readonly) BOOL backIssueRequested;
@property (nonatomic, readonly) BOOL waitingForCatalogToRequestBackIssue;

@property (nonatomic, readonly) PROrderStatus status;
@property (nonatomic, readonly) PROrderIssueState issueState;
@property (nonatomic, readonly) PROrderDeliveryResult deliveryResult;

@property (nullable, nonatomic, strong) NSString *selectedServiceName;
@property (nonatomic, assign) PRThumbnailSourceSizeType thumbnailSizeType;

@property (nullable, nonatomic, readonly) NSArray<NSString *> *productIdsForCurrentIssue;
@property (nonatomic, readonly, getter=isPremiumProductAvailableForPurchase) BOOL premiumProductAvailableForPurchase;

@property (nonatomic, readonly) BOOL latestIssueDatesRequestInProgress;
@property (nonatomic, readonly) BOOL mightShowPaymentOptions;

@property (nonatomic, readonly) BOOL hasRadio;

@property (nullable, nonatomic, strong, readonly) PRConsumableBundle *bundle;

@end

NS_ASSUME_NONNULL_END
