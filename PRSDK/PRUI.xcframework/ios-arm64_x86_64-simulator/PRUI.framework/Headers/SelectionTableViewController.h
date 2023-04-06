//
//  SelectionTableViewController.h
//  PR-UI
//
//  Created by Viacheslav Soroka on 10/17/19.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SelectionTableView.h"

NS_ASSUME_NONNULL_BEGIN

@interface SelectionTableViewController : UIViewController

+ (instancetype)selectionTableViewController;

- (void)setSelectionList:(NSArray<NSString *> *)selectionList
    withSelectedCallback:(void(^)(NSInteger))cbblock;
- (void)setSelectionList:(NSArray<NSString *> *)selectionList
       selectedItemIndex:(NSInteger)index
    withSelectedCallback:(void(^)(NSInteger))cbblock;

@property (nonatomic, readonly) SelectionTableView *tableView;

@end

NS_ASSUME_NONNULL_END
