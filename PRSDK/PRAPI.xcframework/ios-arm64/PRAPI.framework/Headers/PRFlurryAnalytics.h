//
//  PRFlurryAnalytics.h
//  PRAPI
//
//  Created by berec on 16/10/2020.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PRFlurryAnalytics : NSObject

+ (void)startSession;

+ (void)endTimedEvent:(nonnull NSString *)eventName
       withParameters:(nullable NSDictionary *)parameters;

+ (void)logEvent:(nonnull NSString *)eventName
  withParameters:(nullable NSDictionary *)parameters
           timed:(BOOL)timed;

+ (void)setUserID:(nullable NSString *)userID;
+ (void)sessionProperties:(nonnull NSDictionary *)parameters;

@property (class, nullable, nonatomic, readonly) Class flurryClass;
@property (class, nonatomic, readonly) NSString *apiKey;

@end

NS_ASSUME_NONNULL_END
