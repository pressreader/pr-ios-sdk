//
//  PRAnalyticsProto.h
//  PRiphone
//
//  Created by OlegB on 11-02-25.
//  Copyright 2011 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol PRAnalyticsBaseService<NSObject>
- (void) tracker:(NSString *)trackerId pageView:(NSString *)pageUrl;
@end


/// `rawValue` must be equal to the last part of the case name with exception of underscore characters.
///
/// Valid name example:
///
///     PRAnalyticsTrackName const PRAnalyticsTrackSomeEvent = @"SomeEvent";
///     PRAnalyticsTrackName const PRAnalyticsTrackSomeOtherEvent = @"Some_Other_Event";
///
/// Invalid name example:
///
///     PRAnalyticsTrackName const PRAnalyticsTrackSomeEvent = @"Who CaresThose-Names!";
///
typedef NSString * PRAnalyticsTrackName NS_TYPED_ENUM;

/// `rawValue` must be equal to the last part of the case name.
/// `camelCase` is preferable.
///
/// Valid name example:
///
///     PRAnalyticsTrackParameter const PRAnalyticsTrackParameterItemId = @"itemId";
///     PRAnalyticsTrackParameter const PRAnalyticsTrackParameterOtherItemId = @"OtherItemId";
///
/// Invalid name example:
///
///     PRAnalyticsTrackParameter const PRAnalyticsTrackParameterItemId = @"I wanna_use-this!";
///
typedef NSString * PRAnalyticsTrackParameter NS_TYPED_ENUM;

typedef NS_OPTIONS(NSUInteger, PRAnalyticsTrackOptions) {
    PRAnalyticsTrackOptionsNone                 = 0,
    PRAnalyticsTrackOptionsViewDidAppear        = 1 << 0,
};

@protocol PRAnalytics <PRAnalyticsBaseService>
@property (class, nonatomic, readonly) BOOL enabled;

- (void)track:(PRAnalyticsTrackName)name
   parameters:(nullable NSDictionary<PRAnalyticsTrackParameter, id> *)parameters
      options:(PRAnalyticsTrackOptions) options;

// for GA compatibility reported from inside SF scripts
- (void)trackGAPageView:(NSString*)pageURL;
- (void)trackGAEvent:(NSString *)category action:(NSString *)action label:(nullable NSString *)label value:(NSInteger)value;
- (void)trackGATimingWithCategory:(NSString *)category variable:(NSString *)variable timeSpent:(NSInteger)timeSpent;

@end

NS_ASSUME_NONNULL_END
