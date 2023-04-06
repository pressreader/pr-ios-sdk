//
//  UIViewController+Child.h
//  PR-UI
//
//  Created by berec on 02/08/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIViewController (Child)
- (void)addChild:(UIViewController *)child containerView:(nullable UIView *)view;
- (void)removeChild:(UIViewController *)child;

@end

NS_ASSUME_NONNULL_END
