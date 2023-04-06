//
//  UIImage+fontGlyph.h
//  test1
//
//  Created by Oleg Stepanenko on 27.04.16.
//  Copyright © 2016 StephanWhite. All rights reserved.
//

@import UIKit;

NS_ASSUME_NONNULL_BEGIN

@interface UIImage (Text)

+ (UIImage *)imageWithText:(NSString *)text
                  fontName:(NSString *)fontName
                    height:(CGFloat)height;

+ (UIImage *)imageWithText:(NSString *)text
                      size:(CGSize)size
           backgroundColor:(nullable UIColor *)color
            textAttributes:(nullable NSDictionary *)textAttributes;

@end

NS_ASSUME_NONNULL_END
