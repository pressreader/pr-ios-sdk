//
//  PRFilterableCollectionVC_Protected.h
//  PR-UI
//
//  Created by berec on 04/02/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#ifndef PRFilterableCollectionVC_Protected_h
#define PRFilterableCollectionVC_Protected_h

NS_ASSUME_NONNULL_BEGIN

@class PRFilterBarVC;
@class AdDataSource;
@protocol AdDataSourceDelegate;

@interface PRFilterableCollectionVC ()<AdDataSourceDelegate>

- (void)showActionMenu:(nullable id)sender;

- (void)updateContentInsets;

@property (nonatomic, readonly) CGFloat spaceBetweenRows;
@property (nonatomic, getter=areViewTraitsChanged, readonly) BOOL viewTraitsChanged;

// For CollapsableTopBar category
@property (nonatomic)  CGSize scrollAnchorOffset;
@property (nonatomic)  CGSize scrollPreviousOffset;
@property (nonatomic, getter=isScrollingBackVertically)  BOOL scrollingBackVertically;

@property (nonatomic, readonly) BOOL hasActionMenu;

@property (nonatomic, strong) AdDataSource *adDataSource;

@end

NS_ASSUME_NONNULL_END

#endif /* PRFilterableCollectionVC_Protected_h */
