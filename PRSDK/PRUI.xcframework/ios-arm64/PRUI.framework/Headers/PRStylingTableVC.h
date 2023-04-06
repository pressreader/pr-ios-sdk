//
//  PRStylingTableVC.h
//  PR-UI
//
//  Created by Vitali Bounine on 2019-04-18.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

@import UIKit;
@import PRUIKit.UIView_Theme;

NS_ASSUME_NONNULL_BEGIN

@interface PRStylingTableVC : UITableViewController

@property (nonatomic) BOOL autoUpdateNavigationBarOnScroll;
@property (nonatomic) BOOL shouldUpdateTableViewAppearance;

@property (nonatomic) PRAppearanceOption appearanceOptions;

#pragma mark - override

- (void)updateAppearance;

@end

NS_ASSUME_NONNULL_END
