//
//  PROrderDelivery+Error.h
//  PRUtils
//
//  Created by Viacheslav Soroka on 12/11/20.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import "PROrderDelivery.h"

@import PRUtils.PRErrorProvider;

NS_ASSUME_NONNULL_BEGIN

extern NSErrorDomain const PROrderDeliveryErrorDomain;
typedef NS_ERROR_ENUM(PROrderDeliveryErrorDomain, PROrderDeliveryError) {
    PROrderDeliveryErrorInvalidAccount,
    PROrderDeliveryErrorInvalidSubscription,
    PROrderDeliveryErrorServiceUnavailable
};

@interface PROrderDelivery (Error) <PRErrorProvider>

+ (NSError *)errorWithCode:(PROrderDeliveryError)code description:(nullable NSString *)description;
- (NSError *)errorWithCode:(PROrderDeliveryError)code description:(nullable NSString *)description;

@end

NS_ASSUME_NONNULL_END
