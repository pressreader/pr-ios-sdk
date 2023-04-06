//
//  GoogleAnalytics.h
//  PRiphone
//
//  Created by OlegB on 11-05-02.
//  Copyright 2011 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PRAnalyticsProto.h"

@interface GoogleAnalytics  : NSObject<PRAnalytics>

- (void) setSessionScopeCustomVariables;

@end
