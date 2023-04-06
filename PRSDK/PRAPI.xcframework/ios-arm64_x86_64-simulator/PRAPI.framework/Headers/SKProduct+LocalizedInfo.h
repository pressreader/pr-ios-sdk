//
//  SKProduct+LocalizedInfo.h
//  PRAPI
//
//  Created by Vitali Bounine on 2022-01-24.
//  Copyright © 2022 NewspaperDirect. All rights reserved.
//

@import Foundation;
@import StoreKit;

NS_ASSUME_NONNULL_BEGIN

@interface SKProduct (LocalizedInfo)

@property (nullable, nonatomic) NSString *subscriptionBundleIdentifier;

+ (nullable NSString *)localizedPrice:(nullable NSDecimalNumber *)price withLocale:(nullable NSLocale *)locale NS_SWIFT_NAME(localizedPrice(_:locale:));

- (NSString *)localizedPrice;
- (nullable NSString *)localizedIntroPrice;
- (NSString *)localizedEligiblePrice;

- (BOOL) isSubscription;
- (BOOL) isIntroFreeTrial;

+ (nullable NSString *)localizedSubscriptionPeriodWithCalendarUnit:(NSCalendarUnit)calendarUnit numberOfUnits:(NSUInteger)numberOfUnits oneUnitPeriodDropsNumber:(BOOL)oneUnitPeriodDropsNumber;

- (nullable NSString *)localizedSubscriptionPeriod;
- (nullable NSString *)localizedOneIntroPeriod;
- (nullable NSString *)localizedTotalIntroPeriod;

@end

NS_ASSUME_NONNULL_END
