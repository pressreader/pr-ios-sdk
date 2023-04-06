//
//  NTFFeedDataSource.h
//  PRiphone
//
//  Created by Viacheslav Soroka on 5/22/17.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <PRUI/NTFDataSource.h>
@import PRAPI.NTFDataService;

NS_ASSUME_NONNULL_BEGIN

extern NSNotificationName const NTFFeedDataSourceStateChangedNotification;

@class NTFFeedDataSource, PRPromise;

typedef NS_ENUM(uint8_t, NTFFeedDataSourceRefreshReason) {
    NTFFeedDataSourceRefreshReasonDataReady = 0,
    NTFFeedDataSourceRefreshReasonDataRecompiled,
    NTFFeedDataSourceRefreshReasonCommentsUpdated,
    NTFFeedDataSourceRefreshReasonArticleUpdated,
    NTFFeedDataSourceRefreshReasonPagesetUpdated,
};

@protocol NTFFeedDataSourceDelegate <NSObject>
- (void)refreshContentWithReason:(NTFFeedDataSourceRefreshReason)reason;
- (BOOL)waitForFeedDataSource;

@end

@class NTFFeedItem, NTFArticleItem;

typedef NS_OPTIONS(NSUInteger, NTFFeedDataSourceOption) {
    NTFFeedDataSourceOptionNone = 0,
    NTFFeedDataSourceOptionPreloadThumbnails = 1 << 0,
    NTFFeedDataSourceOptionObserveRefreshTriggers = 1 << 1
};

typedef NS_OPTIONS(uint8_t, NTFDataState) {
    NTFDataStatePreloaded = 1 << 0,
    NTFDataStateRequesting = 1 << 1,
    NTFDataStateRefreshing = 1 << 2,
    NTFDataStateRefreshingSilently = 1 << 3
};

typedef void(^ _Nullable NTFRequestCompletion)(NSInteger deleteAtBegininng, NSInteger appendAtEnd, NSError *_Nullable error);

@interface NTFFeedDataSource : NTFDataSource

/// Calls 'initWithFeedId:service:parameters' with parameters set
/// [NTFFeedDataSourceParameterRequestDataImmediately]
- (instancetype)initWithFeedID:(nullable NSManagedObjectID *)feedId
                       service:(nullable __kindof NTFDataService *)dataService;

- (instancetype)initWithFeedID:(nullable NSManagedObjectID *)feedId
                       service:(nullable __kindof NTFDataService *)dataService
                       options:(NTFFeedDataSourceOption)parameters
                    layoutType:(NTFLayoutType)layoutType
                 layoutOptions:(NTFLayoutOption)layoutOptions NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;

@property (nonatomic, readonly) NSInteger accountNumber;

@property (nonatomic, readonly) NTFDataState dataState;
@property (nonatomic, readonly) BOOL isOffline;
@property (nonatomic, readonly) BOOL isEmpty;
@property (nonatomic, readonly) BOOL readyForPreload;

@property (nonatomic, readonly) NSManagedObjectContext *managedObjectContext;

@property (nonatomic, readonly) NTFFeedDataSourceOption parameters;

@property (nullable, nonatomic, readonly) __kindof NTFDataService *dataService;
@property (nullable, nonatomic, strong, readonly) NSManagedObjectID *feedId;

/// Time interval between feed's reload from the network.
/// Used in conjunction with NTFFeedDataSourceParameterObserveRefreshTriggers.
/// Default value is 0 which leads to refreshing the feed on
///  every refresh trigger (entering foreground).
@property (nonatomic) NSTimeInterval feedRefreshTimeInterval;

@end

@interface NTFFeedDataSource (MultipleDelegation)
- (void)setFeedDelegate:(id<NTFFeedDataSourceDelegate>)delegate;
- (void)unsetFeedDelegate:(id<NTFFeedDataSourceDelegate>)delegate;

@end

NS_ASSUME_NONNULL_END

#import <PRUI/NTFFeedDataSource_Protected.h>
#import <PRUI/NTFFeedDataSource+Analytics.h>
