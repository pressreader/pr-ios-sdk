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

+ (instancetype)invalidParametersError;
+ (instancetype)unavailableError;
+ (instancetype)timeoutError;

+ (instancetype)errorWithCode:(NSInteger)code description:(nullable NSString *)description;

+ (void)logParameterRequiredErrorForMethod:(SEL)selector
                                 parameter:(NSString *)parameter;

@end

NS_ASSUME_NONNULL_END
