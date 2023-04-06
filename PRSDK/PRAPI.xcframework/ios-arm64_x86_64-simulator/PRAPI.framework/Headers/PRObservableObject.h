//
//  PRObservableObject.h
//  PR-API
//
//  Created by Viacheslav Soroka on 12/3/18.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

@interface PRObservableObject<T> : NSObject

/// ObservableObject handles deallocated observers by itself.
/// Do not call this method inside dealloc method of an observer.
- (void)removeObserver:(T)observer;
- (void)addObserver:(T)observer;

@end

NS_ASSUME_NONNULL_END
