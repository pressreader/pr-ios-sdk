//
//  NTFCategoryFeedDataService.h
//  PR-API
//
//  Created by Viacheslav Soroka on 1/31/18.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import "NTFDataService.h"

NS_ASSUME_NONNULL_BEGIN

@interface NTFCategoryFeedDataService : NTFDataService

+ (instancetype)serviceWithFeedID:(NSManagedObjectID *)feedID
                         category:(NSString *)category
                      sectionJSON:(nullable NSDictionary *)sectionJSON;

+ (instancetype)serviceWithFeedID:(nullable NSManagedObjectID *)feedId NS_UNAVAILABLE;
- (instancetype)initWithFeedID:(nullable NSManagedObjectID *)feedId NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
