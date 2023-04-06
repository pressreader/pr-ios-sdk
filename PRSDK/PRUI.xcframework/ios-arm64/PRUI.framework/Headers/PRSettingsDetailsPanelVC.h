//
//  PRSettingsDetailsPanelVC.h
//  PRiphone
//
//  Created by Jackie Cane on 10/1/13.
//  Copyright (c) 2013 NewspaperDirect. All rights reserved.
//

#import "PRStylingTableVC.h"

NS_ASSUME_NONNULL_BEGIN

@interface PRSettingsDetailsPanelVC : PRStylingTableVC

- (instancetype)initWithNibName:(nullable NSString *)nibNameOrNil bundle:(nullable NSBundle *)nibBundleOrNil NS_UNAVAILABLE;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;

- (UISwitch *)newSwitchWithValue:(BOOL)value action:(SEL)selector;

- (UITableViewCell *)tableView:(UITableView *)tableView
                 cellWithStyle:(UITableViewCellStyle)style
               reuseIdentifier:(NSString *)reuseIdentifier;

- (UITableViewCell *)tableView:(UITableView *)tableView
 optionCellWithReuseIdentifier:(NSString *)reuseIdentifier;

- (UITableViewCell *)tableView:(UITableView *)tableView
           switchCellWithTitle:(NSString *)title
                   detailsText:(nullable NSString *)detailsText
                      switchOn:(BOOL)switchOn
                  switchAction:(SEL)action;

@end

NS_ASSUME_NONNULL_END
