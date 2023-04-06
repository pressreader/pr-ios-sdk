//
//  PRFirebaseAnalytics.h
//  PRAPI
//
//  Created by berec on 16/10/2020.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PRFirebaseAnalytics : NSObject

+ (void)setAnalyticsCollectionEnabled:(BOOL)analyticsEnabled;
+ (void)setUserID:(nullable NSString *)userID;

+ (void)setUserPropertyString:(nullable NSString *)value forName:(NSString *)name NS_SWIFT_NAME(setUserProperty(_:forName:));

+ (void)logEventWithName:(NSString *)name
              parameters:(nullable NSDictionary<NSString *, id> *)parameters
    NS_SWIFT_NAME(logEvent(_:parameters:));

+ (void)logScreenWithName:(NSString *)screenName class:(NSString *)screenClass;
+ (void)logScreenWithName:(NSString *)screenName class:(NSString *)screenClass parameters:( NSDictionary * _Nullable )parameters;

+ (void)activateRemoteConfigWithCompletionHandler:(void(^)(NSError * _Nullable error))completion;

@property (class, nonatomic, readonly) PRFirebaseAnalytics *instance;
@property (class, nonatomic, readonly) NSDictionary<NSString *, id> *remoteConfigRepresentation;

@end

NS_ASSUME_NONNULL_END
