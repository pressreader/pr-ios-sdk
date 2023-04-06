//
//  UINavigationItem+Title_AppLogo.h
//  PR-UI
//
//  Created by berec on 23/03/2020.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UINavigationItem (Title_AppLogo)

- (void)setupDefaultTitle;
- (void)setupDefaultTitleWithCompletion:(void(^ _Nullable)(void))completion;

- (void)setupTitleMasthedWithDefaultTitle:(NSString *)title;
- (void)setupTitleMasthedWithDefaultTitle:(NSString *)title large:(BOOL)isLarge;
- (void)setupTitleMasthedWithDefaultTitle:(NSString *)title
                                    large:(BOOL)isLarge
                               completion:(void(^_Nullable)(void))completion;

@end

NS_ASSUME_NONNULL_END
