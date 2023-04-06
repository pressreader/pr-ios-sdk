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
@property (nonatomic, strong) NSString *cid;

@property (nonatomic, copy) NSString *titleText;
@property (nonatomic, copy) NSString *detailsText;

@property (nonatomic, readonly) UIView *titleView;

@property (nonatomic) PROrderInfoBarStyle style;

+ (instancetype)view;
+ (instancetype)viewWithCID:(NSString *)cid;

@end

NS_ASSUME_NONNULL_END
