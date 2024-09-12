//
//  UIViewController+Popover.h
//  PR-UI
//
//  Created by berec on 24/06/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSUInteger, PRPopoverOption) {
    PRPopoverOptionUseNavigationStack = 1 << 0,
    PRPopoverOptionDisableAdaptivePresentation = 1 << 1
};

@interface UIViewController (Popover)

- (void)presentViewControllerInPopover:(UIViewController *)viewController
                               options:(PRPopoverOption)options
                        dismissHandler:(void(^_Nullable)(void))dismissHandler
NS_SWIFT_NAME(presentInPopover(_:options:dismissHandler:));

- (void)presentViewControllerInPopover:(UIViewController *)viewController
                        dismissHandler:(void(^_Nullable)(void))dismissHandler
NS_SWIFT_NAME(presentInPopover(_:dismissHandler:));

- (void)presentInPopoverWithOptions:(PRPopoverOption)options
                     dismissHandler:(void(^_Nullable)(void))dismissHandler
NS_SWIFT_NAME(presentInPopover(options:dismissHandler:));

- (void)presentInPopoverWithDismissHandler:(void(^_Nullable)(void))dismissHandler;

- (void)presentViewControllerInPopover:(UIViewController *)vc
                                anchor:(id)sender
              permittedArrowDirections:(UIPopoverArrowDirection)permittedArrowDirections
                    useNavigationStack:(BOOL)useNavigationStack
NS_SWIFT_NAME(presentInPopover(_:anchor:permittedArrowDirections:useNavigationStack:));

- (void)dismissPopoverAnimated:(BOOL)animated completion:(void(^_Nullable)(void))completion;

- (void)resizePopover;
- (void)resizePopoverAnimated:(BOOL)animated;

@property (nonatomic, readonly) BOOL isInPopover;
@property (nonatomic, readonly) BOOL isActuallyInPopover;
@property (nonatomic, readonly) UIEdgeInsets popoverLayoutMargins;

@property (class, nonatomic, readonly) CGFloat defaultPopoverWidth;

@end

NS_ASSUME_NONNULL_END
