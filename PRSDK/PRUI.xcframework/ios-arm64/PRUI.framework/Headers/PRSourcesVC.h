//
//  PRSourcesVC.h
//  PRiphone
//
//  Created by Oleg Stepanenko on 12.12.12.
//  Copyright (c) 2012 NewspaperDirect. All rights reserved.
//

#import <PRUI/PRSourceCollectionVC.h>
#import <PRUI/PRTooltipDelegate.h>
@import PRAPI.PRSourceListFilter;

@class PRCountableValue;
@class CatalogFiltersCollectionVC;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM (NSUInteger, PRSourcesListType) {
    PRSourcesListType_Default,
    PRSourcesListType_SourcesWithSupplement
};

@protocol PRSourcesVCOrderDelegate <NSObject>
- (BOOL)shouldOrderParentTitleOnlyForCID:(NSString *)CID;
@end


@interface PRSourcesVC : PRSourceCollectionVC

+ (NSArray *)controllersWithSourceList:(PRSourceList *)sourceList
                               andPath:(NSArray<NSDictionary<NSString *, id> *> *)path;

@property (nullable, nonatomic, strong) NSString *listName;
@property (nullable, nonatomic) id<PRSourcesVCOrderDelegate> orderDelegate;

@property (nonatomic, readonly) NSArray<PRSourceListFilter *> *sourceListFilters;
@property (nonatomic) CatalogNavigationType selectedFilterID;

@end


@interface PRSourcesVC (/*Protected*/)

- (void)displayFilters;
- (void)removeFilters;

@property (nonatomic, getter=isWaitingForCatalog) BOOL waitingForCatalog;
@property (nonatomic, readonly) BOOL isSearchAvailable;
@property (nullable, nonatomic, strong) CatalogFiltersCollectionVC *filtersVC;

@end

@interface PRSourcesVC (/*Protected*/)<PRTooltipVCProtocol>
@property (nonatomic, strong) PRTooltipDelegate *tooltipDelegate;
@end

#ifdef TEST
@interface PRSourcesVC ()
- (void)orderItemAtIndexPath:(NSIndexPath *)indexPath;
@end
#endif


NS_ASSUME_NONNULL_END

#import "PRSourcesVC+Filtering.h"
