//
//  CCCryptor.h
//  PRiphone
//
//  Created by Vitali Bounine on 7/16/10.
//  Copyright 2010 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CCCryptorAES256 : NSObject {
	void *cryptorRef;
	NSData *iv;
}

+ (CCCryptorAES256 *) cryptorWithSalt:(NSData *)salt password:(NSData *)password cycleCount:(NSUInteger)cycleCount;
- (instancetype)initWithSalt:(NSData *)salt password:(NSData *)password cycleCount:(NSUInteger)cycleCount;

- (NSData *) decryptData:(NSData *)data;
- (NSString *) decryptStringFromData:(NSData *)data encoding:(NSStringEncoding)encoding;

+ (NSData *) generateKeyAndIV:(NSData *_Nonnull *_Nonnull)iv salt:(NSData *)salt pass:(NSData *)pass cycleCount:(NSUInteger)cycleCount;
+ (nullable NSData *) decryptData:(NSData *)data key:(NSData *)key IV:(NSData *)iv;

/// iv is first 16 bytes of encrypted data
/// no padding with removing bytes at the end with counter containing in the last byte
+ (nullable NSData *) decryptData:(NSData *)data key:(NSData *)key;
+ (nullable NSString *) decryptStringFromData:(NSData *)data key:(NSData *)key IV:(NSData *)iv encoding:(NSStringEncoding)encoding;

NS_ASSUME_NONNULL_END

@end
