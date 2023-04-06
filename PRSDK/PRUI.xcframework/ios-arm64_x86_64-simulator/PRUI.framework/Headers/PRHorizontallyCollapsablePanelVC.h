//
//  PRHorizontallyCollapsablePanelVC.h
//  PRiphone
//
//  Created by berec on 4/22/16.
//  Copyright © 2016 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

@class PRHorizontallyCollapsablePanelVC;

@protocol PRFilterPanelDelegate <NSObject>

- (void)filterPanel:(PRHorizontallyCollapsablePanelVC *)panel didSelectItem:(id)item;

@end

@interface PRHorizontallyCollapsablePanelVC : UIViewController <UITableViewDelegate, UITableViewDataSource>
@property (nonatomic, assign) CGFloat expandedWidth;

@property (nonatomic, readonly) UITableView *tableView;
@property (nonatomic, readonly) CGFloat headerHeight;

@property (nonatomic, weak) id<PRFilterPanelDelegate> delegate;

@property (nonatomic, readonly, getter=isExpanded) BOOL expanded;

- (void)setHeaderView:(UIView *)header height:(CGFloat)height;

@end


@interface PRHorizontallyCollapsablePanelVC (/*Appearance*/)
@property (nonatomic, copy) UIColor *contentBackgroundColor;

@end
