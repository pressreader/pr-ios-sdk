//
//  PRSwitcherMenuItem.h
//  PRUIKit
//
//  Created by berec on 25/11/2018.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import "PRMenuItem.h"

NS_ASSUME_NONNULL_BEGIN

@interface PRSwitcherMenuItem : PRMenuItem

+ (instancetype)itemWithTitle:(NSString *)title
                   switcherOn:(BOOL)on
                         icon:(nullable NSString *)icon
               executionBlock:(nullable void(^)(void))executionBlock;

- (void)toggleSwitcherOn;

@property (nonatomic, readonly) BOOL switcherOn;

@end

NS_ASSUME_NONNULL_END
