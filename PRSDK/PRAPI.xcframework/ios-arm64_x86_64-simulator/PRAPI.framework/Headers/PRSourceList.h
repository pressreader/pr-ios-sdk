//
//  PRSourceList.h
//  PRiphone
//
//  Created by Oleg Stepanenko on 07.12.12.
//  Copyright (c) 2012 NewspaperDirect. All rights reserved.
//

//@import PRAPI.PRSourceListFilter;
//@import PRAPI.PROptions;

#import "PRSourceListFilter.h"
#import "PROptions.h"

@class PRCatalog;

NS_ASSUME_NONNULL_BEGIN

extern NSString *const PRSourcesListDidChangeNotification;
extern NSString *const PRSourcesListDidSortingNotification;
extern NSString *const PRSourcesListDidFilterNotification;

@class PRCountableValue;
@class PRSourceList;
@class PRSubscription;

@protocol PRTitleObject;
@protocol PRCatalogItem;

@protocol PRSourceListDelegate <NSObject>
- (void)sourceListDidChange:(PRSourceList *)sourceList;
@optional
- (void)sourceListDidFilter:(PRSourceList *)sourceList;
- (void)sourceListDidSort:(PRSourceList *)sourceList;
@end

typedef NS_OPTIONS(NSUInteger, PRSourceListOption) {
    PRSourceListOptionPlain = 1 << 0,
    /// Grouping (activates joining of source items into groups)
    PRSourceListOptionUseGroups = 1 << 1,
    PRSourceListOptionIncludeSupplements = 1 << 2,
};

@interface PRSourceList : NSObject

#pragma mark Init

+ (instancetype)listWithDelegate:(nullable id<PRSourceListDelegate>)delegate;
+ (instancetype)listWithCatalog:(PRCatalog *)catalog;

+ (instancetype)listWithSourceList:(PRSourceList *)sourceList;
- (instancetype)initWithSourceList:(PRSourceList *)sourceList;

+ (instancetype)listWithList:(NSArray<id<PRCatalogItem>> *)list;
- (instancetype)initWithList:(NSArray<id<PRCatalogItem>> *)list;

- (instancetype)initWithCIDs:(NSArray<NSString *> *)cids;

#pragma mark Basic Operations With Sources

- (void)setNeedsReloadList;

/// Calls `reloadListCheckingContent` with `checkContent` set to YES.
- (void)reloadList;

/// If `checkContent` is true then .PRSourcesListDidChange note won't be sent if content stays the same after reload.
- (void)reloadListCheckingContent:(BOOL)checkContent;

- (void)filterList;
- (void)sortList;

/// Deactivate groupping and include supplemenets (if not presented by parent)
- (void)turnSemiplainMode;
- (void)turnPlainMode;

@property (nullable, nonatomic, weak) id<PRSourceListDelegate> delegate;

@property (nonatomic, readonly) BOOL isReady;
@property (nonatomic, readonly) BOOL isEmpty;

#pragma mark Representation

/// SourceList's content
@property (nonatomic, strong, readonly) NSArray<__kindof id<PRCatalogItem>> *list;
@property (nonatomic, strong, readonly) NSArray<__kindof NSObject<PRCatalogItem> *> *objectiveList;

@property (nonatomic) PRSourceListOption options;

/// List <ANY: PRTitleItem, PRTitleExemplar> without groups and including supplements.
/// IMPORTANT: Supplements are not included into the list if it contains their parent.
@property (nonatomic, strong, readonly) NSArray<id<PRCatalogItem>> *semiplainList;

/// List <ANY: PRTitleItem, PRTitleExemplar> without groups and including supplements.
@property (nonatomic, strong, readonly) NSArray<id<PRCatalogItem>> *plainList;

#pragma mark Auxiliary

/// Checks all items in `list` for conforming to `PRTitleObject` protocol
@property (nonatomic, strong, readonly) NSArray<id<PRTitleObject>> *titleObjects;

/// Disables initWithSourceList:. Default is YES.
@property (nonatomic, readonly) BOOL isCopyingEnabled;

/// Shows if this list represents concrete issues.
/// If the value is `NO`, then this list should be treated as a list of publications.
@property (nonatomic) BOOL representsTitleItemExemplars;
@property (nonatomic) BOOL prefersOpeningReaderView;

#pragma mark Filtering

- (void)addFilter:(PRSourceListFilter *)filter;
- (void)removeFilterWithID:(PRSourceListFilterID)filterId;
- (nullable PRSourceListFilter *)filterByID:(PRSourceListFilterID)filterId;

@property (nonatomic, strong, readonly) NSArray<PRSourceListFilter *> *filters;

@property (nonatomic) NSUInteger limit;
@property (nonatomic, readonly, getter = isLimitReached) BOOL limitReached;

// filter stack filters
@property (nonatomic, strong, readonly) PRCountableValue *isFavorite;
@property (nonatomic, strong, readonly) PRCountableValue *isFree;
@property (nonatomic, strong, readonly) PRCountableValue *isCustomCatalogTitle;
@property (nonatomic, strong, readonly) PRCountableValue *type;
@property (nonatomic, strong, readonly) PRCountableValue *language;
@property (nonatomic, strong, readonly) PRCountableValue *country;
@property (nonatomic, strong, readonly) PRCountableValue *mainCID;
@property (nonatomic, strong, readonly) PRCountableValue *minRate;
@property (nonatomic, strong, readonly) NSString *group;
@property (nonatomic, strong, readonly) NSArray<NSString *> *cids;
@property (nonatomic, copy, readonly) NSArray<PRSubscription *> *subscriptions;
@property (nonatomic, strong, readonly) NSArray<NSDictionary *> *categories;
@property (nonatomic, strong, readonly) NSArray<NSDictionary *> *sections;
@property (nonatomic, strong, readonly) NSArray<NSDictionary *> *regions;

// filters not included into filter stack
@property (nonatomic, copy) NSString *text;

#pragma mark Sorting

@property (nonatomic) PRCatalogSortingOrder order;
@property (nullable, nonatomic, strong, readonly) NSString *sortingOrderMainCountryISOCode;

@property (nonatomic) NSInteger tag;

@end

NS_ASSUME_NONNULL_END

#import "PRSourceList+Info.h"
#import "PRSourceList+Equality.h"
#import "PRSourceList+Factory.h"
