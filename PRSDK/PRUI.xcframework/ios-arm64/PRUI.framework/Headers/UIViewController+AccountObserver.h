//
//  UIViewController+AccountObserver.h
//  PRiphone
//
//  Created by Jackie Cane on 7/25/13.
//  Copyright (c) 2013 NewspaperDirect. All rights reserved.
//
//
// Given category is intended to symplify an attaching of the
// "account observer" to any view controller.
//

#import <UIKit/UIKit.h>

@protocol PRAccountObserver <NSObject>
- (void)accountDidRequestErrorNotification:(NSNotification*)notification;
- (void)accountWillAuthorizeNotification:(NSNotification*)notification;
- (void)accountDidAuthorizeNotification:(NSNotification*)notification;
- (void)accountWillDeauthorizeNotification:(NSNotification*)notification;
- (void)accountDidDeauthorizeNotification:(NSNotification*)notification;
- (void)accountServiceSelectNotification:(NSNotification*)notification;
- (void)accountInterruptAuthorisation:(NSNotification *)noteification;
@end

@protocol PRAuthorizationActivity <NSObject>
- (void)showAuthorizationActivityIndicatorWithTitle:(NSString *)title;
- (void)hideAuthorizationActivityIndicator;

@end

@protocol PRAccountUI <NSObject>
@optional
- (UITableView *)accountTableView;
- (UIButton *)authorizeButton;
- (UIActivityIndicatorView *)authorizeButtonIndicator;

@end

@protocol PRPopoverAdjustable <NSObject>
@optional
- (void)adjustPopoverSize;

@end

@interface UIViewController (AccountObserver)<PRAccountObserver, PRAuthorizationActivity, PRAccountUI, PRPopoverAdjustable>

- (void)registerAsAccountObserver;
- (void)unregisterAsAccountObserver;

@end
