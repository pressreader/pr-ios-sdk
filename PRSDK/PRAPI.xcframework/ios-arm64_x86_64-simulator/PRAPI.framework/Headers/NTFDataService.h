//
//  NTFDataService.h
//  PRiphone
//
//  Created by Viacheslav Soroka on 3/29/17.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NTFCoreDataController.h"

@class PRPromise;
@class NTFFeed;

typedef NS_OPTIONS(NSUInteger, PRFeedArticleField) {
    PRFeedArticleFieldNone = 0,
    //PRFeedArticleFieldAll = 0x7FFFFFFF,
    PRFeedArticleFieldShortContent = 1 << 0,
    PRFeedArticleFieldImages = 1 << 1,
    PRFeedArticleFieldIssues = 1 << 2,
    PRFeedArticleFieldPublications = 1 << 3,
    //PRFeedArticleFieldParagraphs = 1 << 4,
    PRFeedArticleFieldRelated = 1 << 5,
    PRFeedArticleFieldSimilars = 1 << 6,
    //PRFeedArticleFieldAccess = 1 << 7,
    PRFeedArticleFieldComments = 1 << 8,
    PRFeedArticleFieldVotes = 1 << 9,
    PRFeedArticleFieldAnalyticProfiles = 1 << 10,
    PRFeedArticleFieldClassification = 1 << 11,
    
    PRFeedArticleFieldAllAvailable = PRFeedArticleFieldShortContent
    | PRFeedArticleFieldImages
    | PRFeedArticleFieldIssues
    | PRFeedArticleFieldPublications
    | PRFeedArticleFieldRelated
    | PRFeedArticleFieldSimilars
    | PRFeedArticleFieldComments
    | PRFeedArticleFieldVotes
    | PRFeedArticleFieldAnalyticProfiles
    | PRFeedArticleFieldClassification,
};

typedef NS_OPTIONS(uint8_t, NTFDataServiceState) {
    NTFDataServiceStateUnknown = 0,
    NTFDataServiceStateAtBeginning = 1 << 0,
    NTFDataServiceStateAtEnd = 1 << 1,
    NTFDataServiceStateServiceError = 1 << 2,
    NTFDataServiceStateReloadNeeded = 1 << 3,
    NTFDataServiceStateOffline = 1 << 4,
};

NS_ASSUME_NONNULL_BEGIN

typedef NSDictionary<NSString *, id> * JSONDictionary;
typedef NSArray<JSONDictionary> * JSONCollection;

@interface NTFDataService : NSObject

/**
 * @param feedId managed object identifier of feed used for caching retrieved data
 */
+ (instancetype)serviceWithFeedID:(NSManagedObjectID *)feedId;

/**
 *  @param feedId managed object identifier of feed used for caching retrieved data
 */
- (instancetype)initWithFeedID:(NSManagedObjectID *)feedId defaultState:(NTFDataServiceState)defaultState NS_DESIGNATED_INITIALIZER;

/**
 * @brief Calls initWithFeedID:defaultState: with default state NTFDataServiceStateAtBeginning
 * @param feedId managed object identifier of feed used for caching retrieved data
 */
- (instancetype)initWithFeedID:(NSManagedObjectID *)feedId;

- (instancetype)init NS_UNAVAILABLE;

- (PRPromise *)requestData;

- (PRPromise *)feedItemsWithArticlesFromFeedItems:(JSONCollection)feedItems
                                         viewType:(NSString *)viewType
                                       parameters:(NSDictionary *)parameters;
- (NSString *)articlesIdsFromFeedItems:(JSONCollection)feedItems;
- (NSArray *)joinFeedItems:(NSArray<NSDictionary *> *)feedItems
              withArticles:(NSArray<NSDictionary *> *)articles
                parameters:(NSDictionary *)parameters;

- (PRPromise *)flowItemsFromFeedItems:(NSArray<NSDictionary *> *)feedItems
                             viewType:(NSString *)viewType
                           parameters:(NSDictionary *)parameters;

- (PRPromise *)promiseMapJSONPromiseIntoFlowData:(PRPromise *)JSONItems;
- (PRPromise *)promiseMapJSONIntoFlowData:(NSArray<NSDictionary *> *)items;
- (NSArray<NSManagedObjectID *> *)mapJSONIntoFlowData:(NSArray<NSDictionary *> *)items;

- (PRPromise *)refreshFeedSettings;

- (void)resetDataService;
- (void)resetAtEndStatus;

- (void)isDataReloadNeeded:(void(^)(BOOL reload))completion;

@property (nullable, nonatomic, strong) NSString *translationISO;
@property (nonatomic, readonly, strong) NSSet<NSString *> *userLanguages;
@property (nonatomic, readonly, strong) NSArray<NSString *> *defaultLocales;
@property (nonatomic, readonly, strong) NSDictionary *feedSettings;

/// Supports all data types when nil and none when empty. For list of available types see NTFDataItemType.
@property (nullable, nonatomic, strong) NSArray<NSNumber/**<NTFDataItemType>*/ *> *supportedDataTypes;

@property (nonatomic, assign) NTFDataServiceState state;
@property (nonatomic, readonly) NTFDataServiceState defaultState;

@property (nonatomic, readonly) JSONDictionary articlesRequestParameters;
@property (nonatomic, assign) NSUInteger batchSize;

@property (nonatomic, strong) NSManagedObjectID *feedId;
@property (nonatomic, strong, readonly) NSManagedObjectContext *context;
@property (nonatomic, strong, readonly) NTFFeed *feed;

@property (nullable, nonatomic, readonly) NSDictionary *sectionJSON;

@property (nonatomic, readonly, getter=isReady) BOOL ready;

/// Loads full content after obtaining feed data. YES by default.
@property (nonatomic, readonly) BOOL requestFullData;

@end

NS_ASSUME_NONNULL_END
