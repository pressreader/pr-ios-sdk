//
//  PRMenuViewCell.h
//  PressReader
//
//  Created by Oleg Stepanenko on 12.03.16.
//  Copyright © 2016 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

@class PRMenuView;

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(uint8_t, PRMenuCellOptions) {
    PRMenuCellOptionNone = 0,
    PRMenuCellOptionIgnoreSafeArea = 1 << 0,
    PRMenuCellOptionHideText = 1 << 1,
    PRMenuCellOptionShowTextIfNoImage = 1 << 2
};

@interface PRMenuViewCell : UIView

@property (nullable, nonatomic, readonly) UIImageView *imageView;
@property (nullable, nonatomic, readonly) UILabel *textLabel;
@property (nonnull, nonatomic, readonly) UIView *contentView;

@property (nullable, nonatomic, strong) UIView *selectedBackgroundView;
@property (nullable, nonatomic, strong) UIColor *color;
@property (nullable, nonatomic, strong) UIColor *imageColor;
@property (nullable, nonatomic, strong) UIColor *selectionColor;
@property (nullable, nonatomic, strong) UIColor *backgroundHighlightColor;

@property (nonatomic, getter=isEnabled) BOOL enabled;
@property (nonatomic, getter=isSelected) BOOL selected;
@property (nonatomic, getter=isHighlighted) BOOL highlighted;
@property (nonatomic) PRMenuCellOptions options;

- (void)setSelected:(BOOL)selected animated:(BOOL)animated;
- (void)setHighlighted:(BOOL)highlighted animated:(BOOL)animated;
- (void)updateStackViewIconTextSpacingConstant:(CGFloat)spacingConstant;

@property (nullable, nonatomic, strong) NSArray<NSLayoutConstraint *> *sizeConstraints;

+ (instancetype)cellWithFrame:(CGRect)frame
                     menuView:(PRMenuView *)menuView
                      options:(PRMenuCellOptions)options;

- (instancetype)initWithFrame:(CGRect)frame
                     menuView:(PRMenuView *)menuView
                      options:(PRMenuCellOptions)options NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;
- (instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
