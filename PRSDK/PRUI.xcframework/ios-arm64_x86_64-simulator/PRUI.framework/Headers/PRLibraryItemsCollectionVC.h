//
//  PRLibraryItemsCollectionVC.h
//  PRiphone
//
//  Created by Jackie Cane on 10/11/14.
//  Copyright (c) 2014 NewspaperDirect. All rights reserved.
//

#import "PRFilterableCollectionVC.h"

@class PROrderDelivery;
@class PRMyLibraryItem;
@class PRSourceItem;
@class PRSourceItemManager;

@protocol LibraryItemProtocol;

NS_ASSUME_NONNULL_BEGIN

@class PRLibraryItemsCollectionVC;

@protocol PRLibraryItemsCollectionControllerDelegate <NSObject>

- (void)libraryItemsCollectionController:(PRLibraryItemsCollectionVC *)controller didSelectItem:(PRMyLibraryItem *)item userInfo:(NSDictionary *)userInfo;

@optional
- (void)discloseLibraryItemsCollection:(PRLibraryItemsCollectionVC *)controller;

@end

@protocol PRLibraryItemsEditorDelegate <NSObject>

- (void)setEditingMode:(BOOL)editing;
- (void)refreshSelections:(NSArray *)items;
- (void)refreshLocks:(NSArray *)items;
- (void)removeDeleted:(NSArray *)items;
- (void)refreshEditControls;
- (void)changeEditModeTo:(BOOL)isEditingMode;
@optional
- (BOOL)isInEditMode;

@end

@interface PRLibraryItemsCollectionVC : PRFilterableCollectionVC

- (instancetype)initWithCID:(NSString *)cid;
- (void)reloadDataProvider;
- (nullable id)itemAtIndexPath:(NSIndexPath *)indexPath;
- (nullable id<LibraryItemProtocol>)libraryItemAtIndexPath:(NSIndexPath *)indexPath;

@property (nonatomic, strong, readonly) NSString *CID;
@property (nullable, nonatomic, strong) NSArray *dataProvider;
@property (nonatomic, weak) id<PRLibraryItemsCollectionControllerDelegate> libraryItemsCollectionControllerDelegate;
@property (nonatomic, weak) id<PRLibraryItemsEditorDelegate> libraryItemsEditorDelegate;

@end


@interface PRLibraryItemsCollectionVC (/*Business*/)
@property (nonatomic, strong) PROrderDelivery *orderDelivery;
@property (nonatomic, strong, readonly) PRSourceItemManager *sourceItemManager;

@end

@interface PRLibraryItemsCollectionVC (/*Notifications*/)

- (void)registerLibraryUpdatedNotificationObserver:(BOOL)registerObserver;
- (void)purchaseAdvicesRefreshNotification:(nullable NSNotification *)notification;
- (void)reloadListNotification:(nullable NSNotification *)notification;
- (void)myLibraryInitializationDone:(nullable NSNotification *)notification;

@end

NS_ASSUME_NONNULL_END
