//
//  NSString+Bits.h
//  PRAPI
//
//  Created by berec on 15/01/2020.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (Bits)

+ (NSString *)bitStringFromInteger:(NSUInteger)mask;

@end

NS_ASSUME_NONNULL_END
