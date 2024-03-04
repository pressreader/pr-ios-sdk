//
//  PRTitleItem+Favorites.h
//  PR-API
//
//  Created by berec on 16/02/2018.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import "PRTitleItem.h"

NS_ASSUME_NONNULL_BEGIN

@class PRPromise;

extern NSNotificationName const PRTitleItemFavoriteChangedNotification;

@interface PRTitleItem (Favorites)

- (BOOL)isFavoriteForService:(NSString *)serviceName;
- (void)setFavorite:(BOOL)favorite forService:(PRAccountItem *)service;
- (void)setFavorite:(BOOL)favorite forService:(PRAccountItem *)service saveAndNotify:(BOOL)needSaveAndNotifiy;

- (void)changeFavoriteStatus:(void(^)(BOOL success))completion;
- (void)setFavorite:(BOOL)favorite completion:(void(^_Nullable)(BOOL success))completion;

@property (nonatomic, readonly) BOOL isFavorite;

@end

NS_ASSUME_NONNULL_END
