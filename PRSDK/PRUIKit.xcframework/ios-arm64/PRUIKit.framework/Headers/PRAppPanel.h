//
//  PRAppPanel.h
//  PRiphone
//
//  Created by Oleg Stepanenko on 25.10.12.
//  Copyright (c) 2012 NewspaperDirect. All rights reserved.
//

@import UIKit;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(unsigned int, PRPanelId) {
    PRPanelIdNone = 0,
    PRPanelIdCatalog,
    PRPanelIdDownloaded,
    PRPanelIdOptions,
    PRPanelIdNewsFeed,
    PRPanelIdMyTopics,
    PRPanelIdMyBookmarks,
    PRPanelIdOnlineProfile,
    PRPanelIdSearchResult,
    PRPanelIdMyAccount,
    PRPanelIdChannel,
    PRPanelIdAboutUs,
    PRPanelIdBlog,
    PRPanelIdHelpCenter,
    PRPanelIdOrder,
    PRPanelIdOnlineWebView,
    PRPanelIdHotSpotMap,
    PRPanelIdUniversalSources,
    PRPanelIdOnboarding,
    PRPanelIdOpinions,
    PRPanelIdRegistration,
    PRPanelIdFavourites,
    PRPanelIdSubscriptions,
    PRPanelIdSendFeedback,
    PRPanelIdSettings,
    PRPanelIdCustomerSupport
};

@interface PRAppPanel : NSObject

- (instancetype)initWithId:(PRPanelId)anId content:(id) content;

@property (nonatomic, readonly) PRPanelId panelId;
@property (nonatomic) NSInteger menuId;
@property (nonatomic, strong) id content;
@property (nullable, nonatomic, readonly) UINavigationController *contentNavigationController;
@property (nonatomic, copy) NSString *title;

@end

NS_ASSUME_NONNULL_END
