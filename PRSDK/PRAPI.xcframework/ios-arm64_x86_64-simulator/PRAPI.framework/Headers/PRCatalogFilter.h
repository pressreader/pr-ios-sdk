//
//  PRCatalogFilter.h
//  PRAPI
//
//  Created by Jackie Cane on 05/05/15.
//  Copyright (c) 2015 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PRSourceList;
@class PRCatalogFilterItem;

NS_ASSUME_NONNULL_BEGIN

@protocol PRCatalogFilterDelegate <NSObject>
- (void)catalogFilterDidUpdate:(id)sender;
@end

@interface PRCatalogFilter : NSObject

- (instancetype)initWithSourceList:(PRSourceList *)sourceList;
- (instancetype)init NS_UNAVAILABLE;

- (void)updateFilters;

@property (nonatomic, strong, readonly) PRSourceList *sourceList;
@property (nonatomic, weak) id<PRCatalogFilterDelegate> delegate;

@property (nonatomic) BOOL ignoreSourceListFiltration;

@property (nonatomic, strong, readonly) NSArray<PRCatalogFilterItem *> *allFilters;

/// contains only not activated filters (which don't affect certain source list)
@property (nonatomic, strong, readonly) NSArray<PRCatalogFilterItem *> *availableFilters;

@property (nullable, nonatomic, readonly) PRCatalogFilterItem *countriesFilter;
@property (nullable, nonatomic, readonly) PRCatalogFilterItem *languagesFilter;

@end

NS_ASSUME_NONNULL_END
