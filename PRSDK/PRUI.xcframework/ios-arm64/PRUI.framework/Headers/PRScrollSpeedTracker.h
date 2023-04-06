//
//  PRSpeedTrackerVC.h
//  PR-UI
//
//  Created by berec on 09/08/2018.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface PRScrollSpeedTracker : NSObject <UIScrollViewDelegate>

- (instancetype)initWithScrollView:(UIScrollView *)scrollView;

/// Resets tracking point to a current position
- (void)updateLastOffset;

@property (nonatomic) BOOL disableSpeedTracking;

@property (nonatomic, weak) UIScrollView *scrollView;
@property (nonatomic, readonly) BOOL isScrollingFast;

/// default is 2.5
@property (nonatomic) CGFloat fastScrollingSpeedThreshold;
@property (nonatomic, assign, readonly) CGFloat scrollSpeed;

@end
