//
//  UIView+Nib.h
//  PRiphone
//
//  Created by Viacheslav Soroka on 3/13/17.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIView (Nib)

+ (nullable instancetype)viewWithNibName:(NSString *)nibName;
+ (nullable instancetype)viewWithDefaultNibName NS_SWIFT_NAME(viewWithDefaultNibName());

@end

NS_ASSUME_NONNULL_END
