//
//  NTFFeedDataSource_Protected.h
//  PRiphone
//
//  Created by Viacheslav Soroka on 8/28/17.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

#ifndef NTFFeedDataSource_Protected_h
#define NTFFeedDataSource_Protected_h

#import "NTFFeedDataSource.h"

#import "PRCompactLayoutManager.h"

typedef NS_ENUM(uint8_t, NTFRequestDirection) {
    NTFRequestDirectionForward = 0,
    NTFRequestDirectionBackward
};

@class NTFFeedCommentsDataSource;
@class NTFFeedSectionItem;
@class ReadingMapArticleFrame;

NS_ASSUME_NONNULL_BEGIN

@interface NTFFeedDataSource ()

- (void)requestFeedInDirection:(NTFRequestDirection)direction
                    completion:(NTFRequestCompletion)completion;

- (void)updateDataProviderWithObjectIDs:(NSArray<NSManagedObjectID *> *)objectIDs
                              direction:(NTFRequestDirection)direction
                             completion:(void(^_Nonnull)(void))completion;

- (void)reloadFeedData:(NTFRequestCompletion)completion;
- (void)reloadFeedDataAfter:(NSTimeInterval)delay;
- (void)setNeedsReloadFeedData;

- (BOOL)isValidIndex:(NSInteger)idx;

// notification handlers
- (void)registerNotificationHandlers;
- (void)commentsUpdated:(NSNotification *)notification;
- (void)acrticleUpdated:(NSNotification *)notification;
- (void)articleCollectionsUpdated:(NSNotification *)note;
- (void)pagesetUpdated:(NSNotification *)notification;
- (void)refreshDataByTriggerHandler:(nullable NSNotification *)note;

- (void)refreshContentWithReason:(NTFFeedDataSourceRefreshReason)reason
                      calleeInfo:(NSString *)callee;

- (nullable NSString *)tagForSection:(NTFFeedSectionItem *)section;
- (nullable UIColor *)tagColorForSection:(NTFFeedSectionItem *)section;
- (nullable NTFFeedSectionItem *)sectionForItem:(id)item;
- (nullable NTFFeedSectionItem *)sectionForItem:(id)item ignoreHiddenSections:(BOOL)ignore;

@property (nonatomic, readonly, nullable) NSString *feedCollectionId;
@property (nonatomic, strong, nullable) NTFFeedCommentsDataSource *commentsDataSource;
@property (nonatomic, strong, nullable) PRPromise *currentDataRequest;

@property (nullable, nonatomic, strong) NSManagedObjectID *feedId;
@property (nullable, nonatomic, strong) NTFDataService *dataService;

@property (nullable, nonatomic, strong) NTFFeed *feed;
@property (nullable, nonatomic, strong) ReadingMapArticleFrame *readingMapFrame;

/*
 [f88eaf9] #86166: Delay reload of feed data while menu still presented
 to finish "save to collection" after user signed in.
 Promise gets created on suspendReadingMap with "item" menu and resolved on resumeReadngMap.
 Initial state is "resolved"
 */
@property (nonatomic, strong) PRPromise *waitBeforeReloadPromise;
@property (nonatomic, readonly) PRSubscription *defaultSubscription;

@end

NS_ASSUME_NONNULL_END

#endif /* NTFFeedDataSource_Protected_h */
