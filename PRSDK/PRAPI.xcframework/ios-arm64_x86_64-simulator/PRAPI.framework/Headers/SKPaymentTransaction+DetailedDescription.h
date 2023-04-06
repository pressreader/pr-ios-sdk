//
//  SKPaymentTransaction+DetailedDescription.h
//  PRAPI
//
//  Created by Vitali Bounine on 2022-01-24.
//  Copyright © 2022 NewspaperDirect. All rights reserved.
//

@import Foundation;
#import <StoreKit/StoreKit.h>

@class AppReceipt, AppReceiptIAP;

NS_ASSUME_NONNULL_BEGIN

@interface SKPaymentTransaction (DetailedDescription)

@property (nonatomic, readonly) NSData * receiptData;
@property (nonatomic, readonly) AppReceiptIAP *receipt;
@property (nonatomic) BOOL validating;
@property (nonatomic) NSInteger validationStatus;

@end

NS_ASSUME_NONNULL_END
