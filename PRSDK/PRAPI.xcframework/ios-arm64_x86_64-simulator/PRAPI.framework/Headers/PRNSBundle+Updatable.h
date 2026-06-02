//
//  PRNSBundle+Updatable.h
//  PR-API
//
//  Created by berec on 16/11/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PRUtils/PRUtils.h>
#import <PRConfiguration/PRNSBundle.h>

@class PRUpdateItem;

NS_ASSUME_NONNULL_BEGIN

@interface PRNSBundle (Updatable)

+ (nullable PRUpdateItem *)resourceUpdateItem;
+ (void)UpdateOnlineContentUpdaterItems;

+ (nullable NSBundle *)updatedResourceBundle;

@end

NS_ASSUME_NONNULL_END
