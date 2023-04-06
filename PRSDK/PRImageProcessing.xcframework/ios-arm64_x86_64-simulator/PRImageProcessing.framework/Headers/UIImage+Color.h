//
//  UIImage+Color.h
//  PRiphone
//
//  Created by Viacheslav Soroka on 11/8/16.
//  Copyright © 2016 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIImage (Color)

+ (instancetype)imageWithColor:(UIColor *)color size:(CGSize)size radius:(CGFloat)cornerRadius;
+ (instancetype)imageWithColor:(UIColor *)color size:(CGSize)size;

- (UIImage *)monochromeImageWithColor:(UIColor *)color;
- (UIImage *)grayscaledImage;
- (nullable UIImage *)imageWithCIFilterName:(NSString *)filterName
                                    parameters:(nullable NSDictionary *)parameters;

/**
 @brief Performs calculation of image's average color synchronously if no completion set.
 @return always nil if completion block is provided
 */
- (nullable UIColor *)averageColorWithNativeAlpha:(BOOL)useNativeAlpha
                                       completion:(void(^_Nullable)(UIColor *))completion;
/**
 @brief Performs calculation of image's average color synchronously if no completion set.
 @return always nil if completion block is provided
 */
- (nullable UIColor *)averageColor:(void(^_Nullable)(UIColor *color))completion;

@end

NS_ASSUME_NONNULL_END
