//
//  PRSourcesCollectionViewFlowLayout.h
//  PRiphone
//
//  Created by Jackie Cane on 9/12/13.
//  Copyright (c) 2013 NewspaperDirect. All rights reserved.
//

#import "_PRCollectionViewFlowLayout.h"

extern NSNotificationName const PRCollectionViewLayoutUpdated;

@interface PRCollectionViewFlowLayout : _PRCollectionViewFlowLayout

- (NSArray<NSValue *> *)sizesForItemsInSection:(NSInteger)section;
- (NSInteger)constantHeightForSection:(NSInteger)section;
- (NSInteger)numberOfItemsInLineForSection:(NSInteger)section;

@property (nonatomic) CGSize maxItemSize;
@property (nonatomic) CGFloat itemsAdditionalPadding;
@property (nonatomic) CGFloat heightToWidthRatio;
/// constant added after applying heightToWidthRatio multipier: itemHeight = itemWidth * heightToWidthRatio + constantHeight
@property (nonatomic) CGFloat constantHeight;

@property (nonatomic, readonly) id<UICollectionViewDelegateFlowLayout> delegate;
@property (nonatomic, readonly) BOOL isEmpty;

@end

#import "PRCollectionViewFlowLayout+CellSize.h"
