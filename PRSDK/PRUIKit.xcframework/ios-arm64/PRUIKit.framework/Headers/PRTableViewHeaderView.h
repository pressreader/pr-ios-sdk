//
//  PRTableViewHeaderView.h
//  PRiphone
//
//  Created by Oleg Stepanenko on 12.07.16.
//  Copyright © 2016 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

@class PRTableViewHeaderView;

@protocol PRTableViewHeaderViewDelegate <NSObject>

@optional
- (void)headerView:(PRTableViewHeaderView *)headerView buttonDidTouch:(NSInteger)tag;
- (void)headerViewDidTap:(PRTableViewHeaderView *)headerView;

@end

@interface PRTableViewHeaderView : UITableViewHeaderFooterView
@property (nonatomic, assign) NSInteger selectedButton;
@property (nonatomic, strong) UIColor *selectedColor;
@property (nonatomic, strong) NSArray *buttons;
@property (nonatomic, assign) CGFloat verticalContentInset;
@property (nonatomic, strong, readonly) UIView *topSeparator;
@property (nonatomic, strong, readonly) UIView *bottomSeparator;

@property (nonatomic, readonly) UILabel *titleLabel;
@property (nonatomic, strong) UIView *rightView;

@property (nonatomic, weak) id<PRTableViewHeaderViewDelegate> delegate;

- (UIButton *)createButton:(NSInteger)tag withImage:(UIImage *)image;

@end
