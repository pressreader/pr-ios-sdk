//
//  PRSwitcherMenuItem.h
//  PR-API
//
//  Created by berec on 25/11/2018.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import "PRMenuItem.h"

NS_ASSUME_NONNULL_BEGIN

@interface PRSwitcherMenuItem : PRMenuItem

+ (instancetype)itemWithTitle:(NSString *)title
                   switcherOn:(BOOL)on
                     iconName:(nullable NSString *)iconName
               executionBlock:(nullable void(^)(void))executionBlock;

@property (nonatomic, readonly) BOOL switcherOn;
- (void)toggleSwitcherOn;

@end

NS_ASSUME_NONNULL_END
