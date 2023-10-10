//
//  PRVerticalFeedVC.h
//  PRiphone
//
//  Created by Viacheslav Soroka on 7/28/17.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

#import "NTFFeedDataSource.h"
#import "CustomStyleableTextFlowVC.h"

@class PRMenuItem;

NS_ASSUME_NONNULL_BEGIN

@interface PRVerticalFeedVC : CustomStyleableTextFlowVC <NTFFeedDataSourceDelegate>

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

- (NSArray<PRMenuItem *> *)mainMenuItems;

@end

NS_ASSUME_NONNULL_END
