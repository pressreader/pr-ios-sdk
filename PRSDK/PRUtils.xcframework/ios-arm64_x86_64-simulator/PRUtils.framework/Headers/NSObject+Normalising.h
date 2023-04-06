//
//  NSObject+Normalising.h
//  PR-API
//
//  Created by berec on 15/11/2018.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSObject (Normalising)

- (void)removeNulls;
- (void)removeUndefined;

@end

NS_ASSUME_NONNULL_END
