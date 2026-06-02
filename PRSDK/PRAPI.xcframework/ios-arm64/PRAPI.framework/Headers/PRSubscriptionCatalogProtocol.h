//
//  PRSubscriptionCatalogProtocol.h
//  PRiphone
//
//  Created by berec on 11/23/12.
//  Copyright (c) 2012 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PRTitleItem;
@class PRAccountItem;
@class PRSubscriptionItem;

NS_ASSUME_NONNULL_BEGIN

typedef void(^_Nullable PRServiceCompletion)(BOOL success, NSError *_Nullable error);

@protocol PRSubscriptionCatalogProtocol <NSObject>

#pragma mark Bundles
- (void)updateBundles;
- (void)updateUserBundles;

#pragma mark - Catalog management
- (void)UpdateSubscriptions;
- (void)restartStatistics;
- (BOOL)isSubscriptionsUpdated;

- (void)deleteSubscriptionsForCID:(NSString *)CID includeSupplements:(BOOL)include keepParent:(BOOL)keep successBlock:(void(^_Nullable)(void))successBlock failureBlock:(void(^_Nullable)(NSError *))failureBlock;
- (void)changeDeleteSubscription:(PRSubscriptionItem*)order del:(BOOL)del includeSupplements:(BOOL)include successBlock:(void(^_Nullable)(void))successBlock failureBlock:(void(^_Nullable)(NSError *))failureBlock;
- (void)addSubscriptionForCID:(NSString *)cid
           includeSupplements:(BOOL)include
                 successBlock:(void(^_Nullable)(void))successBlock
                 failureBlock:(void(^_Nullable)(NSError *))failureBlock;

- (void)RequestIssueVersionsForCID:(NSString*)CID issueDate:(NSDate *)issueDate;
- (void)RequestAudioUrlsForTitle:(PRTitleItem *)ti;

// subscription interface
- (NSString*) localizedSubscriptionResult:(NSString*)resultCode;
- (NSString *) localizedAccessResult:(NSString *)accessCode;

- (BOOL)isCIDAccessible:(NSString *)CID;
// Online services
- (void) AddReadingStatistics:(NSArray *)frames forViewType:(NSString *)view;
- (void) addBookReadingStatisticsEvents:(NSArray<NSDictionary *> *)events NS_SWIFT_NAME(addBookReadingStatistics(events:));

// template url and revision
- (void) RequestTemplateInfo:(NSString *)locale;
- (nullable NSString *)templateUrl;
- (nullable NSString *)templateRevision;

@end

NS_ASSUME_NONNULL_END
