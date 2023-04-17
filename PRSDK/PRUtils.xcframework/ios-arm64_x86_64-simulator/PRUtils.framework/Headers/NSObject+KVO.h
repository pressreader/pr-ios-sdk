//
//  NSObject+KVO.h
//  PR-API
//
//  Created by berec on 31/01/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//
//  Category for accessing KVO functinality using block API.
//  Handy for debug purposes.

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^PRKVO)(id object, NSDictionary<NSKeyValueChangeKey,id> *_Nullable change);

@interface NSObject (KVO)

/// @param identifier Providing a unique identifier allows to set more than one block observer of the same `keyPath`
- (void)setBlockObserverForKeyPath:(NSString *)keyPath
                        identifier:(NSString *_Nullable)identifier
                          observer:(PRKVO)observer;

- (void)setBlockObserverForKeyPath:(NSString *)keyPath observer:(PRKVO)observer;

- (void)removeBlockObserverForKeyPath:(NSString *)keyPath identifier:(NSString *_Nullable)identifier;
- (void)removeBlockObserverForKeyPath:(NSString *)keyPath;

- (void)removeAllBlockObservers;

@end

NS_ASSUME_NONNULL_END
