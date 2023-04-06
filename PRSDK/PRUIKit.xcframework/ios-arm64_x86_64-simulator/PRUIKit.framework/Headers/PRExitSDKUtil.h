//
//  PRExitSDKUtil.h
//  PRUI
//
//  Created by berec on 30/12/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface PRExitSDKUtil : NSObject

@property (class, nonatomic, readonly) NSString *title;
@property (class, nonatomic, readonly) NSString *iconName;
@property (class, nonatomic, readonly) UIImage *icon;
@property (class, nonatomic, readonly) void(^actionBlock)(void);

@property (class, nonatomic, readonly) UIBarButtonItem *barButtonItem;

@end

NS_ASSUME_NONNULL_END
