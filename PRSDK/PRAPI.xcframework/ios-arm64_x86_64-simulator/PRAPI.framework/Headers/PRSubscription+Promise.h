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

+ (PRPromise *)getMyTopics;

+ (PRPromise *)getMyCollections;
+ (PRPromise *)getCollectionsForUserId:(NSString *)userId;
+ (PRPromise *)deleteCollectionWithId:(NSString *)collectionId;

+ (PRPromise *)getMastheadInfoForCID:(NSString *)cid;

+ (PRPromise *)getCIDsInUsersSubscriptions;

@end

NS_ASSUME_NONNULL_END
