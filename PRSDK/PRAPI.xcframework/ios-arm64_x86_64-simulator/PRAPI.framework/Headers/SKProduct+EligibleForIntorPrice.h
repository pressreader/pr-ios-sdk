//
//  SKProduct+EligibleForIntorPrice.h
//  PRAPI
//
//  Created by Vitali Bounine on 2022-01-24.
//  Copyright © 2022 NewspaperDirect. All rights reserved.
//

@import Foundation;
@import StoreKit;

NS_ASSUME_NONNULL_BEGIN

@interface SKProduct (EligibleForIntroPrice)

@property (nonatomic, readonly) BOOL eligibleForIntoPrice NS_SWIFT_NAME(isEligibleForIntoPrice);
@property (nonatomic, readonly) NSDecimalNumber *eligiblePrice;

@end


NS_ASSUME_NONNULL_END
