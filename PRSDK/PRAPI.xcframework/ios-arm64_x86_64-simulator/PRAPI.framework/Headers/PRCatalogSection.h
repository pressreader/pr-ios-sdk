//
//  PRCatalogSection.h
//  PRiphone
//
//  Created by Jackie Cane on 10/11/14.
//  Copyright (c) 2014 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PRAPI/PROptions.h>

@class PRAccountItem;
@protocol CatalogFacade;

NS_ASSUME_NONNULL_BEGIN

typedef NSString * PRCatalogSectionName NS_STRING_ENUM;
extern PRCatalogSectionName const PRCatalogSectionNameFullCatalog;
extern PRCatalogSectionName const PRCatalogSectionNameLatestIssues;

typedef NS_ENUM(NSInteger, PRCatalogSectionType) {
    PRCatalogSectionTypeBegin = -2,
    
    PRCatalogSectionTypeNone,
    PRCatalogSectionTypeFeatured,
    PRCatalogSectionTypeFilters,
    PRCatalogSectionTypeListen,
    PRCatalogSectionTypeFavorites,
    PRCatalogSectionTypeRecentlyRead,
    PRCatalogSectionTypeLinkedService,
    PRCatalogSectionTypeTopMagazines,
    PRCatalogSectionTypeTopNewspapers,
    PRCatalogSectionTypeBooks,
    PRCatalogSectionTypeJustAdded,
    PRCatalogSectionTypeNewReleases,
    PRCatalogSectionTypeTopFree,
    PRCatalogSectionTypeDownloaded,
    PRCatalogSectionTypeLatestIssues,
    
    PRCatalogSectionTypeBannerBegin,
    //
    PRCatalogSectionTypeBannerHotspotServices,
    PRCatalogSectionTypeBannerPremiumSubscription,
    PRCatalogSectionTypeBannerImproveExperience,
    PRCatalogSectionTypeBannerPersonalizationCompleted,
    PRCatalogSectionTypeBannerBooks,
    PRCatalogSectionTypeBannerBrazeContentCard,
    PRCatalogSectionTypeBannerAll,
    //
    PRCatalogSectionTypeBannerEnd,

    PRCatalogSectionTypeCategories,
    PRCatalogSectionTypeFullCatalog,
    PRCatalogSectionTypeCategoryContent,
    /// Special categories for custom catalog. Might support rows in the future.
    PRCatalogSectionTypeSections,
    PRCatalogSectionTypeHotSpot,
    
    PRCatalogSectionTypeTopAdBanner,
    PRCatalogSectionTypeInlineAdBanner,
    
    PRCatalogSectionTypeEnd,
};

typedef NS_OPTIONS(NSUInteger, PRCatalogSectionOption) {
    PRCatalogSectionOptionShowSeeAll = 1 << 0,
    PRCatalogSectionOptionOneCIDRestriction = 1 << 1,
    PRCatalogSectionOptionShowSingleLineTitle = 1 << 2,
    PRCatalogSectionOptionStandout = 1 << 3,
    PRCatalogSectionOptionNew = 1 << 4
};

@class PRCollectionVC, PRSourceList;

@interface PRCatalogSection : NSObject

+ (PRCatalogSectionType)sectionTypeForName:(NSString *)name;
+ (NSString *)sectionNameForType:(PRCatalogSectionType)type;
+ (nullable NSString *)sectionReuseIdForType:(PRCatalogSectionType)type;

+ (instancetype)sectionWithCIDs:(NSArray<NSString *> *)cids title:(NSString *)title;

/// DEPRECATED. Avoid model - controller association to be able to reuse section controllers effectively.
@property (nullable, nonatomic, strong) UIViewController *associatedController;

@property (nonatomic) PRCatalogSectionType sectionType;
@property (nonatomic) PRLayoutType layoutType;
@property (nonatomic) PRCatalogSectionOption viewOptions;

@property (nonatomic, readonly) BOOL isExemplarSection;
@property (nonatomic, readonly) BOOL showDatesOnly;

@property (nullable, nonatomic, strong) NSString *title;
@property (nullable, nonatomic, strong) NSString *subtitle;
@property (nullable, nonatomic, strong) NSString *prompt;

/// For PRCatalogDetailsSectionTypeLinkedService
@property (nonatomic, strong) PRAccountItem *account;

@property (nullable, nonatomic, strong) id<CatalogFacade> sourceList;
@property (nonatomic, strong) id data;
@property (nonatomic, strong) UIButton *discloseButton;

@property (nullable, nonatomic, strong) NSArray<PRCatalogSection *> *subsections;

@end

NS_ASSUME_NONNULL_END
