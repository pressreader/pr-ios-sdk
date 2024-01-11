//
//  PRConfig+Appearance.h
//  PR-API
//
//  Created by berec on 11/03/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import <PRConfiguration/PRConfig.h>

#import <PRConfiguration/PRFeedConfig.h>
#import <PRConfiguration/PROrderConfig.h>
#import <PRConfiguration/PROnboardingConfig.h>
#import <PRConfiguration/PRBannersConfig.h>
#import <PRConfiguration/PRCatalogConfig.h>

@class PRArticleConfig;
@class ReaderConfig;
@class LibraryConfig;
@class UserConsentConfig;
@class FontConfig;
@class SearchConfig;
@class IAPConfig;
@class HomeConfig;
@class RadioConfig;

NS_ASSUME_NONNULL_BEGIN

/// Category contains content presentation/behaviour configurations.
@interface PRConfig (Presentation)
@property (class, nonatomic, readonly) PRFeedConfig *feedConfig NS_SWIFT_NAME(feed);
@property (class, nonatomic, readonly) PROrderConfig *orderConfig NS_SWIFT_NAME(order);
@property (class, nonatomic, readonly) PRArticleConfig *articleConfig NS_SWIFT_NAME(article);
@property (class, nonatomic, readonly) PROnboardingConfig *onboardingConfig NS_SWIFT_NAME(onboarding);
@property (class, nonatomic, readonly) PRBannersConfig *bannersConfig NS_SWIFT_NAME(banner);
@property (class, nonatomic, readonly) PRCatalogConfig *catalogConfig NS_SWIFT_NAME(catalog);
@property (class, nonatomic, readonly) ReaderConfig *readerConfig NS_SWIFT_NAME(reader);
@property (class, nonatomic, readonly) LibraryConfig *libraryConfig NS_SWIFT_NAME(library);
@property (class, nonatomic, readonly) HomeConfig *homeConfig NS_SWIFT_NAME(home);
@property (class, nonatomic, readonly) UserConsentConfig *userConsentConfig NS_SWIFT_NAME(userConsent);
@property (class, nonatomic, readonly) FontConfig *fontConfig NS_SWIFT_NAME(font);
@property (class, nonatomic, readonly) SearchConfig *searchConfig  NS_SWIFT_NAME(search);
@property (class, nonatomic, readonly) IAPConfig *iapConfig  NS_SWIFT_NAME(iap);

@property (class, nonatomic, readonly) BOOL showBookmarksOnLibrary;
@property (class, nonatomic, readonly) BOOL showDisabledActionMenu;

@property (class, nonatomic, readonly) BOOL zoomIntoArticleOnPageViewSwitch;

@end

NS_ASSUME_NONNULL_END

#define SHOW_ONLINE_VIEWS               _PRCONFIG_BOOL_(@"SHOW_ONLINE_VIEWS", YES)
#define SHOW_ABOUTUS_AND_BLOG           _PRCONFIG_BOOL_(@"SHOW_ABOUTUS_AND_BLOG", NO)
