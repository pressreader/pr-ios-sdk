//
//  NTFSearchDataService.h
//  PRAPI
//
//  Created by Viacheslav Soroka on 10/25/17.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

#import "NTFDataService.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, NTFSearchScope) {
    NTFSearchScopeAll = 0,
    NTFSearchScopeArticles
};

typedef NS_ENUM(NSInteger, NTFSearchSortingOrder) {
    NTFSearchSortingOrderRelevance = 0,
    NTFSearchSortingOrderPublished
};

@interface NTFSearchDataService : NTFDataService

@property (nullable, nonatomic, strong) NSString *searchText;
@property (nonatomic) NTFSearchScope scope;
@property (nonatomic) NTFSearchSortingOrder sortingOrder;
@property (nonatomic, strong, readonly) NSSet<NSString *> *searchTokens;
@property (nullable, nonatomic, strong) NSArray<NSString *> *cids;
@property (nullable, nonatomic, strong) NSDate *startDate;
@property (nullable, nonatomic, strong) NSDate *endDate;

@end

NS_ASSUME_NONNULL_END
