//
//  NSError+HTTPURLResponse.h
//  PRUtils
//
//  Created by Vitali Bounine on 2020-12-03.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSError (NSHTTPURLResponse)
+ (nullable instancetype)errorWithHttpResponse:(nullable NSHTTPURLResponse *)response;
@end

NS_ASSUME_NONNULL_END
