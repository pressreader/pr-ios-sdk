//
//  PRAccountVC.h
//  PRiphone
//
//  Created by Jackie Cane on 10/01/14.
//  Copyright (c) 2014 NewspaperDirect. All rights reserved.
//

#import "PRStylingTableVC.h"

@class PRAccountItem;

NS_ASSUME_NONNULL_BEGIN

@interface PRAccountVC : PRStylingTableVC
@property (nullable, nonatomic, strong) PRAccountItem *accountItem;

@end

NS_ASSUME_NONNULL_END
