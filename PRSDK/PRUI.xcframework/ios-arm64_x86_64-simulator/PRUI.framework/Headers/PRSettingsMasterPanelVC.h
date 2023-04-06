//
//  PRSettingsMasterPanelVC.h
//  PRiphone
//
//  Created by Jackie Cane on 10/1/13.
//  Copyright (c) 2013 NewspaperDirect. All rights reserved.
//

#import "PRUniversalMasterVC.h"

NS_ASSUME_NONNULL_BEGIN

@interface PRSettingsMasterPanelVC : PRUniversalMasterVC

- (void)selectSettingsByName:(NSString *)title;
- (void)presentDetailsVC:(Class)SettingsDetailsPanelClass withTitle:(nullable NSString *)title;

// to override
- (nullable NSString *)titleForRowAtIndexPath:(NSIndexPath *)indexPath;
- (nullable Class)settingsDetailsPanelClassAtIndexPath:(NSIndexPath *)indexPath;

@end

NS_ASSUME_NONNULL_END
