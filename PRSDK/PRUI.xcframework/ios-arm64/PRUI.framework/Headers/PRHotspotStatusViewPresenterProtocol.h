//
//  PRHotspotStatusViewPresenterProtocol.h
//  PRiphone
//
//  Created by Viacheslav Soroka on 11/11/16.
//  Copyright © 2016 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol PRHotspotStatusViewPresenterProtocol <NSObject>

- (void)showHotspotStatusView:(UIView *)view additionalViews:(NSArray *)views;
- (void)hideHotspotStatusView:(UIView *)view additionalViews:(NSArray *)views;

@end
