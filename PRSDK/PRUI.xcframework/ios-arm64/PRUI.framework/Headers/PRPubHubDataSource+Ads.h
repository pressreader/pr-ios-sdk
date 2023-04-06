//
//  PRPubHubDataSource+Ads.h
//  PRUI
//
//  Created by Viacheslav Soroka on 10/27/20.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import "PRPubHubDataSource.h"

@import PRAds;

NS_ASSUME_NONNULL_BEGIN

@interface PRPubHubDataSource (Ads) <AdDataSourceDelegate>

- (nullable PRCatalogSection *)topScrollableAdBannerSection;
- (nullable PRCatalogSection *)inlineAdBannerSection;

- (void)loadAndPresentBanners;

@property (nonatomic, readonly) AdBannerScreen adScreen;

@end

NS_ASSUME_NONNULL_END
