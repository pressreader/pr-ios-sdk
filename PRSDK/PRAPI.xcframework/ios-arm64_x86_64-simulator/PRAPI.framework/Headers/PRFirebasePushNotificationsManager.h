//
//  PRFirebasePushNotificationsManager.h
//  PRAPI
//
//  Created by Viacheslav Soroka on 2022-06-24.
//  Copyright © 2022 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PRFirebasePushNotificationsManager : NSObject

+ (void)setup;
+ (void)setAPNSToken:(NSData *)token;

@end

NS_ASSUME_NONNULL_END
