//
//  NTFSimilarArticlesService.h
//  PR-API
//
//  Created by Viacheslav Soroka on 9/24/18.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import <PRAPI/NTFDataService.h>

NS_ASSUME_NONNULL_BEGIN

@interface NTFSimilarArticlesDataService : NTFDataService

+ (instancetype)serviceWithFeedID:(NSManagedObjectID *)feedID
                       articleKey:(NSString *)articleKey
                      sectionJSON:(nullable NSDictionary *)sectionJSON
                      articleJSON:(nullable NSDictionary *)articleJSON;

+ (instancetype)serviceWithFeedID:(NSManagedObjectID *)feedId NS_UNAVAILABLE;
- (instancetype)initWithFeedID:(NSManagedObjectID *)feedId NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
