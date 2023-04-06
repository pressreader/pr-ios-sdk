//
//  UIView+Drawing.h
//  PR-API
//
//  Created by Viacheslav Soroka on 9/19/18.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIView (Drawing)

///Draw view hierarchy
- (nullable UIImage *)snapshot;
- (nullable UIImage *)snapshotOfRect:(CGRect)rect;
- (nullable UIImage *)snapshotOfRect:(CGRect)rect scale:(CGFloat)scale;


/// Draw view layer on the graphic context.
/// In case view is NOT added to the views stack, it won't be rendered on the context correctly (just black image).
/// In case of view layer, it works correctly.
- (nullable UIImage *)layerSnapshot;
- (nullable UIImage *)layerSnapshotOfRect:(CGRect)rect;
- (nullable UIImage *)layerSnapshotOfRect:(CGRect)rect scale:(CGFloat)scale;


@end

NS_ASSUME_NONNULL_END
