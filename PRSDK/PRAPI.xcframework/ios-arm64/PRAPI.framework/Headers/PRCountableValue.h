//
//  PRCountableValue.h
//  PRiphone
//
//  Created by berec on 11/27/12.
//  Copyright (c) 2012 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PRCountableValue : NSObject

+ (instancetype)value:(id)value title:(nullable NSString *)title;
- (instancetype)initWithValue:(id)value title:(nullable NSString *)title;

@property (nullable, nonatomic, strong, readonly) NSString *title;
@property (nonatomic, strong, readonly) id value;
@property (nullable, nonatomic, strong) id extraData;
@property (nonatomic) NSInteger count;

@end

NS_ASSUME_NONNULL_END
