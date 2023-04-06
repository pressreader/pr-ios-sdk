//
//  PRCatalogFilterPanelVC.h
//  PRiphone
//
//  Created by Oleg Stepanenko on 11.02.14.
//  Copyright (c) 2014 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

@import PRAPI.PRSourceList;
@import PRAPI.PRSourceListFilter;

@class PRCatalogFilterPanelVC;
@class PRCatalogFilterItem;
@protocol CatalogFilterProtocol;
@protocol CatalogFilterVariant;

NS_ASSUME_NONNULL_BEGIN

@protocol PRCatalogFilterPanelDelegate <NSObject>
- (void)catalogFilterPanel:(PRCatalogFilterPanelVC *)filterPanel
             didSelectItem:(id<CatalogFilterVariant>)item;
@end


@interface PRCatalogFilterPanelVC : UITableViewController

- (instancetype)initWithFilter:(id<CatalogFilterProtocol>)filter;
- (instancetype)initWithStyle:(UITableViewStyle)style NS_UNAVAILABLE;
- (instancetype)initWithNibName:(nullable NSString *)nibNameOrNil bundle:(nullable NSBundle *)nibBundleOrNil NS_UNAVAILABLE;
- (nullable instancetype)initWithCoder:(NSCoder *)coder NS_UNAVAILABLE;
- (id)init NS_UNAVAILABLE;

@property (nonatomic, assign, readonly) PRSourceListFilterID sourceListFilterID;

@property (nonatomic) CGSize imageSize;

@property (nonatomic) BOOL displayImagePlaceholder;
@property (nonatomic) BOOL shouldShowSectionIndex;
@property (nonatomic) BOOL isImageRounded;

@property (nonatomic, weak) id<PRCatalogFilterPanelDelegate> panelDelegate;

@end

NS_ASSUME_NONNULL_END
