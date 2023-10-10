//
//  PROrderInfoBarView.h
//  PR-UI
//
//  Created by Viacheslav Soroka on 12/19/18.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

@import UIKit;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(uint8_t, PROrderInfoBarStyle) {
    PROrderInfoBarStyleDefault = 0,
    PROrderInfoBarStyleLarge
};

@interface PROrderInfoBarView : UIView

+ (instancetype)view;
+ (instancetype)viewWithCID:(NSString *)cid;

@property (nonatomic, strong) NSString *cid;

@property (nonatomic, copy) NSString *titleText;
@property (nonatomic, copy) NSString *detailsText;

@property (nonatomic, readonly) UIView *titleView;

@property (nonatomic) PROrderInfoBarStyle style;

@end

@interface PROrderInfoBarView (/*PROTECTED*/)
@property (nonatomic, strong) IBOutlet UIImageView *mastheadImageView;
@property (nonatomic, strong) IBOutlet NSLayoutConstraint *mastheadHeight;
@property (nonatomic, strong) IBOutlet UILabel *titleLabel;
@property (nonatomic, strong) IBOutlet UILabel *subtitleLabel;
@property (nonatomic, strong) IBOutletCollection(NSLayoutConstraint) NSArray<NSLayoutConstraint *> *spaces;
@end

NS_ASSUME_NONNULL_END
