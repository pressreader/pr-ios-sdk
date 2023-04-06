//
//  PRUINavigationController+Presentation.h
//  PRiphone
//
//  Created by Viacheslav Soroka on 9/9/17.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

@import UIKit;

NS_ASSUME_NONNULL_BEGIN

@protocol PRDiscardableViewController

- (BOOL)isDiscardableFromTopOfNavigation;

@end

@interface UINavigationController (Presentation)
@property (nonatomic, readonly) __kindof UINavigationController *topNavigationController;

- (void)pushViewControllerOnTop:(UIViewController *)controller animated:(BOOL)animated;
- (void)presentViewControllerOnTop:(UIViewController *)controller animated:(BOOL)animated;
- (void)presentViewControllerOnTop:(UIViewController *)controller enbeddedInNavigationController:(BOOL)embedded animated:(BOOL)animated;

- (void)popViewControllerFromTopAnimated:(BOOL)animated completion:(void(^)(void))completion;
- (void)popDiscardableControllersAnimated:(BOOL)animated;

@end

NS_ASSUME_NONNULL_END
