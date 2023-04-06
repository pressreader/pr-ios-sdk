//
//  PRSourceItem+Masthead.h
//  PR-API
//
//  Created by Viacheslav Soroka on 12/26/18.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import "PRSourceItem.h"
#import "PRMastheadProvider.h"

@class PRPromise;

NS_ASSUME_NONNULL_BEGIN

@interface PRSourceItem (Masthead) <PRMastheadProvider>

- (PRPromise *)loadMastheadInfo;

@end

NS_ASSUME_NONNULL_END
