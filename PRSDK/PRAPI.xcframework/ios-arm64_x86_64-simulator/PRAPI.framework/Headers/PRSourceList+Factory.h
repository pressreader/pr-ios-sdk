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
@protocol CatalogNavigation;

@interface PRSourceList (Factory)

+ (instancetype)supplementSourceListForTitleItem:(PRTitleItem *)titleItem;
+ (instancetype)supplementSourceListForTitleItemAndWithoutIt:(PRTitleItem *)titleItem;

- (void)applyMinRateFilter;
- (void)applyFreeFilter;
- (void)applyFavoriteFilter;
- (void)applyCustomCatalogTitleFilter;
- (void)applyParentTitleFilter:(PRTitleItem *)titleItem;
- (void)applySourceTypeFilter:(PRSourceType)sourceType;
- (void)applyCategoryFilter:(PRCountableValue *)value;
- (void)applySectionFilter:(PRCountableValue *)value;
- (void)applyCountryFilter:(id<CatalogNavigation>)value;
- (void)applyLanguageFilter:(PRCountableValue *)value;
- (void)applyGroupFilter:(NSString *)name title:(NSString *)title;
- (void)applyCIDsFilter:(NSArray<NSString *> *)cids title:(nullable NSString *)title;
- (void)applySubscriptionFilter:(PRSubscription *)subscription;

@end

NS_ASSUME_NONNULL_END
