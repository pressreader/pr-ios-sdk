//
//  PRPubHubSchemeProvider.h
//  PRiphone
//
//  Created by Viacheslav Soroka on 3/3/17.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

@import PRAPI;

NS_ASSUME_NONNULL_BEGIN

typedef NSString * PRCIDsType;
extern PRCIDsType const PRCIDsTypeMain;
extern PRCIDsType const PRCIDsTypeAll;

typedef NSString * PRPubHubSchemeKey;
extern PRPubHubSchemeKey const PRPubHubSchemeKeySectionType;
extern PRPubHubSchemeKey const PRPubHubSchemeKeyFromFavourites;
extern PRPubHubSchemeKey const PRPubHubSchemeKeyCid;

typedef NS_OPTIONS(NSUInteger, PRCatalogSectionSchemeOption) {
    PRCatalogSectionSchemeOptionShowTitle = 1 << 0,
    PRCatalogSectionSchemeOptionShowSeeAllButton = 1 << 1,
    PRCatalogSectionSchemeOptionStandout = 1 << 2,
    PRCatalogSectionSchemeOptionNew = 1 << 3,
    PRCatalogSectionSchemeOptionCombine = 1 << 4,
    PRCatalogSectionSchemeOptionFormFromFavorites = 1 << 5
};

@interface PRPubHubSchemeProvider : PRSchemeProvider

+ (instancetype)catalogSchemeProvider;
+ (instancetype)homeSchemeProvider;
+ (instancetype)librarySchemeProvider;
+ (instancetype)favouritesSchemeProvider;
+ (instancetype)latestIssuesSchemeProvider;
+ (instancetype)bookCatalogSchemeProvider;

- (NSArray<NSString *> *)sections;

- (PRCatalogSortingOrder)sortingOrderForSection:(NSString *)section;
- (PRLayoutType)layoutTypeForSection:(NSString *)section;
- (nullable NSArray<NSString *> *)cidsForSection:(NSString *)section;
- (nullable NSString *)customTitleForSection:(NSString *)section;

- (PRCatalogSortingOrder)sortingOrderForSubsectionsOfSection:(NSString *)section;
- (PRCatalogSectionSchemeOption)optionsForSection:(PRCatalogSectionType)section;

@end

NS_ASSUME_NONNULL_END
