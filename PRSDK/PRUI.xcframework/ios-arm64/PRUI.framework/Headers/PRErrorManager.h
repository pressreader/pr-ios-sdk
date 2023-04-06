//
//  PRErrorManager.h
//  PRiphone
//
//  Created by Jackie Cane on 27/07/15.
//  Copyright (c) 2015 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>
 
NS_ASSUME_NONNULL_BEGIN

@interface PRErrorManager : NSObject
- (void)processAuthError:(nullable NSError *)error title:(nullable NSString *)title;
- (void)processNetworkUnlinkError:(NSError *)error;
- (void)processSubscriptionManagementError:(NSError *)error;

@end

@interface PRErrorManager(/*Protected*/)
- (void)processTooManyActivationsError:(NSError *)error;
@end

NS_ASSUME_NONNULL_END
#import "PRErrorManager+SocialSignIn.h"
