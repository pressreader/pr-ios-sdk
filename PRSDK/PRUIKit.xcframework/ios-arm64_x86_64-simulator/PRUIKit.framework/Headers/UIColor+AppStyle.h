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
@property(class, nonatomic, readonly) UIColor *_redColor;

@property(class, nonatomic, readonly) UIColor *personalInfoBackgroundColor;

@property(class, nonatomic, readonly) UIColor *lightTableViewBackgroundColor;
@property(class, nonatomic, readonly) UIColor *darkTableViewBackgroundColor;
@property(class, nonatomic, readonly) UIColor *darkMasterViewBackgroundColor;
@property(class, nonatomic, readonly) UIColor *lightGrayTextColor;
@property(class, nonatomic, readonly) UIColor *darkThemeTextColor;
@property(class, nonatomic, readonly) UIColor *searchHighlightBackgroundColor;

@property(nonatomic, class, readonly) UIColor *lightTableViewHeaderFooterTextColor;
@property(nonatomic, class, readonly) UIColor *darkTableViewHeaderFooterTextColor;

@property(class, nonatomic, readonly) UIColor *defaultTextFieldBackgroundColor;

@property(class, nonatomic, readonly) UIColor *darkPopoverBackgroundColor;

@property(class, nonatomic, readonly) UIColor *masterPanelBackgroundColor;

@property(class, nullable, nonatomic, readonly) UIColor *navigationBarBrandedBarTintColor;

@property(class, nonatomic, readonly) UIColor *pageViewLinksBackgroundColor;
@property(class, nonatomic, readonly) UIColor *pageViewLinksUnderlineColor;

@end

NS_ASSUME_NONNULL_END
