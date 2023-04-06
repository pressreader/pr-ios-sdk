//
//  PRAnimatableOnScroll.h
//  PR-UI
//
//  Created by Viacheslav Soroka on 6/28/18.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

@import UIKit;

NS_ASSUME_NONNULL_BEGIN

@class PRAnimateOnScrollActor;

@protocol PRAnimatableOnScroll <NSObject>
@property (nullable, nonatomic, strong) PRAnimateOnScrollActor *animateActor;
@property (nonatomic, assign) BOOL scrollAnimationEnabled;

/**
 This method is intended for inner implementation and should never be called directly. To start animation,
 look at PRAnimateOnScrollActor.
 @param distance
    Distance is always constrained within minDistance and maxDistance.
 */
- (void)performAnimationWithBottomDistance:(CGFloat)distance
                               maxDistance:(CGFloat)maxDistance
                               minDistance:(CGFloat)minDistance;

@optional
@property (nonatomic, readonly) BOOL resetOnReachingMinDistance;

@end

NS_ASSUME_NONNULL_END
