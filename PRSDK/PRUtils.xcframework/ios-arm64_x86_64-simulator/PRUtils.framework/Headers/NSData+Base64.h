//
//  NSData+Base64.h
//  PRUtils
//
//  Created by Viacheslav Soroka on 11/24/20.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSData (Base64)

- (NSString *)urlSafeBase64EncodedString;

@end

NS_ASSUME_NONNULL_END
