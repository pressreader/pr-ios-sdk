//
//  PRUINavigationController+Presentation.h
//  PRiphone
//
//  Created by Viacheslav Soroka on 9/9/17.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

@import UIKit;

NS_ASSUME_NONNULL_BEGIN

@interface UINavigationController (Presentation)
@property (nonatomic, readonly) __kindof UINavigationController *topNavigationController;

- (void)pushViewControllerOnTop:(UIViewController *)controller animated:(BOOL)animated;
- (void)pushViewControllerOnTop:(UIViewController *)controller animated:(BOOL)animated completion:(nullable void(^)(void))completion;
- (void)presentViewControllerOnTop:(UIViewController *)controller animated:(BOOL)animated;
- (void)presentViewControllerOnTop:(UIViewController *)controller animated:(BOOL)animated completion:(nullable void(^)(void))completion;
- (void)presentViewControllerOnTop:(UIViewController *)controller
    embeddedInNavigationController:(BOOL)embedded
                          animated:(BOOL)animated;

- (void)presentViewControllerOnTop:(UIViewController *)controller
    embeddedInNavigationController:(BOOL)embedded
                          animated:(BOOL)animated
                        completion:(nullable void(^)(void))completion;

- (void)popViewControllerFromTopAnimated:(BOOL)animated;
- (void)popViewControllerFromTopAnimated:(BOOL)animated completion:(nullable void(^)(void))completion;
- (void)popDiscardableControllersAnimated:(BOOL)animated;
- (void)popDiscardableControllersAnimated:(BOOL)animated completion:(nullable void(^)(void))completion;

@end

NS_ASSUME_NONNULL_END
