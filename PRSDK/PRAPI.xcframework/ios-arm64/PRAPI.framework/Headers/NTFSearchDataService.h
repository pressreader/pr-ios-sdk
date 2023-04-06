//
//  NTFSearchDataService.h
//  PR-API
//
//  Created by Viacheslav Soroka on 10/25/17.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

#import "NTFDataService.h"

typedef NS_ENUM(NSInteger, NTFSearchScope) {
    NTFSearchScopeAll = 0,
    NTFSearchScopeArticles
};

typedef NS_ENUM(NSInteger, NTFSearchSortingOrder) {
    NTFSearchSortingOrderRelevance = 0,
    NTFSearchSortingOrderPublished
};

extern NSString * const kPRSearchTextKey;
extern NSString * const kPRSearchInKey;
extern NSString * const kPRSearchAuthorKey;
extern NSString * const kPRSearchLanguagesKey;
extern NSString * const kPRSearchNewspapersKey;
extern NSString * const kPRSearchCountriesKey;
extern NSString * const kPRSearchStartDateKey;
extern NSString * const kPRSearchStopDateKey;
extern NSString * const kPRSearchHideSimilarKey;
extern NSString * const kPRSearchHideSnippetsKey;
extern NSString * const kPRSearchOrderByKey;

@interface NTFSearchDataService : NTFDataService

@property (nonatomic, strong) NSString *searchText;
@property (nonatomic) NTFSearchScope scope;
@property (nonatomic) NTFSearchSortingOrder sortingOrder;

@end
