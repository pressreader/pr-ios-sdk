//
//  PRSubscriptionService.h
//  PRAPI
//
//  Created by Ivan Berezin on 26/03/2024.
//  Copyright © 2024 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PRSubscription;

NS_ASSUME_NONNULL_BEGIN

typedef void(^_Nullable PRSimpleResult)(NSError *_Nullable error);

@interface PRSubscriptionService : NSObject

- (instancetype)initWithSubscription:(PRSubscription *)subscription;

@property (nonatomic, unsafe_unretained) PRSubscription *subscription;

@end

NS_ASSUME_NONNULL_END
