//
//  PRProgressView.h
//  PRiphone
//
//  Created by Jackie Cane on 03/12/14.
//  Copyright (c) 2014 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, PRProgressViewStyle) {
    PRProgressViewStyleBar = 0,
    PRProgressViewStyleCircle
};

@interface PRProgressView : UIView
@property (nonatomic, assign) PRProgressViewStyle style;
@property (nonatomic, assign) CGFloat progress;

@property (nonatomic, strong) UIColor *color;
@property (nonatomic, assign) CGFloat size;
@property (nonatomic, assign) CFTimeInterval animationDuration;

/**
 * The observedProgress object to use for updating the progress view
 * When this property is set, the progress view updates its progress value automatically using information it receives from the NSProgress object.
 * Progress updates are animated.
 */
@property (nonatomic, strong) NSProgress *observedProgress;

- (void)setProgress:(CGFloat)progress animated:(BOOL)animated;
@end
