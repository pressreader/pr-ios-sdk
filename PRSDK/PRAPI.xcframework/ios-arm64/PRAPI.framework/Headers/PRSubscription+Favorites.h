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

- (PRPromise *)setFavorite:(BOOL)favorite cid:(NSString *)cid;

@end

NS_ASSUME_NONNULL_END
