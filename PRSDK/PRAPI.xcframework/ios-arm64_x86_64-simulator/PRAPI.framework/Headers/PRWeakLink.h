//
//  PRWeakLink.h
//  PR-API
//
//  Created by Viacheslav Soroka on 11/17/17.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

#import "PRLink.h"

NS_ASSUME_NONNULL_BEGIN

@interface PRWeakLink <__covariant Target> : PRLink <Target>

+ (instancetype)weakLinkWithTarget:(Target)target NS_SWIFT_NAME(init(_:));

- (BOOL)isEqualToWeakLink:(PRWeakLink *)weakLink;

@end

NS_ASSUME_NONNULL_END
