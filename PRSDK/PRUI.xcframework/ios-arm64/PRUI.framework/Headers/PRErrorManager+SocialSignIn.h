//
//  PRErrorManager+SocialSignIn.h
//  PR-UI
//
//  Created by berec on 05/10/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import "PRErrorManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface PRErrorManager (SocialSignIn)
- (void)processSocialSignInError:(NSError *)error;

@end

NS_ASSUME_NONNULL_END
