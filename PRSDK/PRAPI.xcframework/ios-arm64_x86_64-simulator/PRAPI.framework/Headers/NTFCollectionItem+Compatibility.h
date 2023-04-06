//
//  NTFCollectionItem+Compatibility.h
//  PR-API
//
//  Created by berec on 11/02/2020.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import <PRAPI/PRAPI.h>

NS_ASSUME_NONNULL_BEGIN

@interface NTFCollectionItem (Compatibility)
+ (nullable instancetype)transientCollectionWithInfo:(NSDictionary<NSString *, id> *)info;

@end

NS_ASSUME_NONNULL_END
