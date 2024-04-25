//
//  PROrderView.h
//  PRUI
//
//  Created by Viacheslav Soroka on 6/4/19.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

@import UIKit;

NS_ASSUME_NONNULL_BEGIN

@class PROrderThumbnailView;

@interface PROrderView : UIView

- (void)updateSafeAreaInsets;

- (void)showIssuesRemainingViewWithCount:(nullable NSNumber *)count;

- (void)loadTableView;

- (void)updateAppearanceSettings:(BOOL)isRegular;

@property (class, nonatomic, readonly) CGFloat issuesRemainingViewHeight;

@property (nonatomic, readonly) CGSize calendarSize;
@property (nonatomic, readonly) UIColor *defaultBackgroundColor;

@property (nonatomic, strong, readonly) UIView *collectionTitleView;
@property (nonatomic, readonly) BOOL collectionTitleViewContainsCoBranding;
@property (nonatomic) UIEdgeInsets collectionTitleViewInsets;

@property (nonatomic, strong) PROrderThumbnailView *thumbnailView;
@property (nonatomic, strong) UITableView *tableView;

@property (nonatomic, strong, readonly) UIColor *cellColor;
@property (nonatomic, strong, readonly) UIColor *cellTextColor;

@end

NS_ASSUME_NONNULL_END
