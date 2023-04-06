//
//  PRSplashScreenView.h
//  PR-UI
//
//  Created by Viacheslav Soroka on 8/13/19.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

extern NSNotificationName const PRSplashAnimationWillFinishNotification;
extern NSNotificationName const PRSplashAnimationDidFinishNotification;

@interface PRSplashScreenView : UIView

- (void)startPresentationWithCompletion:(void(^)(void))completion;
- (void)showLoadingView;

@property (nonatomic, readonly) BOOL splashAnimationFinished;

@end

NS_ASSUME_NONNULL_END
