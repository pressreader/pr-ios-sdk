//
//  PRActionMenuVC.h
//  PRiphone
//
//  Created by Oleg Stepanenko on 16.12.13.
//  Copyright (c) 2013 NewspaperDirect. All rights reserved.
//

@import PRUIKit.PRCommand;
@import PRUIKit.PRAppStyle_Theme;

NS_ASSUME_NONNULL_BEGIN

extern CGFloat const kAMHeaderHeight;

@class PRMenu;
@class PRMenuItem;
@class PRScrollAnimationSynchronizer;

@interface PRActionMenuVC: UIViewController<UITableViewDataSource, UITableViewDelegate, PRActionMenu>

@property (nonatomic) CGSize estimatedPreferredContentSize;

@property (nonatomic, strong, readonly) UITableView *tableView;

@property (nullable, nonatomic, strong) PRMenu *menu;
@property (nullable, nonatomic, strong) NSIndexPath *initialMenuIndexPath;

@property (nonatomic, strong) NSArray<UIBarButtonItem *> *toolbarItems;

@property (nullable, nonatomic, copy) void (^menuItemDidSelectBlock)(__kindof PRMenuItem *menuItem, void (^completionBlock)(void));
@property (nullable, nonatomic, copy) void (^onMenuDidDismiss)(void);

@property (nonatomic, copy, nullable) void(^configureOnViewDidLoad)(__kindof PRActionMenuVC *actionMenuVC);
@property (nonatomic, copy, nullable) void(^willDisplayCell)(__kindof PRActionMenuVC *actionMenuVC, UITableViewCell *cell, NSIndexPath *menuIndexPath);
@property (nonatomic, copy, nullable) void(^onScrollViewDidScroll)(__kindof UIScrollView *scrollView);
@property (nonatomic, strong, nullable) PRScrollAnimationSynchronizer *scrollSynchronizer;
@property (nonatomic) UIEdgeInsets cellContentInset;
@property (nonatomic) CGFloat maximumWidth;

@property (nonatomic, strong, nullable) UIView *navigationBarBootomView;

@property (nonatomic, strong) UIColor *contentTintColor;
@property (nonatomic, strong) UIColor *highlightedContentTintColor;
@property (nonatomic, strong) UIColor *selectedContentTintColor;

@end

NS_ASSUME_NONNULL_END
