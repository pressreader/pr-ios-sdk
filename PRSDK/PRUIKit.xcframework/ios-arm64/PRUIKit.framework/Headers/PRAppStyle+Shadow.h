//
//  PRAppStyle+Shadow.h
//  PR-UI
//
//  Created by Viacheslav Soroka on 3/1/19.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import "PRAppStyle.h"

NS_ASSUME_NONNULL_BEGIN

@interface PRAppStyle (Shadow)

@property (class, nonatomic, readonly) UIImage *collectionViewCellShadow;
@property (class, nonatomic, readonly) UIImage *collectionViewCellRoundShadow;
@property (class, nonatomic, readonly) UIImage *collectionViewCellLargeTransparentShadow;
@property (class, nonatomic, readonly) UIImage *collectionViewCellEnormousTransparentShadow;
@property (class, nonatomic, readonly) UIImage *collectionViewCellEnormousLightTransparentShadow;

@end

NS_ASSUME_NONNULL_END
