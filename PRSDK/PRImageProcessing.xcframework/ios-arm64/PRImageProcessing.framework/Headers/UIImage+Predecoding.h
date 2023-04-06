//
//  UIImage+Predecoding.h
//  PRiphone
//
//  Created by Jackie Cane on 5/31/13.
//  Copyright (c) 2013 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (Predecoding)

+ (UIImage *)decodedImageWithImage:(UIImage *)image;
+ (UIImage *)decodedImageWithContentsOfFile:(NSString *)filePath;
- (instancetype)initDecodedWithImage:(UIImage *)image;
// returns another instance
- (UIImage *)decode;

@end
