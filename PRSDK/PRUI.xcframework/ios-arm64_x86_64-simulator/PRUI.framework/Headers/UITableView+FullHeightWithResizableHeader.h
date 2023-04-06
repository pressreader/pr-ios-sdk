//
//  UITableView+FullHeightWithResizableHeader.h
//  PR-UI
//
//  Created by KeithC on 2019-04-16.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UITableView (FullHeightWithResizableHeader)

- (void)setNeedsUpdateTableHeaderAndScrollability;

@property (nonatomic) BOOL tableHeaderResizable;
@property (nonatomic) BOOL autoDisabledScrolling;

@end

NS_ASSUME_NONNULL_END
