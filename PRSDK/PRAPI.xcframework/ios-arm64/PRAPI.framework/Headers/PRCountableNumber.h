//
//  PRCountableNumber.h
//  PRAPI
//
//  Created by berec on 21/01/2020.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import "PRCountableValue.h"

NS_ASSUME_NONNULL_BEGIN

@interface PRCountableNumber : PRCountableValue

+ (instancetype)value:(NSNumber *)value title:(nullable NSString *)title;
- (instancetype)initWithValue:(NSNumber *)value title:(nullable NSString *)title;

@property (nonatomic, strong, readonly) NSNumber *value;

@end

NS_ASSUME_NONNULL_END
