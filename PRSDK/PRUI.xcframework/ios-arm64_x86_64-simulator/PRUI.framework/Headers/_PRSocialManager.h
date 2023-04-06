//
//  _PRSocialManager.h
//  PRSocialManagers
//
//  Created by Viacheslav Soroka on 2022-03-14.
//  Copyright © 2022 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class UIViewController;

@interface _PRSocialManager : NSObject
@property (nullable, nonatomic, readonly) UIViewController *presenter;

@end

NS_ASSUME_NONNULL_END
