//
//  NSMutableAttributedString+PRExtensions.h
//  PR-UI
//
//  Created by Viacheslav Soroka on 5/16/18.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSMutableAttributedString (PRExtensions)

- (void)addAttributeWithName:(NSAttributedStringKey)name attribute:(NSObject *)attribute;
- (void)addAttributeWithName:(NSAttributedStringKey)name attribute:(NSObject *)attribute inRange:(NSRange)range;

- (void)highlightRanges:(NSArray<NSValue *> *)ranges withColor:(UIColor *)color;

@end

NS_ASSUME_NONNULL_END
