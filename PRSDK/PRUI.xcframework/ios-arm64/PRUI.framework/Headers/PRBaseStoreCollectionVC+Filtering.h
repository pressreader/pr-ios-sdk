//
//  PRBaseStoreCollectionVC+Filtering.h
//  PR-UI
//
//  Created by berec on 07/04/2020.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import "PRBaseStoreCollectionVC.h"

#import "PRCatalogFilterPanelVC.h"

NS_ASSUME_NONNULL_BEGIN

@interface PRBaseStoreCollectionVC (Filtering) <PRCatalogFilterPanelDelegate>

- (void)openCatalogFilter:(id<CatalogFilterProtocol>)catalogFilterItem
                   sender:(nullable UIView *)view;

@end

NS_ASSUME_NONNULL_END
