//
//  PRSourceListFilter.h
//  PRiphone
//
//  Created by Jackie Cane on 10/02/14.
//  Copyright (c) 2014 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>
@import CoreGraphics;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, PRSourceListFilterID) {
    PRSourceListFilterNone = 0,
    PRSourceListFilterFavorite,
    PRSourceListFilterFree,
    PRSourceListFilterType,
    PRSourceListFilterCategory,
    PRSourceListFilterGenre,
    PRSourceListFilterSection,
    PRSourceListFilterLanguage,
    PRSourceListFilterCountry,
    PRSourceListFilterRegion,
    PRSourceListFilterMainCID,
    PRSourceListFilterMinRate,
    PRSourceListFilterCIDs,
    PRSourceListFilterSubscriptions,
    PRSourceListFilterGroup,
    PRSourceListFilterCustomCatalogTitle
};

extern CGSize const kCategoryImageSize;
extern CGSize const kCategoryLargeImageSize;
extern CGSize const kCountryImageSize;

@interface PRSourceListFilter : NSObject

+ (instancetype)filterWithId:(PRSourceListFilterID)filterId
                       value:(nullable id)value
                       title:(nullable NSString *)title;

@property (nonatomic) PRSourceListFilterID filterId;
@property (nonatomic, strong, nullable) id value;
@property (nonatomic, strong, nullable) NSString *title;
@property (nonatomic, readonly) NSString *path;
@property (nonatomic, readonly) NSString *urlComplientPath;

@property (nonatomic, assign) BOOL rootFilter;

@end

NS_ASSUME_NONNULL_END
