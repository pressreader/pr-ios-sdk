//
//  PRRoundedTableView.h
//  PRiphone
//
//  Created by Jackie Cane on 30/01/15.
//  Copyright (c) 2015 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PRRoundedTableViewCell.h"

NS_ASSUME_NONNULL_BEGIN

@interface UITableView (RoundedCell)

- (void)adjustStyleOfRoundedCell:(PRRoundedTableViewCell *)cell atIndexPath:(NSIndexPath *)indexPath;

@end

NS_ASSUME_NONNULL_END
