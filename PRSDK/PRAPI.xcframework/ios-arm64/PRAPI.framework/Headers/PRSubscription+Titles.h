//
//  PRSubscription+Titles.h
//  PRiphone
//
//  Created by berec on 11/23/12.
//  Copyright (c) 2012 NewspaperDirect. All rights reserved.
//

#import "PRSubscription.h"
#import "PROptions.h"

NS_ASSUME_NONNULL_BEGIN

@interface PRSubscription (Titles)

/// Legacy DQ Catalog API storage. Use PRCatalog for normal accessing items instead.
- (nullable NSArray<PRTitleItem *> *)titles;
- (NSUInteger)titlesCount;
- (nullable NSArray<NSString *> *)allTitleCIDs;

- (nullable PRTitleItem *)titleWithCID:(NSString *)CID NS_SWIFT_NAME(title(cid:));
- (void)setTitle:(PRTitleItem *)titleItem;

@end

NS_ASSUME_NONNULL_END
