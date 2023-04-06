//
//  UIImage+Thumbnail.h
//  PRiphone
//
//  Created by Jackie Cane on 5/31/13.
//  Copyright (c) 2013 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (Thumbnail)

- (UIImage *)createThumbnailWithBounds:(CGRect)bounds inset:(CGFloat)borderInset backgroundColor:(UIColor *)backgroundColor;
- (UIImage *)thumbnailForFrame:(CGRect)frame
				  outsideColor:(UIColor*)outsideColor
				   borderInset:(CGFloat)borderInset
			   backgroundColor:(UIColor*)backgroundColor
				 gradientColor:(UIColor *)gradientColor
				  shadowOffset:(CGSize)shadowOffset
				   shadowColor:(UIColor *)shadowColor
					shadowBlur:(CGFloat)shadowBlur;
- (UIImage*) imageWithRoundCorner:(CGFloat)radius;
- (UIImage*) imageToSquareWidth:(CGFloat)width;
@end
