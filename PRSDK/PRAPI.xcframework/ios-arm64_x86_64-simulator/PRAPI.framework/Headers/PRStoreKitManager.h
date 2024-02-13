//
//  PRStoreKitManager.h
//  PR-API
//
//  Created by Vitali Bounine on 2018-09-14.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <StoreKit/StoreKit.h>
#import "SKProduct+EligibleForIntorPrice.h"
#import "SKProduct+LocalizedInfo.h"
#import "SKPaymentTransaction+DetailedDescription.h"

@class AppReceipt, AppReceiptIAP;

NS_ASSUME_NONNULL_BEGIN

@interface PRStoreKitManager : NSObject

#pragma mark SK App Receipt Processing

+ (nullable NSData *) appReceiptData;
@property (nullable, nonatomic, class, readonly, strong) AppReceipt *appReceipt;

+ (void) validateAndDecodeAppReceipt:(void(^)(AppReceipt *appReceipt, NSError *error))completionBlock;
+ (void) resetAppReceipt;
//+ (nullable NSArray<SKProduct *> *) eligibleTrialOrIntroductorySubscriptions:(nullable NSArray<SKProduct *> *)introPricedSubscriptions;

@property (nullable, nonatomic, readonly) SKStorefront *storefront;

- (nullable SKProduct *) productWithProductIdentifier:(NSString *)productIdentifier;
- (void) requestStoreProductsInfoWithIdentifiers:(NSSet<NSString *> *)productIdentifiers
                                       completed:(void(^)(NSArray<SKProduct *> *products,
                                                          NSArray<NSString *> *invalidProductIdentifiers,
                                                          NSError *_Nullable error))completionBlock;

- (void) requestStoreProductInfoWithIdentifier:(NSString *)productIdentifier
                                     completed:(void(^)(SKProduct *_Nullable product, NSError *_Nullable error))completionBlock;

- (void) refreshAppReceipt:(void(^ _Nullable)(NSData * _Nullable appReceiptData, NSError * _Nullable error))completionBlock;
- (void) obtainAppReceiptForcingRefresh:(BOOL)forceRefresh completed:(void(^ _Nullable)(NSData * _Nullable appReceiptData, NSError * _Nullable error))completionBlock;
- (void) obtainValidateAndDecodeAppReceipt:(void(^ _Nullable)(AppReceipt * _Nullable appReceipt, NSError * _Nullable error))completionBlock;

- (void) checkReceiptForSubscriptionTransactionsWithIdentifiers:(nullable NSArray<NSString *> *)productIdentifiers completed:(void(^)(NSArray<AppReceiptIAP *> * _Nullable appReceiptIAPs, NSError * _Nullable error))completionBlock;
//- (void) checkReceiptForTrialOrIntroductorySubscriptions:(nullable NSArray<SKProduct *> *)subscriptionProducts completed:(void(^)(NSArray<SKProduct *> * _Nullable eligibleIntroPricedSubsciptions))completionBlock;

#pragma mark SK purchase and payment

- (void) purchaseProduct:(SKProduct *)product;
- (void) makePayment:(SKPayment *)payment;
- (BOOL) hasPendingPaymentTransactions;
- (nullable SKPaymentTransaction *)pendingPaymentTransactionForProduct:(NSString *)productIdentifier;
- (nullable SKPaymentTransaction *)pendingPaymentTransactionWithIdentifier:(NSString *)transactionIdentifier;
- (void) finishTransaction:(SKPaymentTransaction *)paymentTransaction;

@end

NS_ASSUME_NONNULL_END
