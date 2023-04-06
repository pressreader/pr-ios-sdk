//
//  UIViewController+Popover.h
//  PR-UI
//
//  Created by berec on 24/06/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIViewController (Popover)

- (void)presentViewControllerInPopover:(UIViewController *)viewController
                    useNavigationStack:(BOOL)useNavigationStack
                        dismissHandler:(void(^)(void))dismissHandler;

- (void)presentViewControllerInPopover:(UIViewController *)viewController
                        dismissHandler:(void(^_Nullable)(void))dismissHandler NS_SWIFT_NAME(presentInPopover(_:dismissHandler:));

- (void)presentInPopoverWithDismissHandler:(void(^_Nullable)(void))dismissHandler;

- (void)presentInPopoverUsingNavigationStack:(BOOL)usingNavigationStack
                              dismissHandler:(void(^_Nullable)(void))dismissHandler;

- (void)presentViewControllerInPopover:(UIViewController *)vc
                                anchor:(id)sender
              permittedArrowDirections:(UIPopoverArrowDirection)permittedArrowDirections
                    useNavigationStack:(BOOL)useNavigationStack NS_SWIFT_NAME(presentInPopover(_:anchor:permittedArrowDirections:useNavigationStack:)) ;

- (void)dismissPopoverAnimated:(BOOL)animated completion:(void(^_Nullable)(void))completion;

- (void)resizePopover;
- (void)resizePopoverAnimated:(BOOL)animated;

@property (nonatomic, readonly) BOOL isInPopover;
@property (nonatomic, readonly) BOOL isActuallyInPopover;
@property (nonatomic, readonly) UIEdgeInsets popoverLayoutMargins;

@property (class, nonatomic, readonly) CGFloat defaultPopoverWidth;

@end

NS_ASSUME_NONNULL_END
