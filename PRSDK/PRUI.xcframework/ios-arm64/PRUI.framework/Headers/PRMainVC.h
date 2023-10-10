//
//  PRMainVC.h
//  PRiphone
//
//  Created by Oleg Stepanenko on 24.09.12.
//  Copyright (c) 2012 Newspaperdirect. All rights reserved.
//

#import "PRSlidingMenuVC.h"

#import "PRAppMenu.h"
#import "PRTooltipDelegate.h"
#import "PRSplashScreenVC.h"

NS_ASSUME_NONNULL_BEGIN

@class PRAccountItem;
@class PRPromise;

@interface PRMainVC : PRSlidingMenuVC<PRTooltipVCProtocol>

- (void)presentEditAccount:(PRAccountItem *)accountItem;

@property(null_resettable, nonatomic,strong) UIView *view NS_UNAVAILABLE;

@property (nonatomic, readonly) PRPromise *finishSplashAnimation;
@property (nonatomic, readonly) BOOL isSplashScreenHidden;

@end

NS_ASSUME_NONNULL_END

#import "UIViewController+PRMainVC.h"
#import "PRBaseMainVC+Size.h"
