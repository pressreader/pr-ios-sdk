//
//  UINavigationItem+Title.h
//  PR-UI
//
//  Created by Viacheslav Soroka on 3/7/19.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

@import UIKit;
@import PRAccessibility;

NS_ASSUME_NONNULL_BEGIN

extern const CGFloat kPRRegularNavigationBarMastheadHeight;
extern const CGFloat kPRCompactNavigationBarMastheadHeight;

@interface UINavigationItem (Title)

@property (nullable, nonatomic, readonly) NSString *titleText;
@property (nullable, nonatomic, readonly) NSString *subtitleText;

- (void)setTitle:(nullable NSString *)title subtitle:(nullable NSString *)subtitle;
- (void)setTitleView:(UIView *)view subtitle:(nullable NSString *)subtitle;

- (void)updateTitleViewWithImage:(nullable UIImage *)image
                      largeImage:(nullable UIImage *)largeImage;

- (void)updateTitleViewWithImage:(nullable UIImage *)image
                        subtitle:(nullable NSString *)subtitle;

@end

NS_ASSUME_NONNULL_END
