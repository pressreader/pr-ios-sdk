//
//  PRDebouncer.h
//  PRiphone
//
//  Created by Viacheslav Soroka on 7/18/17.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void(^PRDebouncerCallback)(void);

NS_ASSUME_NONNULL_BEGIN;

/**
 This class does not deallocate after `call` and before callback execution or `cancel` call.
 */
@interface PRDebouncer : NSObject

+ (instancetype)debouncerWithDelay:(NSTimeInterval)delay callback:(nullable PRDebouncerCallback)callback;
- (instancetype)initWithDelay:(NSTimeInterval)delay callback:(nullable PRDebouncerCallback)callback;

- (void)call;
- (void)callWithCallback:(nullable PRDebouncerCallback)callback;
- (void)callWithCallback:(nullable PRDebouncerCallback)callback delay:(NSTimeInterval)delay;

- (void)callNow;
- (void)callNowWithCallback:(nullable PRDebouncerCallback)callback;

- (void)cancel;

@end

NS_ASSUME_NONNULL_END;
