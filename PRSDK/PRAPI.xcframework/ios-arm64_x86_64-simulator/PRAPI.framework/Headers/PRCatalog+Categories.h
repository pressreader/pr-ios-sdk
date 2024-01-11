//
//  PRCatalog+Categories.h
//  PRiphone
//
//  Created by Jackie Cane on 20/02/14.
//  Copyright (c) 2014 NewspaperDirect. All rights reserved.
//

#import "PRCatalog.h"

@interface PRCatalog (Categories)

- (NSDictionary *)categoryByName:(NSString *)categoryName;

/// @param ceilingCategory Limits degree of generalization. To get the toppest level category set nil.
/// @return Top level category that corresponds to category with given name.
- (NSDictionary *)topCategoryForCategoryWithName:(NSString *)categoryName
                                 ceilingCategory:(NSDictionary *)ceilingCategory;


@end
