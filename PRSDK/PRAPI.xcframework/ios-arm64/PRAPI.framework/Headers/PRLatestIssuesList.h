//
//  PRLatestIssuesList.h
//  PR-API
//
//  Created by Viacheslav Soroka on 12/3/19.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import "PRSourceList.h"

NS_ASSUME_NONNULL_BEGIN

@interface PRLatestIssuesList : PRSourceList

- (instancetype)initWithCIDs:(nullable NSArray<NSString *> *)cids order:(PRCatalogSortingOrder)order;
- (instancetype)initWithCIDs:(nullable NSArray<NSString *> *)cids
                       order:(PRCatalogSortingOrder)order
                         mix:(BOOL)mix;

- (instancetype)initWithCID:(NSString *)cid;

- (instancetype)initWithSourceList:(PRSourceList *)sourceList
                             order:(PRCatalogSortingOrder)order;

- (instancetype)initWithSourceList:(PRSourceList *)sourceList NS_UNAVAILABLE;
- (instancetype)initWithList:(NSArray<id<PRCatalogItem>> *)list NS_UNAVAILABLE;
- (instancetype)initWithCIDs:(NSArray<NSString *> *)cids NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
