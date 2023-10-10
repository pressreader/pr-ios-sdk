//
//  UIButton+AppStyle.h
//  PR-UI
//
//  Created by berec on 12/09/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PRAppStyleProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface UIButton (AppStyle)<PRAppStyleProtocol>

- (void)applyActionStyle;
- (void)applyWhiteStyle;
- (void)applyClearActionStyleWithCornerStyle:(UIButtonConfigurationCornerStyle)cornerStyle;

- (UIColor *)actionButtonColor;

@end

NS_ASSUME_NONNULL_END
