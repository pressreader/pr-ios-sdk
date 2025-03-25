//
//  PRSourceList.h
//  PRiphone
//
//  Created by Oleg Stepanenko on 07.12.12.
//  Copyright (c) 2012 NewspaperDirect. All rights reserved.
//

#import "PRSourceListFilter.h"
#import "PROptions.h"
#import <PRAPI/PRCatalog.h>

NS_ASSUME_NONNULL_BEGIN

extern NSInteger const kPRNumberOfCategoriesInFeaturedSection;

extern NSString *const PRSourcesListDidChangeNotification;
extern NSString *const PRSourcesListDidSortingNotification;
extern NSString *const PRSourcesListDidFilterNotification;

@class PRCountableValue;
@class PRSubscription;

@protocol PRTitleObject;
@protocol PRCatalogItem;
@protocol CatalogFacade;

@protocol PRSourceListDelegate <NSObject>
- (void)sourceListDidChange:(id<CatalogFacade>)sourceList;
@optional
- (void)sourceListDidFilter:(id<CatalogFacade>)sourceList;
- (void)sourceListDidSort:(id<CatalogFacade>)sourceList;
@end

typedef NS_OPTIONS(NSUInteger, PRSourceListOption) {
    PRSourceListOptionPlain = 1 << 0,
    /// Grouping (activates joining of source items into groups)
    PRSourceListOptionUseGroups = 1 << 1,
    PRSourceListOptionIncludeSupplements = 1 << 2,
};

@interface PRSourceList : NSObject

#pragma mark Init

- (instancetype)initWithSourceList:(PRSourceList *)sourceList;
- (instancetype)initWithList:(NSArray<id<PRCatalogItem>> *)list;
- (instancetype)initWithCIDs:(NSArray<NSString *> *)cids;

#pragma mark Basic Operations With Sources

/// Calls `reloadListCheckingContent` with `checkContent` set to YES.
- (void)reloadList;

/// If `checkContent` is true then .PRSourcesListDidChange note won't be sent if content stays the same after reload.
- (void)reloadListCheckingContent:(BOOL)checkContent;

/// Deactivate groupping and include supplemenets (if not presented by parent)
- (void)turnSemiplainMode;
- (void)turnPlainMode;

@property (nullable, nonatomic, weak) id<PRSourceListDelegate> delegate;

@property (nonatomic, readonly) BOOL isReady;
@property (nonatomic, readonly) BOOL isEmpty;

#pragma mark Representation

/// SourceList's content
@property (nonatomic, strong, readonly) NSArray<__kindof id<PRCatalogItem>> *list;

@property (nonatomic) PRSourceListOption options;

/// List <ANY: PRTitleItem, PRTitleExemplar> without groups and including supplements.
/// IMPORTANT: Supplements are not included into the list if it contains their parent.
@property (nonatomic, strong, readonly) NSArray<id<PRCatalogItem>> *semiplainList;

/// List <ANY: PRTitleItem, PRTitleExemplar> without groups and including supplements.
@property (nonatomic, strong, readonly) NSArray<id<PRCatalogItem>> *plainList;

#pragma mark Auxiliary

/// Disables initWithSourceList:. Default is YES.
@property (nonatomic, readonly) BOOL isCopyingEnabled;

#pragma mark Filtering

- (void)applyFilters:(NSArray<PRSourceListFilter *> *)filters;
- (void)applyFilters:(NSArray<PRSourceListFilter *> *)filters checkingContent:(BOOL)checkingContent;

@property (nonatomic, strong) NSArray<PRSourceListFilter *> *filters;

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
@property (nonatomic, strong, readonly) PRCountableValue *issueDate;
@property (nonatomic, strong, readonly) NSString *group;
@property (nonatomic, strong, readonly) NSArray<NSString *> *cids;
@property (nonatomic, copy, readonly) NSArray<PRSubscription *> *subscriptionFilters;
@property (nonatomic, strong, readonly) NSArray<NSDictionary<NSString *, id> *> *categoryFilters;
@property (nonatomic, strong, readonly) NSArray<NSDictionary<NSString *, id> *> *regionFilters;

// filters not included into filter stack
@property (nullable, nonatomic, copy) NSString *text;

#pragma mark Sorting

@property (nonatomic) PRCatalogSortingOrder order;
@property (nullable, nonatomic, strong) NSString *sortingOrderMainCountryISOCode;

@property (nonatomic) NSInteger tag;

@end

NS_ASSUME_NONNULL_END

#import "PRSourceList+Info.h"
#import "PRSourceList+Factory.h"
