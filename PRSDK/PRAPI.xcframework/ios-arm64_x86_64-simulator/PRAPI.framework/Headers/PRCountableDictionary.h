//
//  PRCountableDictionary.h
//  PRAPI
//
//  Created by berec on 21/01/2020.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import "PRCountableValue.h"

NS_ASSUME_NONNULL_BEGIN

@interface PRCountableDictionary : PRCountableValue

+ (instancetype)value:(NSDictionary *)value title:(nullable NSString *)title;
- (instancetype)initWithValue:(NSDictionary *)value title:(nullable NSString *)title;

@property (nonatomic, strong, readonly) NSDictionary *value;

@end

NS_ASSUME_NONNULL_END
