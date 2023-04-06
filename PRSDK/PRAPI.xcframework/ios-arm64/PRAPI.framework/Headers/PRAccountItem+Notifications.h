//
//  PRAccountItem+Notifications.h
//  PR-API
//
//  Created by Viacheslav Soroka on 8/6/20.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import "PRAccountItem.h"

NS_ASSUME_NONNULL_BEGIN

@interface PRAccountItem (Notifications)

- (void)setEnablePromotionalNotifications:(BOOL)enable completion:(void(^ _Nullable)(BOOL))completion;
- (void)setEnableNewsNotifications:(BOOL)enable completion:(void(^ _Nullable)(BOOL))completion;

@end

NS_ASSUME_NONNULL_END
