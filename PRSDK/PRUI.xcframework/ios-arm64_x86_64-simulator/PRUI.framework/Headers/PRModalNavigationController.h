//
//  PRModalNavigationController.h
//  PRiphone
//
//  Created by berec on 7/11/16.
//  Copyright © 2016 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSUInteger, PRModalNavigationControllerOption) {
    PRModalNavigationControllerOptionNone = 0,
    PRModalNavigationControllerOptionTopControllerOverridesRotationRules = 1 << 0,
    PRModalNavigationControllerOptionTopControllerOverridesStatusBarStyle = 1 << 1,
    PRModalNavigationControllerOptionTopControllerOverridesStatusBarHidden = 1 << 2,
};

@interface PRModalNavigationController : UIViewController

- (instancetype)initWithRootViewController:(UIViewController *)rootViewController
                                   options:(PRModalNavigationControllerOption)options;
- (instancetype)initWithRootViewController:(UIViewController *)rootViewController;

@property (nullable, nonatomic, readonly) UIViewController *rootViewController;

@end


@interface PRModalNavigationController (UINavigationController)
- (void)pushViewController:(UIViewController *)viewController animated:(BOOL)animated; // Uses a horizontal slide transition. Has no effect if the view controller is already in the stack.

- (nullable UIViewController *)popViewControllerAnimated:(BOOL)animated; // Returns the popped controller.
- (nullable NSArray<__kindof UIViewController *> *)popToViewController:(UIViewController *)viewController animated:(BOOL)animated; // Pops view controllers until the one specified is on top. Returns the popped controllers.
- (nullable NSArray<__kindof UIViewController *> *)popToRootViewControllerAnimated:(BOOL)animated; // Pops until there's only a single view controller left on the stack. Returns the popped controllers.

@property(nullable, nonatomic,readonly,strong) UIViewController *topViewController; // The top view controller on the stack.
@property(nullable, nonatomic,readonly,strong) UIViewController *visibleViewController; // Return modal view controller if it exists. Otherwise the top view controller.

@property(nonatomic,copy) NSArray<__kindof UIViewController *> *viewControllers; // The current view controller stack.

- (void)setViewControllers:(NSArray<UIViewController *> *)viewControllers animated:(BOOL)animated NS_AVAILABLE_IOS(3_0); // If animated is YES, then simulate a push or pop depending on whether the new top view controller was previously in the stack.

@property(nonatomic,getter=isNavigationBarHidden) BOOL navigationBarHidden;
- (void)setNavigationBarHidden:(BOOL)hidden animated:(BOOL)animated; // Hide or show the navigation bar. If animated, it will transition vertically using UINavigationControllerHideShowBarDuration.
@property(nonatomic,readonly) UINavigationBar *navigationBar; // The navigation bar managed by the controller. Pushing, popping or setting navigation items on a managed navigation bar is not supported.

@property(nonatomic,getter=isToolbarHidden) BOOL toolbarHidden NS_AVAILABLE_IOS(3_0) __TVOS_PROHIBITED; // Defaults to YES, i.e. hidden.
- (void)setToolbarHidden:(BOOL)hidden animated:(BOOL)animated NS_AVAILABLE_IOS(3_0) __TVOS_PROHIBITED; // Hide or show the toolbar at the bottom of the screen. If animated, it will transition vertically using UINavigationControllerHideShowBarDuration.
@property(null_resettable,nonatomic,readonly) UIToolbar *toolbar NS_AVAILABLE_IOS(3_0) __TVOS_PROHIBITED; // For use when presenting an action sheet.

//@property(nullable, nonatomic, weak) id<UINavigationControllerDelegate> delegate;
@property(nullable, nonatomic, readonly) UIGestureRecognizer *interactivePopGestureRecognizer NS_AVAILABLE_IOS(7_0) __TVOS_PROHIBITED;

- (void)showViewController:(UIViewController *)vc sender:(nullable id)sender NS_AVAILABLE_IOS(8_0); // Interpreted as pushViewController:animated:

/// When the keyboard appears, the navigation controller's navigationBar toolbar will be hidden. The bars will remain hidden when the keyboard dismisses, but a tap in the content area will show them.
@property (nonatomic, readwrite, assign) BOOL hidesBarsWhenKeyboardAppears NS_AVAILABLE_IOS(8_0) __TVOS_PROHIBITED;
/// When the user swipes, the navigation controller's navigationBar & toolbar will be hidden (on a swipe up) or shown (on a swipe down). The toolbar only participates if it has items.
@property (nonatomic, readwrite, assign) BOOL hidesBarsOnSwipe NS_AVAILABLE_IOS(8_0) __TVOS_PROHIBITED;
/// The gesture recognizer that triggers if the bars will hide or show due to a swipe. Do not change the delegate or attempt to replace this gesture by overriding this method.
@property (nonatomic, readonly, strong) UIPanGestureRecognizer *barHideOnSwipeGestureRecognizer NS_AVAILABLE_IOS(8_0) __TVOS_PROHIBITED;
/// When the UINavigationController's vertical size class is compact, hide the UINavigationBar and UIToolbar. Unhandled taps in the regions that would normally be occupied by these bars will reveal the bars.
@property (nonatomic, readwrite, assign) BOOL hidesBarsWhenVerticallyCompact NS_AVAILABLE_IOS(8_0) __TVOS_PROHIBITED;
/// When the user taps, the navigation controller's navigationBar & toolbar will be hidden or shown, depending on the hidden state of the navigationBar. The toolbar will only be shown if it has items to display.
@property (nonatomic, readwrite, assign) BOOL hidesBarsOnTap NS_AVAILABLE_IOS(8_0) __TVOS_PROHIBITED;
/// The gesture recognizer used to recognize if the bars will hide or show due to a tap in content. Do not change the delegate or attempt to replace this gesture by overriding this method.
@property (nonatomic, readonly, assign) UITapGestureRecognizer *barHideOnTapGestureRecognizer NS_AVAILABLE_IOS(8_0) __TVOS_PROHIBITED;
@end

NS_ASSUME_NONNULL_END
