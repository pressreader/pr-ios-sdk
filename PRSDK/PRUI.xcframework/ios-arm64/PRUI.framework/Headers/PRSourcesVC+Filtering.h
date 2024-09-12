//
//  PRSourcesVC+Filtering.h
//  PR-UI
//
//  Created by berec on 07/04/2020.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import "PRSourcesVC.h"

#import "PRCatalogFilterPanelVC.h"

NS_ASSUME_NONNULL_BEGIN

@interface PRSourcesVC (Filtering) <PRCatalogFilterPanelDelegate>

- (void)openCatalogFilter:(id<CatalogNavigation>)catalogFilterItem
                   sender:(nullable UIView *)view;

@end

NS_ASSUME_NONNULL_END
