//
//  NSData+String.h
//  PRUtils
//
//  Created by berec on 17/09/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSInteger, HexEncodingOptions) {
    HexEncondingOptionsUpperCase = (1 << 0)
};

@interface NSData (String)
@property (nonatomic, readonly) NSString *hexEncodedString;
- (NSString *)hexEncodedStringWithOptions:(HexEncodingOptions)options;
@end

NS_ASSUME_NONNULL_END
