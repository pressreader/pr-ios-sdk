//
//  LibraryItemFeedUtil.h
//  PRUI
//
//  Created by Viacheslav Soroka on 11/7/17.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

@import UIKit;

@class PRActionMenuVC;
@class LibraryItemFeedVC;
@class PRMenuItem;

NS_ASSUME_NONNULL_BEGIN

@interface LibraryItemFeedUtil: NSObject

+ (void)setTitleForTocVC:(PRActionMenuVC *)tocVC
                   title:(nullable NSString *)title
                subtitle:(nullable NSString *)subtitle
       mastheadImageView:(nullable UIImageView *)mastheadImageView;

+ (nullable NSArray<PRMenuItem *> *)sectionMenuItemsForMenuVC:(PRActionMenuVC *)menuVC feedVC:(LibraryItemFeedVC *)feedVC;

@end

NS_ASSUME_NONNULL_END
