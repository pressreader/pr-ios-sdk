//
//  PROptions+Promise.h
//  PRAPI
//
//  Created by berec on 11/03/2020.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import "PROptions.h"

@class PRPromise;

NS_ASSUME_NONNULL_BEGIN

@interface PROptions (Promise)

- (PRPromise *)configUpdated;

@end

NS_ASSUME_NONNULL_END
