//
//  PRSubscription+Promise.h
//  PRiphone
//
//  Created by Viacheslav Soroka on 8/22/17.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

#import "PRSubscription.h"



NS_ASSUME_NONNULL_BEGIN

@interface PRSubscription (Promise)

+ (PRPromise *)setFavorite:(BOOL)favorite toIssueCid:(NSString *)cid;
+ (PRPromise *)setFavorite:(BOOL)favorite
                toIssueCid:(NSString *)cid
                  userInfo:(nullable NSDictionary *)userInfo;

+ (PRPromise *)setFavorite:(BOOL)favorite
                toIssueCid:(NSString *)cid
             subscriptions:(NSArray<PRSubscription *> *)subscriptions;
+ (PRPromise *)setFavorite:(BOOL)favorite
                toIssueCid:(NSString *)cid
             subscriptions:(NSArray<PRSubscription *> *)subscriptions
                  userInfo:(nullable NSDictionary *)userInfo;

+ (PRPromise *)getMyTopics;

+ (PRPromise *)getMyCollections;
+ (PRPromise *)getCollectionsForUserId:(NSString *)userId;
+ (PRPromise *)deleteCollectionWithId:(NSString *)collectionId;

+ (PRPromise *)getMastheadInfoForCID:(NSString *)cid;

+ (PRPromise *)getCIDsInUsersSubscriptions;

- (PRPromise *)setFavorite:(BOOL)favorite toIssueCid:(NSString *)cid;
- (PRPromise *)setFavorite:(BOOL)favorite
                toIssueCid:(NSString *)cid
                  userInfo:(nullable NSDictionary *)userInfo;

@end

NS_ASSUME_NONNULL_END
