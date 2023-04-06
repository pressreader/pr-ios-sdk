//
//  VerticalTextFlowBaseCell.h
//  PRiphone
//
//  Created by Vitali Bounine on 2016-07-12.
//  Copyright © 2016 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "PRAnimatableOnScroll.h"

@class NTFDataSource;

NS_ASSUME_NONNULL_BEGIN

extern CGFloat const kVerticalTextFlowSeparatorHeight;
extern CGFloat const kVerticalTextFlowSeparatorHeightExtra;
extern CGFloat const kPRDefaultDistanceDivisor;

typedef void(^TextFlowItemAction)(id flowItem,
                                  __nullable id sender,
                                  void(^_Nullable completionHandler)(void));

typedef NS_ENUM(NSInteger, PRVerticalTextFlowSeparatorStyle) {
    PRVerticalTextFlowSeparatorStyleNone = 0,
    PRVerticalTextFlowSeparatorStyleThin,
    PRVerticalTextFlowSeparatorStyleThick,
    PRVerticalTextFlowSeparatorStyleThickExtra
};

@interface VerticalTextFlowBaseCell : UITableViewCell <PRAnimatableOnScroll>

+ (CGFloat)estimatedHeightForRowWithTableViewHeight:(CGFloat)tableViewHeight;

- (void)setupWithRow:(NSInteger)row
          dataSource:(nullable NTFDataSource *)dataSource
         actionBlock:(nullable TextFlowItemAction)actionBlock
        contentWidth:(CGFloat)contentWidth;

@property (nonatomic) CGFloat contentWidth;
@property (nonatomic, copy) TextFlowItemAction actionBlock;

@property (nonatomic, readonly) NSInteger fontSizeAdjustment;

@property (nonatomic, assign) PRVerticalTextFlowSeparatorStyle topSeparatorStyle;
@property (nonatomic, assign) PRVerticalTextFlowSeparatorStyle bottomSeparatorStyle;

@property (nullable, nonatomic, strong) UIColor *topSeparatorColor;
@property (nullable, nonatomic, strong) UIColor *bottomSeparatorColor;

@property (nonatomic) NSNumber *topPadding;
@property (nonatomic) NSNumber *bottomPadding;

@property (nonatomic, assign) CGFloat animationDistanceDivisor;

@property (nonatomic) UIEdgeInsets contentInsets;

@property (nonatomic) BOOL offlineMode;

@property (nonatomic, readonly) UIView *contentView NS_UNAVAILABLE;
@property (nonatomic, strong, readonly) UIView *customContentView;

@end

NS_ASSUME_NONNULL_END
