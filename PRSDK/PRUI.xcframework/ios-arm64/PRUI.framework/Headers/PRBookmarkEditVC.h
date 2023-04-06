//
//  PRBookmarkEditVC.h
//  PRiphone
//
//  Created by Keith Choi on 2016-10-31.
//  Copyright © 2016 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>
@import PRAPI.NTFDataSourcable;

NS_ASSUME_NONNULL_BEGIN

@class PRSmartPageset;

@interface PRBookmarkEditVC : UIViewController 
@property (nonatomic, strong) UITableView *tableView;
@property (nonatomic, strong) UIBarButtonItem *saveButton;
@property (nonatomic, strong) UIBarButtonItem *deleteButton;

@property (nonatomic, strong) id item;
@property (nonatomic, strong) NTFDataSource *dataSource;
@property (nonatomic, strong) NSMutableArray *userCollections;

- (instancetype)initWithItem:(id<NTFDataSourcable>)item;
- (instancetype)initWithItem:(id<NTFDataSourcable>)item pageSelectorReadOnly:(BOOL)readOnly;

- (instancetype)initWithPageSet:(PRSmartPageset *)item dataSource:(NTFDataSource *)dataSource;
- (instancetype)initWithPageSet:(PRSmartPageset *)item dataSource:(NTFDataSource *)dataSource
           pageSelectorReadOnly:(BOOL)readOnly;

- (instancetype)initWithDataSource:(NTFDataSource *)dataSource pages:(NSSet<NSNumber *> *)pages;

- (void)dismiss:(id)sender;

@end

NS_ASSUME_NONNULL_END
