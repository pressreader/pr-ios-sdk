//
//  UIViewController+PRMainVC.h
//  PR-UI
//
//  Created by berec on 24/09/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

@class PRMainVC;

NS_ASSUME_NONNULL_BEGIN

@protocol PRMenuDelegate <NSObject>
- (void)menuWillAppear;
- (void)menuWillHide;
- (void)menuDidAppear;
- (void)menuDidHide;
@optional
- (BOOL)isAppMenuCollapsible;
@end

@interface UIViewController (PRMainVC) <PRMenuDelegate>

- (BOOL)asTopWillAppear;
- (void)asTopDidAppear;
- (BOOL)asTopWillHide;
- (void)asTopDidHide;

// App Menu
- (void)showAppMenu:(BOOL)show animated:(BOOL)animated;
- (void)toggleAppMenu:(BOOL)animated;

// Scrolling
- (void)willBeginDragging:(UIScrollView *)scrollView;
- (void)didEndDragging:(UIScrollView *)scrollView willDecelerate:(BOOL)decelerate;
- (void)movedBy:(UIScrollView *)scrollView;
- (void)movedBy:(UIScrollView *)scrollView withCoefficient:(CGFloat)coefficient;
- (void)movedBy:(UIScrollView *)scrollView withCoefficient:(CGFloat)coefficient forceMoveWhenSwipeUp:(BOOL)shouldMoveWhenSwipeUp;

@end

NS_ASSUME_NONNULL_END
