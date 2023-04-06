//
//  PRGradientLayerView.h
//  PR-UI
//
//  Created by Viacheslav Soroka on 12/22/18.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

@import UIKit;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(uint8_t, PRGradientDirection) {
    PRGradientDirectionDown,
    PRGradientDirectionUp,
    PRGradientDirectionRight,
    PRGradientDirectionLeft,
    PRGradientDirectionDownRight,
};

@interface PRGradientLayerView : UIView

/// @param colors An array of CGColorRef objects.
+ (instancetype)viewWithFrame:(CGRect)frame
                       colors:(NSArray *)colors
                    locations:(nullable NSArray<NSNumber *> *)locations
            gradientDirection:(PRGradientDirection)direction;

+ (instancetype)viewWithFrame:(CGRect)frame
                     topColor:(UIColor *)topColor
                  bottomColor:(UIColor *)bottomColor;

/// @param colors An array of CGColorRef objects.
- (instancetype)initWithFrame:(CGRect)frame
                       colors:(NSArray *)colors
                    locations:(nullable NSArray<NSNumber *> *)locations
            gradientDirection:(PRGradientDirection)direction;

- (instancetype)initWithFrame:(CGRect)frame
                     topColor:(UIColor *)topColor
                  bottomColor:(UIColor *)bottomColor;

/// @param colors An array of CGColorRef objects.
- (void)setupGrardientWithColors:(NSArray *)colors
                       locations:(nullable NSArray<NSNumber *> *)locations
               gradientDirection:(PRGradientDirection)direction;

@end

NS_ASSUME_NONNULL_END
