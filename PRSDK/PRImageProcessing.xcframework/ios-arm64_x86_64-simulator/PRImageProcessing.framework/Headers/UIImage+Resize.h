//
//  UIImage+Resize.h
//  PR-API
//
//  Created by berec on 30/01/2018.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (Resize)

- (UIImage *)imageWithSize:(CGSize)resultSize backgroundColor:(UIColor *)color;
- (UIImage *)imageWithSize:(CGSize)resultSize;
- (UIImage *)imageWithPreciseSize:(CGSize)size;

@end
