//
//  PRCatalogSectionHeaderView.h
//  PRUI
//
//  Created by Viacheslav Soroka on 10/15/20.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <PRUI/PRSectionHeaderView.h>

@class PRCatalogSection;
@class PRCatalogSectionHeaderView;

NS_ASSUME_NONNULL_BEGIN

@protocol PRCatalogSectionHeader <NSObject>

@property (class, nonatomic, readonly) UIFont *titleFont;
@property (class, nonatomic, readonly) UIFont *subtitleFont;
@property (class, nonatomic, readonly) UIFont *promptFont;

@property (class, nonatomic, readonly) CGFloat subtitleTopInset;

@end

@interface PRCatalogSectionHeaderView : UICollectionReusableView <PRCatalogSectionHeader>

+ (CGFloat)leftPadding:(BOOL)isRegular;
+ (CGFloat)rightPadding:(BOOL)isRegular;
+ (CGFloat)contentSpacingWithOptions:(PRSectionHeaderViewOption)options;

- (void)fillWithSection:(PRCatalogSection *)section options:(PRSectionHeaderViewOption)options;

@property (nonatomic, weak) id<PRSectionHeaderViewDelegate> delegate;
@property (nonatomic, strong, readonly) PRSectionHeaderView *insetView;

@end

@interface PRFeedCatalogSectionHeaderView : PRCatalogSectionHeaderView
@end

NS_ASSUME_NONNULL_END
