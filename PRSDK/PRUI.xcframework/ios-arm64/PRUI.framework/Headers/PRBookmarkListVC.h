//
//  PRBookmarkListVC.h
//  PR-UI
//
//  Created by Viacheslav Soroka on 11/29/18.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class NTFCollectionItem;
@class PRCollectionsModel;
@class PRBookmarkListVC;

@protocol PRBookmarkListDelegate <NSObject>

@optional
- (void)bookmarkListVC:(PRBookmarkListVC *)vc didSelectCollection:(NTFCollectionItem *)collection;
- (void)bookmarkListVCDidReceiveDismiss:(PRBookmarkListVC *)vc;

@end

typedef NS_OPTIONS(NSUInteger, PRBookmarkListVCPreference) {
    PRBookmarkListVCPreferenceEditingAllowed = 1 << 0,
    PRBookmarkListVCPreferenceMarkPublicBookmarks = 1 << 1,
    PRBookmarkListVCPreferenceNavigationBarTransparent = 1 << 2,
    PRBookmarkListVCPreferenceDisplayAppLogo = 1 << 3,
    PRBookmarkListVCPreferenceDisplayChannelMasthead = 1 << 4,
    PRBookmarkListVCPreferenceShowDiscloseIndicators = 1 << 5,
    PRBookmarkListVCPreferenceKeepCollectionsOrder = 1 << 6,
    PRBookmarkListVCPreferenceHideAllCollection = 1 << 7,
    PRBookmarkListVCPreferenceHideNavigationBar = 1 << 8,
    PRBookmarkListVCPreferenceShowCollectionItemsCount = 1 << 9,
};

@interface PRBookmarkListVC : UIViewController

+ (instancetype)bookmarkListVCWithCollections:(PRCollectionsModel *)collections;
+ (instancetype)bookmarkListVCWithCollections:(PRCollectionsModel *)collections
                           selectedCollection:(nullable NTFCollectionItem *)selectedCollection;

@property (nonatomic) PRBookmarkListVCPreference preferences;
@property (nonatomic, weak) id<PRBookmarkListDelegate> delegate;
@property (nonatomic, copy) void(^selectionHandler)(NTFCollectionItem *collection);

@property (nonatomic, strong, readonly) PRCollectionsModel *model;
@property (nonatomic, strong, readonly) UITableView *tableView;

@end

NS_ASSUME_NONNULL_END
