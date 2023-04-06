//
//  PRBundle.h
//  PRiphone
//
//  Created by Oleg Stepanenko on 09.08.13.
//  Copyright (c) 2013 NewspaperDirect. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

@class SKProduct;

@interface PRBaseBundle : NSObject
@property (nonatomic, strong) NSString *productID;
@property (nullable, nonatomic, strong) NSString *productType;
@property (nonatomic, strong) NSString *productName;
@property (nullable, nonatomic, strong) NSString *appProductID;
@property (nullable, nonatomic, strong) SKProduct *appProduct;
@property (nullable, nonatomic, strong) NSString *subscriptionFamily;
@property (nullable, nonatomic, strong) NSString *revenueSource;
@property (nonatomic, readonly) BOOL isAppStoreBundle;

- (instancetype)initWithJSON:(NSDictionary *)json userBundle:(BOOL)userBundle;

- (instancetype)initWithProductID:(NSString *)productID
                      productType:(nullable NSString *)productType
                      productName:(NSString *)productName
                     appProductID:(NSString *)appProductID
               subscriptionFamily:(nullable NSString *)subscriptionFamily
                    revenueSource:(nullable NSString *)revenueSource
                 isAppStoreBundle:(BOOL)isAppStoreBundle NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;
@end

typedef NSString * PRBundleProductType NS_TYPED_ENUM;
extern PRBundleProductType const PRUndefinedProductType;
// Issues date range
extern PRBundleProductType const PRPrepaidIssueDatesProductType;
// Certain number of issues
extern PRBundleProductType const PRPrepaidIssuesProductType;
// Certain issues
extern PRBundleProductType const PRPrepaidIssueDateListProductType;

@interface PRBundle : PRBaseBundle
+ (NSArray<PRBundle *> *)bundles:(NSArray<PRBundle *> *)bundles
                filteredWithCIDs:(NSSet<NSString *> *)cids
                      bundleType:(PRBundleProductType)type;
+ (NSArray<NSString *> *)appProductIDsFromBundles:(NSArray<PRBundle *> *)bundles
                                         withCIDs:(NSSet<NSString *> *)cids
                                       bundleType:(PRBundleProductType)type;
+ (nullable PRBundle *)bundles:(NSArray<PRBundle *> *)bundles
         filteredWithProductID:(NSString *)productId;

@property (nullable, nonatomic, strong) NSArray<NSString *> *CIDs;
@property (nullable, nonatomic, strong) NSSet<NSString *> *excludedCIDs;
@property (nonatomic) BOOL isUnlimited;
@property (nonatomic) BOOL isSubscription;
@property (nonatomic) BOOL isRenewable;

@end

@interface PRUserBundle: PRBaseBundle
@property (nonatomic) BOOL isTrial;

@property (nullable, nonatomic, strong, readonly) NSDate *startDate;
@property (nullable, nonatomic, strong, readonly) NSDate *finishDate;

@property (nonatomic, readonly) BOOL isActive;
@property (nonatomic, readonly) BOOL isExpired;

@property (nullable, nonatomic, strong, readonly) NSArray<NSString *> *superiorBundleIDs;

@end

@interface PRConsumableBundle : PRUserBundle
@property (nonatomic, assign) NSInteger initialBalance;
@property (nonatomic, assign) NSInteger balance;
@end

@interface PRSubscriptionBundle : PRUserBundle
@property (nonatomic, strong) NSString *userProductID;
@property (nullable, nonatomic, strong) NSDate *issueStartDate;
@property (nullable, nonatomic, strong) NSDate *issueFinishDate;
@property (nonatomic, readonly) NSDate *startDate;
@property (nonatomic, readonly) NSDate *finishDate;
@property (nonatomic, readonly) NSUInteger backIssueDays;

@property (nonatomic, readonly) NSString *localizedExpirationDate;
@property (nonatomic, readonly) NSString *localizedIntervalTillExpriration;
@end

NS_ASSUME_NONNULL_END

