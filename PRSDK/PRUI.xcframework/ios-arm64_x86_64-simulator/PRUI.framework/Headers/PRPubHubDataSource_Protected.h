//
//  PRPubHubDataSource_Protected.h
//  PR-UI
//
//  Created by berec on 26/08/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#ifndef PRPubHubDataSource_Protected_h
#define PRPubHubDataSource_Protected_h

#import "PRBannerProvider.h"

@class AdBannerPresentation;
@class CatalogSchemeProvider;

NS_ASSUME_NONNULL_BEGIN

@interface PRPubHubDataSource ()

- (void)subscribeToNotifications;

@property (nonatomic, strong) CatalogSchemeProvider *schemeProvider;
@property (nullable, nonatomic, strong) PRBannerProvider *bannerProvider;

@property (nullable, nonatomic, strong) AdBannerPresentation *topScrollableAdBanner;
@property (nullable, nonatomic, strong) AdBannerPresentation *inlineAdBanner;

@end

NS_ASSUME_NONNULL_END

#endif /* PRPubHubDataSource_Protected_h */
