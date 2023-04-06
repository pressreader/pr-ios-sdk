//
//  MTBlockTableView.h
//  MTTableViewController
//
//  Created by Parker Wightman on 8/10/12.
//  Copyright (c) 2012 Mysterious Trousers. All rights reserved.
//

@import UIKit;

@interface MTBlockTableView : UITableView <UITableViewDelegate, UITableViewDataSource>

#pragma mark UITableViewDataSource blocks (required)

@property (nonatomic, copy) NSInteger (^numberOfRowsInSectionBlock)(UITableView *tableView, NSInteger section);
@property (nonatomic, copy) UITableViewCell * (^cellForRowAtIndexPathBlock)(UITableView *tableView, NSIndexPath *indexPath);



#pragma mark UITableViewDataSource blocks (optional)

@property (nonatomic, copy) NSInteger (^numberOfSectionsInTableViewBlock)(UITableView *tableView);
@property (nonatomic, copy) NSString * (^titleForHeaderInSectionBlock)(UITableView *tableView, NSInteger section);
@property (nonatomic, copy) NSString * (^titleForFooterInSectionBlock)(UITableView *tableView, NSInteger section);
@property (nonatomic, copy) BOOL (^canEditRowAtIndexPathBlock)(UITableView *tableView, NSIndexPath *indexPath);
@property (nonatomic, copy) BOOL (^canMoveRowAtIndexPathBlock)(UITableView *tableView, NSIndexPath *indexPath);
@property (nonatomic, copy) NSArray * (^sectionIndexTitlesBlock)(UITableView *tableView);
@property (nonatomic, copy) void (^commitEditingStyleForRowAtIndexPathBlock)(UITableView *tableView, UITableViewCellEditingStyle editingStyle, NSIndexPath *indexPath);
@property (nonatomic, copy) void (^moveRowAtIndexPathToIndexPathBlock)(UITableView *tableView, NSIndexPath *sourceIndexPath, NSIndexPath *destinationIndexPath);
@property (nonatomic, copy) NSInteger (^sectionForSectionIndexTitleAtIndex)(UITableView *tableView, NSString *title, NSInteger index);


#pragma mark - UITableViewDelegate blocks (optional)

@property (nonatomic, copy) void (^accessoryButtonTappedForRowWithIndexPathBlock)(UITableView *tableView, NSIndexPath *indexPath);
@property (nonatomic, copy) BOOL (^canPerformActionForRowAtIndexPathWithSenderBlock)(UITableView *tableView, SEL action, NSIndexPath *indexPath, id sender);
@property (nonatomic, copy) void (^didDeselectRowAtIndexPathBlock)(UITableView *tableView, NSIndexPath *indexPath);
@property (nonatomic, copy) void (^didEndEditingRowAtIndexPathBlock)(UITableView *tableView, NSIndexPath *indexPath);
@property (nonatomic, copy) void (^didSelectRowAtIndexPathBlock)(UITableView *tableView, NSIndexPath *indexPath);
@property (nonatomic, copy) UITableViewCellEditingStyle (^editingStyleForRowAtIndexPathBlock)(UITableView *tableView, NSIndexPath *indexPath);
@property (nonatomic, copy) CGFloat (^heightForFooterInSectionBlock)(UITableView *tableView, NSInteger section);
@property (nonatomic, copy) CGFloat (^heightForHeaderInSectionBlock)(UITableView *tableView, NSInteger section);
@property (nonatomic, copy) CGFloat (^heightForRowAtIndexPathBlock)(UITableView *tableView, NSIndexPath *indexPath);
@property (nonatomic, copy) NSInteger (^indentationLevelForRowAtIndexPathBlock)(UITableView *tableView, NSIndexPath *indexPath);
@property (nonatomic, copy) void (^performActionForRowAtIndexPathWithSenderBlock)(UITableView *tableView, SEL action, NSIndexPath *indexPath, id sender);
@property (nonatomic, copy) BOOL (^shouldIndentWhileEditingRowAtIndexPathBlock)(UITableView *tableView, NSIndexPath *indexPath);
@property (nonatomic, copy) BOOL (^shouldShowMenuForRowAtIndexPathBlock)(UITableView *tableView, NSIndexPath *indexPath);
@property (nonatomic, copy) NSIndexPath * (^targetIndexPathForMoveFromRowAtIndexPathToProposedIndexPathBlock)(UITableView *tableView, NSIndexPath *sourceIndexPath, NSIndexPath *proposedDestinationIndexPath);
@property (nonatomic, copy) NSString * (^titleForDeleteConfirmationButtonForRowAtIndexPathBlock)(UITableView *tableView, NSIndexPath *indexPath);
@property (nonatomic, copy) UIView * (^viewForFooterInSectionBlock)(UITableView *tableView, NSInteger section);
@property (nonatomic, copy) UIView * (^viewForHeaderInSectionBlock)(UITableView *tableView, NSInteger section);
@property (nonatomic, copy) void (^willBeginEditingRowAtIndexPathBlock)(UITableView *tableView, NSIndexPath *indexPath);
@property (nonatomic, copy) NSIndexPath * (^willDeselectRowAtIndexPathBlock)(UITableView *tableView, NSIndexPath *indexPath);
@property (nonatomic, copy) void (^willDisplayCellForRowAtIndexPathBlock)(UITableView *tableView, UITableViewCell *cell, NSIndexPath *indexPath);
@property (nonatomic, copy) NSIndexPath * (^willSelectRowAtIndexPathBlock)(UITableView *tableView, NSIndexPath *indexPath);

#pragma mark - UIScrollViewDelegate

@property (nonatomic, copy) void(^didScrollBlock)(UIScrollView *scrollView);

@end

