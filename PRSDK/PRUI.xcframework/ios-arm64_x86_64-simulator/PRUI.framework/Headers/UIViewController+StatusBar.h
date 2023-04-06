//
//  UIViewController+StatusBar.h
//  PR-UI
//
//  Created by berec on 24/06/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIViewController (StatusBar)

- (void)setStatusBarHidden:(BOOL)hidden;
- (void)setStatusBarHidden:(BOOL)hidden animated:(BOOL)animated;

@property (nonatomic, readonly) BOOL hideStatusBar;
@property (nonatomic, readonly) BOOL prefersStatusBarHiddenWithNavigationBarSynchroniser;

@end

NS_ASSUME_NONNULL_END
