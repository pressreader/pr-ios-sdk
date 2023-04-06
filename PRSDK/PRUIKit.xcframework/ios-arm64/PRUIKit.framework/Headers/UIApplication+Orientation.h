//
//  UIApplication+Orientation.h
//  PRUI
//
//  Created by berec on 02/01/2020.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIApplication (Orientation)

- (void)rotateTo:(UIInterfaceOrientation)orientation;

@property (nonatomic, readonly) UIInterfaceOrientation orientation;

@end

NS_ASSUME_NONNULL_END
