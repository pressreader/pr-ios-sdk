//
//  PRBrazeAnalytics.h
//  PRAPI
//
//  Created by berec on 15/10/2020.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

@import UIKit;

NS_ASSUME_NONNULL_BEGIN

@interface PRBrazeAnalytics: NSObject

+ (void)logCustomEventWithName:(NSString *)name
                    parameters:(nullable NSDictionary<NSString *, id> *)parameters;

+ (void)updateEmailNotificationSubscriptionTypeWithUnsubscribed:(BOOL)unsubscribed;

+ (void)setUserCustomAttributeWithKey:(NSString *)key andStringValue:(NSString *)value;
+ (void)setUserCustomAttributeWithKey:(NSString *)key andIntegerValue:(NSInteger)value;
+ (void)setUserCustomAttributeWithKey:(NSString *)key andDoubleValue:(double)value;
+ (void)setUserCustomAttributeWithKey:(NSString *)key andBOOLValue:(BOOL)value;
+ (void)setUserCustomAttributeArrayWithKey:(NSString *)key
                                     array:(nullable NSArray *)value;
+ (void)unsetUserCustomAttributeWithKey:(NSString *)key;

+ (void)changeUser:(NSString *)userId;

+ (void)setUserEmail:(nullable NSString *)value overwrite:(BOOL)overwrite;
+ (void)setUserFirstName:(nullable NSString *)value overwrite:(BOOL)overwrite;
+ (void)setUserLastName:(nullable NSString *)value overwrite:(BOOL)overwrite;

+ (void)debugLog:(NSString *)log;

- (void)startInApp:(UIApplication *)app
     launchOptions:(nullable NSDictionary *)launchOptions;

@property (class, nonatomic, readonly) PRBrazeAnalytics *instance;
@property (class, nullable, nonatomic, readonly) NSString *apiKey;
@property (class, nonatomic, readonly) NSString *userDefaultPropertyPrefix;
@property (class, nonatomic, readonly) BOOL hasUser;
@property (class, nonatomic, readonly) BOOL isAvailable;
@property (class, nonatomic, readonly) NSString *brazeUserId;

@end

NS_ASSUME_NONNULL_END
