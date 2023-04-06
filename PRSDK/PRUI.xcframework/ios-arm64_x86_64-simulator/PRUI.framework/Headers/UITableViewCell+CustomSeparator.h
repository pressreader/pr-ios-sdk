//
//  UITableViewCell+CustomSeparator.h
//  PR-UI
//
//  Created by Viacheslav Soroka on 6/18/19.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

@import UIKit;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(uint8_t, PRSeparatorStyle) {
    PRSeparatorStyleThin = 0,
    PRSeparatorStyleThick
};

@interface UITableViewCell (CustomSeparator)
@property (nonatomic) BOOL useCustomSeparators;
@property (nonatomic) PRSeparatorStyle customSeparatorStyle;

@property (nullable, nonatomic, strong) UIColor *customSeparatorColor;
@property (nonatomic, getter=isTopSeparatorVisible) BOOL topSeparatorVisible;
@property (nonatomic, getter=isBottomSeparatorVisible) BOOL bottomSeparatorVisible;

- (void)setCustomSeparatorInsets:(UIEdgeInsets)separatorInsets top:(BOOL)top;
@end

NS_ASSUME_NONNULL_END
