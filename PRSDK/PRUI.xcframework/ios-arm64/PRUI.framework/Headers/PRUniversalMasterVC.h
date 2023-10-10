//
//  PRUniversalMasterVC.h
//  PRiphone
//
//  Created by Jackie Cane on 14/01/14.
//  Copyright (c) 2014 NewspaperDirect. All rights reserved.
//
#import "PRStylingTableVC.h"
#import "ViewRefreshable.h"

NS_ASSUME_NONNULL_BEGIN

// Controller which automatically makes desicion about presenting hierarchic disclosure depending on device type.
@interface PRUniversalMasterVC : PRStylingTableVC <ViewRefreshable>

- (void)pushDetailsVC:(UIViewController *)detailsVC animated:(BOOL)animated;

@property (nonatomic, readonly) NSIndexPath *initialIndexPath;

@end

NS_ASSUME_NONNULL_END
