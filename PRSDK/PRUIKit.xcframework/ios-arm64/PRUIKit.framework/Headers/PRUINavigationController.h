//
//  UINavigationController.h
//  PRiphone
//
//  Created by Jackie Cane on 10/26/12.
//  Copyright (c) 2012 NewspaperDirect. All rights reserved.
//

@import UIKit;

NS_ASSUME_NONNULL_BEGIN

@interface PRUINavigationController : UINavigationController

- (instancetype)initWithRootViewController:(UIViewController *)rootViewController
                               navBarClass:(nullable Class)navBarClass
                              toolbarClass:(nullable Class)toolbarClass;

@end


@interface PRUINavigationController (/*PROTECTED*/)

+ (NSArray *)updateLeftBarButtonItems:(NSArray *)items
                    withHotZoneStatus:(NSInteger)hotZoneStatus
                              enabled:(BOOL)enabled
                    reachableAndValid:(BOOL)reachableAndValid;

@property (nonatomic, assign) BOOL popGestureDisabled;
@property (nonatomic, assign) BOOL pushAnimationInProgress;
@property (nonatomic, assign) BOOL isInteractivePopGestureInProgress;
@property (nonatomic, weak) UIViewController *willShowViewController;

@end

NS_ASSUME_NONNULL_END
