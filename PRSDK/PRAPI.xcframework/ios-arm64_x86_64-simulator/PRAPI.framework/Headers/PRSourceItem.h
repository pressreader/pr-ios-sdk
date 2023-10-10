//
//  PRSourceItem.h
//  PRiphone
//
//  Created by Jackie Cane on 6/25/13.
//  Copyright (c) 2013 NewspaperDirect. All rights reserved.
//

@import PRCatalogModel.PRSourceItem_Basics;

NS_ASSUME_NONNULL_BEGIN

extern NSNotificationName const PRSourceItemSubscriptionsChangeNotification;

extern NSString *const kParentCid;
extern NSString *const kSupplementName;
extern NSString *const kSourceType;

@class PRSubscription, PRAccountItem;

@interface PRSourceItem : NSObject

@property (nonatomic, retain, readonly) NSString *CID;
@property (nonatomic, retain, readonly) NSString *title;
@property (nonatomic, retain, readonly) NSString *localizedTitle;
@property (nonatomic, readonly) NSString *titleSlug;
@property (nonatomic, retain, readonly) NSString *parentName;
@property (nonatomic, retain, readonly) NSString *parentCID;
@property (nonatomic, retain, readonly) NSArray *parentCIDs;
@property (nullable, nonatomic, retain, readonly) NSString *supplementName;
@property (nonatomic, retain, readonly) NSDate *issueDate;
@property (nullable, nonatomic, retain, readonly) NSDate *orderDate;
@property (nonatomic, readonly) NSDate *downloadedSortingDateValue;
@property (nonatomic, assign, readonly) PRSourceType sourceType;
@property (nonatomic, retain, readonly) UIColor *paperColor;
@property (nonatomic, readonly) NSString *displayName;

@property (nonatomic, getter=isSoundDisabled) BOOL soundDisabled;
@property (nonatomic, readonly) BOOL isOfflineRadioAvailable;
@property (nonatomic, readonly) BOOL hasRadio;
@property (nonatomic, readonly) BOOL isSmartAvailable;

@property (nonatomic, readonly) BOOL isFavoritable;
@property (nonatomic, readonly) BOOL isBookmarkable;
@property (nonatomic, readonly) BOOL isCommentable;
@property (nonatomic, readonly) BOOL isTranslatable;
@property (nonatomic, readonly) BOOL isSharable;
@property (nonatomic, readonly) BOOL isInCatalog;
@property (nonatomic, readonly) BOOL isServiceReachable;

@property (nonatomic, readonly) NSString *country;
@property (nonatomic, readonly) NSString *countryISOCode;
@property (nonatomic, readonly) NSString *language;
@property (nonatomic, readonly) NSString *languageISOCode;
@property (nonatomic, readonly) NSString *languageRegionCode;
@property (nonatomic, readonly) BOOL isLanguageSupported;
@property (nullable, nonatomic, retain) NSDictionary *newspaperRadioInfo;

@property (nonatomic, readonly) BOOL isSupplement;

@property (nullable, nonatomic, strong) NSString *originalMasthead;
@property (nullable, nonatomic, strong) NSString *templateMasthead;
@property (nonatomic, getter=isMastheadRequested) BOOL mastheadRequested;

@property (nullable, nonatomic, readonly) PRAccountItem *account;

@property (nonatomic, assign) BOOL allowCellularDownload;

@property (nonatomic, strong) NSString *preferableSubscriptionName;

- (instancetype)initWithCID:(NSString *)cid title:(NSString *)title parentName:(NSString *)parent supplementName:(NSString *)supplement;
- (void)saveToPersistentStore;

@end

NS_ASSUME_NONNULL_END

#import "PRSourceItem+Subscription.h"
#import "PRSourceItem+Readiness.h"
