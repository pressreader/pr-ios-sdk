//
//  PRCalendarVC.h
//  Kal
//
//  Created by Jackie Cane on 11/7/12.
//
//

#import <PRUI/KalViewController.h>
#import <PRUI/PRCalendarDelegate.h>

NS_ASSUME_NONNULL_BEGIN

@interface PRCalendarVC : KalViewController

- (instancetype)initWithFrame:(CGRect)frame;
- (instancetype)initWithFrame:(CGRect)frame
                 selectedDate:(NSDate *)date;

@property (class, nonatomic, readonly) CGSize recommendedSize;

@property (nonatomic, assign) CGRect frame;
@property (nonatomic, strong, readonly) CalendarStyle *calendarStyle;
@property (nonatomic, weak) id<PRCalendarDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
