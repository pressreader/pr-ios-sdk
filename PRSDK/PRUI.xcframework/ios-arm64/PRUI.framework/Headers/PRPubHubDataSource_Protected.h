//
//  PRPubHubDataSource_Protected.h
//  PR-UI
//
//  Created by berec on 26/08/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#ifndef PRPubHubDataSource_Protected_h
#define PRPubHubDataSource_Protected_h

#import "PRPubHubSchemeProvider.h"
#import "PRBannerProvider.h"

@class AdBannerPresentation;

@interface PRPubHubDataSource ()

@property (nonatomic, strong) PRPubHubSchemeProvider *schemeProvider;
@property (nonatomic, strong) PRBannerProvider *bannerProvider;

@property (nonatomic, strong) AdBannerPresentation *topScrollableAdBanner;
@property (nonatomic, strong) AdBannerPresentation *inlineAdBanner;

@end

#endif /* PRPubHubDataSource_Protected_h */
