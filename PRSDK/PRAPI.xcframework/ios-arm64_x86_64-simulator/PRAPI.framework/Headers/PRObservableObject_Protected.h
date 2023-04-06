//
//  PRObservableObject_Protected.h
//  PR-API
//
//  Created by berec on 19/07/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#ifndef PRObservableObject_Protected_h
#define PRObservableObject_Protected_h

NS_ASSUME_NONNULL_BEGIN

@class PRWeakLink;

@interface PRObservableObject ()

- (void)notifyObserversWithSelector:(SEL)selector;
- (void)notifyObserversWithSelector:(SEL)selector object:(nullable id)object;

- (void)notifyObserversOnMainThreadWithSelector:(SEL)selector;
- (void)notifyObserversOnMainThreadWithSelector:(SEL)selector object:(nullable id)object;

/**
 @discussion
 An object that sends notifications. In mosts cases it should be self.
 @code
 - (void)modelDidChange:(Model *)model {
 // model is equal to `sender` property.
 }
 */
@property (nullable, nonatomic, weak) id sender;
@property (nonatomic, readonly) NSArray<PRWeakLink *> *observers;

@end

#endif /* PRObservableObject_Protected_h */

NS_ASSUME_NONNULL_END
