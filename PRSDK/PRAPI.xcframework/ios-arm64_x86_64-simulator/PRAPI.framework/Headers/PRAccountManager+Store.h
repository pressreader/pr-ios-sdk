//
//  PRAccounts+Store.h
//  PRiphone
//
//  Created by Jackie Cane on 10/18/12.
//  Copyright (c) 2012 NewspaperDirect. All rights reserved.
//

#import "PRAccountManager.h"

@interface PRAccountManager (Store)

+ (void)deleteAllContentExceptAccount:(BOOL)exceptAccount;
+ (void)deleteAllContent;

@end
