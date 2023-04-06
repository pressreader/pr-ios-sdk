//
//  UIView+Theme.h
//  PR-UI
//
//  Created by berec on 14/12/2018.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>
@import PRAccessibility;

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS (NSUInteger, PRAppearanceOption) {
    PRAppearanceOptionNone = 0,
    PRAppearanceOptionPopover = 1 << 0,
    PRAppearanceOptionTransparent = 1 << 1,
    PRAppearanceOptionShadowy = 1 << 2,
    PRAppearanceOptionInvertedColor = 1 << 3,
    PRAppearanceOptionHideDecorations = 1 << 4,
};

@interface UIView (Theme)

- (void)updateAppearance;
- (void)updateAppearanceWithTheme:(PRTheme)theme;
- (void)updateAppearanceWithOptions:(PRAppearanceOption)options;
- (void)updateAppearanceWithTheme:(PRTheme)theme options:(PRAppearanceOption)options;

- (void)updateAppearanceIfNeeded;

@end

NS_ASSUME_NONNULL_END
