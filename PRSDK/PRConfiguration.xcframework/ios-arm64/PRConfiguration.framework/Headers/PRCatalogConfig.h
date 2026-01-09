//
//  PRCatalogConfig.h
//  PRAPI
//
//  Created by berec on 05/06/2020.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

@class CatalogAppearanceConfig;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, PRCatalogMode) {
    PRCatalogModeUnknown = 0,
    PRCatalogModeRegular,
    PRCatalogModeSingleTitle,
    PRCatalogModeSingleTitlePlusSupplements
};

typedef NS_ENUM(NSInteger, PRCatalogSortingOrder) {
    PRCatalogSortingOrderNotDefined = 0,
    PRCatalogSortingOrderByAlphabet,
    /// rate
    PRCatalogSortingOrderMostPopular,
    /// issue date
    PRCatalogSortingOrderMostCurrent,
    /// activation time
    PRCatalogSortingOrderMostCurrentOnPressreader,
    PRCatalogSortingOrderReadAndMostPopular,
    /// preserves order as in server response
    PRCatalogSortingOrderNone
};

@interface PRCatalogConfig : NSObject

- (void)adjustWithParentSourceCount:(NSInteger)parentSourceCount
                     hasSupplements:(BOOL)hasSupplements NS_SWIFT_NAME(adjust(parentSourceCount:hasSupplements:));

@property (nonatomic, readonly) BOOL thumbClickCatalogItemOpenRead;

/// Open reader for cell, that represents issue, not publication.
@property (nonatomic, readonly) BOOL catalogIssueClickOpenOrder;
@property (nonatomic, readonly) BOOL latestIssuesMixEnabled;
@property (nonatomic, readonly) BOOL presentIssueAsExemplar;
@property (nonatomic, readonly) BOOL useModernServiceAPI;
@property (nonatomic, readonly) BOOL customCatalog;
@property (nonatomic, readonly) BOOL showImagesForCategories;
@property (nonatomic, readonly) BOOL isThumbnailStretchingEnabled;
@property (nonatomic, readonly) NSUInteger catalogSearchMinItemsCount;
@property (nonatomic, readonly) PRCatalogSortingOrder catalogSortingOrder;
@property (nonatomic, readonly) PRCatalogMode catalogMode;
@property (nonatomic, readonly) PRCatalogMode actualCatalogMode;
@property (nonatomic, assign, readonly) NSInteger parentSourceCount;

/// Catalog presentation mode. This value is configurable, you should use it whenever it's possible,
/// because some publishers with one main CID and supplements want to have multi-title mode.
@property (nonatomic, readonly) BOOL isSingleTitleMode;

@property (nonatomic, readonly) BOOL pressCatalogUpdateDisabled;

@property (nonatomic, strong, readonly) CatalogAppearanceConfig *appearanceConfig NS_SWIFT_NAME(appearance);

@end

NS_ASSUME_NONNULL_END
