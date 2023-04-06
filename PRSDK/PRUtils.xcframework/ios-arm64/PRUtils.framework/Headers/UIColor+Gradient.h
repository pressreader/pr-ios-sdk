//
//  UIColor+Gradient.h
//  PRiphone
//
//  Created by Jackie Cane on 2/25/13.
//  Copyright (c) 2013 NewspaperDirect. All rights reserved.
//

@import UIKit;

NS_ASSUME_NONNULL_BEGIN

@interface UIColor (PRGradient)

+ (UIColor *)verticalGradientColorWithHeight:(CGFloat)height startColor:(UIColor *)startColor endColor:(UIColor *)endColor;
+ (UIColor *)verticalGradientColorWithHeight:(CGFloat)height andColors:(NSArray<UIColor *> *)colors;

+ (UIImage *)gradientImageWithHeight:(CGFloat)height andColors:(NSArray<UIColor *> *)colors;
+ (UIImage *)gradientImageWithWidth:(CGFloat)width andColors:(NSArray<UIColor *> *)colors;

+ (UIColor *)radialGradientColorWithSize:(CGSize)size centerColor:(UIColor *)centerColor outerColor:(UIColor *)outerColor;
+ (UIImage *)radialGradientImageWithSize:(CGSize)size centerColor:(UIColor *)centerColor outerColor:(UIColor *)outerColor;

@end

NS_ASSUME_NONNULL_END
