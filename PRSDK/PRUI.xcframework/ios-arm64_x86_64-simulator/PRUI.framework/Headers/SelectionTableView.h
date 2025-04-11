//
//  SelectionTableView.h
//  PRiphone
//
//  Created by Vitali Bounine on 7/31/13.
//  Copyright (c) 2013 NewspaperDirect. All rights reserved.
//

#import "PRMTBlockTableView.h"

NS_ASSUME_NONNULL_BEGIN

@interface SelectionTableView : PRMTBlockTableView

- (void)setSelectionList:(NSArray *)selectionList
       selectedItemIndex:(NSInteger)index
    withSelectedCallback:(void(^)(NSInteger))cbblock;

@end

NS_ASSUME_NONNULL_END
