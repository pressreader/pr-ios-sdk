//
//  PRSearchBar.h
//  PRiphone
//
//  Created by berec on 7/27/16.
//  Copyright © 2016 NewspaperDirect. All rights reserved.
//

@import UIKit;
#import "PRAppStyle+Theme.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSUInteger, PRSearchBarOption) {
    PRSearchBarOptionNone = 0,
    PRSearchBarOptionFitNavigationBar = 1 << 0,
    PRSearchBarOptionCenterPlaceholder = 1 << 1,
    PRSearchBarOptionDisableCursorAnimation = 1 << 2,
    PRSearchBarOptionNarrowSearchField = 1 << 3,
    PRSearchBarOptionBranded = 1 << 4,
};

@interface PRSearchBar : UISearchBar

- (instancetype)initWithFrame:(CGRect)frame appearance:(PRTheme)appearance options:(PRSearchBarOption)options;
- (instancetype)initWithAppearance:(PRTheme)appearance options:(PRSearchBarOption)options;
- (instancetype)initWithOptions:(PRSearchBarOption)options;

///Workaround: Disable show cancel button on UISearchController for IOS before 13
@property (nonatomic) BOOL denyCancelButton;
@property (nonatomic) PRSearchBarOption options;
@property (nonatomic, strong) NSString *cancelButtonTitle;
@property (nonatomic, strong) UIColor *iconsTintColor;

@end

NS_ASSUME_NONNULL_END
