//
//  CryptoData.h
//  PRiphone
//
//  Created by Jackie Cane on 10/5/11.
//  Copyright 2011 NewspaperDirect. All rights reserved.
//  
//  http://en.wikipedia.org/wiki/Block_cipher_modes_of_operation
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSData (CryptoData)

- (nullable NSData *)AES256EncryptWithKey:(NSString *)key;
- (nullable NSData *)AES256DecryptWithKey:(NSString *)key;

@end

NS_ASSUME_NONNULL_END
