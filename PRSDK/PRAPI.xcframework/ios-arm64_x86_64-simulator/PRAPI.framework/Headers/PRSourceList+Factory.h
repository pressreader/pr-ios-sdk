//
//  PRSourceList+Factory.h
//  PRiphone
//
//  Created by Jackie Cane on 10/02/14.
//  Copyright (c) 2014 NewspaperDirect. All rights reserved.
//

#import "PRSourceList.h"

NS_ASSUME_NONNULL_BEGIN

@class PRTitleItem;
@class PRCountry;

@interface PRSourceList (Factory)

+ (instancetype)supplementSourceListForTitleItem:(PRTitleItem *)titleItem;
+ (instancetype)supplementSourceListForTitleItemAndWithoutIt:(PRTitleItem *)titleItem;

+ (PRSourceList *)favouriteSourceListWithOrder:(PRCatalogSortingOrder)order;

- (PRSourceList *)filteredSourceList:(PRSourceListFilter *)filter;

- (void)applyMinRateFilter;
- (void)applyFreeFilter;
- (void)applyFavoriteFilter;
- (void)applyCustomCatalogTitleFilter;
- (void)applyParentTitleFilter:(PRTitleItem *)titleItem;
- (void)applySourceTypeFilter:(PRSourceType)sourceType;
- (void)applyCategoryFilter:(PRCountableValue *)value;
- (void)applySectionFilter:(PRCountableValue *)value;
- (void)applyCountryFilter:(PRCountableValue *)value;
- (void)applyLanguageFilter:(PRCountableValue *)value;
- (void)applyGroupFilter:(NSString *)name title:(NSString *)title;
- (void)applyCIDsFilter:(NSArray<NSString *> *)cids title:(nullable NSString *)title;
- (void)applySubscriptionFilter:(PRSubscription *)subscription;
- (void)applyNominalFilterWithTitle:(NSString *)title;

- (PRSourceList *)favouriteSourceListWithOrder:(PRCatalogSortingOrder)order;
- (PRSourceList *)customCatalogTitleSourceList;

/// Makes copy of source list with deactivated groupping and includes supplemenets
@property (nonatomic, readonly) PRSourceList *semiplainSourceList;

@end

NS_ASSUME_NONNULL_END
