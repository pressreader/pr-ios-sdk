//
//  PROnlineViewCtrl.h
//  PRiphone
//
//  Created by Dmitry Melnik on 15/04/09.
//  Copyright 2009 NewspaperDirect. All rights reserved.
//

@import PRUIKit;
#import <PRUI/PRAppPanel.h>

@class PRAccountItem;

@interface PROnlineViewCtrl : PRSafariVC

@property (nonatomic, strong) PRAccountItem* ai;

- (void)autoSignInAccount:(PRAccountItem*)accountItem;
- (void)setPrevPanelId:(PRPanelId)prevPanelId andEnableBackButton:(BOOL)enabled;

@end
