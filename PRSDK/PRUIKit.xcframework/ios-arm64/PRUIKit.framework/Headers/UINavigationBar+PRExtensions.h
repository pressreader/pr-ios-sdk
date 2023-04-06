//
//  UINavigationBar+PRExtensions.h
//  PR-UI
//
//  Created by Viacheslav Soroka on 9/28/18.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

@import UIKit;

NS_ASSUME_NONNULL_BEGIN

@interface UINavigationBar (PRExtensions)

- (void)setBarBackgroundAlpha:(CGFloat)alpha;

/// light bottom line at the bottom of nav.bar
@property (nonatomic, readonly) UIImageView *hairline;

@property (nonatomic, readonly) BOOL animationInProgress;
@property (nonatomic) UIBlurEffectStyle blurEffectStyle;

@end

NS_ASSUME_NONNULL_END
