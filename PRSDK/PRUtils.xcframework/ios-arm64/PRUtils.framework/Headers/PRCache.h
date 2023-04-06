//
//  PRCache.h
//  PR-API
//
//  Created by Viacheslav Soroka on 7/23/18.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef id<NSCopying, NSCoding> PRKeyType;

NS_ASSUME_NONNULL_BEGIN

@interface PRCache : NSObject

+ (instancetype)sharedCache;

- (instancetype)initWithCountLimit:(NSUInteger)countLimit
       memoryWarningCleanupEnabled:(BOOL)memoryWarningCleanupEnabled NS_DESIGNATED_INITIALIZER;

- (void)setObject:(nullable id)object forKey:(PRKeyType)key;

- (void)removeObjectForKey:(PRKeyType)key;
- (void)removeObject:(id)object;
- (void)removeAllObjects;

- (nullable id)objectForKey:(PRKeyType)key;

- (NSEnumerator *)objectEnumerator;
- (NSEnumerator<PRKeyType> *)keyEnumerator;

@property (nonatomic, readonly) NSUInteger count;
@property (nonatomic, assign) NSUInteger countLimit;

/// Activates keyFootprint collector.
@property (nonatomic) BOOL keepKeyFootprint;
/// Contains keys which objects were purged from cache due to cleanup after reaching `countLimit`.
@property (nonatomic, strong, readonly) NSMutableSet<PRKeyType> *keyFootprint;

@end

NS_ASSUME_NONNULL_END
