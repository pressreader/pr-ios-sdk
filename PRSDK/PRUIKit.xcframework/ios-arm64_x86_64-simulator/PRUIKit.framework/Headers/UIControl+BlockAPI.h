//
//  UIControl+BlockAPI.h
//  PR-UI
//
//  Created by berec on 24/08/2018.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^PRUIControlEventHandler)(void);

/// DEPRECATED: use `UIAction` along with `addAction:forControlEvents` method instead.
@interface UIControl (BlockAPI)

- (void)addHandlerForEvent:(UIControlEvents)event handler:(nullable PRUIControlEventHandler)eventHandler;
- (void)removeEventHandler;

@end

NS_ASSUME_NONNULL_END
