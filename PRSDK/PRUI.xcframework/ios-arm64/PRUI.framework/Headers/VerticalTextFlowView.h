//
//  VerticalTextFlowView.h
//  PR-UI
//
//  Created by berec on 31/03/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import "PRImageSwitcher.h"

@import PRAPI.NTFArticle;

@class PRMenu;
@class TranslationView;

NS_ASSUME_NONNULL_BEGIN

@protocol VerticalTextFlowViewDelegate <NSObject, UITableViewDataSource, UITableViewDelegate>

@property (nonatomic, readonly) PRMenu *actionMenu;

@end

@interface VerticalTextFlowView : UIView

- (void)reloadData;
- (void)refreshMenuBar;
- (void)showMenuBarAnimated:(BOOL)animated;

- (void)updateReplicaThumbnailWithArticle:(id<NTFArticle>)article
                                animation:(PRImageSwitcherAnimationStyle)animation;

- (void)insertTopAdView:(nullable UIView *)view height:(CGFloat)height;
- (void)insertBottomAdView:(nullable UIView *)view height:(CGFloat)height;

- (UIView *)defaultTableHeaderFooter;

@property (nonatomic, weak) UIViewController<VerticalTextFlowViewDelegate> *delegate;

@property (nonatomic, strong, readonly) UITableView *tableView;

@property (nonatomic) BOOL offlineMode;

@property (nonatomic, readonly) BOOL shouldBackgroundMatchNavigationBar;

@property (nonatomic, readonly) CGFloat minPlaceholderHeight;
@property (nullable, nonatomic, strong, readonly) TranslationView *translationView;
@end

NS_ASSUME_NONNULL_END
