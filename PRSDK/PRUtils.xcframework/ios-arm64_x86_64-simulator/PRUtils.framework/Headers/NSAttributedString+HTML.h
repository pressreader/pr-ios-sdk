//
//  NSAttributedString+HTML.h
//  PRiphone
//
//  Created by KeithC on 3/13/17.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

@import UIKit;

NS_ASSUME_NONNULL_BEGIN

@interface NSAttributedString (HTML)

+ (nullable instancetype)attributedStringWithHTML:(NSString *)htmlString;
+ (nullable instancetype)attributedStringWithHTML:(NSString *)htmlString color:(nullable UIColor *)color;
+ (nullable instancetype)attributedStringWithHTML:(NSString *)htmlString color:(nullable UIColor *)color size:(CGFloat)size;
+ (nullable instancetype)attributedStringWithHTML:(NSString *)htmlString color:(nullable UIColor *)color font:(nullable UIFont *)font;

@end

NS_ASSUME_NONNULL_END
