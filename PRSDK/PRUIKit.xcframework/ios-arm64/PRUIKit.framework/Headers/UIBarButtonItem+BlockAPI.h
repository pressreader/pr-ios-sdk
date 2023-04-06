//
//  UIBarButtonItem+BlockAPI.h
//  PRUIKit
//
//  Created by berec on 29/08/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIBarButtonItem (BlockAPI)

- (instancetype)initWithImage:(nullable UIImage *)image action:(void(^)(UIBarButtonItem *))action;

- (instancetype)initWithTitle:(nullable NSString *)title action:(void(^)(UIBarButtonItem *))action;

- (instancetype)initWithTitle:(nullable NSString *)title
                        style:(UIBarButtonItemStyle)style
                       action:(void(^)(UIBarButtonItem *))action;

- (instancetype)initWithBarButtonSystemItem:(UIBarButtonSystemItem)systemItem
                                     action:(void(^)(UIBarButtonItem *))action;

@end

NS_ASSUME_NONNULL_END
