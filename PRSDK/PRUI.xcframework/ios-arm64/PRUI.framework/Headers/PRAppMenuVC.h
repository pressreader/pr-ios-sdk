//
//  PRAppMenuVC.h
//  PRiphone
//
//  Created by Oleg Stepanenko on 24.09.12.
//  Copyright (c) 2012 Newspaperdirect. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PRMenuVC.h"

#import "PRHotspotStatusViewManagerProtocol.h"

@interface PRAppMenuVC : PRMenuVC
@property (nonatomic, strong) UIImageView *logo;

+ (instancetype)controllerWithHotspotStatusViewManager:(id<PRHotspotStatusViewManagerProtocol>)manager;

@end
