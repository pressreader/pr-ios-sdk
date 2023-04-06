//
//  UIFont.h
//  test1
//
//  Created by Oleg Stepanenko on 27.04.16.
//  Copyright © 2016 StephanWhite. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIFont (Pixel)

+(instancetype) fontWithName:(NSString *)fontName sizeInPixels:(CGFloat)pixels;
+(void) registerFontWithName:(NSString *)fontName ofType:(nullable NSString *)type;

@end

NS_ASSUME_NONNULL_END
