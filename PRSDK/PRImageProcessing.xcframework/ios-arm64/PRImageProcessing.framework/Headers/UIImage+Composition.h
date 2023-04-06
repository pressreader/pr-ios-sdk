//
//  UIImage+Composition.h
//  PRiphone
//
//  Created by Viacheslav Soroka on 8/4/17.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(uint8_t, PRImagePosition) {
    PRImagePositionCenter,
    PRImagePositionTop,
    PRImagePositionBottom,
    PRImagePositionTopLeft,
    PRImagePositionTopRight,
    PRImagePositionBottomLeft,
    PRImagePositionBottomRight
};

@interface UIImage (Composition)

- (UIImage *)imageWithOverlayedImage:(UIImage *)image position:(PRImagePosition)position;
- (UIImage *)imageWithOverlayedImage:(UIImage *)image point:(CGPoint)point;

@end
