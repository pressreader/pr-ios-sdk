//
//  NSNotificationCenter+PRExtension.h
//  PR-API
//
//  Created by Vitali Bounine on 2018-03-16.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PRPromise;

@interface NSNotificationCenter (ObserveUntil)

/// Calls observe:object:preference:until: with preference = ConditionPreferenceCheckBeforeStartObserving.
/// @param block return YES to stop observing
+ (void)observe:(nullable NSNotificationName)name
         object:(nullable id)object
          until:(BOOL(^)(NSNotification * _Nullable note))block;

/// Calls observeAnyOf:objects:preference:until: with preference = ConditionPreferenceCheckBeforeStartObserving.
/// @param block return YES to stop observing
+ (void)observeAnyOf:(nullable NSArray<NSNotificationName> *)names
             objects:(nullable NSArray *)objects
               until:(BOOL(^)(NSNotification * _Nullable note))block;

@end

@interface NSNotificationCenter (ObserveWithCondition)

/// Calls observe:object:preference:condition:usingBlock with preference = ConditionPreferenceCheckBeforeStartObserving.
+ (void)observe:(nullable NSNotificationName)name
         object:(nullable id)object
      stopCondition:(BOOL(^)(void))conditionBlock
     usingBlock:(void(^)(NSNotification * _Nullable note))block;

/// Calls observeAnyOf:objects:preference:condition:usingBlock with preference = ConditionPreferenceCheckBeforeStartObserving.
+ (void)observeAnyOf:(nullable NSArray<NSNotificationName> *)names
             objects:(nullable NSArray *)objects
      stopCondition:(BOOL(^)(void))conditionBlock
          usingBlock:(void(^)(NSNotification * _Nullable note))block;

@end

@interface NSNotificationCenter (ObserveOnce)

+ (void)observeOnce:(nullable NSNotificationName)name
              object:(nullable id)object
          usingBlock:(void(^)(NSNotification *note))block;

+ (void)observeOnceAnyOf:(nullable NSArray<NSNotificationName> *)names
                 objects:(nullable NSArray *)objects
              usingBlock:(void(^)(NSNotification * _Nullable))block;

+ (void)observeOnceIfNot:(BOOL)condition
        notificationName:(nullable NSNotificationName)name
                  object:(nullable id)object
              usingBlock:(void(^)(NSNotification * _Nullable note))block;

+ (void)observeOnceAnyIfNot:(BOOL)condition
          notificationNames:(nullable NSArray<NSNotificationName> *)notificationNames
                    objects:(nullable NSArray *)objects
                 usingBlock:(void(^)(NSNotification * _Nullable))block;

@end

@interface NSNotificationCenter (Promise)

+ (PRPromise *)observe:(nullable NSNotificationName)name
                object:(nullable id)object
        stopCondition:(BOOL(^)(NSNotification * _Nullable note))conditionBlock;

/// resolves with NSNotification object
+ (PRPromise *)observeOnce:(nullable NSNotificationName)name
                    object:(nullable id)object;

+ (PRPromise *)observeOnce:(nullable NSArray<NSNotificationName> *)names
                   objects:(nullable NSArray<id> *)objects;

+ (PRPromise *)observeOnceIfNot:(BOOL)condition
               notificationName:(nullable NSNotificationName)name
                         object:(nullable id)object;

+ (PRPromise *)observeOnceIfNot:(BOOL)condition
              notificationNames:(nullable NSArray<NSNotificationName> *)names
                        objects:(nullable NSArray<id> *)objects;

@end


NS_ASSUME_NONNULL_END
