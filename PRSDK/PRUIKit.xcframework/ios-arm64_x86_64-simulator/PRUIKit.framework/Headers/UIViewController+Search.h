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

extern NSUInteger const PRUIViewControllerSearchButtonTag;

@class PRSearchBar;

NS_ASSUME_NONNULL_BEGIN

@interface UIViewController (Search)

- (UIBarButtonItem *)createSearchBarButton;
- (PRSearchBar *)createSearchBar;

- (void)searchButtonAction:(id)sender;

@property (nonatomic, readonly) PRNavigationBarSearchItemStyle searchItemStyle;

@end

NS_ASSUME_NONNULL_END
