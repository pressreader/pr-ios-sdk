//
//  PRSubscription+Error.h
//  PRAPI
//
//  Created by Viacheslav Soroka on 12/11/20.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import "PRSubscription.h"

@import PRUtils.PRErrorProvider;

NS_ASSUME_NONNULL_BEGIN

extern NSErrorDomain const PRRSubscriptionErrorDomain;
typedef NS_ERROR_ENUM(PRRSubscriptionErrorDomain, PRSubscriptionError) {
    PRSubscriptionErrorUnknown,
    PRSubscriptionErrorDownloadLicenseRequestFailed,
    PRSubscriptionErrorMethodNotSupported,
    PRSubscriptionErrorLocalServerPriority,
    PRSubscriptionErrorInvalidSubscription
};

@interface PRSubscription (Error) <PRErrorProvider>

+ (NSError *)errorWithCode:(PRSubscriptionError)code description:(nullable NSString *)description;
- (NSError *)errorWithCode:(PRSubscriptionError)code description:(nullable NSString *)description;

@end

NS_ASSUME_NONNULL_END
