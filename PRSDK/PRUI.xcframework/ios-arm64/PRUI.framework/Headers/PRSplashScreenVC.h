//
//  PRSplashScreenVC.h
//  PRiphone
//
//  Created by Oleg Stepanenko on 08.10.12.
//  Copyright (c) 2012 NewspaperDirect. All rights reserved.
//

@import PRUIKit.PRVC;
#import "PRSplashScreenView.h"

NS_ASSUME_NONNULL_BEGIN

extern NSNotificationName const PRSplashScreenNotification;

@interface PRSplashScreenVC : PRVC

- (void)showInView:(UIView *)mainView;

@property (nullable, nonatomic, readonly) PRSplashScreenView *rootView;

@end

NS_ASSUME_NONNULL_END
