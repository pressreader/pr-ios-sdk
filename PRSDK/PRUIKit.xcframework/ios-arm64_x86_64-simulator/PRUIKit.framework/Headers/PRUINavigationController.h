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

- (instancetype)initWithViewControllers:(NSArray<UIViewController *> *)viewControllers;

@end


@interface PRUINavigationController (/*PROTECTED*/)

+ (NSArray *)updateLeftBarButtonItems:(NSArray *)items
                              hotzone:(BOOL)hotzone
                              enabled:(BOOL)enabled
                    reachableAndValid:(BOOL)reachableAndValid;

@property (nonatomic, assign) BOOL popGestureDisabled;
@property (nonatomic, assign) BOOL pushAnimationInProgress;
@property (nonatomic, weak) UIViewController *willShowViewController;

@end

NS_ASSUME_NONNULL_END
