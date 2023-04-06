//
//  PRSubscription+Back2ObjC.h
//  PR-API
//
//  Created by berec on 15/11/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import "PRSubscription.h"

#import <PRAPI/PRAccountItemNestedTypes.h>
@class PRPromise;

NS_ASSUME_NONNULL_BEGIN

@interface PRSubscription (Back2ObjC)

- (PRPromise *)objc_updateOnboardingStatus:(PROnboardingStatus)status;

@end

NS_ASSUME_NONNULL_END
