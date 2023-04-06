//
//  UIViewController+Modal.h
//  PR-UI
//
//  Created by berec on 04/10/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

@import UIKit;

NS_ASSUME_NONNULL_BEGIN

@interface UIViewController (Modal)

- (void)presentViewControllerModally:(UIViewController *)viewController;
- (void)presentViewControllerModally:(UIViewController *)viewController
                  useNavigationStack:(BOOL)useNavigationStack;

- (void)presentModally;
- (void)presentModallyUsingNavigationStack:(BOOL)useNavigationStack;

- (void)presentViewController:(UIViewController *)viewController animated:(BOOL)animated dismissPresented:(BOOL)dismissPresented completion:(nullable dispatch_block_t)completion;

@end

NS_ASSUME_NONNULL_END
