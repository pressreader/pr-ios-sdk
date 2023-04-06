//
//  PRCalendarDelegate.h
//  PRUI
//
//  Created by KeithC on 2020-12-10.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN

@protocol PRCalendarDelegate <NSObject>
- (void)calendarDidSelectDate:(NSDate *)date;
@end

NS_ASSUME_NONNULL_END
