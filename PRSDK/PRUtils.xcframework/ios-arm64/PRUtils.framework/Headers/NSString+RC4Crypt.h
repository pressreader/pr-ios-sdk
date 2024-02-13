//
//  NSString+RC4Crypt.h
//  PRUtils
//
//  Created by Ivan Berezin on 18/01/2024.
//  Copyright © 2024 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (RC4Crypt)

- (NSString *)rc4EncodeWithKey:(NSString *)key;
- (NSString *)rc4DecodeWithKey:(NSString *)key;

@end

NS_ASSUME_NONNULL_END
