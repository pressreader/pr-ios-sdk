//
//  PRBaseStoreCollectionVC.h
//  PRiphone
//
//  Created by Oleg Stepanenko on 12.12.12.
//  Copyright (c) 2012 NewspaperDirect. All rights reserved.
//

#import "PRSourceCollectionVC.h"

@import PRAPI.PRSourceListFilter;
@class CatalogFiltersCollectionVC;

NS_ASSUME_NONNULL_BEGIN

/// This class represents UI layer of SourcesVC. It provides full screen view for presenting sources.
@interface PRBaseStoreCollectionVC : PRSourceCollectionVC

@property (nonatomic) CatalogNavigationType selectedFilterID;

@end


@interface PRBaseStoreCollectionVC (/*Protected*/)

- (void)displayFilters;
- (void)removeFilters;

@property (nonatomic, getter=isWaitingForCatalog) BOOL waitingForCatalog;
@property (nonatomic, readonly) BOOL isSearchAvailable;
@property (nullable, nonatomic, strong) CatalogFiltersCollectionVC *filtersVC;
@property (nonatomic, readonly) BOOL presentsFiltersInHeader;

@end

NS_ASSUME_NONNULL_END

#import "PRBaseStoreCollectionVC+Filtering.h"
