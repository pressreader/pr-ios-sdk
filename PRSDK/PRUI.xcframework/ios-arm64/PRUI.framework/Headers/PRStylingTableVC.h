//
//  PRStylingTableVC.h
//  PR-UI
//
//  Created by Vitali Bounine on 2019-04-18.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

@import UIKit;
@import PRUIKit;

NS_ASSUME_NONNULL_BEGIN

@interface PRStylingTableVC : UITableViewController
@property (nonatomic) BOOL shouldUpdateTableViewAppearance;

@property (nonatomic) AppearanceOption *appearanceOptions;

- (void)updateAppearance;

@end

NS_ASSUME_NONNULL_END
