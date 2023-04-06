//
//  PRMenuVC.h
//  PRiphone
//
//  Created by Oleg Stepanenko on 18.10.12.
//  Copyright (c) 2012 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "PRMenuView.h"
@class PRMenu;

NS_ASSUME_NONNULL_BEGIN

@protocol PRMenuVCDelegate<NSObject>

@optional
- (void)menu:(PRMenu *)menu itemDidSelect:(NSIndexPath *)indexPath;
@end

@class PRMenuItem, PRActionMenuVC;

@interface PRMenuVC :  UIViewController <PRMenuViewDelegate, UIPopoverPresentationControllerDelegate>

- (void)reloadData;
- (PRMenuViewCell *)setupCell:(PRMenuViewCell *)cell withMenuItem:(__kindof PRMenuItem *)item;
- (UITableViewCell *)setupSubmenuCell:(UITableViewCell *)cell withMenuItem:(__kindof PRMenuItem *)item;
- (void)presentViewController:(UIViewController *)vc fromMenuItem:(PRMenuItem *)menuItem backgroundColor:(nullable UIColor *)bgColor;

@property (nonatomic) PRMenuViewStyle menuViewStyle;
@property (nonatomic, readonly) BOOL isMenuVertical;

@property (nullable, nonatomic, strong) PRMenu *menu;
@property (nonatomic, strong, readonly) PRMenuView *menuView;
@property (nullable, nonatomic, strong, readonly) PRMenuItem *moreItem;
@property (nullable, nonatomic, copy) void (^submenuDidDismissBlock)(PRMenuItem *submenuItem);

// for overriding
- (void)configureMoreMenuVC:(PRActionMenuVC *)moreMenuVC;
- (void)moreMenuDidSelectItem:(PRMenuItem *)menuItem;

@end

NS_ASSUME_NONNULL_END
