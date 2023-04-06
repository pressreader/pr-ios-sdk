//
//  PRNSBundle+Updatable.h
//  PR-API
//
//  Created by berec on 16/11/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

@import Foundation;
@import PRUtils.PRNSBundle;

@class PRUpdateItem;


NS_ASSUME_NONNULL_BEGIN

@interface PRNSBundle (Updatable)

+ (PRUpdateItem *)resourceUpdateItem;
+ (void)UpdateOnlineContentUpdaterItems;

+ (NSBundle *)updatedResourceBundle;

@end

NS_ASSUME_NONNULL_END
