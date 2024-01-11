//
//  PRAppMenu.h
//  PRiphone
//
//  Created by Oleg Stepanenko on 16.10.12.
//  Copyright (c) 2012 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

@import PRUIKit.PRAppPanel;
@import PRUIKit.PRMenu;
@import PRProtocols;

@protocol CatalogFacade;

NS_ASSUME_NONNULL_BEGIN

typedef NSString * PRAppMenuItemType NS_TYPED_ENUM;
extern PRAppMenuItemType const PRAppMenuItemTypeHome;
extern PRAppMenuItemType const PRAppMenuItemTypeFavorites;
extern PRAppMenuItemType const PRAppMenuItemTypeCatalog;
extern PRAppMenuItemType const PRAppMenuItemTypeLibrary;
extern PRAppMenuItemType const PRAppMenuItemTypeBookmarks;
extern PRAppMenuItemType const PRAppMenuItemTypeOrder;
extern PRAppMenuItemType const PRAppMenuItemTypeAccount;
extern PRAppMenuItemType const PRAppMenuItemTypeHotspot;
extern PRAppMenuItemType const PRAppMenuItemTypeSettings;
extern PRAppMenuItemType const PRAppMenuItemTypeAbout;
extern PRAppMenuItemType const PRAppMenuItemTypeBlog;
extern PRAppMenuItemType const PRAppMenuItemTypeHelp;
extern PRAppMenuItemType const PRAppMenuItemTypeSubscriptions;
extern PRAppMenuItemType const PRAppMenuItemTypeSendFeedback;
extern PRAppMenuItemType const PRAppMenuItemTypeCustomerSupport;
extern PRAppMenuItemType const PRAppMenuItemTypeWebView;

typedef NSString * PRAppMenuIcon NS_TYPED_ENUM;
extern PRAppMenuIcon const PRAppMenuIconHome;
extern PRAppMenuIcon const PRAppMenuIconForYou;
extern PRAppMenuIcon const PRAppMenuIconExplore;
extern PRAppMenuIcon const PRAppMenuIconPublications;
extern PRAppMenuIcon const PRAppMenuIconPrintEditions;
extern PRAppMenuIcon const PRAppMenuIconLibrary;
extern PRAppMenuIcon const PRAppMenuIconDownloaded;
extern PRAppMenuIcon const PRAppMenuIconBookmarks;
extern PRAppMenuIcon const PRAppMenuIconOrder;
extern PRAppMenuIcon const PRAppMenuIconAccount;
extern PRAppMenuIcon const PRAppMenuIconHotspot;
extern PRAppMenuIcon const PRAppMenuIconSettings;
extern PRAppMenuIcon const PRAppMenuIconAbout;
extern PRAppMenuIcon const PRAppMenuIconBlog;
extern PRAppMenuIcon const PRAppMenuIconHelp;
extern PRAppMenuIcon const PRAppMenuIconSubscriptions;
extern PRAppMenuIcon const PRAppMenuIconSendFeedback;
extern PRAppMenuIcon const PRAppMenuIconCustomerSupport;
extern PRAppMenuIcon const PRAppMenuIconWebView;
extern PRAppMenuIcon const PRAppMenuIconSports;
extern PRAppMenuIcon const PRAppMenuIconFinancial;
extern PRAppMenuIcon const PRAppMenuIconObituaries;
extern PRAppMenuIcon const PRAppMenuIconPodcasts;
extern PRAppMenuIcon const PRAppMenuIconWeather;
extern PRAppMenuIcon const PRAppMenuIconPuzzles;
extern PRAppMenuIcon const PRAppMenuIconVideo;
extern PRAppMenuIcon const PRAppMenuIconBrandedVideo;

extern NSString *const PRAppMenuDidChangeNotification;

@interface PRAppMenuItem : PRMenuItem
@end

@interface PRAppMenuSection : PRMenuSection
@end

@interface PRAppMenu : PRMenu <Singleton>

- (void)selectByPanelId:(PRPanelId)panelId;

@property (class, nonatomic, readonly) PRAppMenu *instance;

@property (nonatomic, getter = isFavoriteSourcesDisclosed) BOOL favoriteSourcesDisclosed;
@property (nullable, nonatomic, readonly) PRMenuItem *accountItemForRegularStyle;

@end


@interface PRAppMenu (/*PROTECTED*/)
@property (nonatomic, strong) id<CatalogFacade> favoritesSourceList;
@property (nonatomic, readonly) BOOL isBrandEdition;

@end

NS_ASSUME_NONNULL_END
