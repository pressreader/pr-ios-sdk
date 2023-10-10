//
//  PRActivityVC.h
//  PRiphone
//
//  Created by Jackie Cane on 6/10/11.
//  Copyright 2011 NewspaperDirect. All rights reserved.
//

@import UIKit;

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSUInteger, PRActivityViewOption) {
    PRActivityViewOptionVertical = 1 << 0
};

@interface PRActivityVC : UIViewController

+ (instancetype)activityVCWithOptions:(PRActivityViewOption)options NS_SWIFT_NAME(init(options:));
+ (instancetype)activityVC NS_SWIFT_NAME(activityVC());

- (void)showInView:(UIView *)view insets:(UIEdgeInsets)insets;
- (void)showInView:(UIView *)view;

- (void)hide;

@property (nonatomic, getter=isAnimating) BOOL animating;
@property (nonatomic, strong) UIFont *font;
@property (nonatomic, strong) UIColor *background;

@end

NS_ASSUME_NONNULL_END
