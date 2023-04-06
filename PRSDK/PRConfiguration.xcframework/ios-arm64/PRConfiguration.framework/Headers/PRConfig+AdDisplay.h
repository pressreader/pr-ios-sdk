//
//  PRConfig+AdDisplay.h
//  PRSharedData
//
//  Created by berec on 20/05/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import <PRConfiguration/PRConfig.h>

NS_ASSUME_NONNULL_BEGIN

#define ADVERTISEMENT_DISPLAY_ENABLED  (![[[PRModel instance] options] localServiceName] && _PRCONFIG_BOOL_(@"ADVERTISEMENT_DISPLAY_ENABLED", NO))
#define ADVERTISEMENT_DISPLAY_TEXT_VIEW_AD_REFRESHING_PERIOD _PRCONFIG_INT_(@"ADVERTISEMENT_DISPLAY_TEXT_VIEW_AD_REFRESHING_PERIOD", 60 * 60 * 24)

@interface PRConfig (AdDisplay)
@property (class, nonatomic, readonly) BOOL isAdvertisementDisplayEnabled;

@property (class, nonatomic, readonly) BOOL simulateGoogleAds;
@property (class, nonatomic, readonly) BOOL shouldShowOnlineBanners;

@end

NS_ASSUME_NONNULL_END
