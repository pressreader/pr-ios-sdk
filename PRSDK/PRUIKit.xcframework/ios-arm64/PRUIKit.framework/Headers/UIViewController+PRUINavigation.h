//
//  UIViewController+PRUINavigation.h
//  PRiphone
//
//  Created by berec on 9/27/16.
//  Copyright © 2016 NewspaperDirect. All rights reserved.
//

#import "PRAppStyle+Theme.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, PRDismissNavigationButtonStyle) {
    PRDismissNavigationButtonStyleIcon = 0,
    PRDismissNavigationButtonStyleCancel,
    PRDismissNavigationButtonStyleDone
};

typedef NS_ENUM(NSInteger, PRNavigationBarHairlineStyle) {
    PRNavigationBarHairlineStyleDefault = 0,
    PRNavigationBarHairlineStyleShadow,
    PRNavigationBarHairlineStyleHidden
};

typedef NS_OPTIONS(uint8_t, PRNavigationBarRefreshOption) {
    PRNavigationBarRefreshOptionNone = 0,
    PRNavigationBarRefreshOptionLeft = 1 << 0,
    PRNavigationBarRefreshOptionTitle = 1 << 1,
    PRNavigationBarRefreshOptionRight = 1 << 2,
    PRNavigationBarRefreshOptionBarButtonItems = PRNavigationBarRefreshOptionLeft | PRNavigationBarRefreshOptionRight,
    PRNavigationBarRefreshOptionAll = PRNavigationBarRefreshOptionBarButtonItems | PRNavigationBarRefreshOptionTitle
};

@interface UIViewController (PRUINavigation)
@property (nullable, nonatomic, readonly) NSArray<UIBarButtonItem *> *navigationBarLeftBarButtonItems;
@property (nullable, nonatomic, readonly) NSArray<UIBarButtonItem *> *navigationBarRightBarButtonItems;

@property (nonatomic, readonly) UIView *navigationItemTitleView;
@property (nonatomic, readonly) CGFloat navigationItemTitleViewWidth;

@property (nonatomic, readonly) CGFloat navigationBarItemInset;

@property (nonatomic, readonly) UIColor *barContentTintColor;
@property (nonatomic, readonly) UIColor *customBarContentTintColor;
@property (nonatomic, readonly) UIColor *customBarTintColor;

@property (nonatomic, readonly) PRNavigationBarHairlineStyle navigationBarHairlineStyle;

@property (nonatomic, readonly) PRTheme navigationBarTheme;
@property (nonatomic, readonly) BOOL isNavigationBarTransparent;
@property (nonatomic, readonly) BOOL isNavigationBarHidden;
@property (nonatomic, readonly) BOOL isNeedPostponeNavigationBarHiddenUpdateAfterNavigationCompleted;
@property (nonatomic, readonly) BOOL isNavigationBarCollapsable;

@property (nonatomic, readonly) BOOL isNavigationBarAppearanceManuallyAdjusted;
@property (nonatomic, readonly) BOOL isStatusBarAppearanceManuallyAdjusted;
@property (nonatomic, readonly) BOOL isNavigationBarShadowHidden;

/// set background color of status bar when hiding navigation bar to be the same
@property (nonatomic, readonly) BOOL prefersStatusBarHaveColorOfHiddenNavigationBar;

/// Displays close button in navigation bar when controller is modally presented.
@property (nonatomic, readonly) BOOL needDismissButton;
@property (nonatomic, readonly) PRDismissNavigationButtonStyle dismissButtonStyle;
@property (nullable, nonatomic, readonly) void(^dismissCompletionHandler)(void);

@property (nonatomic, readonly) BOOL needBackButton;
@property (nonatomic, readonly) PRDismissNavigationButtonStyle backButtonStyle;

@property (nonatomic) BOOL discardOnTraitCollectionChanges;

@property (nonatomic, readonly) BOOL isRootInNavigationStack;

- (void)updateNavigationBarItemsAnimated:(BOOL)animated;
- (void)updateNavigationBarItemsAnimated:(BOOL)animated options:(PRNavigationBarRefreshOption)options;

- (void)backButtonAction:(id)sender;
- (void)setShowParams:(NSDictionary*)p;

- (void)setLeftBarButtonItems:(nullable NSArray<UIBarButtonItem *> *)items animated:(BOOL)animated;
- (void)setRightBarButtonItems:(nullable NSArray<UIBarButtonItem *> *)items animated:(BOOL)animated;

@end

NS_ASSUME_NONNULL_END

#import "UIViewController+Search.h"
