//
//  PRTitleItem.h
//  PRiphone
//
//  Created by Jackie Cane on 4/5/11.
//  Copyright 2011 NewspaperDirect. All rights reserved.
//

#import "PRSourceItem.h"

#import <PRAPI/PRTitleObject.h>
#import <PRAPI/PRTitleItemNestedTypes.h>

NS_ASSUME_NONNULL_BEGIN

// Keys
extern NSString *const kOrderNumber;
extern NSString *const kName;
extern NSString *const kDisplayName;
extern NSString *const kLatestAvailableIssueDate;
extern NSString *const kRegionalParentCID;
extern NSString *const kPRRegionalCIDs;
extern NSString *const kLocalizedTitle;
extern NSString *const kTitleSlug;
extern NSString *const kPRSections;
extern NSString *const kPRNightEdition;
extern NSString *const kPRParents;
extern NSString *const kPRCustomSupplementsList;
extern NSString *const kPRCustomCatalogTitle;

@class PRSubscription;
@class PRAccountItem;
@class PRTitleItemExemplar;
@class PRCountry;

typedef NSMutableDictionary<NSString *, NSMutableDictionary<NSString *, id> *> * PRTitleItemServiceSpecificProperties;

@interface PRTitleItem : PRSourceItem <PRTitleObject>

- (instancetype)initFromDictionary:(NSDictionary *)dict service:(PRAccountItem *)accountItem;

- (BOOL)titleContains:(NSString*)filter;
- (BOOL)titleStartWith:(NSString*)filter;

- (void)updateAvailableDates:(NSArray<NSDate *> *)dates;
- (void)updateAvailableVersions:(NSDictionary *)versions;
- (void)updatePaperColor;
- (BOOL)markArticleAsListened:(NSString *)articleID issueDate:(NSDate *)issueDate;
- (BOOL)isArticleMarkedAsListened:(NSString *)articleID;
- (NSString *)currentArtIDtoListen;
- (void)setCurrentArtIDtoListen:(NSString *)artID;
- (void)resetNewspaperRadioStatistics;

- (NSArray *)subscriptionsForOrder;
- (NSArray *)subscriptionsForOrderConformToSubscriptions:(nullable NSArray *)filterSubscriptions;

- (void)getRecentTitleExemplars:(NSInteger)amount
              lastAvailableDate:(nullable NSDate *)lastAvailableDate
                   subscription:(PRSubscription *)subscription
                     completion:(void(^)(NSArray<PRTitleItemExemplar *> *_Nullable, NSError *_Nullable))completion;
- (void)getRecentTitleExemplars:(NSInteger)amount
              lastAvailableDate:(nullable NSDate *)lastAvailableDate
                     completion:(void(^)(NSArray<PRTitleItemExemplar *> *_Nullable, NSError *_Nullable))completion;
- (void)getRecentTitleExemplars:(NSInteger)amount
                     completion:(void(^)(NSArray<PRTitleItemExemplar *> *_Nullable, NSError *_Nullable))completion;

- (nullable NSArray<PRTitleItemExemplar *> *)getRecentTitleExemplarsWithSubscription:(PRSubscription *)subscription limit:(NSInteger)limit;

- (BOOL)isRead;
- (void)resetServiceSpecificProperties;

@property (class, nonatomic, readonly) NSString *categoriesKey;
@property (class, nonatomic, readonly) NSInteger defaultDatesRequestLimit;

@property (nonatomic) CGFloat aspectRatio;
@property (nullable, nonatomic, strong) NSDate* latestAvailableIssueDate;
@property (nonatomic) NSInteger latestAvailableIssueVersion;
@property (nonatomic) NSInteger latestAvailableLayoutVersion;
@property (nonatomic, strong) NSString *latestAvailableExpungeVersion;

@property (nonatomic, strong) NSDate *activationTime;

@property (nonatomic, strong, readonly) NSArray<PRCountry *> *countries;
@property (nonatomic, strong, readonly) NSDictionary *countryRegions;
@property (nonatomic, copy, readonly) NSArray *categories;
@property (nonatomic, copy, readonly) NSArray *sections;
@property (nonatomic, readonly) NSString *Schedule;
@property (nonatomic, readonly) BOOL free;
@property (nonatomic, readonly) BOOL sample;
@property (nonatomic, readonly) BOOL isLanguageSupported;
@property (nonatomic, readonly) BOOL right2Left;
@property (nonatomic, readonly) NSString *paperFormat;
@property (nonatomic, readonly) NSString *hexPaperColor;
@property (nullable, nonatomic, readonly) NSString *regionalParentCID;
@property (nullable, nonatomic, readonly) NSArray<NSString *> *regionalCIDs;
@property (nonatomic, readonly) NSString *parentCID;
@property (nonatomic, readonly) BOOL isSupplement;
@property (nonatomic, readonly) NSString *alternativeNames;
@property (nonatomic, copy, readonly) NSDictionary* properties;

@property (nonatomic, readonly) NSMutableDictionary* newspaperRadioStatistics;
@property (nullable, nonatomic, strong) NSDate *radioInfoIssueDate;
@property (nonatomic, readonly) NSUInteger numberOfListenedArticles;

@property (nonatomic) NSInteger orderNumber;
@property (nullable, nonatomic, copy, readonly) NSArray<NSDate *> *availableDates;
@property (nonatomic, readonly) NSArray<PRTitleItemExemplar *> *availableExemplars;
@property (nonatomic, strong, readonly) NSDictionary *availableVersions;
@property (nonatomic) BOOL newspaperRadioAvailable;
@property (nonatomic, readonly) NSUInteger supplementsCount;
@property (nonatomic, readonly) NSArray *customSupplementCIDs;
@property (nonatomic, strong) PRTitleItemServiceSpecificProperties serviceSpecificProperties;

@property (nonatomic, strong, readonly) PRTitleItemExemplar *lastExemplar;
@property (nonatomic, readonly) PRTitleItemScheduleType scheduleType;
@property (nonatomic, getter=isSmartflowDisabled) BOOL smartflowDisabled;

@end

// Purchase advise extension
@class PRMyLibraryItem;

@interface PRTitleItem (/*PurchaseAdvise*/)
@property (nullable, nonatomic, strong) PRMyLibraryItem *replacedLibraryItem;
@end

NS_ASSUME_NONNULL_END


#import "PRTitleItem+Thumbnail.h"
#import "PRTitleItem+Promise.h"
#import "PRTitleItem+NightEdition.h"

