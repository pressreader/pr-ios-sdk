//
//  UIViewController+VisibilityState.h
//  PR-UI
//
//  Created by berec on 15/07/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(uint8_t, VCVisibilityState) {
    VCVisibilityStateNone = 0,
    VCVisibilityStateWillAppear = 1 << 0,
    VCVisibilityStateDidAppear = 1 << 1,
    VCVisibilityStateWillDisappear = 1 << 2,
    VCVisibilityStateDidDisappear = 1 << 3
};

@interface UIViewController (VisibilityState)

- (void)updateVisibilityState:(VCVisibilityState)state;

@property (nonatomic, readonly) VCVisibilityState visibilityState;

@end

NS_ASSUME_NONNULL_END
