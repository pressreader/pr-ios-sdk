//
//  PREditAccountVC.h
//  PressReader
//
//  Created by Oleg Stepanenko on 14.03.17.
//  Copyright © 2017 Newspaperdirect. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PRStylingTableVC.h"

@class PRAccountItem;

NS_ASSUME_NONNULL_BEGIN
@interface PREditAccountVC : PRStylingTableVC
+ (PREditAccountVC *)editAccount:(PRAccountItem *)accountItem;
+ (PREditAccountVC *)editAccount:(PRAccountItem *)accountItem displayEditorialAndPasswordField:(BOOL)display;

@property (nonatomic, strong, readonly) PRAccountItem *accountItem;
@property (nonatomic, strong, readonly) UIBarButtonItem *closeButton;
@property (nonatomic) BOOL displayEditorialAndPasswordField;

@end
NS_ASSUME_NONNULL_END
