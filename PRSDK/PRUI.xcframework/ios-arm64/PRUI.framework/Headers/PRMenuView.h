//
//  PRMenuView.h
//  PressReader
//
//  Created by Oleg Stepanenko on 12.03.16.
//  Copyright © 2016 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PRMenuViewCell.h"

typedef NS_ENUM(NSInteger, PRMenuViewStyle) {
    PRMenuViewStyleNotDefined,
    PRMenuViewStyleVertical,
    PRMenuViewStyleHorizontal,
    PRMenuViewStyleVerticalWideSpaced
};

@class PRMenuView;

NS_ASSUME_NONNULL_BEGIN

@protocol PRMenuViewDelegate<NSObject>

@required
- (NSInteger)menuView:(PRMenuView *)menuView numberOfCellInSection:(NSInteger)section;
- (PRMenuViewCell *)menuView:(PRMenuView *)menuView setupCell:(PRMenuViewCell *)cell forIndexPath:(NSIndexPath *)indexPath;
- (PRMenuViewCell *)menuView:(PRMenuView *)menuView setupAsMoreCell:(PRMenuViewCell *)cell;

@optional
- (NSInteger)numberOfSectionsInMenuView:(PRMenuView *)menuView; // Default is 1 if not implemented
- (void)menuView:(PRMenuView *)menuView willDisplayCell:(PRMenuViewCell *)cell atIndexPath:(NSIndexPath *)indexPath;
- (CGFloat)menuView:(PRMenuView *)menuView leadingSizeInSection:(NSInteger)section;
- (CGFloat)menuView:(PRMenuView *)menuView trailingSizeInSection:(NSInteger)section;
- (BOOL)menuView:(PRMenuView *)menuView shouldHighlightCellAtIndexPath:(NSIndexPath *)indexPath;
- (void)menuView:(PRMenuView *)menuView didSelectCellAtIndexPath:(NSIndexPath *)indexPath;
- (void)didSelectMoreInMenuView:(PRMenuView *)menuView;
- (NSInteger)menuView:(PRMenuView *)menuView maxNumberOfItemsInSection:(NSInteger)section;

@end

@interface PRMenuView : UIView

+ (CGSize)requiredSizeForStyle:(PRMenuViewStyle)style;

@property (nonatomic, readonly) CGFloat menuSize; //width for vertical menu or height for horizontal
@property (nonatomic, readonly) CGSize contentSize;
@property (nonatomic) PRMenuViewStyle style;
@property (nullable, nonatomic, readonly) NSIndexPath *moreItemIndexPath;
@property (nullable, nonatomic, weak) id<PRMenuViewDelegate> delegate;
@property (nonatomic) UIEdgeInsets contentInset;// default UIEdgeInsetsZero
@property (nonatomic, copy, readonly) NSDictionary <NSIndexPath *, PRMenuViewCell *> *cells;
@property (nonatomic, readonly) CGSize cellSize;
@property (nonatomic, readonly) CGFloat cellMargin;
@property (nonatomic, assign) BOOL distributed;
@property (nonatomic) CGFloat indicatorSize;
@property (nonatomic) CGFloat sectionLeadingSize;
@property (nonatomic) CGFloat sectionTrailingSize;
@property (nonatomic) CGFloat prefIconTextSpacingConstant;
@property (nonatomic, assign) NSInteger maxNumberOfItems;
@property (nullable, nonatomic, strong) UIColor *cellColor;
@property (nullable, nonatomic, strong) UIColor *cellImageColor;
@property (nullable, nonatomic, strong) UIColor *cellSelectionColor;
@property (nullable, nonatomic, strong) NSIndexPath *selectedIndex;
@property (nonatomic) BOOL selectionColorEnabled;
@property (nonatomic, assign) BOOL ignoreSafeArea;
@property (nonatomic, assign) BOOL hideText;
@property (nonatomic, assign) BOOL disableGradient;
@property (nonatomic, assign) BOOL showTextIfNoImage;

@property (nonatomic, readonly) BOOL vertical;

- (void)setSelectedIndex:(nullable NSIndexPath *)selectedIndex animated:(BOOL)animated;

- (nullable NSIndexPath *)indexPathForCell:(PRMenuViewCell *)cell;
- (void)doSelectCellAtIndexPath:(NSIndexPath *)indexPath;
- (void)doSelectDisabledCellAtIndexPath:(NSIndexPath *)indexPath;
- (void)selectMoreCell;
- (void)selectMoreCellAnimated:(BOOL)animated;
- (CGRect)rectForIndexPath:(NSIndexPath *)indexPath;
- (NSArray<PRMenuViewCell *> *)visibleCells;

- (void)reloadData;
- (void)refreshCells:(nullable NSSet<NSIndexPath *> *)indexPaths;
- (void)layoutMenuItems;

- (CGSize)requiredSizeForStyle:(PRMenuViewStyle)style;
- (void)refreshSelectedCell;

@end

NS_ASSUME_NONNULL_END
