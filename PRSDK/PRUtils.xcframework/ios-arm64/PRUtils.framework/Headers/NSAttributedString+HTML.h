//
//  NSAttributedString+HTML.h
//  PRiphone
//
//  Created by KeithC on 3/13/17.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

@import UIKit;

@interface NSAttributedString (HTML)

+ (instancetype)attributedStringWithHTML:(NSString *)htmlString;
+ (instancetype)attributedStringWithHTML:(NSString *)htmlString color:(UIColor *)color;
+ (instancetype)attributedStringWithHTML:(NSString *)htmlString color:(UIColor *)color size:(CGFloat)size;
+ (instancetype)attributedStringWithHTML:(NSString *)htmlString color:(UIColor *)color font:(UIFont *)font;

@end
