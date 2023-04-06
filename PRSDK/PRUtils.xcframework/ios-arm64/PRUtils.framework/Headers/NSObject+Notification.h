//
//  NSObject+Notification.h
//  PR-API
//
//  Created by Viacheslav Soroka on 1/3/19.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSObject (Notification)

- (void)subscribeToNotifications:(NSArray<NSNotificationName> *)notifications selector:(SEL)selector;
- (void)subscribeTo:(NSNotificationName)notificationName
           selector:(SEL)selector
             object:(nullable id)object;
- (void)subscribeTo:(NSNotificationName)notificationName selector:(SEL)selector;

- (void)unsubscribe:(NSNotificationName)notificationName object:(nullable id)object;
- (void)unsubscribe:(NSNotificationName)notificationName;

/// same as `subscribeTo:selector:object`
- (void)observe:(NSNotificationName)notificationName
       selector:(SEL)selector
         object:(nullable id)object;

/// same as `subscribeTo:selector:`
- (void)observe:(NSNotificationName)notificationName selector:(SEL)selector;

- (void)observe:(NSNotificationName)notificationName
       selector:(SEL)selector
         object:(nullable id)object
        observe:(BOOL)observe;

- (void)post:(NSNotificationName)notificationName userInfo:(nullable NSDictionary *)userInfo;
- (void)post:(NSNotificationName)notificationName;

- (void)enqueue:(NSNotificationName)notificationName;
- (void)enqueue:(NSNotificationName)notificationName userInfo:(nullable NSDictionary *)dict;
- (void)enqueue:(NSNotificationName)notificationName userInfo:(nullable NSDictionary *)dict coalesce:(BOOL)coalesce;

@end

NS_ASSUME_NONNULL_END
