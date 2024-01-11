//
//  PRCatalogFilterTableCell.h
//  PR-UI
//
//  Created by Viacheslav Soroka on 2/22/19.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

@import UIKit;

@class PRThumbnailObject;

NS_ASSUME_NONNULL_BEGIN

extern const CGFloat kPRCatalogFilterCellPadding;

@interface PRCatalogFilterTableCell : UITableViewCell
@property (nonatomic, strong) UIStackView *stackView;
@property (nonatomic, strong) NSLayoutConstraint *rightPaddingConstraint;
@property (nonatomic, strong) NSLayoutConstraint *leftPaddingConstraint;
@property (nonatomic, strong) NSLayoutConstraint *bottomPaddingConstraint;
@property (nonatomic, strong) NSLayoutConstraint *topPaddingConstraint;
@property (nonatomic, strong) UIImageView *thumbnailView;
@property (nonatomic, strong) UILabel *titleLabel;
@property (nonatomic, strong) UILabel *accessoryLabel;

@property (nullable, nonatomic, strong) PRThumbnailObject *thumbnail;
@property (nonatomic) BOOL enableCustomRightPadding;

@end

NS_ASSUME_NONNULL_END
