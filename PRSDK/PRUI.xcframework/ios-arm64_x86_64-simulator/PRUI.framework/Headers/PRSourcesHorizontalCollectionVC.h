//
//  PRSourcesHorizontalCollectionVC.h
//  PRiphone
//
//  Created by Viacheslav Soroka on 1/20/17.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

#import "PRSourceCollectionVC.h"

@interface PRSourcesHorizontalCollectionVC : PRSourceCollectionVC

+ (CGSize)defaultItemSizeForCollectionWidth:(CGFloat)collectionWidth
                               infoBarStyle:(PRCellInfoBarStyle)style
                                 multiplier:(CGFloat)multiplier
NS_SWIFT_NAME(defaultItemSize(collectionWidth:infoBarStyle:multiplier:));

+ (CGSize)defaultItemSizeForCollectionWidth:(CGFloat)collectionWidth
NS_SWIFT_NAME(defaultItemSize(collectionWidth:));

/// Current item size. Might be recalculated automatically if collectionView size changed.
@property (nonatomic) CGSize itemSize;
/// Dynamic `itemSize` corrector. Default value is 1.
@property (nonatomic) CGFloat itemSizeMultiplier;
@property (nonatomic) CGFloat customSidePadding;

@end
