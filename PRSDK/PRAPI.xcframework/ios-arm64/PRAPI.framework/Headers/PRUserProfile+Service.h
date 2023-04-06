//
//  PRUserProfile+Service.h
//  PRiphone
//
//  Created by Viacheslav Soroka on 7/4/17.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

#import "NTFUserItem.h"

#import "PRUserProfile.h"

NS_ASSUME_NONNULL_BEGIN

@interface PRUserProfile (Service)

+ (PRPromise *)userSettings;

+ (PRPromise *)profileNameForEnAccountNumber:(NSString *)enAccountNumber;

+ (PRPromise *)followUserWithProfileId:(NSString *)profileId;
+ (PRPromise *)unfollowUserWithProfileId:(NSString *)profileId;

+ (PRPromise *)followersJSONWithProfileId:(NSString *)profileId
                                     skip:(NSInteger)skip
                                 pageSize:(NSInteger)pageSize
                                   filter:(nullable NSString *)filter;
+ (PRPromise *)followsJSONWithProfileId:(NSString *)profileId
                                   skip:(NSInteger)skip
                               pageSize:(NSInteger)pageSize
                                 filter:(nullable NSString *)filter;

+ (PRPromise *)userProfilesForIds:(NSArray<NSString *> *)ids;

+ (PRPromise *)opinionsWithProfileId:(NSString *)profileId
                                skip:(NSInteger)skip
                            pageSize:(NSInteger)pageSize
                   continuationToken:(nullable NSString *)continuationToken;

- (PRPromise *)follow;
- (PRPromise *)unfollow;

@end

NS_ASSUME_NONNULL_END
