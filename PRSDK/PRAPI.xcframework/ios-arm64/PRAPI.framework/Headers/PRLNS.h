//
//  PRLNS.h
//  PRAPI
//
//  Created by berec on 05/10/2020.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PRLNS : NSObject

+ (void)presentLocalNotificationWithId:(nullable NSString *)Id
                                  title:(nullable NSString *)title
                                   body:(nullable NSString *)body
                               hasSound:(BOOL)hasSound
                            badgeNumber:(NSInteger)badgeNumber
                             attachment:(nullable NSURL *)mediaUrl
                              userInfo:(NSDictionary *)userInfo;

@end

NS_ASSUME_NONNULL_END
