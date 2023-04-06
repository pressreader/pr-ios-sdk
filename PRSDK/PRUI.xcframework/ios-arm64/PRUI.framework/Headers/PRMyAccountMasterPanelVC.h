//
//  PRMyAccountMasterPanelVC.h
//  PRiphone
//
//  Created by Jackie Cane on 10/01/14.
//  Copyright (c) 2014 NewspaperDirect. All rights reserved.
//


#import "PRUniversalMasterVC.h"

@class PRAccountItem;

NS_ASSUME_NONNULL_BEGIN

@interface PRMyAccountMasterPanelVC : PRUniversalMasterVC

- (void)selectAccount:(PRAccountItem *)account;

@end

NS_ASSUME_NONNULL_END
