//
//  PRDismissOnSwipeActor.h
//  PR-UI
//
//  Created by Viacheslav Soroka on 12/21/17.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "NTFDataSource.h"

NS_ASSUME_NONNULL_BEGIN

@interface PRDismissOnSwipeActor : NSObject
@property (nonatomic, assign) BOOL dismissOnSwipeUp;
@property (nonatomic, assign) BOOL dismissOnSwipeDown;

/// Speed in points per millisecond
@property (nonatomic, assign) CGFloat swipeDownMinimalSpeed;

/// Speed in points per millisecond
@property (nonatomic, assign) CGFloat swipeUpMinimalSpeed;

@property (nonatomic, assign) BOOL horizontalSwipeDisabled;

@property (nonatomic, readonly) BOOL dismissInProgress;

@property (nullable, nonatomic, readonly) UIPercentDrivenInteractiveTransition *dismissInteractor;
@property (nonatomic, readonly) id<UIViewControllerAnimatedTransitioning> animationController;

@property (nullable, nonatomic, weak) UIScrollView *scrollView;
@property (nullable, nonatomic, weak) NTFDataSource * dataSource;

- (instancetype)initWithVC:(UIViewController<UIViewControllerTransitioningDelegate> *)vc;

- (void)onViewDidAppear;
- (void)onScrollViewWillBeginDragging:(UIScrollView *)scrollView;
- (void)onScrollViewDidScroll:(UIScrollView *)scrollView;
- (void)onScrollViewDidEndDecelerating:(UIScrollView *)scrollView;

@end

NS_ASSUME_NONNULL_END
