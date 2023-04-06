//
//  PRCatalog+Promise.h
//  PR-API
//
//  Created by Viacheslav Soroka on 12/30/19.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import "PRCatalog.h"

@import PRPromiseKit;

NS_ASSUME_NONNULL_BEGIN

@interface PRCatalog (Promise)

+ (PRPromise *)wait;

- (PRPromise *)wait;

@end

NS_ASSUME_NONNULL_END
