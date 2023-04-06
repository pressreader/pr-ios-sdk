//
//  ISO8601DateFormatter.h
//  PRSmart
//
//  Created by berec on 18/11/2018.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ISO8601DateFormatter : NSDateFormatter

+ (instancetype)shared;

@end

NS_ASSUME_NONNULL_END
