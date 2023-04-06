//
//  PRConfig+AppPanels.h
//  PRSharedData
//
//  Created by berec on 20/05/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import <PRConfiguration/PRConfig.h>

NS_ASSUME_NONNULL_BEGIN

#define SPLASH_ANIMATION _PRCONFIG_BOOL_(@"SPLASH_ANIMATION", YES)
#define SPLASH_ANIMATION_DURATION  _PRCONFIG_DOUBLE_(@"SPLASH_ANIMATION_DURATION", PRConfig.isBrandEdition ? 0.0 : 2.5)
#define APP_PANEL_NEWSFEED 0
#define APP_PANEL_DOWNLOADED 1
#define APP_PANEL_PUBLICATIONS 2
#define APP_PANEL_MY_PUBLICATIONS_SECTION 3

#define DEFAULT_APP_PANEL                 _PRCONFIG_INT_(@"DEFAULT_APP_PANEL", APP_PANEL_NEWSFEED)

#define BE_LIBRARY      _PRCONFIG_BOOL_(@"BE_LIBRARY", PRConfig.isBrandEdition)

typedef NS_OPTIONS(NSUInteger, PRAppMenuItemAbsence) {
    PRAppMenuItemAbsenceHome = 1 << 0,
    PRAppMenuItemAbsenceCatalog = 1 << 1,
    PRAppMenuItemAbsenceDownloaded = 1 << 2,
    PRAppMenuItemAbsenceBookmarks = 1 << 3,
    PRAppMenuItemAbsenceSignIn = 1 << 4,
    PRAppMenuItemAbsenceHotspots = 1 << 5,
    PRAppMenuItemAbsenceAccount = 1 << 6,
    PRAppMenuItemAbsenceSettings = 1 << 7,
    PRAppMenuItemAbsenceSubscriptions = 1 << 8,
    PRAppMenuItemAbsenceAbout = 1 << 9,
    PRAppMenuItemAbsenceMore = 1 << 10,
    PRAppMenuItemAbsenceSendFeedback = 1 << 11,
    PRAppMenuItemAbsenceCustomerSupport = 1 << 12,
    PRAppMenuItemAbsenceWebView = 1 << 13
};

typedef NS_ENUM(uint8_t, PRAppPanelID) {
    PRAppPanelUndefined = -1,
    PRAppPanelNewsfeed = APP_PANEL_NEWSFEED,
    PRAppPanelDownloaded = APP_PANEL_DOWNLOADED,
    PRAppPanelPublications = APP_PANEL_PUBLICATIONS,
    PRAppPanelMyPublicationsSection = APP_PANEL_MY_PUBLICATIONS_SECTION
};

typedef NS_ENUM(uint8_t, PRCatalogPanelMode) {
    /// Uses our default algorithm to determine whether Catalog tab shold be available in the app
    PRCatalogPanelModeAutomatic = 0,
    /// Catalog tab is being shown unconditionally
    PRCatalogPanelModeDisplay,
    /// Catalog tab is being hidden unconditionally
    PRCatalogPanelModeHide,
};

@interface PRConfig (AppPanels)
@property (class, nonatomic, readonly) PRAppPanelID initialAppPanel;

/// Indicates whether we should replace default app panel with value, stored in `initialAppPanel`.
@property (class, nonatomic, assign) BOOL shouldReplaceDeaultAppPanel;

@property (class, nonatomic, readonly) BOOL restrictOrderOpenOnCatalog;

@property (class, nonatomic, readonly) PRAppPanelID appPanelForOfflineMode;

@property (class, nonatomic, readonly) PRCatalogPanelMode catalogPanelMode;

@end

NS_ASSUME_NONNULL_END
