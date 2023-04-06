//
//  PRSourceList+Equality.h
//  PR-API
//
//  Created by berec on 22/05/2020.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import "PRSourceList.h"

NS_ASSUME_NONNULL_BEGIN

@interface PRSourceList (Equality)

- (BOOL)hasEqualContentWithSourceList:(PRSourceList *)sourceList;
- (BOOL)isContentListEqualToList:(NSArray<id<PRCatalogItem>> *)list;
- (BOOL)isContentListEqualToList:(NSArray<id<PRCatalogItem>> *)list
                        services:(nullable NSArray<NSString *> *)services;

@end

NS_ASSUME_NONNULL_END
