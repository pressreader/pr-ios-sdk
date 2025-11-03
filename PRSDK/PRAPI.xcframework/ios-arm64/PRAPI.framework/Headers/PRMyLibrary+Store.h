//
//  PRMyLibrary+Store.h
//  PRiphone
//
//  Created by Jackie Cane on 10/18/12.
//  Copyright (c) 2012 NewspaperDirect. All rights reserved.
//

#import "PRMyLibrary.h"

@interface PRMyLibrary (Store)

- (void)deleteAllContent;

- (void)restore:(BOOL)preload;

@end
