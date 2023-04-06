//
//  PRCountableCountry.h
//  PRAPI
//
//  Created by berec on 21/01/2020.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import "PRCountableValue.h"

@class PRCountry;

NS_ASSUME_NONNULL_BEGIN

@interface PRCountableCountry : PRCountableValue

+ (instancetype)value:(PRCountry *)value title:(nullable NSString *)title;

@property (nonatomic, strong, readonly) PRCountry *value;

@end

NS_ASSUME_NONNULL_END
