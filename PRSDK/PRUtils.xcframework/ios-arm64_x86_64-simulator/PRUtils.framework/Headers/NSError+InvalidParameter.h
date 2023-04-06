//
//  NSError+InvalidParameter.h
//  PRiphone
//
//  Created by Viacheslav Soroka on 8/22/17.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

@interface NSError (InvalidParameter)

+ (instancetype)invalidParametersErrorWithDescription:(nullable NSString *)description;
+ (instancetype)invalidParametersError;

+ (void)logParameterRequiredErrorForMethod:(SEL)selector
                                 parameter:(NSString *)parameter;

@end

NS_ASSUME_NONNULL_END
