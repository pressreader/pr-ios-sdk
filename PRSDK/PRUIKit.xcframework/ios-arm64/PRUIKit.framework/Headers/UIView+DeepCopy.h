//
//  UIView+DeepCopy.h
//  PR-UI
//
//  Created by Viacheslav Soroka on 4/11/19.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIView (DeepCopy)

- (instancetype)deepCopy;

@end

NS_ASSUME_NONNULL_END
