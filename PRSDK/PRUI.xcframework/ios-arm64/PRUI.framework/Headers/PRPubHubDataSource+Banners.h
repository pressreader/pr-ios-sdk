//
//  PRPubHubDataSource+Banners.h
//  PR-UI
//
//  Created by berec on 26/08/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import "PRPubHubDataSource.h"

NS_ASSUME_NONNULL_BEGIN

@interface PRPubHubDataSource (Banners)

- (BOOL)isBanner:(PRCatalogSectionType)type;

- (nullable PRCatalogSection *)allBannersSection;

@property (nonatomic, readonly) BOOL shouldShowBanners;

@end

NS_ASSUME_NONNULL_END
