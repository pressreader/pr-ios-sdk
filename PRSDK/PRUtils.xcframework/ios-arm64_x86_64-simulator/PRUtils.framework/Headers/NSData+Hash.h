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
@property(nonatomic, readonly) NSData *MD5Hash;
@property(nonatomic, readonly) NSData *SHA256Hash;
- (NSData *)HMACSHA256WithKey:(NSData *)key NS_SWIFT_NAME(hmacSHA256(key:));
@end

NS_ASSUME_NONNULL_END
