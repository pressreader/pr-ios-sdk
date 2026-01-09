//
//  UIColor+PRExtensions.h
//  PRiphone
//
//  Created by Viacheslav Soroka on 11/11/16.
//  Copyright © 2016 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

#define ColorWithRGB(r, g, b) ColorWithRGBA(r, g, b, 1.0)
#define ColorWithRGBA(r, g, b, a) [UIColor colorWithRed:r / 255.0 green:g / 255.0 blue:b / 255.0 alpha:a]
#define PRColorWithWhite(w) [UIColor colorWithWhite: w alpha:1]

NS_ASSUME_NONNULL_BEGIN

@interface UIColor (PRExtensions)

+ (instancetype)intermediateColorFrom:(UIColor *)from to:(UIColor *)to progress:(CGFloat)progress;

/// Supported color encoded string formats are:
/// "UIDeviceRGBColorSpace 0.5 0 0.25 1",
/// "UIDeviceWhiteColorSpace 1 1",
/// "UIExtendedGrayColorSpace 1 1",
+ (instancetype)colorWithString:(NSString *)string;

- (instancetype)colorWithBlendedColor:(UIColor *)color NS_SWIFT_NAME(blendedWith(_:));

@end

NS_ASSUME_NONNULL_END

#import <PRUtils/UIColor+Hex.h>
