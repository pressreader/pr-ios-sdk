//
//  ConsoleAnalytics.h
//  PRiphone
//
//  Created by OlegB on 11-02-25.
//  Copyright 2011 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PRAnalytics/PRAnalytics.h>

NS_ASSUME_NONNULL_BEGIN

@interface ConsoleAnalytics : NSObject<LegacyAnalyticsService, PRPageViewTracker, PRGATracker>

@end

NS_ASSUME_NONNULL_END
