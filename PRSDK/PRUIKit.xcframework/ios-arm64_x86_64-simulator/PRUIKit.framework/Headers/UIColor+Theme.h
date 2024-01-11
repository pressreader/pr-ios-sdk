//
//  UIColor+Theme.h
//  PR-API
//
//  Created by berec on 13/09/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIColor (Theme)

+ (UIColor *)menuBarTintColor:(BOOL)translucent;
+ (UIColor *)defaultUIControlSubtitleColor:(UIUserInterfaceStyle)theme;

@property (class, nonatomic, readonly) UIColor *navigationBarContentTintColor;

@property (class, nonatomic, readonly) UIColor *textFieldPlaceholderColor;
@property (class, nonatomic, readonly) UIColor *contentTintColor;
@property (class, nonatomic, readonly) UIColor *menuContentTintColor;
@property (class, nonatomic, readonly) UIColor *linkColor;

@property (class, nonatomic, readonly) UIColor *tableViewHeaderFooterTextColor;
@property (class, nonatomic, readonly) UIColor *tableViewHighlightBackgroundColor;
@property (class, nonatomic, readonly) UIColor *tableViewHighlightContentTintColor;
@property (class, nonatomic, readonly) UIColor *tableViewBackgroundColor;
@property (class, nonatomic, readonly) UIColor *tableViewCellBackgroundColor;
@property (class, nonatomic, readonly) UIColor *tableViewHeaderBackgroundColor;

@property (class, nonatomic, readonly) UIColor *tableViewInPopoverSelectedBackgroundColor NS_SWIFT_NAME(tableViewInPopoverSelectedBackground);
@property (class, nonatomic, readonly) UIColor *tableViewInPopoverCellBackgroundColor NS_SWIFT_NAME(tableViewInPopoverCellBackground);

@property (class, nonatomic, readonly) UIColor *popoverBackgroundColor;

@property (class, nonatomic, readonly) UIColor *defaultUIControlBackgroundColor;
@property (class, nonatomic, readonly) UIColor *defaultUIControlSubtitleColor;
@property (class, nonatomic, readonly) UIColor *defaultUIControlTitleColor;

@property (class, nonatomic, readonly) UIColor *defaultBackgroundColor;

@end

NS_ASSUME_NONNULL_END
