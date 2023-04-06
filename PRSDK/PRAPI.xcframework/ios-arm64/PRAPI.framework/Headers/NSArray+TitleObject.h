//
//  NSArray+TitleItems.h
//  PRiphone
//
//  Created by Jackie Cane on 04/03/14.
//  Copyright (c) 2014 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "PRTitleObject.h"
#import "PROptions.h"

NS_ASSUME_NONNULL_BEGIN

@interface NSSortDescriptor (TitleObject)

+ (nullable NSArray<NSSortDescriptor *> *)titleObjectsSortDescriptorsByOrder:(PRCatalogSortingOrder)order;

@end

@interface NSArray (TitleObject)

- (NSMutableArray<id<PRTitleObject>> *)sortedTitleObjects:(PRCatalogSortingOrder)order;

@end

NS_ASSUME_NONNULL_END
