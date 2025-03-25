//
//  PROrderDelivery.h
//  PRiphone
//
//  Created by Vitali Bounine on 2/24/10.
//  Copyright 2010 NewspaperDirect. All rights reserved.
//

@import PRAPI.PRBundle;
#import "PROrderEnum.h"

NS_ASSUME_NONNULL_BEGIN

typedef void(^CompletionBlock)(PROrderDeliveryResult result);
typedef void(^CancellationBlock)(void);

@class PRSubscription, SKPayment, SKProduct, PRProduct, PurchaseConfirmation;

typedef NS_OPTIONS(NSUInteger, PROrderDeliveryOption) {
    PROrderDeliveryOptionSilent = 1 << 0,
    PROrderDeliveryOptionSkipDownload = 1 << 1,
    PROrderDeliveryOptionIncludeSupplements = 1 << 2,
    PROrderDeliveryOptionRetrieveProductInfo = 1 << 3,
    PROrderDeliveryOptionSkipReadingSuggestion = 1 << 4,
    PROrderDeliveryOptionUsePremiumProduct = 1 << 5,
    /// By default `PROrderDelivery` doesn't retrieve purchase information and doesn't try to buy an issue if there is a downloaded
    /// library item. With this option we can force `PROrderDelivery` to ignore downloaded library item and proceed with a
    /// purchase flow anyway.
    PROrderDeliveryOptionIgnoreDownloadedItem = 1 << 6,
    PROrderDeliveryOptionOrderConfirmed = 1 << 7
};

extern NSNotificationName const PROrderDeliveryResultNotification;

@protocol PRPurchaseSelectorProtocol <NSObject>
- (void)productSelected:(NSInteger)index;
- (void)requestRestoredTransactions;
- (void)requestRestoredTransactionsForced:(BOOL)forced completionHandler:(nullable void(^)(BOOL success))completionHandler NS_SWIFT_NAME(requestRestoredTransactions(forced:completionHandler:));
@end

@interface PROrderDelivery : NSObject <PRPurchaseSelectorProtocol>

- (void)requestBackIssueForSubscription:(PRSubscription *)subs
                                    CID:(NSString *)CID
                                   date:(NSDate *)issueDate
                                options:(PROrderDeliveryOption)options
                        purchaseProduct:(nullable NSString *)productIdentifier
                       orderDescription:(nullable NSDictionary *)orderDescription
                        completionBlock:(nullable DeliveryCompletionBlock)completionBlock
                      cancellationBlock:(nullable CancellationBlock)cancellationBlock;
- (void)requestBackIssueWithPurchaseConfirmationStatus:(BOOL)purchaseConfirmedByUser;

- (void)renewSubscription:(nullable PRSubscription *)subs;

- (void)purchaseProductWithIdentifiers:(NSArray<NSString *> *)ids;

- (void)purchaseProductWithIdentifiers:(NSArray<NSString *> *)ids
                          subscription:(nullable PRSubscription *)subscription;

- (void)purchaseProductWithIdentifiers:(NSArray<NSString *> *)productIdentifiers
                          subscription:(nullable PRSubscription *)subs
                             completed:(nullable CompletionBlock)completionBlock
                             cancelled:(nullable CancellationBlock)cancellationBlock;

- (void)purchaseProductBundleForCIDs:(nullable NSSet<NSString *> *)cids
                        subscription:(PRSubscription *)subs
                          bundleType:(PRBundleProductType)type
                           completed:(CompletionBlock)completionBlock
                           cancelled:(CancellationBlock)cancellationBlock;

- (void)purchaseProduct:(SKProduct *)product
                payment:(SKPayment *)payment
           subscription:(PRSubscription *)subs
              completed:(CompletionBlock)completionBlock
              cancelled:(CancellationBlock)cancellationBlock;

- (void)restorePurchasesWithProductIdentifier:(NSString *)productIdentifier
                                 subscription:(PRSubscription *)subs
                                    completed:(CompletionBlock)completionBlock
                                    cancelled:(CancellationBlock)cancellationBlock;

@property (nullable, nonatomic, weak) PRSubscription *subscription;
@property (nullable, nonatomic, copy) NSString *cid;
@property (nullable, nonatomic, strong) NSDate *issueDate;

@property (nonatomic, assign) int orderId;
@property (nonatomic) PROrderDeliveryOption options;
@property (nullable, nonatomic, strong) NSDictionary *orderDescription;
@property (nonatomic, strong) NSDictionary *productsInfo;
@property (nonatomic, strong, readonly) NSArray<NSString *> *productIDList;
@property (nullable, nonatomic, strong, readonly) PRConsumableBundle *bundle;
@property (nonatomic, readonly) PROrderDeliveryResult deliveryResult;

@property (nullable, nonatomic, copy) CompletionBlock completionBlock;
@property (nullable, nonatomic, copy) DeliveryCompletionBlock deliveryCompletionBlock;
@property (nullable, nonatomic, copy) CancellationBlock cancellationBlock;

@end

@interface PROrderDelivery (/*PROTECTED*/)
- (void)cancelOrderDelivery;
- (void)requestBackIssue;
- (void)completeHotSpotWaiting;

@property (nullable, nonatomic, strong) SKProduct *purchasingProduct;
@property (nullable, nonatomic, copy) NSString *purchasingTransactionId;
@property (nonatomic) BOOL confirmingServerSidePurchase;
@property (nullable, nonatomic, strong) id issuePrice;
@property (nullable, nonatomic, copy) NSString *issuePriceCurrency;

@end

#ifdef TEST
@interface PROrderDelivery ()
- (void)presentConfirmationScreenWithSuccess:(BOOL)isSuccess
                                   restoring:(BOOL)isRestoring
                     unlimitedOrTrialUpdated:(BOOL)isUnlimitedOrTrialUpdated
                         confirmationHandler:(void (^__nullable)(PurchaseConfirmation *))confirmationHandler;

@end
#endif

@interface PROrderDelivery (/*PRIVATE*/)
- (void)processProducts:(NSSet *)productIDs
           descriptions:(NSObject *)descriptions
                   info:(NSDictionary *)info;
@end

NS_ASSUME_NONNULL_END
