//
//  NSArray+TitleItems.h
//  PRiphone
//
//  Created by Jackie Cane on 04/03/14.
//  Copyright (c) 2014 NewspaperDirect. All rights reserved.
//

#import <PRConfiguration/PRCatalogConfig.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSSortDescriptor (TitleObject)

+ (NSArray<NSSortDescriptor *> *)titleObjectsSortDescriptorsByOrder:(PRCatalogSortingOrder)order;

@end

NS_ASSUME_NONNULL_END
