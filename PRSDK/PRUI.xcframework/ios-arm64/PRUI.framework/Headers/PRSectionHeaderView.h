//
//  PRSectionHeaderView.h
//  PRUI
//
//  Created by Artem Serbin on 23.04.2021.
//  Copyright © 2021 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

@class PRSeeAllButton;
@class PRSectionHeaderViewModel;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, PRSectionHeaderStyle) {
    PRSectionHeaderStyleDefault,
    PRSectionHeaderStyleFeed
};

@protocol PRSectionHeaderViewDelegate <NSObject>

- (void)headerViewDidReceiveSeeAllTap:(UIButton *)seeAllButton;

@end

extern CGFloat const kSeeAllButtonWidth;

typedef NS_OPTIONS(NSUInteger, PRSectionHeaderViewOption) {
    PRSectionHeaderViewOptionShowSeeAllButton = 1 << 0,
    PRSectionHeaderViewOptionShowTopHairline = 1 << 1,
    PRSectionHeaderViewOptionShowNewIndicator = 1 << 2,
    PRSectionHeaderViewOptionPromptOnTop = 1 << 3
};

@interface PRSectionHeaderView : UIView

+ (UIFont *)titleFontWithStyle:(PRSectionHeaderStyle)style;
+ (UIFont *)subtitleFont;
+ (UIFont *)promptFont;
+ (CGFloat)subtitleTopInset;
+ (CGFloat)brandNewIndicatorWidth;
+ (CGFloat)titleStackSpacing;

- (instancetype)initWithStyle:(PRSectionHeaderStyle)style;

@property (nonatomic, weak) id<PRSectionHeaderViewDelegate> delegate;
@property (nonatomic) PRSectionHeaderViewOption options;
@property (nonatomic) PRSectionHeaderViewModel *viewModel;

@end

NS_ASSUME_NONNULL_END
