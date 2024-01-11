//
//  PRSources.h
//  PRiphone
//
//  Created by Oleg Stepanenko on 25.11.12.
//  Copyright (c) 2012 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

@import PRConfiguration.PRCatalogConfig;

@class PRTitleItem;
@class PRTitleItemExemplar;
@class PressCatalog, Downloads, Books, Publications;
@class PRAccountItem;
@class PRCountableValue;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, PRCatalogStatus) {
    PRCatalogStatusUninitialized,
    PRCatalogStatusInitialization,
    PRCatalogStatusPartlyReady,
    PRCatalogStatusReady,
    PRCatalogStatusUpdating
};

typedef NS_OPTIONS(NSInteger, PRCatalogPartitionState) {
    PRCatalogPartitionStateIssuesLoaded = 1 << 0,
    PRCatalogPartitionStateBooksLoaded = 1 << 1
};

extern NSNotificationName const PRCatalogUpdateNotification;

typedef NSString * PRCatalogUpdateNotificationInfoKey NS_STRING_ENUM;
extern PRCatalogUpdateNotificationInfoKey const PRCatalogUpdateNotificationInfoKeyReason;

typedef NS_OPTIONS(NSInteger, PRCatalogUpdateNotificationReason) {
    PRCatalogUpdateNotificationReasonLatestIssueInfo = 1 << 0,
    PRCatalogUpdateNotificationReasonRecentlyRead = 1 << 1,
    PRCatalogUpdateNotificationReasonFavorites = 1 << 2,
    PRCatalogUpdateNotificationReasonPreloadPublications = 1 << 3
};

extern NSNotificationName const PRCatalogCustomCatalogUpdateNotification;
extern NSNotificationName const PRCatalogPartitionStateUpdateNotification;
extern NSNotificationName const PRCatalogLoadingErrorNotification;

@interface PRCatalog : NSObject

/// Reload catalog from server
- (void)reloadCatalog;
- (void)reloadCustomCatalog;

- (nullable PRTitleItem *)sourceByCid:(NSString *)cid NS_SWIFT_NAME(source(cid:));
- (nullable NSArray *)supplementsByCID:(NSString *)cid;
- (nullable NSArray *)relatedPublicationsByCID:(NSString *)cid;

- (void)updateStatus;

@property (nonatomic, assign, readonly) PRCatalogStatus status;
@property (nonatomic) PRCatalogPartitionState partitionState;
@property (nonatomic) PRCatalogMode mode;

@property (nonatomic, readonly) BOOL containsSingleCID;
@property (nonatomic, readonly) BOOL containsSingleParentCID;

/**
 Catalog presentation style. This value is configurable, you should use it whenever it's possible, because some publishers with one main CID
 and supplements want to have multi-title style, and some of them - single-title.
*/
@property (nonatomic, readonly) BOOL isSingleTitleStyle;

@property (nonatomic, readonly) PRAccountItem *defaultService;
@property (nonatomic, readonly) NSArray<PRAccountItem *> *services;

@property (nullable, nonatomic, strong) NSArray<PRTitleItem *> *sources;

/// Sources without supplements
@property (nullable, nonatomic, strong) NSArray<PRTitleItem *> *parentSources;

@property (nullable, nonatomic, strong) NSDictionary<NSString *, PRTitleItem *> *sourcesByCID;

@property (nullable, nonatomic, strong) NSDictionary<NSString *, NSArray<NSString *> *> *groupsByName;
@property (nullable, nonatomic, strong) NSDictionary<NSString *, NSArray<NSString *> *> *groupsByCID;

@property (nullable, nonatomic, strong) NSDictionary<NSString *, NSArray<PRTitleItem *> *> *supplementsByCID;

@property (nullable, nonatomic, strong) NSDictionary *topCategoriesByName;

@property (nullable, nonatomic, strong) NSArray *regions;
@property (nullable, nonatomic, strong) NSArray *featuredSourcesCIDs;

/**
 Tells us whether we can already determine catalog mode and build UI according to its value. If this property returns `NO`, we should wait
 for catalog.
 */
@property (nonatomic, readonly) BOOL isAppearanceDetermined;

@end

@interface PRCatalog (/*Subscriptable*/)
- (nullable PRTitleItem *)objectForKeyedSubscript:(NSString *)cid;
@end


NS_ASSUME_NONNULL_END

#import "PRCatalog+Promise.h"
#import "PRCatalog+Categories.h"
#import "PRCatalog+RecentlyRead.h"
#import "PRCatalog+Regions.h"
