//
//  PRAccountInfoCell.h
//  PRiphone
//
//  Created by Jackie Cane on 01/08/14.
//  Copyright (c) 2014 NewspaperDirect. All rights reserved.
//

@import PRUIKit.PRRoundedTableViewCell;

@class PRAccountItem;

NS_ASSUME_NONNULL_BEGIN

@protocol PRAccountInfoCellDelegate <NSObject>

- (void)editAccountPicture:(UIView *)sourceView;

@end

@interface PRAccountInfoCell : PRRoundedTableViewCell<UITableViewDataSource, UITableViewDelegate>

- (void)showActivityIndicator:(BOOL)show;
- (void)updateAccountPicture;

@property (nonatomic, weak) UIViewController<PRAccountInfoCellDelegate> *delegate;
@property (nonatomic, weak) PRAccountItem *account;
@property (nonatomic, strong, readonly) UIImageView *accountPictureView;

@end

NS_ASSUME_NONNULL_END
