//
//  PRMainVC+Size.h
//  PR-UI
//
//  Created by berec on 17/01/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import "PRMainVC.h"

NS_ASSUME_NONNULL_BEGIN

@interface PRMainVC (Size)

/// Multiplier with basis 4 inches in Fixed Coordinate Space
@property (nonatomic, readonly) CGFloat heightMultiplier_4in;
/// Multiplier with basis 4.7 inches in Fixed Coordinate Space
@property (nonatomic, readonly) CGFloat widthMultiplier_4_7in;
@property (nonatomic, readonly) CGFloat landscapeWidthMultiplier_11_0in;

@end

NS_ASSUME_NONNULL_END
