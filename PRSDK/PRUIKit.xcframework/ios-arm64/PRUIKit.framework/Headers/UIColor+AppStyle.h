//
//  UIColor+AppStyle.h
//  PR-API
//
//  Created by berec on 13/09/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "PRConfig+Theme.h"

NS_ASSUME_NONNULL_BEGIN

@interface UIColor (AppStyle)

+ (UIColor *)navigationBarTitleGradientColorForTextHeight:(CGFloat)height;

@property(class, nonatomic, readonly) UIColor *brandColor;
@property(class, nonatomic, readonly) UIColor *darkBrandColor;

@property(class, nonatomic, readonly) UIColor *lightBarTintColor;
@property(class, nonatomic, readonly) UIColor *darkBarTintColor;
@property(class, nonatomic, readonly) UIColor *lightTranslucentBarTintColor;
@property(class, nonatomic, readonly) UIColor *darkTranslucentBarTintColor;
@property(class, nonatomic, readonly) UIColor *lightTranslucentNavigationBarTintColor;
@property(class, nonatomic, readonly) UIColor *darkTranslucentNavigationBarTintColor;
@property(class, nonatomic, readonly) UIColor *_redColor;
@property(class, nonatomic, readonly) UIColor *bodyTextColor;

@property(class, nonatomic, readonly) UIColor *selectionColor;
@property(class, nonatomic, readonly) UIColor *personalInfoBackgroundColor;

@property(class, nonatomic, readonly) UIColor *lightBackgroundColor;
@property(class, nonatomic, readonly) UIColor *darkBackgroundColor;
@property(class, nonatomic, readonly) UIColor *lightTableViewBackgroundColor;
@property(class, nonatomic, readonly) UIColor *darkTableViewBackgroundColor;
@property(class, nonatomic, readonly) UIColor *darkMasterViewBackgroundColor;
@property(class, nonatomic, readonly) UIColor *themeTextColor;
@property(class, nonatomic, readonly) UIColor *lightThemeTextColor;
@property(class, nonatomic, readonly) UIColor *lightGrayTextColor;
@property(class, nonatomic, readonly) UIColor *darkThemeTextColor;
@property(class, nonatomic, readonly) UIColor *searchHighlightBackgroundColor;

@property(class, nonatomic, readonly) UIColor *defaultDetailsTextColor;

@property(class, nonatomic, readonly) UIColor *lightSearchFieldBackgoundColor;
@property(class, nonatomic, readonly) UIColor *darkSearchFieldBackgroundColor;

@property(class, nonatomic, readonly) UIColor *semiPrimaryTextColor;
@property(class, nonatomic, readonly) UIColor *secondaryTextColor;

@property(nonatomic, class, readonly) UIColor *lightTableViewHeaderFooterTextColor;
@property(nonatomic, class, readonly) UIColor *darkTableViewHeaderFooterTextColor;
@property(class, nonatomic, readonly) UIColor *darkTableViewSeparatorColor;
@property(class, nonatomic, readonly) UIColor *lightTableViewSeparatorColor;

@property(class, nonatomic, readonly) UIColor *darkTableViewCellDisclosureIndicatorColor;

@property(class, nonatomic, readonly) UIColor *darkTableViewHighlightBackgroundColor;
@property(class, nonatomic, readonly) UIColor *lightTableViewHighlightBackgroundColor;

@property(class, nonatomic, readonly) UIColor *defaultTableViewHighlightBackgroundColor;
@property(class, nonatomic, readonly) UIColor *defaultTableViewHighlightContentTintColor;
@property(class, nonatomic, readonly) UIColor *defaultTextFieldPlaceholderColor;
@property(class, nonatomic, readonly) UIColor *defaultTextFieldBackgroundColor;

@property(class, nonatomic, readonly) UIColor *darkTableViewHighlightContentTintColor;
@property(class, nonatomic, readonly) UIColor *lightTableViewHighlightContentTintColor;

@property(class, nonatomic, readonly) UIColor *darkPopoverBackgroundColor;
@property(class, nonatomic, readonly) UIColor *darkPopoverSolidBackgroundColor;
@property(class, nonatomic, readonly) UIColor *defaultTableViewPopoverBackgroundColor;
@property(class, nonatomic, readonly) UIColor *standardPopoverBackgroundColor;

@property(class, nonatomic, readonly) UIColor *masterPanelBackgroundColor;

@property(class, nonatomic, readonly) UIColor *darkMenuContentTintColor;
@property(class, nonatomic, readonly) UIColor *lightMenuContentTintColor;
@property(class, nonatomic, readonly) UIColor *defaultMenuContentTintColor;

@property(class, nonatomic, readonly) NSArray<UIColor *> *brandGradientColors;

/// An array of CGColorRef.
@property(class, nonatomic, readonly) NSArray *brandGradientCGColors;

@property(class, nonatomic, readonly) UIColor *navigationBarBrandedBarTintColor;

@property(class, nonatomic, readonly) UIColor *collectionViewCoverBackgroundColor;

@property(class, nonatomic, readonly) UIColor *pageViewLinksBackgroundColor;
@property(class, nonatomic, readonly) UIColor *pageViewLinksUnderlineColor;

@end

NS_ASSUME_NONNULL_END
