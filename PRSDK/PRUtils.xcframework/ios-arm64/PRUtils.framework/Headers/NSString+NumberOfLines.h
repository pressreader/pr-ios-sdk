//
//  NSString+NumberOfLines.h
//  PRDataUtils
//
//  Created by berec on 11/10/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (NumberOfLines)

- (NSUInteger)numberOfLinesWithSize:(CGSize)size font:(UIFont *)font;
- (NSUInteger)numberOfLinesWithWidth:(CGFloat)width font:(UIFont *)font;

@end

NS_ASSUME_NONNULL_END
