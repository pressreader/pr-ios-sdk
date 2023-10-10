//
//  UIImage+Bundle.h
//  PRiphone
//
//  Created by Jackie Cane on 6/9/12.
//  Copyright (c) 2012 NewspaperDirect. All rights reserved.
//

//#ifdef PR_IOS
//#import <UIKit/UIKit.h>
//#else
//#import <Cocoa/Cocoa.h>
//typedef NSImage UIImage;
//#endif

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

+ (nullable UIImage *)bundledTemplateImageNamed:(NSString *)name NS_SWIFT_NAME(init(bundledTemplateWithName:));
+ (nullable UIImage *)bundledImageNamed:(NSString *)name NS_SWIFT_NAME(init(bundledWithName:));
+ (nullable UIImage *)bundledImageNamed:(NSString *)name
          compatibleWithTraitCollection:(nullable UITraitCollection *)traitCollection NS_SWIFT_NAME(init(bundledWithName:compatibleWith:));

/**
 This method returns selected image if exists or nil. Image name will generated automatically.
 For example:
 @code 
 [UIImage bundledImageNamed:@"some_image.png"] @endcode
 is identically to the next:
 @code 
 [UIImage bundledImageNamed:@"some_image-selected.png" selected:YES xl:NO] @endcode
 */
+ (nullable UIImage *)bundledImageNamed:(nullable NSString *)name selected:(BOOL)selected xl:(BOOL)xl;

@end

NS_ASSUME_NONNULL_END
