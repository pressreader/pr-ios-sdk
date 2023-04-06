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
#import <PRUI/UINavigationItem+OptionTitle.h>

NS_ASSUME_NONNULL_BEGIN

/// This class represents UI layer of SourcesVC. It provides full screen view for presenting sources.
@interface PRBaseStoreCollectionVC : PRSourceCollectionVC<BarOptionTitleViewDelegate>

@property (nonatomic) PRSourceListFilterID selectedFilterID;

/// Store collection can use its own source list, in this case inherited source list
/// should be passed to globalSourceList property.
/// This list is used for correct presentation of filter path view (bread crumb) and
/// for dimming titles which are not comply with current source list.
@property (nonatomic, strong) PRSourceList *globalSourceList;

@end


@interface PRBaseStoreCollectionVC (/*Protected*/)

- (void)displayFilters;
- (void)removeFilters;

@property (nonatomic, getter=isWaitingForCatalog) BOOL waitingForCatalog;
@property (nonatomic, readonly) BOOL isSearchAvailable;
@property (nullable, nonatomic, strong) CatalogFiltersCollectionVC *filtersVC;

@end

NS_ASSUME_NONNULL_END

#import "PRBaseStoreCollectionVC+Filtering.h"
