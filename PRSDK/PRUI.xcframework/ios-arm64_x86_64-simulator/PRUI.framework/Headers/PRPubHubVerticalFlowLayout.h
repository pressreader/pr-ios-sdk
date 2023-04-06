//
//  PRPubHubVerticalFlowLayout.h
//  PRiphone
//
//  Created by Viacheslav Soroka on 1/20/17.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

#import "PRCollectionViewFlowLayout.h"

#import "PRSourceItemCell.h"

@import PRAPI.PROptions;

@protocol PRPubHubVerticalFlowLayoutDelegate <NSObject>

- (PRLayoutType)layoutTypeForSection:(NSInteger)section;
- (PRSourceItemCellPresentationStyle)cellPresentationStyle;

@optional
- (PRCellInfoBarStyle)infoBarStyleForSection:(NSInteger)section;
- (UIEdgeInsets)insetForSection:(NSInteger)section;

@end

@interface PRPubHubVerticalFlowLayout : PRCollectionViewFlowLayout

+ (instancetype)layoutWithDelegate:(id<PRPubHubVerticalFlowLayoutDelegate>)delegate;
- (instancetype)initWithDelegate:(id<PRPubHubVerticalFlowLayoutDelegate>)delegate;

@property (nonatomic, weak) id <PRPubHubVerticalFlowLayoutDelegate> verticalLayoutDelegate;

@end
