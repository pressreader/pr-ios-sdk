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

@property (nonatomic, readonly) BOOL isNavigationBarHidden;
@property (nonatomic, readonly) BOOL postponeNavigationBarHiddenUpdateUntilNavigationCompleted;

@property (nonatomic, readonly) BOOL isStatusBarAppearanceManuallyAdjusted;

/// Displays close button in navigation bar when controller is modally presented.
@property (nonatomic, readonly) BOOL needDismissButton;
@property (nonatomic, readonly) PRDismissNavigationButtonStyle dismissButtonStyle;
@property (nullable, nonatomic, readonly) void(^dismissCompletionHandler)(void);

@property (nonatomic, readonly) BOOL needBackButton;
@property (nonatomic, readonly) PRDismissNavigationButtonStyle backButtonStyle;

@property (nonatomic) BOOL discardOnTraitCollectionChanges;

- (void)updateNavigationBarItemsAnimated:(BOOL)animated;
- (void)updateNavigationBarItemsAnimated:(BOOL)animated options:(PRNavigationBarRefreshOption)options;

- (void)backButtonAction:(id)sender;
- (void)setShowParams:(NSDictionary*)p;

- (void)setLeftBarButtonItems:(nullable NSArray<UIBarButtonItem *> *)items animated:(BOOL)animated;
- (void)setRightBarButtonItems:(nullable NSArray<UIBarButtonItem *> *)items animated:(BOOL)animated;

@end

NS_ASSUME_NONNULL_END

#import "UIViewController+Search.h"
