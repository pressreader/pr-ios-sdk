//
//  PRNotification.h
//  PRiphone
//
//  Created by Vitali Bounine on 1/12/10.
//  Copyright 2010 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PRNotification : NSObject

- (void) AddObserver:(id)observer selector:(SEL)selector name:(NSString *)name;
- (void) RemoveObserver:(id)observer;
- (void) RemoveObserver:(id)observer name:(NSString*)name;

- (void) postNotificationName:(NSString *)name;	
- (void) postNotificationName:(NSString *)name withUserInfo:(NSDictionary*)userInfo;
- (void) postNotificationName:requestType withException:(NSException *)e userInfo:(NSDictionary *)userInfo;
- (void) postNotificationName:requestType withError:(NSError *)error userInfo:(NSDictionary *)userInfo;
- (void) enqueueNotificationName:(NSString *)name;
- (void) enqueueNotificationName:(NSString *)name withUserInfo:(NSDictionary*)userInfo;
- (void) postNotification;
- (void) postNotificationWithUserInfo:(NSDictionary*)userInfo;
- (void) enqueueNotification;
- (void) enqueueNotificationWithUserInfo:(NSDictionary*)userInfo;

@end
