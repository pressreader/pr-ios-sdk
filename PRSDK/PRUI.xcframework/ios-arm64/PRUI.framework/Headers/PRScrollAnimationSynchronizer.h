//
//  PRScrollAnimationSynchronizer.h
//  PR-UI
//
//  Created by Viacheslav Soroka on 1/17/19.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

@import UIKit;

NS_ASSUME_NONNULL_BEGIN

@interface PRScrollAnimationSynchronizer : NSObject

+ (instancetype)synchronizerWithScrollSubview:(UIView *)subview
                                viewToAnimate:(UIView *)view;
+ (instancetype)synchronizerWithScrollSubview:(UIView *)subview
                                viewToAnimate:(UIView *)view
                                   startScale:(CGFloat)startScale
                                     endScale:(CGFloat)endScale;

- (void)onScrollViewDidScroll;

@end

NS_ASSUME_NONNULL_END
