//
//  UIViewController+Search.h
//  PRUIKit
//
//  Created by Ivan Berezin on 15/03/2023.
//  Copyright © 2023 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, PRNavigationBarSearchItemStyle) {
    PRNavigationBarSearchItemStyleNone = 0,
    PRNavigationBarSearchItemStyleButton,
    PRNavigationBarSearchItemStyleTextField
};

extern NSInteger const PRUIViewControllerSearchButtonTag;

@class PRSearchBar;

NS_ASSUME_NONNULL_BEGIN

@interface UIViewController (Search)

- (UIView *)createSearchBar;
- (UIView *)createSearchBarWithText:(nullable NSString *)text
                        placeholder:(nullable NSString *)placeholder;

@property (nonatomic, readonly) CGFloat searchBarRegularWidth;
@property (nonatomic, readonly) PRNavigationBarSearchItemStyle searchItemStyle;

@end

NS_ASSUME_NONNULL_END
