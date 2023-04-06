//
//  PRStringExtendedByRegEx.h
//  PRiphone
//
//  Created by Jackie Cane on 6/8/11.
//  Copyright 2011 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface NSString (PRStringExtendedByRegEx)

// Returns the first match of specified capture number from the regular expression.
// 
// Parameters:
// 
// pattern
// The regular expression pattern. 
//
// captureNumber 
// The number of regular expression's capture group, which is created with the use of () parenthesis.
// For example, the regular expression \b(\w+)\b has a single capture group.
// The text that was matched inside the parenthesis is available for use in the replacement text by using $n, 
// where n is the parenthesized capture group you would like to use. 
// Additional capture groups are numbered sequentially in the order that they appear from left to right. 
// Capture group 0 (zero) is also available and is equivalent to all the text that the regular expression matched.
- (NSString *)stringByMatching:(NSString *)pattern captureNumber:(NSInteger)captureNumber options:(NSRegularExpressionOptions)options;
- (NSString *)stringByMatching:(NSString *)pattern captureNumber:(NSInteger)captureNumber;
- (NSArray *)stringsByMatching:(NSString *)pattern;


@end
