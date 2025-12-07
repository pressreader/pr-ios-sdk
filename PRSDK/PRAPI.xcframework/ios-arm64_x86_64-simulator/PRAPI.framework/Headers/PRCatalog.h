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
@class DQCatalog;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, PRCatalogStatus) {
    PRCatalogStatusUninitialized,
    PRCatalogStatusInitialization,
    PRCatalogStatusPartlyReady,
    PRCatalogStatusReady,
    PRCatalogStatusUpdating
};

extern NSNotificationName const PRCatalogUpdateNotification;

typedef NSString * PRCatalogUpdateNotificationInfoKey NS_STRING_ENUM;
extern PRCatalogUpdateNotificationInfoKey const PRCatalogUpdateNotificationInfoKeyReason;

typedef NS_OPTIONS(NSInteger, PRCatalogUpdateNotificationReason) {
    PRCatalogUpdateNotificationReasonLatestIssueInfo = 1 << 0,
    PRCatalogUpdateNotificationReasonFavorites = 1 << 1,
    PRCatalogUpdateNotificationReasonPreloadPublications = 1 << 2
};

extern NSNotificationName const PRCatalogCustomCatalogUpdateNotification;
extern NSNotificationName const PRCatalogLoadingErrorNotification;

@interface PRCatalog : NSObject

/// Reload catalog from server
- (void)reloadCatalog;
- (void)reloadCustomCatalog;

- (void)updateStatus;

@property (nonatomic, assign, readonly) PRCatalogStatus status;
@property (nullable, nonatomic, readonly) PRAccountItem *defaultService;
@property (nullable, nonatomic, readonly) NSArray<PRAccountItem *> *services;

@property (nonatomic, strong, readonly) DQCatalog *dqCatalog;

@end

NS_ASSUME_NONNULL_END
