//
//  ModelProtocol.h
//  PR-API
//
//  Created by Viacheslav Soroka on 12/3/18.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(uint8_t, ModelState) {
    ModelUnloaded = 0,
    ModelLoading,
    ModelLoaded,
    ModelFailLoading,
    ModelUpdated
};

@protocol ModelProtocol <NSObject>

@property (nonatomic, readonly) ModelState state;

@optional
- (void)load;
- (void)load:(void(^)(BOOL success))completion;
- (void)unload;

- (void)update;

- (void)cancel;

// This method should be called directly when model started loadind.
- (void)startLoading;

// This method should be called directly when model finisded loadind.
- (void)finishLoading;

// This method should be called directly when model failed loadind.
- (void)failLoading;

// This method should be called directly when model finisded updating.
- (void)finishUpdating;

// This method should be called directly when model finisded unloading.
- (void)finishUnloading;

@end

NS_ASSUME_NONNULL_END
