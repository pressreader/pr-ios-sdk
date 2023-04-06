//
//  NSObject+PerformSelector.h
//  PR-UI
//
//  Created by berec on 20/08/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSObject (PerformSelector)
- (void)tryToPerformSelector:(SEL)selector;
- (void)tryToPerformSelector:(SEL)selector withObject:(id)object;

- (void)setNeedsPerformSelector:(SEL)selector afterDelay:(NSTimeInterval)delay;
- (void)setNeedsPerformSelector:(SEL)selector;

- (void)cancelDelayedPerformSelector:(SEL)selector object:(nullable id)object;
- (void)cancelDelayedPerformSelector:(SEL)selector;
- (void)cancelDelayedPerformSelectors;

@end

NS_ASSUME_NONNULL_END
