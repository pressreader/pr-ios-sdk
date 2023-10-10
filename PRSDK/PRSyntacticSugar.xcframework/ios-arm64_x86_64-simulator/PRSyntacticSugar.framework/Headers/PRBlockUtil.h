//
//  PRBlockUtil.h
//  PR-API
//
//  Created by berec on 01/10/2018.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^PRSimpleBlock)(void);

@interface PRBlockUtil : NSObject

// perfrom block in main thread after delay
+ (id)performBlockInMainThread:(PRSimpleBlock)aBlock afterDelay:(NSTimeInterval)seconds;

/// perfrom block in dispatch_queue after delay
+ (id)performBlockAfterDelay:(NSTimeInterval)seconds queue:(dispatch_queue_t)queue block:(PRSimpleBlock)block;

/// return handle to use with cancel
+ (id)performBlock:(PRSimpleBlock)aBlock afterDelay:(NSTimeInterval)seconds dispatch_queue:(dispatch_queue_t)dispatch_queue;

/// cancel previous perform block
+ (void)cancelPreviousPerformBlockInMainThread:(id)aHandle;

+ (void)performBlockInMainThread:(PRSimpleBlock)aBlock NS_SWIFT_NAME(performInMainThread(_:));
+ (void)performBlockInMainThreadAsync:(BOOL)async block:(PRSimpleBlock)block;

+ (void)performBlockInBackgroundThread:(PRSimpleBlock)block NS_SWIFT_NAME(performInBackgroundThread(_:));

@end


@interface PRBlockUtil (Convenience)

void PRMainThread(PRSimpleBlock block);

/// Guaranties that `block` will be called asynchronously
void PRMainThreadAsync(PRSimpleBlock block);

void PRMainThreadAfterDelay(NSTimeInterval delay, PRSimpleBlock block);

void PRBackgroundThread(PRSimpleBlock block);

/// Guaranties that `block` will be called asynchronously
void PRBackgroundThreadAsync(PRSimpleBlock block);

@end

NS_ASSUME_NONNULL_END
