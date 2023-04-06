//
//  NSNotificationCenter+Auxiliary.h
//  PR-API
//
//  Created by berec on 10/04/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(uint8_t, ConditionPreference) {
    /// First time executes block with nil `note` before start of the observation.
    ConditionPreferenceCheckBeforeStartObserving = 0,
    ConditionPreferenceCheckWhenObserving
};

@interface NSNotificationCenter (Auxiliary)

#pragma mark Observe Until

/// @param block  return YES to stop observing
/// @return  observer object
+ (nullable id)observe:(nullable NSNotificationName)name
               object:(nullable id)object
           preference:(ConditionPreference)preference
                until:(BOOL(^)(NSNotification * _Nullable note))block;

/// @param block return YES to stop observing
/// @return  array of observer object
+ (nullable NSArray *)observeAnyOf:(nullable NSArray<NSNotificationName> *)names
                          objects:(nullable NSArray *)objects
                       preference:(ConditionPreference)preference
                            until:(BOOL(^)(NSNotification * _Nullable note))block;

#pragma mark Observe Once

/// @return  observer object
+ (nullable id)observeOnce:(nullable NSNotificationName)name
                   object:(nullable id)object
                    queue:(NSOperationQueue *)queue
               usingBlock:(void(^)(NSNotification * _Nullable))block;

/// @return  array of observer object
+ (nullable NSArray *)observeOnceAnyOf:(nullable NSArray<NSNotificationName> *)names
                              objects:(nullable NSArray *)objects
                                queue:(NSOperationQueue *)queue
                           usingBlock:(void(^)(NSNotification * _Nullable))block;

@end

NS_ASSUME_NONNULL_END
