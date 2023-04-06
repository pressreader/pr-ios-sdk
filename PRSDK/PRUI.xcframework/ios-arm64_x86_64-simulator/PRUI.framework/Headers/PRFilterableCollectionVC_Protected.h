//
//  PRFilterableCollectionVC_Protected.h
//  PR-UI
//
//  Created by berec on 04/02/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#ifndef PRFilterableCollectionVC_Protected_h
#define PRFilterableCollectionVC_Protected_h

#import "PRHorizontallyCollapsablePanelVC.h"

NS_ASSUME_NONNULL_BEGIN

@class PRFilterBarVC;
@class SearchBarHeaderView;
@class AdDataSource;
@protocol AdDataSourceDelegate;

@interface PRFilterableCollectionVC ()<AdDataSourceDelegate>

- (void)showActionMenu:(nullable id)sender;

- (void)updateContentInsets;
- (void)updateSearchBarAppearance;

@property (nonatomic, readonly) CGFloat spaceBetweenRows;
@property (nonatomic, getter=areViewTraitsChanged, readonly) BOOL viewTraitsChanged;

/// If YES, display app menu icon in navigation bar and algorithm of scrolling is changed.
@property (nonatomic, readonly) BOOL appMenuIconRequired;

// For CollapsableTopBar category
@property (nonatomic)  CGSize scrollAnchorOffset;
@property (nonatomic)  CGSize scrollPreviousOffset;
@property (nonatomic, getter=isScrollingBackVertically)  BOOL scrollingBackVertically;

@property (nonatomic, readonly) BOOL isInSearchMode;
@property (nonatomic, readonly) BOOL hasActionMenu;

@property (nonatomic, strong) SearchBarHeaderView *searchHeaderView;

@property (nonatomic, strong) AdDataSource *adDataSource;

@end

NS_ASSUME_NONNULL_END

#endif /* PRFilterableCollectionVC_Protected_h */
