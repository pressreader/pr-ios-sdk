//
//  PRAppMenu_Protected.h
//  PRUI
//
//  Created by Viacheslav Soroka on 2/12/21.
//  Copyright © 2021 NewspaperDirect. All rights reserved.
//

#ifndef PRAppMenu_Protected_h
#define PRAppMenu_Protected_h

#import "PRAppMenu.h"

NS_ASSUME_NONNULL_BEGIN

@class PRMenuItem;
@class PRCommandMenuItem;
@protocol AppMenuSchemeProvider;

@interface PRAppMenu()

@property (nullable, nonatomic, readonly) PRCommandMenuItem *homeMenuItem;
@property (nullable, nonatomic, readonly) PRCommandMenuItem *beHomeMenuItem;
@property (nullable, nonatomic, readonly) NSArray<PRCommandMenuItem *> *orderMenuItems;
@property (nullable, nonatomic, readonly) PRCommandMenuItem *signInMenuItem;
@property (nullable, nonatomic, readonly) PRCommandMenuItem *bookmarksMenuItem;
@property (nullable, nonatomic, readonly) PRCommandMenuItem *catalogItem;
@property (nullable, nonatomic, readonly) PRCommandMenuItem *beCatalogItem;
@property (nullable, nonatomic, readonly) PRCommandMenuItem *favouritesItem;
@property (nullable, nonatomic, readonly) PRCommandMenuItem *downloadedItem;
@property (nullable, nonatomic, readonly) PRCommandMenuItem *myAccountItem;
@property (nullable, nonatomic, readonly) PRCommandMenuItem *hotspotItem;
@property (nullable, nonatomic, readonly) PRCommandMenuItem *settingsItem;
@property (nullable, nonatomic, readonly) PRMenuItem *aboutUsItem;
@property (nullable, nonatomic, readonly) PRCommandMenuItem *blogItem;
@property (nullable, nonatomic, readonly) PRCommandMenuItem *helpCenterItem;
@property (nullable, nonatomic, readonly) PRCommandMenuItem *sendFeedbackItem;
@property (nullable, nonatomic, readonly) PRCommandMenuItem *webViewItem;
@property (nullable, nonatomic, readonly) PRCommandMenuItem *moreItem;

@property (nonatomic, readonly) BOOL isSingleTitle;
@property (nonatomic, readonly) BOOL hasFeed;
@property (nonatomic, readonly) BOOL hasHome;

@property (nonatomic, strong) id<AppMenuSchemeProvider> schemeProvider;

@end

NS_ASSUME_NONNULL_END

#endif /* PRAppMenu_Protected_h */
