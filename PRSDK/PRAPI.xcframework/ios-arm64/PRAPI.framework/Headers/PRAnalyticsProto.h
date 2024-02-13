//
//  PRAnalyticsProto.h
//  PRiphone
//
//  Created by OlegB on 11-02-25.
//  Copyright 2011 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>
@import PRAnalytics;

NS_ASSUME_NONNULL_BEGIN

@protocol PRPageViewTracker <NSObject>
- (void)tracker:(NSString *)trackerId pageView:(NSString *)pageUrl;
@end

@protocol PRGATracker <NSObject>
- (void)trackGAPageView:(NSString*)pageURL;
- (void)trackGAEvent:(NSString *)category action:(NSString *)action label:(nullable NSString *)label value:(NSInteger)value;
- (void)trackGATimingWithCategory:(NSString *)category variable:(NSString *)variable timeSpent:(NSInteger)timeSpent;
@end

NS_ASSUME_NONNULL_END
