//
//  PRTitleItem+Subscription.h
//  PRiphone
//
//  Created by Jackie Cane on 26/02/14.
//  Copyright (c) 2014 NewspaperDirect. All rights reserved.
//

#import <PRAPI/PRTitleItem.h>

NS_ASSUME_NONNULL_BEGIN

@interface PRTitleItem (Subscription)

- (BOOL)isLinkedToSubscription:(PRSubscription *)subscription;
- (void)linkSubscription:(PRSubscription *)subscription;
- (void)unlinkSubscription:(PRSubscription *)subscription;

/// sourceItem can be linked to more then one subscription
@property (nonatomic, readonly) NSArray<PRSubscription *> *linkedSubscriptions;

@end

NS_ASSUME_NONNULL_END
