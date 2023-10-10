//
//  VerticalTextFlowVC.h
//  PRiphone
//
//  Created by Vitali Bounine on 2016-07-04.
//  Copyright © 2016 NewspaperDirect. All rights reserved.
//

@import PRUIKit.PRVC;
@import PRConfiguration.PRFeedConfig;
@import PRAccessibility;
#import <PRUI/AdditionalContentInsetable.h>
#import <PRUI/NTFDataSource.h>

NS_ASSUME_NONNULL_BEGIN

@class NTFFeedDataSource;
@protocol ItemSelectionDelegate;

typedef NS_ENUM(uint8_t, NTFTextFlowType) {
    NTFTextFlowTypeUndefined = 0,
    NTFTextFlowTypeHomeFeed,
    NTFTextFlowTypeBookmarks,
    NTFTextFlowTypeMLI
};

/**
    This class was intended to work with any NTFDataSource.
    We can have several root data source classes, that adopt to NTFDataSource protocol.
    So, you should work only with NTFDataSource *and avoid to put any code depending on implementation into this class.
 */
@interface VerticalTextFlowVC : PRVC <NTFDataSourceDelegate, AdditionalContentInsetable>

+ (instancetype)controllerWithDataSource:(NTFDataSource *)dataSource;

- (instancetype)initWithDataSource:(nullable NTFDataSource *)dataSource NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithNibName:(nullable NSString *)nibNameOrNil
                         bundle:(nullable NSBundle *)nibBundleOrNil NS_UNAVAILABLE;
- (instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (void)scrollToCurrentRow;
- (void)scrollToCurrentRowAnimated:(BOOL)animated forced:(BOOL)forced;

- (void)reloadData;

@property (class, nonatomic, readonly) NTFLayoutType preferredLayoutType;
@property (class, nonatomic, readonly) NTFLayoutType layoutType;

@property (nonatomic, readonly) UITableView *tableView;
@property (nonatomic, strong) NTFDataSource *dataSource;

@property (nonatomic) UIEdgeInsets contentInsets;

@property (nonatomic) PRFeedArticleAction articleActions;

@property (nonatomic) BOOL embedded;
@property (nonatomic, readonly) NTFTextFlowType textFlowType;

@property (nullable, nonatomic, weak) id<ItemSelectionDelegate> itemSelectionDelegate;

@end

NS_ASSUME_NONNULL_END
