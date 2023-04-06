//
//  PRProduct.h
//  iPurchase
//
//  Created by OlegB on 11-03-07.
//  Copyright 2011 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>
@import StoreKit.SKProduct;

NS_ASSUME_NONNULL_BEGIN

@interface PRProduct : NSObject

@property (nullable, nonatomic, strong) NSString *CIDToBuy;
@property (nullable, nonatomic, strong) NSDate *issueDateToBuy;

@property (nonatomic, strong) NSString *productIdentifier;

@property (nullable, nonatomic, strong) NSString *subscriptionBundleIdentifier;
@property (nullable, nonatomic, strong) NSString *subscriptionGroupIdentifier;

@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) NSString *productDescription;
@property (nonatomic, strong) NSString *priceStr;
@property (nonatomic, strong) NSDecimalNumber *price;
@property (nonatomic, strong) NSLocale *priceLocale;
@property (nullable, nonatomic, strong) NSString *introPriceStr;
@property (nonatomic, strong) NSDate *subscriptionStartDateAfterIntroCompleted;
@property (nullable, nonatomic, strong) NSString *subscriptionPeriodDescription;
@property (nonatomic) SKProductPeriodUnit subscriptionPeriodUnit;
@property (nonatomic) NSInteger numberOfPeriodUnits;
@property (nullable, nonatomic, strong) NSString *introPeriodDescription;
@property (nullable, nonatomic, strong) NSString *introAllPeriodsDescription;
@property (nonatomic, assign) BOOL introFreeTrial;
@property (nonatomic, assign) BOOL isPremium;
/// Shows whether the product is a special `Select` subscription.
@property (nonatomic, readonly) BOOL isSelect;
@property (nonatomic, readonly) BOOL isUnlimited;

// computed properties
@property (nullable, nonatomic, readonly) NSString *introTitle;
@property (nullable, nonatomic, readonly) NSString *introSubtitle;

@property (nonatomic, readonly) BOOL isSubscription;

@property (nonatomic, readonly) NSArray<NSString *> *CIDs NS_SWIFT_NAME(CIDs);

@end

NS_ASSUME_NONNULL_END
