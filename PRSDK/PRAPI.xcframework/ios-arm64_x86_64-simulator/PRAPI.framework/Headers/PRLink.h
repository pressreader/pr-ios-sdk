//
//  PRLink.h
//  PR-API
//
//  Created by Viacheslav Soroka on 12/3/18.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PRLink <__covariant Target> : NSObject

+ (instancetype)linkWithTarget:(Target)target;

- (instancetype)initWithTarget:(Target)target;

- (BOOL)isEqualToLink:(__kindof PRLink *)weakLink;

@property (nullable, nonatomic, readonly) Target target;

@end

NS_ASSUME_NONNULL_END
