//
//  PRTitleItemSchedule.h
//  PRCatalogModel
//
//  Created by Ivan Berezin on 10/02/2025.
//  Copyright © 2025 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(uint8_t, PRTitleItemScheduleType) {
    PRTitleItemScheduleNotDefined = 0,
    PRTitleItemScheduleTypeDaily,
    PRTitleItemScheduleTypeWeekly,
    PRTitleItemScheduleTypeBiweekly,
    PRTitleItemScheduleTypeMonthly,
    PRTitleItemScheduleTypeBimonthly,
    PRTitleItemScheduleTypeQuarterly,
    PRTitleItemScheduleTypeSemiAnnually,
    PRTitleItemScheduleTypeAnnually,
    PRTitleItemScheduleTypeBiannually,
    PRTitleItemScheduleTypeIrregularly,
    PRTitleItemScheduleTypeOnce,
    PRTitleItemScheduleTypeUnsupported
};

@interface PRTitleItemSchedule : NSObject

+ (PRTitleItemScheduleType)typeWithString:(NSString *)string;

@end

NS_ASSUME_NONNULL_END
