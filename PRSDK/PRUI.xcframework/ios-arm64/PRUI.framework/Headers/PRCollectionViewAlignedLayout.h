//
//  PRCollectionViewAlignedLayout.h
//  PressReader
//
//  Created by Oleg Stepanenko on Mar 02, 2017.
//  Copyright (c) 2017 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, PRCellAlignment) {
    PRCellAlignmentLeft = NSTextAlignmentLeft,    // Visually left aligned
    PRCellAlignmentCenter = NSTextAlignmentCenter, // Visually centered
    PRCellAlignmentRight = NSTextAlignmentRight, // Visually right aligned
    PRCellAlignmentJustified = NSTextAlignmentJustified,
    PRCellAlignmentDistributed
};

@class PRCollectionViewAlignedLayout;

@protocol PRCollectionViewAlignedLayoutDelegate <NSObject>

- (void)collectionViewLayout:(PRCollectionViewAlignedLayout *)layout didChangeContentSize:(CGSize)size;

@end

@interface PRCollectionViewAlignedLayout : UICollectionViewFlowLayout
@property (nonatomic, weak) id<PRCollectionViewAlignedLayoutDelegate> layoutDelegate;
@property (nonatomic, assign) PRCellAlignment cellAlignment;
@property (nonatomic, assign) CGSize maxItemSize;

@end
