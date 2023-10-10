//
//  PRSelectionPanelVC.h
//  PRiphone
//
//  Created by Oleg Stepanenko on 04/11/16.
//  Copyright (c) 2016 NewspaperDirect. All rights reserved.
//

#import "PRSettingsDetailsPanelVC.h"

@interface PRSelectionPanelVC : PRSettingsDetailsPanelVC
@property (nonatomic) NSInteger selectedIndex;
@property (nonatomic, copy) NSArray<NSString *> *options;
@property (nonatomic, copy) void (^blockOnSelect)(NSInteger index);
@end
