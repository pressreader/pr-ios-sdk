//
//  PRObservableModel.h
//  PR-API
//
//  Created by Viacheslav Soroka on 12/3/18.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import "PRObservableObject.h"

#import "ModelProtocol.h"
#import "ModelObserver.h"

NS_ASSUME_NONNULL_BEGIN

@protocol PRObservableModelSpecific <NSObject>
- (void)addObserver:(id<ModelObserver>)observer NS_SWIFT_NAME(addObserver(_:));

@end

@interface PRObservableModel : PRObservableObject <ModelProtocol, PRObservableModelSpecific>

// This method is always performed in background and subclasses should overload it to
// define the background processing capabilities.
// This method is intended for subclassing and should never be called directly.
- (void)loadInBackground;

// This method is always performed in main thread and subclasses should overload
// This method is intended for subclassing and should never be called directly.
- (void)unloadInMainThread;

@end

NS_ASSUME_NONNULL_END
