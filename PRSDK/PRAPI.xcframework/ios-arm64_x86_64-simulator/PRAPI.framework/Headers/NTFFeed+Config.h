//
//  NTFFeed+Config.h
//  PR-API
//
//  Created by berec on 14/11/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import "NTFFeed+CoreDataClass.h"

NS_ASSUME_NONNULL_BEGIN

@interface NTFFeed (Config)
@property (class, nonatomic, readonly) BOOL isAuthorizationRequiredToRead;
@property (class, nonatomic, readonly) BOOL isSubscriptionRequiredToRead;
@end

NS_ASSUME_NONNULL_END
