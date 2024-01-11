//
//  GoogleAnalytics.h
//  PRiphone
//
//  Created by OlegB on 11-05-02.
//  Copyright 2011 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PRAnalyticsProto.h"

NS_ASSUME_NONNULL_BEGIN

@interface GoogleAnalytics  : NSObject<PROptionalAnalytics>

- (void) setSessionScopeCustomVariables;

@end

NS_ASSUME_NONNULL_END
