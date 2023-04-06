//
//  PRSubscriptionBundle+PlanType.h
//  PR-API
//
//  Created by berec on 24/03/2020.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

@import PRAPI.PRBundle;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, PRSubscriptionPlanType) {
    PRSubscriptionPlanTypeWeekly = 7,
    PRSubscriptionPlanTypeBiWeekly = 14,
    PRSubscriptionPlanTypeMonthly = 30,
    PRSubscriptionPlanTypeQuarterly = 91,
    PRSubscriptionPlanTypeSemiAnnual = 182,
    PRSubscriptionPlanTypeAnnual = 365,
    PRSubscriptionPlanTypeCustom = 9999,
};

@interface PRSubscriptionBundle (PlanType)
@property (nonatomic, readonly) PRSubscriptionPlanType planType;

@end

NS_ASSUME_NONNULL_END
