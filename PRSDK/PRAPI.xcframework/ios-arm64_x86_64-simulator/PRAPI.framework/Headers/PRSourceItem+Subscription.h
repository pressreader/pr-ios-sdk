//
//  PRSourceItem+Subscription.h
//  PRiphone
//
//  Created by Jackie Cane on 26/02/14.
//  Copyright (c) 2014 NewspaperDirect. All rights reserved.
//

#import "PRSourceItem.h"

NS_ASSUME_NONNULL_BEGIN

@interface PRSourceItem (Subscription)

- (BOOL)isLinkedToSubscription:(PRSubscription *)subscription;
- (void)linkSubscription:(PRSubscription *)subscription;
- (void)unlinkSubscription:(PRSubscription *)subscription;

- (PRSubscription *)defaultSubscriptionAmongSubscriptions:(NSArray *)subscriptions;

/// defaultSubscription can be nil when object can not make decision which is preferable
@property (nullable, nonatomic, readonly) PRSubscription *defaultSubscription;

/// sourceItem can be linked to more then one subscription
@property (nonatomic, readonly) NSArray<PRSubscription *> *linkedSubscriptions;

@end

NS_ASSUME_NONNULL_END
