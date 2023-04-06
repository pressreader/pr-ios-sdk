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

@interface NSData (CryptoData)

- (NSData *)AES256EncryptWithKey:(NSString *)key;
- (NSData *)AES256DecryptWithKey:(NSString *)key;

@end
