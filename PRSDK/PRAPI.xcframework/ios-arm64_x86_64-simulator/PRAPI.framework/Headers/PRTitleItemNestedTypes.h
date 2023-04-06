//
//  PRTitleItemNestedTypes.h
//  PRAPI
//
//  Created by berec on 09/12/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#ifndef PRTitleItemNestedTypes_h
#define PRTitleItemNestedTypes_h

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

// Determines the available sorting ways.
typedef enum {
    PRTitleSortingNone            = 0,
    PRTitleSortingAlphabetically  = 1 << 0,
    PRTitleSortingByRating        = 1 << 1,
    PRTitleSortingByActivation    = 1 << 2
} PRTitleSorting;

// A bit mask that determines what kind of sorting are available.
// You specify the value of this mask by combining the constants described in PRTitleSorting enum using the C bitwise OR operator.
// The default value of this property is PRTitleSortingNotDefined (-1), which indicates that
// all sorting ways (alphabetically, by raiting, by activation) are available.
//#define SORTING_MASK            _PRCONFIG_INT_(@"SORTING_MASK", -1)

#endif /* PRTitleItemNestedTypes_h */
