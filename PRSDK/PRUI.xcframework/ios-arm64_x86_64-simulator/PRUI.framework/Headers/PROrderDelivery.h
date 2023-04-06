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

@class PRSubscription, SKPayment, SKProduct, PRProduct;

typedef NS_OPTIONS(NSUInteger, PROrderDeliveryOption) {
    PROrderDeliveryOptionSilent = 1 << 0,
    PROrderDeliveryOptionSkipDownload = 1 << 1,
    PROrderDeliveryOptionIncludeSupplements = 1 << 2,
    PROrderDeliveryOptionRetrieveProductInfo = 1 << 3
};

extern NSNotificationName const PROrderDeliveryResultNotification;

@protocol PRPurchaseSelectorProtocol <NSObject>
- (void)productSelected:(NSInteger)index;
- (void)requestRestoredTransactions;
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

- (void)renewSubscription:(nullable PRSubscription *)subs;

- (void)purchaseProductWithIdentifier:(NSString *)productIdentifier
                         subscription:(PRSubscription *)subs
                            completed:(CompletionBlock)completionBlock
                            cancelled:(CancellationBlock)cancellationBlock;

- (void)purchaseProductWithIdentifiers:(NSArray<NSString *> *)productIdentifiers
                          subscription:(PRSubscription *)subs
                             completed:(CompletionBlock)completionBlock
                             cancelled:(CancellationBlock)cancellationBlock;

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
@property (nullable, nonatomic, strong, readonly) NSNumber *balance;
@property (nonatomic, readonly) PROrderDeliveryResult deliveryResult;

@property (nullable, nonatomic, copy) CompletionBlock completionBlock;
@property (nullable, nonatomic, copy) DeliveryCompletionBlock deliveryCompletionBlock;
@property (nullable, nonatomic, copy) CancellationBlock cancellationBlock;

@end

NS_ASSUME_NONNULL_END
