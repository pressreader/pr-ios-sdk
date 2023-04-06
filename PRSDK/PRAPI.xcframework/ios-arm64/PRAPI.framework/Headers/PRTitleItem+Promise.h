//
//  PRTitleItem+Promise.h
//  PR-API
//
//  Created by Viacheslav Soroka on 1/7/20.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import "PRTitleItem.h"

NS_ASSUME_NONNULL_BEGIN

@class PRPromise;

@interface PRTitleItem (Promise)

- (PRPromise *)getRecentTitleExemplars:(NSInteger)amount;
- (PRPromise *)getRecentTitleExemplars:(NSInteger)amount
                     lastAvailableDate:(nullable NSDate *)lastAvailableDate;

@end

NS_ASSUME_NONNULL_END
