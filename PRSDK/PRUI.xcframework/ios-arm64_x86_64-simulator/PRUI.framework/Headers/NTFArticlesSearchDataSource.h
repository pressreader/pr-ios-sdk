//
//  NTFArticlesSearchDataSource.h
//  PR-UI
//
//  Created by Viacheslav Soroka on 10/26/17.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

#import "NTFFeedDataSource.h"
@import PRAPI.NTFSearchDataService;

NS_ASSUME_NONNULL_BEGIN

@interface NTFArticlesSearchDataSource : NTFFeedDataSource

- (instancetype)initWithFeedID:(NSManagedObjectID *)feedId
                       service:(__kindof NTFDataService *)dataService
                    searchText:(NSString *)searchText
                      useDelay:(BOOL)useDelay;

@property (null_resettable, nonatomic, strong) NSString *searchText;
@property (nonatomic) NTFSearchScope scope;
@property (nonatomic) NTFSearchSortingOrder sortingOrder;

@end

NS_ASSUME_NONNULL_END
