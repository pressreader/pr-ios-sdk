//
//  PRConfig+RCU.h
//  PRSharedData
//
//  Created by Vitali Bounine on 2019-10-03.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import <PRConfiguration/PRConfig.h>

NS_ASSUME_NONNULL_BEGIN

#define CONFIG_VERSION                  _PRCONFIG_INT_(@"config_version", 0)
#define CONFIG_RUN_TIME_UPDATE_TIMEOUT  _PRCONFIG_DOUBLE_(@"CONFIG_RUN_TIME_UPDATE_TIMEOUT", 3.0)


@interface PRConfig (RCU)
@property (class, nonatomic, readonly) NSInteger configVersion;
@property (class, nonatomic) NSData *rcuHash;
@property (class, nonatomic, readonly) BOOL isRCUEnabled;
@property (class, nonatomic, readonly) NSTimeInterval rcuTimeout;

@end

NS_ASSUME_NONNULL_END
