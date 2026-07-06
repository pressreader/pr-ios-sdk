//
//  PRAppPanel.h
//  PRiphone
//
//  Created by Oleg Stepanenko on 25.10.12.
//  Copyright (c) 2012 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(unsigned int, PRPanelId) {
    PRPanelIdNone = 0,
    PRPanelIdCatalog,
    PRPanelIdDownloaded,
    PRPanelIdOptions,
    PRPanelIdNewsFeed,
    PRPanelIdMyBookmarks,
    PRPanelIdMyAccount,
    PRPanelIdAboutUs,
    PRPanelIdBlog,
    PRPanelIdHelpCenter,
    PRPanelIdOrder,
    PRPanelIdOnlineWebView,
    PRPanelIdHotSpotMap,
    PRPanelIdOnboarding,
    PRPanelIdFavourites,
    PRPanelIdSubscriptions,
    PRPanelIdSettings,
    PRPanelIdCustomerSupport,
    PRPanelIdVideos
};

@interface PRAppPanel : NSObject

- (instancetype)initWithId:(PRPanelId)anId content:(UIViewController *)content;

@property (nonatomic, readonly) PRPanelId panelId;
@property (nonatomic) NSInteger menuId;
@property (nonatomic, strong) __kindof UIViewController *content;
@property (nullable, nonatomic, readonly) UINavigationController *contentNavigationController;
@property (nonatomic, copy) NSString *title;

@end

NS_ASSUME_NONNULL_END
