//
//  UIGraphics+.h
//  PRUIKit
//
//  Created by Vitalii Hudenko on 08.11.2023.
//  Copyright © 2023 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^UIGraphicsBlock)(CGContextRef context);

UIImage* _Nullable UIGraphicsGetImageWithSize(CGSize size, UIGraphicsBlock block);
UIImage* _Nullable UIGraphicsGetImage(CGSize size, BOOL opaque, CGFloat scale, UIGraphicsBlock block);

NS_ASSUME_NONNULL_END
