//
//  NSString+Encoding.h
//  PRDataUtils
//
//  Created by berec on 18/11/2018.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (Encoding)

- (NSString *)XMLEncode;
- (NSString *)HTMLEncodeWithLineBreakReplacement:(nullable NSString *)htmlLineBreak;

- (NSString *)URLEncode;
- (NSString *)URLDecode;
- (NSString *)URLPathEncode;
- (NSString *)URLWithValidatedPath;

- (nullable NSString *)nullIfWhiteSpace;

@end

NS_ASSUME_NONNULL_END
