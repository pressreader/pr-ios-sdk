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

@interface UIControl (BlockAPI)

- (void)addHandlerForEvent:(UIControlEvents)event handler:(PRUIControlEventHandler)eventHandler;
- (void)removeEventHandler;

@end

NS_ASSUME_NONNULL_END
