//
//  AnalyticsService.h
//  PRAnalytics
//
//  Created by Ivan Berezin on 07/08/2024.
//  Copyright © 2024 NewspaperDirect. All rights reserved.
//

#ifndef AnalyticsService_h
#define AnalyticsService_h

#import <Foundation/Foundation.h>
#import <PRAnalytics/PRAnalyticsTrackName.h>
#import <PRAnalytics/PRAnalyticsTrackParameter.h>

NS_ASSUME_NONNULL_BEGIN

@protocol AnalyticsService <NSObject>

- (void)track:(PRAnalyticsTrackName)name
   parameters:(nullable NSDictionary<PRAnalyticsTrackParameter, id> *)parameters;

@property (class, nonatomic, readonly) BOOL isEnabled;

@end

NS_ASSUME_NONNULL_END

#endif /* AnalyticsService_h */
