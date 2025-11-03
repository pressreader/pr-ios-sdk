//
//  PROrderVC.h
//  PRiphone
//
//  Created by Jackie Cane on 23/01/14.
//  Copyright (c) 2014 NewspaperDirect. All rights reserved.
//

@import PRUIKit.PRVC;

@class PROrder;
@class PRGroupedExemplarsCollectionVC;
@class PROrderModel;

NS_ASSUME_NONNULL_BEGIN

@interface PROrderVC : PRVC

- (instancetype)initWithOrder:(PROrder *)order;

@property (nonatomic, strong) PROrder *order;
@property (nonatomic, strong, readonly) PROrderModel *model;
@property (nonatomic, strong, readonly) PRGroupedExemplarsCollectionVC *otherIssuesVC;

@end

@class PRCalendarVC;
@class PRCalendarDataSource;
@class PRDropdownView;

@interface PROrderVC (/*PROTECTED*/)
- (void)displayMainThumbnailLoadingIndicator:(BOOL)display;
- (void)switchToDate:(NSDate *)toDate;

@property (nullable, nonatomic, strong) PRCalendarVC *calendarVC;
@property (nullable, nonatomic, strong) PRCalendarDataSource *calendarDataSource;
@property (nullable, nonatomic, strong) PRDropdownView *dropview;

@end

#ifdef TEST
@interface PROrderVC ()
- (void)openReaderWithCompletion:(nullable PRSimpleBlock)completion;
@end
#endif

NS_ASSUME_NONNULL_END
