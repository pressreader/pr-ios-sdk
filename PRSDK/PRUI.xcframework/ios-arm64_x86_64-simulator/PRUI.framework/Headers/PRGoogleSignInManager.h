//
//  PRGoogleSignInManager.h
//  PRSocialManagers
//
//  Created by Viacheslav Soroka on 2022-02-28.
//  Copyright © 2022 NewspaperDirect. All rights reserved.
//

#import "_PRSocialManager.h"

NS_ASSUME_NONNULL_BEGIN

@class GoogleSignInResult;

@interface PRGoogleSignInManager : _PRSocialManager

+ (instancetype)shared;

- (void)signIn:(void(^)(GoogleSignInResult *))completion NS_SWIFT_NAME(signIn(_:));

@end

NS_ASSUME_NONNULL_END
