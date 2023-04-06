//
//  PRPopoverBackgroundView.h
//  PRiphone
//
//  Created by Jackie Cane on 1/17/13.
//  Copyright (c) 2013 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/// PopoverBackgroundView without taking in account arrow view.
/// Can be used for skinning PopoverControllers which are presented with permittedArrowDirections == 0.
@interface PRPopoverBackgroundView : UIPopoverBackgroundView
- (instancetype)initWithFrame:(CGRect)frame
                  borderColor:(nullable UIColor *)borderColor
                   arrowColor:(nullable UIColor *)arrowColor;

@end

/// Shades underneath area
@interface PRPopoverDimmingBackgroundView : PRPopoverBackgroundView
@end

NS_ASSUME_NONNULL_END
