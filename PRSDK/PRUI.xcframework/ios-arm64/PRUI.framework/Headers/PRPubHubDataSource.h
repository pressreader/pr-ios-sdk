//
//  PRPubHubDataSource.h
//  PR-UI
//
//  Created by Viacheslav Soroka on 2/27/19.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import <PRAPI/PRAPI.h>

@class PRCountableValue;
@class PRBannerPresentationConfig;
@class CatalogSchemeProvider;
@class CatalogSectionScheme;
@class PRSourceList;
@class AdBannerPresentation;
@class PRBannerProvider;

@protocol PRPubHubDataSourceDelegate;
@protocol CatalogItemDataSourceProtocol;
@protocol PRSourceCollectionControllerDelegate;

NS_ASSUME_NONNULL_BEGIN

extern NSNotificationName const PRPubHubDataSourceDidUpdateNotification;

typedef NS_OPTIONS(NSUInteger, PRPubHubDataSourceOption) {
    PRPubHubDataSourceOptionShowBanners = 1 << 0,
    PRPubHubDataSourceOptionSkipWaitForCatalogReadiness = 1 << 1,
    PRPubHubDataSourceOptionDisplayEmptySections = 1 << 2
};

@interface PRPubHubDataSource : NSObject

+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithSchemeProvider:(CatalogSchemeProvider *)schemeProvider;

- (void)resetSections;

- (void)update;
- (void)setNeedsUpdate;

- (CGSize)adBannerSizeForCatalogSection:(PRCatalogSection *)section;

- (void)startSectionObservation:(PRCatalogSection *)section;
- (void)stopSectionObservation:(PRCatalogSection *)section;

@property (nullable, nonatomic, weak) UIViewController<PRPubHubDataSourceDelegate> *delegate;
@property (nonatomic, readonly) id<CatalogFacade> sourceList;
@property (nullable, nonatomic, readonly) PRSourceList *legacySourceList;

@property (nonatomic, strong) PRBannerPresentationConfig *bannerConfig;

@property (nonatomic, readonly) BOOL isEmpty;
@property (nonatomic, readonly) BOOL isReady;
@property (nonatomic, readonly) BOOL isValid;

@property (nonatomic, strong, readonly) CatalogSchemeProvider *schemeProvider;

@end

@interface PRPubHubDataSource (/*PROTECTED*/) <DataSourceObserver>

- (void)updateContentSize;

- (PRCatalogSection *)sectionWithScheme:(CatalogSectionScheme *)scheme
                       titlePlaceholder:(nullable NSString *)titlePlaceholder
                             dataSource:(nullable id)dataSource
                                  index:(NSInteger)index
NS_SWIFT_NAME(section(scheme:title:dataSource:index:));

- (PRCatalogSection *)dataSectionWithScheme:(CatalogSectionScheme *)scheme
                                      title:(nullable NSString *)title
                                 dataSource:(nullable id<CatalogItemDataSourceProtocol>)dataSource
NS_SWIFT_NAME(dataSection(scheme:title:dataSource:));

- (nullable PRCatalogSection *)sectionOfType:(PRCatalogSectionType)sectionType;
- (nullable PRCatalogSection *)hotspotSectionWithIndex:(NSInteger)index;

- (void)updateSection:(PRCatalogSection *)section
                title:(nullable NSString *)title
               prompt:(nullable NSString *)prompt
             subtitle:(nullable NSString *)subtitle
                 show:(BOOL)shouldShow;

- (void)updateSection:(PRCatalogSection *)section title:(nullable NSString *)title show:(BOOL)shouldShow;
- (void)updateSection:(PRCatalogSection *)section source:(id<CatalogItemDataSourceProtocol>)source;
    
- (void)subscribeToNotifications;

@property (nullable, nonatomic, strong) PRBannerProvider *bannerProvider;

@property (nullable, nonatomic, strong) AdBannerPresentation *topScrollableAdBanner;
@property (nullable, nonatomic, strong) AdBannerPresentation *inlineAdBanner;

@property (nullable, nonatomic, strong) NSArray<PRCatalogSection *> *sections;
@property (nonatomic) PRPubHubDataSourceOption options;
@property (nonatomic, readonly) BOOL isItemsSizeFixed;

@property (nonatomic) CGSize contentSize;

@end


@protocol PRPubHubDataSourceDelegate <NSObject, PRSourceCollectionControllerDelegate>

- (void)dataSourceDidUpdate:(PRPubHubDataSource *)dataSource;
- (void)dataSource:(PRPubHubDataSource *)dataSource didUpdateSectionAtIndex:(NSInteger)index headerUpdated:(BOOL)headerUpdated;
- (void)dataSourceDidUpdateAdBanners:(PRPubHubDataSource *)dataSource;
- (void)scrollToTop;
- (void)discloseCategory:(id<CatalogNavigationVariant>)value;

@property (nonatomic, readonly) CGSize viewSize;

@end

NS_ASSUME_NONNULL_END

#import "PRPubHubDataSource+Banners.h"
#import "PRPubHubDataSource+Ads.h"
