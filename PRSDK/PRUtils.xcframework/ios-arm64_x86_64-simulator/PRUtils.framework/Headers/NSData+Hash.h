//
//  NSData+Hash.h
//  PRAPI
//
//  Created by berec on 09/12/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSData (Hash)

- (NSData *)HMACSHA256WithKey:(NSData *)key NS_SWIFT_NAME(hmacSHA256(key:));
- (NSData *)HMACSHA1WithKey:(NSData *)key NS_SWIFT_NAME(hmacSHA1(key:));

@property(nonatomic, readonly) NSData *MD5Hash;

@end

NS_ASSUME_NONNULL_END
