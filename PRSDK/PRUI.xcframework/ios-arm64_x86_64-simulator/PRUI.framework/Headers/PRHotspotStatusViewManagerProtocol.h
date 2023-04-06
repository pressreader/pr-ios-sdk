//
//  PRHotspotStatusViewManagerProtocol.h
//  PRiphone
//
//  Created by Viacheslav Soroka on 11/11/16.
//  Copyright © 2016 NewspaperDirect. All rights reserved.
//

@import UIKit;

#import "PRHotspotStatusViewPresenterProtocol.h"

NS_ASSUME_NONNULL_BEGIN

extern const NSInteger kPRStatusViewTag;

@protocol PRHotspotStatusViewManagerProtocol <NSObject>
@property (nonatomic, assign) id<PRHotspotStatusViewPresenterProtocol> presenter;
@property (nonatomic, assign) CGSize statusViewSize;

@property (nonatomic, readonly) UIView *statusView;
@property (nonatomic, readonly) NSArray *additionalViews;

- (UIColor *)colorForCurrentStatus;

@end

NS_ASSUME_NONNULL_END
