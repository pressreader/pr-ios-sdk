//
//  UIColor+Hex.h
//  PRUtils
//
//  Created by berec on 26/03/2021.
//  Copyright © 2021 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIColor (Hex)

+ (instancetype)colorWithHex:(NSUInteger)hex;
+ (instancetype)colorWithHex:(NSUInteger)hex alpha:(CGFloat)alpha;
+ (instancetype)colorWithHexRGBA:(NSUInteger)hex;
+ (instancetype)colorWithHexString:(NSString *)hex;

@property (nonatomic, readonly) NSString *hexRGBA;
@property (nonatomic, readonly) NSString *hexRGB;

@end

NS_ASSUME_NONNULL_END
