//
//  UIImage+Stretchable.h
//  PRiphone
//
//  Created by Oleg Stepanenko on 07.02.13.
//  Copyright (c) 2013 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (Stretchable)

typedef enum {
    UIImageResizeMethodFill, // Crop center
    UIImageResizeMethodFillStart, // Crop top or left (prefer top)
    UIImageResizeMethodFillEnd, // Crop bottom or right (prefer bottom)
    UIImageResizeMethodFit 
} UIImageResizeMethod;

- (UIImage *)imageToSize:(CGSize)size method:(UIImageResizeMethod)method;
- (UIImage *)imageCroppedToSize:(CGSize)size;
- (UIImage *)imageScaledToSize:(CGSize)size;
- (void)drawInRect:(CGRect)rect toContext:(CGContextRef)context;
@end
