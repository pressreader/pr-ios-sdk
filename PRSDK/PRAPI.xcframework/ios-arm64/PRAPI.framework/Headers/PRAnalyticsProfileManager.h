//
//  PRAnalyticsProfileManager.h
//  PR-API
//
//  Created by Vitali Bounine on 2018-02-22.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

@import PRAnalytics;

NS_ASSUME_NONNULL_BEGIN

@interface PRAnalyticsProfileManager : NSObject

- (void) cacheAnalyticsProfile:(PRAnalyticsProfile *)profile;

- (void) updateAnalyticsProfile:(PRAnalyticsProfileBase *)profile completed:(void(^ _Nullable)(PRAnalyticsProfile * _Nullable, NSError * _Nullable error))completionBlock;
- (void) updateAnalyticsProfiles:(NSArray<PRAnalyticsProfileBase *> *)profiles allCompleted:(void(^ _Nullable)(NSArray<PRAnalyticsProfile *> * _Nullable analyticsProfiles))completionBlock;

- (void) reportAnalyticsEvent:(PRAnalyticsProfileEventName)event parameters:(NSDictionary<PRAnalyticsPatternPlaceholder, id> *)params profiles:(NSArray<NSString *> *)profileIds;

- (NSArray<NSDictionary *> *) jsonAnalyticsProfiles:(NSArray<NSString *> *)profileIDs;
- (void) requestJsonAnalyticsProfilesConfigurationAndComplete:(void(^ _Nullable)(NSArray<NSDictionary *> * configurations, NSError * error))completionBlock;

@end

NS_ASSUME_NONNULL_END
