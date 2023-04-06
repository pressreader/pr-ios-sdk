//
//  PRPromise+Timeout.h
//  PRPromiseKit
//
//  Created by Vitali Bounine on 2019-06-05.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import <PRPromiseKit/PRPromise.h>

NS_ASSUME_NONNULL_BEGIN

@interface PRPromise (Timeout)

+ (instancetype)promiseWithTimeout:(NSTimeInterval)timeInterval;

@end

NS_ASSUME_NONNULL_END
