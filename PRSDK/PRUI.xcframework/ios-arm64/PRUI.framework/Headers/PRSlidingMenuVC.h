//
//  PRSlideMenuVC.h
//  PRiphone
//
//  Created by Oleg Stepanenko on 18.10.12.
//  Copyright (c) 2012 NewspaperDirect. All rights reserved.
//

#import "PRMenuVC.h"

NS_ASSUME_NONNULL_BEGIN

@interface PRSlidingMenuVC : UIViewController<PRMenuVCDelegate>

/// View controller that is presented above the other view controllers.
@property (nullable, nonatomic, strong) UIViewController *topVC;
@property (nullable, nonatomic, strong, readonly) UIView *contentView;
@property (nullable, nonatomic, readonly) UIView *topView;
@property (nullable, nonatomic, strong) PRMenuVC *menuVC;
@property (nonatomic, readonly) CGFloat menuSize;
@property (nonatomic, readonly) CGFloat visibleMenuSize;
@property (nonatomic, getter=isMenuMoving, readonly) BOOL menuMoving;
@property (nonatomic) BOOL moreItemsToBeShown;
@property (nonatomic, getter=isCollapsible) BOOL collapsible;

- (BOOL)isMenuShown;
- (CGFloat)percentMenuShown;
- (void)menuWillAppear;
- (void)menuWillHide;
- (void)menuDidAppear;
- (void)menuDidHide;

- (void)showMenuAnimated:(BOOL)animated;
- (void)hideMenuAnimated:(BOOL)animated;

@end

NS_ASSUME_NONNULL_END
