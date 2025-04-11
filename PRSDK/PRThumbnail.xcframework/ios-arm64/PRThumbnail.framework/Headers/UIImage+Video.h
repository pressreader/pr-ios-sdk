//
//  UIImage+Video.h
//  PR-UI
//
//  Created by berec on 26/07/2018.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIImage (Video)

- (UIImage *)imageWithVideoIcon;
- (UIImage *)imageWithVideoIconAtPoint:(CGPoint)point;

@property (class, nonatomic, readonly) UIImage *videoIcon;

@end

NS_ASSUME_NONNULL_END
