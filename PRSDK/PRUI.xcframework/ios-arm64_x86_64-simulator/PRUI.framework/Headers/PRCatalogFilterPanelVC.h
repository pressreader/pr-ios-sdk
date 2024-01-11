//
//  PRCatalogFilterPanelVC.h
//  PRiphone
//
//  Created by Oleg Stepanenko on 11.02.14.
//  Copyright (c) 2014 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

@import PRAPI;

@class PRCatalogFilterPanelVC;
@class PRCatalogFilterItem;
@protocol CatalogNavigation;
@protocol CatalogNavigationVariant;
@class PRCatalogFilterTableCell;

NS_ASSUME_NONNULL_BEGIN

@protocol PRCatalogFilterPanelDelegate <NSObject>
- (void)catalogFilterPanel:(PRCatalogFilterPanelVC *)filterPanel
             didSelectItem:(id<CatalogNavigationVariant>)item;
@end


@interface PRCatalogFilterPanelVC : UITableViewController

- (instancetype)initWithFilter:(id<CatalogNavigation>)filter;
- (instancetype)initWithStyle:(UITableViewStyle)style NS_UNAVAILABLE;
- (instancetype)initWithNibName:(nullable NSString *)nibNameOrNil bundle:(nullable NSBundle *)nibBundleOrNil NS_UNAVAILABLE;
- (nullable instancetype)initWithCoder:(NSCoder *)coder NS_UNAVAILABLE;
- (id)init NS_UNAVAILABLE;

@property (nonatomic, assign, readonly) CatalogNavigationType sourceListFilterID;

@property (nonatomic) BOOL displayImagePlaceholder;
@property (nonatomic) BOOL shouldShowSectionIndex;
@property (nonatomic) BOOL isImageRounded;

@property (nonatomic, weak) id<PRCatalogFilterPanelDelegate> panelDelegate;

@property (nonatomic, strong) UIColor *textColor;
@property (nonatomic, strong) UIColor *tintColor;

@end


@interface PRCatalogFilterPanelVC (/*PROTECTED*/)

- (void)setupThumbnail:(nullable PRThumbnailObject *)thumbnail cell:(PRCatalogFilterTableCell *)cell;

@property (nonatomic, readonly) CGSize imageSize;
@property (nonatomic, readonly) BOOL useLargeCellsWithImage;

@end

NS_ASSUME_NONNULL_END
