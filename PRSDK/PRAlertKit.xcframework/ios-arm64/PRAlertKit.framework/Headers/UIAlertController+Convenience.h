//
//  UIAlertController+Convenience.h
//  ExternalSources
//
//  Created by Vitali Bounine on 2016-04-19.
//  Copyright © 2016 ND. All rights reserved.
//
//  Covneniently adds presentation methods for UIAlertController for both compact and regular size environments

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIAlertAction (Convenience)
+ (instancetype)actionWithTitle:(nullable NSString *)title handler:(void (^ __nullable)(UIAlertAction *action))handler;
@end

@interface UIAlertController (Convenience)

// Convenience initializers
+ (instancetype)actionSheetWithTitle:(nullable NSString *)title;
+ (instancetype)alertWithTitle:(nullable NSString *)title message:(nullable NSString *)message NS_SWIFT_NAME(alert(title:message:));

// Convenience. Presents a simple modal alert. Can be dismissed only by dismissViewController method
// Will use the root view controller if `controller` is nil.
+ (instancetype)presentAlertWithTitle:(nullable NSString *)title
                              message:(nullable NSString *)message
                           controller:(nullable UIViewController *)controller;

+ (instancetype)presentAlertWithTitle:(nullable NSString *)title
                              message:(nullable NSString *)message
                           controller:(nullable UIViewController *)controller
                             animated:(BOOL)animated
                           completion:(void (^__nullable)(void))completion;

// Convenience. Presents a simple alert with a "Dismiss" button.
// Will use the root view controller if `controller` is nil.
// Will use the ok if `cancelButtonTitle` is nil.
+ (instancetype)presentDismissableAlertWithTitle:(nullable NSString *)title
                                         message:(nullable NSString *)message
                               cancelButtonTitle:(nullable NSString *)cancelButtonTitle
                                      controller:(nullable UIViewController *)controller
                                       dismissed:(void (^__nullable)(void))completion;

+ (instancetype)presentDismissableAlertWithTitle:(nullable NSString *)title
                                         message:(nullable NSString *)message
                               cancelButtonTitle:(nullable NSString *)cancelButtonTitle
                                      controller:(nullable UIViewController *)controller;

+ (instancetype)presentDismissableAlertWithTitle:(nullable NSString *)title
                                         message:(nullable NSString *)message;


// Variant that will present an error.
+ (instancetype)presentDismissableAlertWithTitle:(nullable NSString *)title
                                           error:(nullable NSError *)error
                               cancelButtonTitle:(nullable NSString *)cancelButtonTitle
                                      controller:(nullable UIViewController *)controller;

+ (instancetype)presentDismissableAlertWithTitle:(nullable NSString *)title
                                           error:(nullable NSError *)error
                               cancelButtonTitle:(nullable NSString *)cancelButtonTitle
                                      controller:(nullable UIViewController *)controller
                                       dismissed:(void (^ __nullable)(void))completion;

// Presentation and dismissal
// sender can be either UIBarButtonItem, UIView, NSValue with CGRectValue or otherwise including nil controller.view
// controller is preseting view controller or app's root view controller if nil
- (void)showWithSender:(nullable id)sender controller:(nullable UIViewController *)controller animated:(BOOL)animated completion:(void (^ __nullable)(void))completion;
- (void)showWithSender:(nullable id)sender arrowDirection:(UIPopoverArrowDirection)arrowDirection controller:(nullable UIViewController *)controller animated:(BOOL)animated completion:(void (^ __nullable)(void))completion;
- (void)showWithCompletion:(void (^ __nullable)(void))completion;
- (void)show;

@end

@interface UIAlertController (ContentView)

typedef void (^ AlertContentViewConfigurationHandler)(UIView *contentView);

- (void)addContentViewWithConfigurationHandler:(AlertContentViewConfigurationHandler)configurationHandler;
@property (nullable, nonatomic, readonly) NSArray<__kindof UIView *> *contentViews;

@end

@interface UIAlertController (ModalActivity)

+ (instancetype) activityAlertWithTitle:(nullable NSString *)title message:(nullable NSString *)message;

+ (instancetype) presentActivityAlertWithTitle:(nullable NSString *)title message:(nullable NSString *)message controller:(nullable UIViewController *)controller;

@end

@interface UIAlertController (Options)

- (void) addOptionWithConfigurationHandler:(void (^)(UILabel *label, UISwitch *switchView))configurationHandler;

@end

NS_ASSUME_NONNULL_END

