//
//  PROrderTableViewCell.h
//  PRiphone
//
//  Created by Jackie Cane on 23/01/14.
//  Copyright (c) 2014 NewspaperDirect. All rights reserved.
//

@import UIKit;

NS_ASSUME_NONNULL_BEGIN

// Set horizontalPading parameter to enable "settings like style". Otherwise class behave like a regular UITableViewCell.
@interface PRRoundedTableViewCell : UITableViewCell
@property (nonatomic) CGFloat horizontalPadding;
@property (nonatomic) UIRectCorner roundedCorners;
@property (nonatomic) CGFloat cornerRadius;
@property (nonatomic) CGFloat borderWidth;

@property (nullable, nonatomic, strong) UIColor *borderColor;

@end

NS_ASSUME_NONNULL_END
