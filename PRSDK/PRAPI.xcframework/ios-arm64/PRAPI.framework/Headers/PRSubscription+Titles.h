//
//  PRSubscription+Titles.h
//  PRiphone
//
//  Created by berec on 11/23/12.
//  Copyright (c) 2012 NewspaperDirect. All rights reserved.
//

#import "PRSubscription.h"
#import "PROptions.h"

@interface PRSubscription (Titles)

- (NSUInteger)titlesCount;
- (NSArray<NSString *> *)allTitleCIDs;
- (NSArray<PRTitleItem *> *)titles;
- (PRTitleItem *)titleForCID:(NSString *)CID;
- (void)setTitle:(PRTitleItem *)titleItem forCID:(NSString *)CID;
- (void)enumerateCIDsAndTitlesUsingBlock:(void (NS_NOESCAPE ^)(NSString* CID, PRTitleItem *titleItem, BOOL *stop))block;
- (NSArray<PRTitleItem *> *)parentTitles;

#pragma mark - Supplements
- (NSArray<PRTitleItem *> *)supplementsForCID:(NSString *)CID sorted:(PRCatalogSortingOrder)sortingOrder;
- (PRTitleItem *)regionalParentForTitleWithCID:(NSString *)CID;

- (void)searchForSources:(NSString *)searchString count:(NSUInteger)count success:(void (^)(NSArray<PRTitleItem *> *sources))success failure:(void (^)(NSError *error))failure;
@end
