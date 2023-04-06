//
//  PRTooltipDelegate.h
//  PRiphone
//
//  Created by Jackie Cane on 23/04/14.
//  Copyright (c) 2014 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PRTooltipPopoverController.h"

@protocol PRTooltipVCProtocol <NSObject>
- (BOOL)showTooltips;
- (void)showTooltipsAfterDelay:(NSTimeInterval)delay;
@optional
- (void)tooltipDelegateDidDismissTooltips;
@end


@interface PRTooltipDelegate : NSObject

+ (BOOL)isTooltipsAreEligibleForController:(UIViewController *)controller;
+ (BOOL)isAnyTooltipActive;

- (id)initWithTooltipVC:(UIViewController<PRTooltipVCProtocol> *)tooltipVC;
- (PRTooltipPopoverController *)tooltipWithText:(NSString *)text;
- (void)hideTooltips;

// YES by default
@property (nonatomic) BOOL dismissAllTooltipsAtOnce;
@property (nonatomic, strong, readonly) NSMutableArray *tooltips;

@end
