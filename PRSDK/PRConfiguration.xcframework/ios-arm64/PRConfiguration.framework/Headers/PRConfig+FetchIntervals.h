//
//  PRConfig+FetchIntervals.h
//  PR-API
//
//  Created by berec on 27/01/2020.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import <PRConfiguration/PRConfig.h>

NS_ASSUME_NONNULL_BEGIN

@interface PRConfig (FetchIntervals)
@property (class, nonatomic, readonly) NSTimeInterval booksFetchInterval;
@property (class, nonatomic, readonly) NSTimeInterval interestsFetchInterval;
@property (class, nonatomic, readonly) NSTimeInterval catalogUpdateInterval;
@property (class, nonatomic, readonly) NSTimeInterval newsfeedUpdateInterval;

@end

NS_ASSUME_NONNULL_END
