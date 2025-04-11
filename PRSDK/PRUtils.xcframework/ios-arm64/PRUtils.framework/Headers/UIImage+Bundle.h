//
//  UIImage+Bundle.h
//  PRiphone
//
//  Created by Jackie Cane on 6/9/12.
//  Copyright (c) 2012 NewspaperDirect. All rights reserved.
//
// This category provides easy access to bundle images.
// Accessing bundled images via this category is more preferable 
// because it guaranties image's caching.
// Note. 
// This category's methods require providing image name 
// with extension as an argument. 
// For example [UIImage bundledImageNamed:@"some_image.png"]. 
// It won't work if you provide just image name without extension.

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIImage (Bundle)

+ (nullable instancetype)templateImageWithName:(NSString *)name preferredBundle:(nullable NSBundle *)preferredBundle
NS_SWIFT_NAME(template(name:preferredBundle:));

+ (nullable instancetype)imageWithName:(NSString *)name preferredBundle:(nullable NSBundle *)preferredBundle;

+ (nullable instancetype)imageWithName:(NSString *)name
                       preferredBundle:(nullable NSBundle *)preferredBundle
         compatibleWithTraitCollection:(nullable UITraitCollection *)traitCollection;

@end

NS_ASSUME_NONNULL_END
