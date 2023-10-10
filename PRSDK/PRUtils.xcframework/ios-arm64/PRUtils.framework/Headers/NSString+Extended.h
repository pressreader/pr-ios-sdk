//
//  NSString+Extended.h
//  PRiphone
//
//  Created by Jackie Cane on 18/11/13.
//  Copyright (c) 2013 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (Extended)

- (BOOL)isCIEqualToString:(NSString *)aString;
- (BOOL)isCIEqualToAny:(NSArray<NSString *> *)strings;

- (BOOL)containsAny:(NSArray<NSString *> *)strings;

- (BOOL)isEmpty;
- (BOOL)isFirstLetterUppercased;

- (NSString *)initials;
- (NSString *)nameInitials;

- (NSString *)substringToWidth:(CGFloat)width withFont:(UIFont *)font;
- (NSString *)substringToLimit:(NSUInteger)limit;
- (NSString *)substringToLimit:(NSUInteger)limit truncationSymbol:(NSString *)truncationSymbol;

- (NSString *)pr_stringByRemovingCharactersInSet:(NSCharacterSet *)characterSet;

- (NSString *)capitalizedFirstLetter;

@end

NS_ASSUME_NONNULL_END
