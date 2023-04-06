//
//  PROrderConfig.h
//  PR-API
//
//  Created by Viacheslav Soroka on 3/19/19.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(uint8_t, PROrderInfoBarBylineStyle) {
    PROrderInfoBarBylineStyleDefault = 0,
    PROrderInfoBarBylineStyleDate
};

typedef NS_ENUM(uint8_t, PROrderSupplementsSortingOrder) {
    PROrderSupplementsSortingOrderDefault = 0,
    PROrderSupplementsSortingOrderReverseChronological
};

@interface PROrderConfig : NSObject
@property (nonatomic, readonly) PROrderInfoBarBylineStyle infoBarBylineStyle;
@property (nonatomic, readonly, getter=isAppMenuAllowed) BOOL appMenuAllowed;
@property (nonatomic, readonly) BOOL goPremiumPaymentFlow;
@property (nonatomic, readonly) BOOL reportPurchasesToBranch;
@property (nonatomic, readonly) BOOL showCIDsForPaymentFlow;
@property (nonatomic, readonly) BOOL showPublicationDetailsView;
@property (nonatomic, readonly) NSInteger maxNumberOfCIDsToShowLatestIssues;
@property (nonatomic, readonly) PROrderSupplementsSortingOrder supplementsOrder;
@property (nonatomic, readonly) BOOL simulateTimeLimitedLicense;

@end

NS_ASSUME_NONNULL_END
