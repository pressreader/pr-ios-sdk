//
//  NSNotificationCenter+ConvenienceAPI.h
//  PR-API
//
//  Created by berec on 10/04/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSNotificationCenter (ConvenienceAPI)

id ObserveUntil(NSNotificationName _Nullable name,
                  id _Nullable object,
                  BOOL(^untilBlock)(NSNotification *note));

NSArray * ObserveAnyUntil(NSArray<NSNotificationName> *_Nullable names,
                          NSArray *_Nullable objects,
                          BOOL(^untilBlock)(NSNotification *note));

id ObserveOnce(NSNotificationName _Nullable name,
                 id _Nullable object,
                 void(^usingBlock)(NSNotification *note));

NSArray * ObserveAnyOnce(NSArray<NSNotificationName> *_Nullable names,
                         NSArray *_Nullable objects,
                         void(^usingBlock)(NSNotification *note));

@end

NS_ASSUME_NONNULL_END
