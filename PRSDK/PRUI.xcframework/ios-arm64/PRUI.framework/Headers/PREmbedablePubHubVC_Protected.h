//
//  PREmbedablePubHubVC_Protected.h
//  PR-UI
//
//  Created by Artem Serbin on 29.06.2021.
//  Copyright © 2021 NewspaperDirect. All rights reserved.
//

#ifndef PREmbedablePubHubVC_Protected_h
#define PREmbedablePubHubVC_Protected_h

#import <PRUI/PREmbedablePubHubVC.h>
#import <PRUI/PRCatalogSectionHeaderView.h>

@protocol PRCatalogSectionHeader;

NS_ASSUME_NONNULL_BEGIN

@interface PREmbedablePubHubVC (/*PROTECTED*/) <PRPubHubDataSourceDelegate, PRSectionHeaderViewDelegate>

- (void)setupCollectionCell:(UICollectionViewCell *)cell atIndexPath:(NSIndexPath *)indexPath;

- (void)sectionDisclosureButtonTouch:(UIButton *)sender;

- (void)updateDataSource;

- (CGFloat)itemSizeMultiplierForSection:(PRCatalogSection *)section;
- (CGSize)itemSizeForSection:(PRCatalogSection *)section;

- (void)setupFilterSectionWithCell:(UICollectionViewCell *)cell NS_SWIFT_NAME(setupFilterSection(cell:));

- (PRCatalogSection *)sectionForIndexPath:(NSIndexPath *)indexPath;
- (BOOL)showSeeAllButtonForSection:(NSInteger)section;

@property (nullable, nonatomic, strong) id<PRHotspotStatusViewManagerProtocol> hotspotStatusManager;
@property (nonatomic, strong) UIView *hotspotStatusView;
@property (nonatomic, strong) NSMutableArray *hotspotStatusViewConstraints;

@property (nonatomic, strong) NSCache<NSString *, NSValue *> *offsetCache;

@property (nonatomic, readonly) Class<PRCatalogSectionHeader> sectionHeaderClass;

@end

NS_ASSUME_NONNULL_END

#endif /* PREmbedablePubHubVC_Protected_h */
