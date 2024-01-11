//
//  PRSourceItemCell_Protected.h
//  PR-UI
//
//  Created by berec on 01/11/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#ifndef PRSourceItemCell_Protected_h
#define PRSourceItemCell_Protected_h

#import "PRSourceItemCell.h"
#import <PRThumbnail/PRThumbnail.h>

@class PRMyLibraryItem;

NS_ASSUME_NONNULL_BEGIN

@interface PRSourceItemCell ()

- (void)setupWithPresentationStyle:(PRSourceItemCellPresentationStyle)style;
- (void)refreshRibbon;
- (void)refreshRibbonMargin:(BOOL)supplements;
- (void)refreshDownload:(NSInteger)progress;
- (BOOL)isCurrentItem:(NSObject *)item;

@property (nonatomic, readonly) BOOL shouldShowActionButton;

@property (nonatomic) PRThumbnailSourceSizeType thumbnailSizeType;

@property (nullable, nonatomic, strong) NSObject<PRCatalogItem> *sourceItem;
@property (nullable, nonatomic, strong) PRThumbnailObject *thumbnail;
@property (nullable, nonatomic, strong, readonly) PRMyLibraryItem *mli;

@end

#endif /* PRSourceItemCell_Protected_h */

NS_ASSUME_NONNULL_END
