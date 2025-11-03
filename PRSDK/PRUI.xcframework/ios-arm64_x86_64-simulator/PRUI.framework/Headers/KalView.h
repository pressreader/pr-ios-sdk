/* 
 * Copyright (c) 2009 Keith Lazuka
 * License: http://www.opensource.org/licenses/mit-license.html
 */

#import "CalendarStyle.h"

NS_ASSUME_NONNULL_BEGIN

extern CGFloat const kHeaderHeight;
extern CGFloat const kMonthLabelHeight;
extern CGFloat const kMonthHeaderHeight;
extern CGFloat const kContentPadding;
extern CGFloat const kTopContentPadding;

@class KalGridView, KalLogic, KalDate;
@protocol KalViewDelegate, KalDataSourceCallbacks;

/*
 *    KalView
 *    ------------------
 *
 *    Private interface
 *
 *  As a client of the Kal system you should not need to use this class directly
 *  (it is managed by KalViewController).
 *
 *  KalViewController uses KalView as its view.
 *  KalView defines a view hierarchy that looks like the following:
 *
 *       +-----------------------------------------+
 *       |                header view              |
 *       +-----------------------------------------+
 *       |                                         |
 *       |                                         |
 *       |                                         |
 *       |                 grid view               |
 *       |             (the calendar grid)         |
 *       |                                         |
 *       |                                         |
 *       +-----------------------------------------+
 *
 */
@interface KalView : UIView {
    KalGridView *gridView;
    UIImageView *shadowView;
    __weak id<KalViewDelegate> delegate;
    KalLogic *logic;
}

@property (nonatomic, weak) id<KalViewDelegate> delegate;
@property (nonatomic, readonly) KalDate *selectedDate;
@property (nonatomic, readonly) UIView *monthBackgroundView;
@property (nullable, nonatomic, strong) UIView *contentView;
@property (nullable, nonatomic, strong) UIButton *headerButton;

@property (nonatomic, retain) CalendarStyle *calendarStyle;

- (instancetype)initWithFrame:(CGRect)frame delegate:(id<KalViewDelegate>)delegate logic:(KalLogic *)logic;

- (BOOL)isSliding;
- (void)selectDate:(KalDate *)date;
- (void)markTilesForDates:(NSArray *)dates;
- (void)redrawEntireMonth;

// These 3 methods are exposed for the delegate. They should be called 
// *after* the KalLogic has moved to the month specified by the user.
- (void)slideDown;
- (void)slideUp;
- (void)jumpToSelectedMonth;    // change months without animation (i.e. when directly switching to "Today")

- (void)configureHeaderViewWithFrame:(CGRect)frame;
- (void)configureContentViewWithFrame:(CGRect)frame;

- (void)setHeaderTitleText:(NSString *)text;
- (void)setPrevMonthEnabled:(BOOL)value;
- (void)setNextMonthEnabled:(BOOL)value;

- (void)addChangeMonthButtonsToHeaderView:(UIView *)headerView;
- (void)addWeekdayColumnLabelsToView:(UIView *)view topView:(UIView *)topView;
- (void)addSelectedMonthLabelToHeaderView:(UIView *)headerView;

- (void)reloadDates;

- (CGFloat)desiredHeight;

@end

#pragma mark -

@class KalDate;

@protocol KalViewDelegate

- (NSDate *)selectedDate;
- (void)showPreviousMonth;
- (void)showFollowingMonth;
- (BOOL)shouldSelectDate:(KalDate *)date;
- (void)didSelectDate:(KalDate *)date byUser:(BOOL)byUser;
- (void)headerViewDidReceiveTap:(UIView *)headerView;

@end

NS_ASSUME_NONNULL_END
