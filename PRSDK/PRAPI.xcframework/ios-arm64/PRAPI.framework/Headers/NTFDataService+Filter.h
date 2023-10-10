//
//  NTFDataService+Filter.h
//  PRAPI
//
//  Created by Ivan Berezin on 01/06/2023.
//  Copyright © 2023 NewspaperDirect. All rights reserved.
//

#import <PRAPI/PRAPI.h>

@class PRNavMenuFilter;

NS_ASSUME_NONNULL_BEGIN

@interface NTFDataService (Filter)

/// @param feedAlias Optional alias in case feed uniqueness's required.
+ (nullable NTFDataService *)dataServiceWithFilter:(PRNavMenuFilter *)filter feedAlias:(nullable NSString *)feedAlias;
+ (nullable NTFDataService *)dataServiceWithFilter:(PRNavMenuFilter *)filter;

@end

NS_ASSUME_NONNULL_END
