//
//  PRCanonicalDateFormatter.h
//  PRUtils
//
//  Created by berec on 17/11/2018.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PRCanonicalDateFormatter : NSDateFormatter

+ (instancetype)shared;

- (instancetype)initWithFormat:(NSString *)format NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
