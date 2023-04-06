//
//  UIImage+BarButtonSystemItem.h
//  PRiphone
//
//  Created by Vitali Bounine on 2016-09-02.
//  Copyright © 2016 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIImage (BarButtonSystemItem)

+ (nullable UIImage *)imageFromBarButtonSystemItem:(UIBarButtonSystemItem)barButtonSystemItem;
+ (nullable UIImage *)imageForTransparentBar:(BOOL)transparent
                  withImageForTransparentBar:(NSString *)transparentImage
                                regularImage:(NSString *)regularImage;

@end

@interface NSString (BarButtonSystemItem)

+ (nullable NSString *)stringWithBarButtonSystemItem:(UIBarButtonSystemItem)barButtonSystemItem;
- (UIBarButtonSystemItem)barBarButtonSystemItem;

@end

NS_ASSUME_NONNULL_END
