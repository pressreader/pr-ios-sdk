//
//  PRVC.h
//  PR-UI
//
//  Created by Viacheslav Soroka on 4/15/19.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import "_PRVC.h"

NS_ASSUME_NONNULL_BEGIN

@interface PRVC : _PRVC

// Implementation is hidden for Swift as long as rootView name is
// used in PRRootViewGetable protocol (Swift can't in covariant).
@property (nullable, nonatomic, readonly) __kindof UIView *rootView NS_SWIFT_UNAVAILABLE("Swift has its own implementation");

@property (nonatomic, strong) Class rootViewClass;

@end

NS_ASSUME_NONNULL_END
