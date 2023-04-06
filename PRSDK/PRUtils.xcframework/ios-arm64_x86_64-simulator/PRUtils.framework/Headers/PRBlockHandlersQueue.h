//
//  PRBlockHandlersQueue.h
//  PR-API
//
//  Created by berec on 20/11/2018.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PRBlockHandler;

/**
 @brief Stack of handlers which are executed in FIFO order with respect of their priority
 */
@interface PRBlockHandlersQueue : NSObject

/**
 @param discardable NO if handler is supposed to be executed only once with subsequent removal from the stack
 @return newly created handler object that you can use as a parameter in removeHandler: method
 */
- (PRBlockHandler *)addHandlerWithPriority:(NSOperationQueuePriority)priority discardable:(BOOL)discardable block:(void(^)(void))block;
- (void)removeHandler:(PRBlockHandler *)handler;
- (void)executeHandlers;

@end

NS_ASSUME_NONNULL_END
