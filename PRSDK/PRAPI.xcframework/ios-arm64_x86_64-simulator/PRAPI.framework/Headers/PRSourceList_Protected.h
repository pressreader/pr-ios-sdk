//
//  PRSourceList_Protected.h
//  PR-API
//
//  Created by berec on 17/01/2020.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#ifndef PRSourceList_Protected_h
#define PRSourceList_Protected_h

#import "PRSourceList.h"
@class PRCatalog;

NS_ASSUME_NONNULL_BEGIN

@interface PRSourceList (/*Protected*/)

- (void)updateWithCustomList:(nullable NSArray *)list;

- (void)resetComputedLists;

- (void)notifyAboutDataChange;

- (NSArray<id<PRTitleObject>> *)refilter;
- (NSArray<id<PRTitleObject>> *)sort:(NSArray *)sourceList byOrder:(PRCatalogSortingOrder)order;

@property (nonatomic, weak) PRCatalog *catalog;

@property (nonatomic, strong) NSArray<NSString *> *services;

@end

NS_ASSUME_NONNULL_END

#endif /* PRSourceList_Protected_h */
