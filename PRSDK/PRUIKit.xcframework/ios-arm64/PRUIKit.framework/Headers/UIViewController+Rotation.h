//
//  UIViewController+Rotation.h
//  PR-UI
//
//  Created by berec on 02/08/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIViewController (Rotation)
@property (nonatomic, readonly) BOOL isLandscape;
@property (nonatomic, readonly) BOOL isRotationSupported;

@property (nonatomic, readonly) UIInterfaceOrientationMask pr_supportedInterfaceOrientations;
@property (nonatomic, readonly) UIInterfaceOrientation pr_preferredInterfaceOrientationForPresentation;

@end

NS_ASSUME_NONNULL_END
