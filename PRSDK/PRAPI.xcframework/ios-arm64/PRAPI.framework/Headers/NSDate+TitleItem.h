//
//  NSDate+TitleItem.h
//  PR-API
//
//  Created by berec on 10/05/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PRTitleItemNestedTypes.h"

NS_ASSUME_NONNULL_BEGIN

@interface NSDate (TitleItem)

- (NSString *)formattedDate:(PRTitleItemScheduleType)scheduleType;
- (NSString *)longFormattedDate:(PRTitleItemScheduleType)scheduleType;
- (NSString *)shortFormattedDate:(PRTitleItemScheduleType)scheduleType;

@end

NS_ASSUME_NONNULL_END
