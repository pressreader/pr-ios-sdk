//
//  PRHotspotStatusViewManager.h
//  PRiphone
//
//  Created by Viacheslav Soroka on 11/10/16.
//  Copyright © 2016 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "PRHotspotStatusViewManagerProtocol.h"

/**
 * This class was intended only for subclassing. You shouldn't instantiate it directly.
 */
@interface PRHotspotStatusViewManager : NSObject <PRHotspotStatusViewManagerProtocol>
@property (nonatomic, readonly) NSInteger viewsCount;

+ (instancetype)manager;
+ (instancetype)managerWithViewsCount:(NSInteger)viewsCount;
+ (instancetype)managerWithPresenter:(id<PRHotspotStatusViewPresenterProtocol>)presenter;

- (instancetype)initWithPresenter:(id<PRHotspotStatusViewPresenterProtocol>)presenter;

/**
 This method was intender for subclassing as entry point. Default implementation does nothing. 
 */
- (void)updateStatusView:(UIView *)view;
- (void)updateStatusViewSize:(UIView *)view;

/**
 This method was intender for subclassing and should never being called directly.
 */
- (UIView *)initiatedStatusView;

@end
