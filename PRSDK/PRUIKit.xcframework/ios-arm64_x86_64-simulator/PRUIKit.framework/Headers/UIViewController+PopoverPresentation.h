//
//  UIViewController+PopoverPresentation.h
//  PRUI
//
//  Created by berec on 20/02/2020.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIViewController (PopoverPresentation)

- (void)setupDefaultPopoverWithSourceView:(UIView *)view sourceRect:(CGRect)rect;
- (void)setupDefaultPopoverWithBarButtonItem:(UIBarButtonItem *)item;

@end

@interface UIPopoverPresentationController (Delegate) <UIPopoverPresentationControllerDelegate>

- (void)setupDefault;

@property (nullable, nonatomic, copy) void(^dismissPopoverHandler)(void);

@end

NS_ASSUME_NONNULL_END
