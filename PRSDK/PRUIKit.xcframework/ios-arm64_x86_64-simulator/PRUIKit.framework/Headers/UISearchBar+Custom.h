//
//  UISearchBar+Custom.h
//  PRiphone
//
//  Created by Jackie Cane on 11/28/12.
//  Copyright (c) 2012 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UISearchBar (Custom)

- (void)setSearchIconColor:(UIColor *)color;
- (void)setClearIconColor:(UIColor *)color;

/// WORKAROUND to restore search bar's tint color which can be overridden by system in some scenarious
- (void)restoreTintColor;

@property (nullable, nonatomic, readonly) UIButton *cancelButton;
@property (nullable, nonatomic, readonly) UIView *barBackground;

@property (nonatomic) BOOL centersPlaceholder;

@end

NS_ASSUME_NONNULL_END
