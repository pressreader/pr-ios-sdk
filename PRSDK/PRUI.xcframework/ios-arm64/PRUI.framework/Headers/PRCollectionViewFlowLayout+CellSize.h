//
//  PRCollectionViewFlowLayout+CellSize.h
//  PR-UI
//
//  Created by Viacheslav Soroka on 4/2/19.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import "PRCollectionViewFlowLayout.h"

#import "PRSourceItemCell.h"

@protocol PRTitleObject;

NS_ASSUME_NONNULL_BEGIN

@interface PRCollectionViewFlowLayout (CellSize)

+ (CGSize)cellSizeForDesiredWidth:(CGFloat)desiredWidth
                    desiredHeight:(CGFloat)desiredHeight
                   sourceListItem:(nullable id<PRTitleObject>)item
                     infoBarStyle:(PRCellInfoBarStyle)infoBarStyle;

+ (CGSize)cellSizeForDesiredWidth:(CGFloat)desiredWidth
                    desiredHeight:(CGFloat)desiredHeight
                        maxHeight:(CGFloat)maxHeight
                   sourceListItem:(nullable id<PRTitleObject>)item
                     infoBarStyle:(PRCellInfoBarStyle)infoBarStyle;

@end

NS_ASSUME_NONNULL_END
