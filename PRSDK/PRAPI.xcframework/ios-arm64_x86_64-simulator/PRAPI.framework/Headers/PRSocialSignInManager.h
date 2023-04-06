//
//  PRSocialSignInManager.h
//  PRiphone
//
//  Created by Jackie Cane on 22/07/15.
//  Copyright (c) 2015 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PRAccountManager;

NS_ASSUME_NONNULL_BEGIN

extern NSString * const kLinkToAccountRequestType;

@interface PRSocialSignInManager : NSObject

- (instancetype)initWithAccountManager:(PRAccountManager *)accountManager;

@property (nonatomic, strong) PRAccountManager *accountManager;
@end

NS_ASSUME_NONNULL_END
