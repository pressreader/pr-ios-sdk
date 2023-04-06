//
//  PRTooltipPopoverController.h
//  PRiphone
//
//  Created by Jackie Cane on 16/04/14.
//  Copyright (c) 2014 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PRTooltipsController.h"

@import WYPopoverController;

@interface PRTooltipPopoverController : WYPopoverController<WYPopoverControllerDelegate>

+ (id)tooltipPopoverControllerWithText:(NSString *)text delegate:(id<WYPopoverControllerDelegate>)delegate;
+ (id)tooltipPopoverControllerWithText:(NSString *)text;
- (void)presentInView:(UIView *)view forRect:(CGRect)rect showArrow:(BOOL)showArrow acceptableFrame:(CGRect)acceptableFrame preferableArrowDirection:(WYPopoverArrowDirection)arrowDirection;
- (void)presentInView:(UIView *)view forRect:(CGRect)rect showArrow:(BOOL)showArrow preferableArrowDirection:(WYPopoverArrowDirection)preferableArrowDirection;
- (void)presentInView:(UIView *)view forRect:(CGRect)rect showArrow:(BOOL)showArrow;
- (BOOL)isArrowDirectionAcceptable:(WYPopoverArrowDirection)arrowDirection forRect:(CGRect)rect acceptableFrame:(CGRect)acceptableFrame;

@property (nonatomic) PRTooltipType tooltipType;
@property (nonatomic, strong) id data;

@end
