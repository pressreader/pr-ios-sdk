//
//  PRTipButton.h
//  PR-UI
//
//  Created by berec on 24/10/2018.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface PRTipButton : UIButton

+ (instancetype)buttonWithCount:(NSInteger)count font:(UIFont *)font;
+ (instancetype)buttonWithType:(UIButtonType)buttonType NS_UNAVAILABLE;

@property (nonatomic) NSInteger count;
@property (nonatomic, strong) UIFont *tipFont;

@property (nonatomic, strong, readonly) NSLayoutConstraint *heightConstraint;
@property (nonatomic, strong, readonly) NSLayoutConstraint *widthConstraint;

@end


@interface PRTipButton (/*PROTECTED*/)

/// Default implementation does nothing. Place your appearance generation code based on count and font here.
- (void)updateAppearance;
- (void)setupAccessibility;

@property (nonatomic, readonly) CGSize tipSize;

@end

NS_ASSUME_NONNULL_END
