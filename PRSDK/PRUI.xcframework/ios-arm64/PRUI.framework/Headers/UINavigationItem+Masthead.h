//
//  UINavigationItem+Masthead.h
//  PRUI
//
//  Created by Ivan Berezin on 04/03/2022.
//  Copyright © 2022 NewspaperDirect. All rights reserved.
//

@import UIKit;
@import PRAccessibility;
@import PRAPI.PRMastheadProvider;

NS_ASSUME_NONNULL_BEGIN

@interface UINavigationItem (Masthead)

- (void)setupTitleViewWithMastheadProvider:(id<PRMastheadProvider>)mastheadProvider;

- (void)setupTitleViewWithMastheadProvider:(id<PRMastheadProvider>)mastheadProvider
                                     title:(nullable NSString *)title
                                  subtitle:(nullable NSString *)subtitle;

- (void)setupTitleViewWithMastheadProvider:(id<PRMastheadProvider>)mastheadProvider
                                     title:(nullable NSString *)title
                                  subtitle:(nullable NSString *)subtitle
                                     theme:(PRTheme)theme
                                completion:(void (^_Nullable)(UIImage * _Nullable, NSError * _Nullable))completion;

@end

NS_ASSUME_NONNULL_END
