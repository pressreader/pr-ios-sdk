//
//  PRPubHubDataSource.h
//  PR-UI
//
//  Created by Viacheslav Soroka on 2/27/19.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

@import PRAPI;

#import <PRUI/PRMessageBar.h>

@class PRSourceList;
@class PRCountableValue;
@class PRBannerPresentationConfig;
@class PRPubHubSchemeProvider;

@protocol PRPubHubDataSourceDelegate;
@protocol CatalogItemDataSourceProtocol;
@protocol PRSourceCollectionControllerDelegate;

NS_ASSUME_NONNULL_BEGIN

extern const NSInteger kPRNumberOfCategoriesInFeaturedSection;

extern NSNotificationName const PRPubHubDataSourceDidUpdateNotification;

typedef NS_OPTIONS(NSUInteger, PRPubHubDataSourceOption) {
    PRPubHubDataSourceOptionShowBanners = 1 << 0,
    PRPubHubDataSourceOptionSkipWaitForCatalogReadiness = 1 << 1,
    PRPubHubDataSourceOptionWaitForCatalogUpdate = 1 << 2,
    PRPubHubDataSourceOptionDisplayEmptySections = 1 << 3
};

@interface PRPubHubDataSource : NSObject

+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithSchemeProvider:(PRPubHubSchemeProvider *)schemeProvider;

- (BOOL)sectionFormedFromFavorites:(PRCatalogSectionType)section;
- (void)resetSections;

- (void)update;
- (void)setNeedsUpdate;

- (PRSourceList *)sourceListWithCategory:(PRCountableValue *)category;
- (nullable PRCountableValue *)categoryAtIndexPath:(NSIndexPath *)indexPath;

- (CGSize)adBannerSizeForCatalogSection:(PRCatalogSection *)section;

- (void)startSectionObservation:(PRCatalogSection *)section;
- (void)stopSectionObservation:(PRCatalogSection *)section;

@property (nullable, nonatomic, weak) UIViewController<PRPubHubDataSourceDelegate> *delegate;
@property (nonatomic, strong, readonly) NSArray<PRCountableValue *> *catalogFilters;
@property (nonatomic, strong) PRSourceList *sourceList;

@property (nonatomic, strong) PRBannerPresentationConfig *bannerConfig;

@property (nonatomic, readonly) BOOL isEmpty;
@property (nonatomic, readonly) BOOL isReady;
@property (nonatomic, readonly) BOOL isValid;

@end

@interface PRPubHubDataSource (/*PROTECTED*/) <DataSourceObserver>

- (void)updateContentSize;

- (PRCatalogSection *)sectionWithType:(PRCatalogSectionType)sectionType NS_SWIFT_NAME(section(type:));

- (PRCatalogSection *)sectionWithType:(PRCatalogSectionType)sectionType
                                title:(nullable NSString *)title
                               prompt:(nullable NSString *)prompt
                             subtitle:(nullable NSString *)subtitle
                           dataSource:(nullable id)dataSource
                            skipCache:(BOOL)skipCache NS_SWIFT_NAME(section(type:title:prompt:subtitle:dataSource:skipCache:));

- (PRCatalogSection *)sectionWithType:(PRCatalogSectionType)sectionType
                     titlePlaceholder:(nullable NSString *)titlePlaceholder
                           dataSource:(nullable id)dataSource
                                index:(NSInteger)index NS_SWIFT_NAME(section(type:title:dataSource:index:));


- (nullable PRCatalogSection *)sectionOfType:(PRCatalogSectionType)sectionType;
- (nullable PRCatalogSection *)hotspotSectionWithIndex:(NSInteger)index;

- (void)updateSection:(PRCatalogSection *)section
                title:(nullable NSString *)title
               prompt:(nullable NSString *)prompt
             subtitle:(nullable NSString *)subtitle
                 show:(BOOL)shouldShow;

- (void)updateSection:(PRCatalogSection *)section title:(nullable NSString *)title show:(BOOL)shouldShow;
- (void)updateSection:(PRCatalogSection *)section source:(id<CatalogItemDataSourceProtocol>)source;
    
@property (nullable, nonatomic, strong) NSArray<PRCatalogSection *> *sections;
@property (nonatomic, readonly) NSArray<NSNumber *> *sectionsOrder;
@property (nonatomic) PRPubHubDataSourceOption options;
@property (nonatomic, readonly) BOOL isItemsSizeFixed;
@property (nonatomic, readonly) BOOL isLocalServiceOn;

@property (nullable, nonatomic, readonly) PRAccountItem *defaultAccount;
@property (nonatomic) CGSize contentSize;
@property (nonatomic, readonly) PRCatalog *catalog;

@end


@protocol PRPubHubDataSourceDelegate <NSObject, PRSourceCollectionControllerDelegate, PRMessageBarDelegate>

- (void)dataSourceDidUpdate:(PRPubHubDataSource *)dataSource;
- (void)dataSource:(PRPubHubDataSource *)dataSource didUpdateSectionAtIndex:(NSInteger)index headerUpdated:(BOOL)headerUpdated;
- (void)dataSourceDidUpdateAdBanners:(PRPubHubDataSource *)dataSource;
- (void)scrollToTop;
- (void)discloseCategory:(PRCountableValue *)value;

@property (nonatomic, readonly) CGSize viewSize;

@end

NS_ASSUME_NONNULL_END

#import "PRPubHubDataSource+Banners.h"
#import "PRPubHubDataSource+Ads.h"
