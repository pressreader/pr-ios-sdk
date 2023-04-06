//
//  PRVerticalFeedVC.h
//  PRiphone
//
//  Created by Viacheslav Soroka on 7/28/17.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

#import "VerticalTextFlowVC.h"

#import "NTFFeedDataSource.h"

@class PRMenuItem;

NS_ASSUME_NONNULL_BEGIN

@interface PRVerticalFeedVC : VerticalTextFlowVC <NTFFeedDataSourceDelegate>

+ (instancetype)controllerFromStoryboardWithDataSource:(NTFFeedDataSource *)dataSource;

- (nullable NSDictionary<NSString *, NSString *> *)itemNameToCellIdMap;

/// `dataSource` casted into `NTFFeedDataSource`
@property (nonatomic, readonly) __kindof NTFFeedDataSource *feedDataSource;

@property (nonatomic, readonly) BOOL isBarTransparent;
@property (nonatomic, readonly) UIImage *lensImage;
@property (nonatomic, readonly) UIImage *actionMenuImage;
@property (nonatomic, readonly) UIImage *backImage;

@end

@class PRNavMenuFilter;

@interface PRVerticalFeedVC (/*Protected*/)

- (void)openFilterResultsWithFilter:(PRNavMenuFilter *)filter;
- (NSArray<PRMenuItem *> *)mainMenuItems;

@end

NS_ASSUME_NONNULL_END
