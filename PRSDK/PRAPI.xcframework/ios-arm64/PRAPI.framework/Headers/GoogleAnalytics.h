//
//  GoogleAnalytics.h
//  PRiphone
//
//  Created by OlegB on 11-05-02.
//  Copyright 2011 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PRAPI/PRAnalyticsProto.h>
#import <PRAnalytics/PRAnalytics.h>

NS_ASSUME_NONNULL_BEGIN

@interface GoogleAnalytics  : NSObject<LegacyAnalyticsService, PRPageViewTracker, PRGATracker>

- (void) setSessionScopeCustomVariables;

@end

NS_ASSUME_NONNULL_END
