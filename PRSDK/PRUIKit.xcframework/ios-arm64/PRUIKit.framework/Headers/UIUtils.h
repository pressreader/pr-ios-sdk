//
//  UIUtils.h
//  PRiphone
//
//  Created by Dmitry Melnik on 10-08-26.
//  Copyright 2010 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

void HexColorToFloatsColor(int c, CGFloat* flColor);

BOOL PRIsHorizontalTraitRegular(UITraitCollection * _Nullable traitCollection);
BOOL PRIsVerticalTraitRegular(UITraitCollection * _Nullable traitCollection);
BOOL PRIsAnyTraitRegular(UITraitCollection * _Nullable traitCollection);
BOOL PRAreBothTraitsRegular(UITraitCollection * _Nullable traitCollection);
BOOL PRIsHorizontalSizeRegular(id<UITraitEnvironment> _Nullable traitEnvironment);
BOOL PRIsVerticalSizeRegular(id<UITraitEnvironment> _Nullable traitEnvironment);
BOOL PRIsAnyOrientationSizeRegular(id<UITraitEnvironment> _Nullable traitEnvironment);
BOOL PRAreBothOrientationSizesRegular(id<UITraitEnvironment> _Nullable traitEnvironment);
BOOL PRIsRootControllerHorizontalSizeRegular(void);
BOOL PRIsRootControllerVerticalSizeRegular(void);
BOOL PRIsAnyRootControllerOrientationSizeRegular(void);
BOOL PRAreBothRootControllerOrientationSizesRegular(void);
BOOL PRIsRootControllerOrientationLandscape(void);
BOOL IS_UI_IDIOM_PAD(void);
BOOL IS_UI_IPHONE_SE(void);
UIViewController * PRRootVC(void);

#define activate(...) [NSLayoutConstraint activateConstraints:@[__VA_ARGS__]]
#define deactivate(...) [NSLayoutConstraint deactivateConstraints:@[__VA_ARGS__]]

#define _activate4(frmt, opt, mtr, v) \
    [NSLayoutConstraint activateConstraints:[NSLayoutConstraint constraintsWithVisualFormat:frmt \
                                                                                    options:opt \
                                                                                    metrics:mtr \
                                                                                      views:v]]
#define _activate3(format, metrics, views) _activate4(format, 0, metrics, views)
#define _activate2(format, views) _activate3(format, nil, views)

#define activateVisualFormat(...) __GET_MACRO4(__VA_ARGS__, _activate4, _activate3, _activate2)(__VA_ARGS__)

@interface UIUtils: NSObject

+ (void) RemoveSubviews:(UIView*)view;

+ (long) GetElementByX:(CGFloat)x elemsArray:(NSMutableArray*)elemsArray descending:(BOOL)descending;
+ (long) GetElementByXdesc:(CGFloat)x elemsArray:(NSMutableArray*)elemsArray;

@end

@interface UIView (UIUtils)
- (BOOL)isOnScreen;
@end

@interface UIResponder (firstResponder)
+ (id)currentFirstResponder;
@end

NS_ASSUME_NONNULL_END
