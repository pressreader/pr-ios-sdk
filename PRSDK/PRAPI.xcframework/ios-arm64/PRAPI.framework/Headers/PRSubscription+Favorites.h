//
//  PRSubscription+Favorites.h
//  PRAPI
//
//  Created by Ivan Berezin on 13/03/2024.
//  Copyright © 2024 NewspaperDirect. All rights reserved.
//

#import <PRAPI/PRSubscription.h>
#import <PRPromiseKit/PRPromiseKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface PRSubscription (Favorites)

- (PRPromise *)getFavoriteCIDs;
- (PRPromise *)getFavoriteCIDsWithAccountToken:(nullable NSString *)token;

- (void)updateFavoritesWithCID:(NSString *)userCID
                      favorite:(BOOL)addFavorite
                    completion:(void(^_Nullable)(BOOL success))completion;

- (void)updateFavoritesWithCID:(NSString *)userCID
                      favorite:(BOOL)addFavorite
                      userInfo:(nullable NSDictionary *)userInfo
                    completion:(void(^_Nullable)(BOOL success))completion;

- (PRPromise *)mergeFavorites;

@end

NS_ASSUME_NONNULL_END
