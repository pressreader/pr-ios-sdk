//
//  UIColor+Theme.h
//  PR-API
//
//  Created by berec on 13/09/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>
@import PRAccessibility;

NS_ASSUME_NONNULL_BEGIN

@interface UIColor (Theme)

+ (nullable UIColor *)thumbnailBackgroundColorForTheme:(PRTheme)theme;

+ (UIColor *)navigationBarTintColorForTheme:(PRTheme)theme;
+ (UIColor *)translucentNavigationBarTintColorForTheme:(PRTheme)theme;

+ (UIColor *)navigationBarContentTintColorForTheme:(PRTheme)theme;
+ (UIColor *)customNavigationBarContentTintColorForTheme:(PRTheme)theme;

+ (UIColor *)searchBarBackgroundColorForTheme:(PRTheme)theme;

+ (UIColor *)menuBarTintColorForTheme:(PRTheme)theme translucent:(BOOL)translucent;

+ (UIColor *)textColorForTheme:(PRTheme)theme;
+ (UIColor *)detailsTextColorForTheme:(PRTheme)theme;
+ (UIColor *)textFieldPlaceholderColorForTheme:(PRTheme)theme;
+ (UIColor *)contentTintColorForTheme:(PRTheme)theme;
+ (UIColor *)menuContentTintColorForTheme:(PRTheme)theme;
+ (UIColor *)linkColorForTheme:(PRTheme)theme;

+ (UIColor *)tableViewSeparatorColorForTheme:(PRTheme)theme;
+ (UIColor *)tableViewHeaderFooterTextColorForTheme:(PRTheme)theme;
+ (UIColor *)tableViewHighlightBackgroundColorForTheme:(PRTheme)theme;
+ (UIColor *)tableViewHighlightContentTintColorForTheme:(PRTheme)theme;
+ (UIColor *)tableViewSelectedBackgroundColorForTheme:(PRTheme)theme;
+ (UIColor *)tableViewSelectedContentTintColorForTheme:(PRTheme)theme;
+ (UIColor *)tableViewBackgroundColorForTheme:(PRTheme)theme;
+ (UIColor *)tableViewCellBackgroundColorForTheme:(PRTheme)theme;
+ (UIColor *)tableViewHeaderBackgroundColorForTheme:(PRTheme)theme;

+ (UIColor *)tableViewInPopoverSelectedBackgroundColorForTheme:(PRTheme)theme;
+ (UIColor *)tableViewInPopoverCellBackgroundColorForTheme:(PRTheme)theme;
+ (UIColor *)tableViewInPopoverBackgroundColorForTheme:(PRTheme)theme;

+ (UIColor *)popoverBackgroundColorForTheme:(PRTheme)theme;
+ (UIColor *)popoverSolidBackgroundColorForTheme:(PRTheme)theme;
+ (UIColor *)menuPopoverBackgroundColorForTheme:(PRTheme)theme;
+ (UIColor *)standardPopoverBackgroundColorForTheme:(PRTheme)theme;

+ (UIColor *)defaultUIControlBackgroundColorForTheme:(PRTheme)theme;
+ (UIColor *)defaultUIControlSubtitleColorForTheme:(PRTheme)theme;
+ (UIColor *)defaultUIControlTitleColorForTheme:(PRTheme)theme;

+ (UIColor *)defaultBackgroundColorForTheme:(PRTheme)theme;

+ (UIColor *)standoutViewBackgroundColorForTheme:(PRTheme)theme;
+ (UIColor *)standoutViewTextColorForTheme:(PRTheme)theme;
+ (UIColor *)standoutViewHeaderColorForTheme:(PRTheme)theme;
+ (UIColor *)standoutViewSeparatorColorForTheme:(PRTheme)theme;

+ (UIColor *)defaultTextColorForTheme:(PRTheme)theme;

+ (UIColor *)labelColorForTheme:(PRTheme)theme;
+ (UIColor *)secondaryLabelColorForTheme:(PRTheme)theme;

@end

NS_ASSUME_NONNULL_END
