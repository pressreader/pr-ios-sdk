//
//  PRTitleItem.h
//  PRiphone
//
//  Created by Jackie Cane on 4/5/11.
//  Copyright 2011 NewspaperDirect. All rights reserved.
//

#import "PRSourceItem.h"
#import <PRCatalogModel/PRTitleItemSchedule.h>

NS_ASSUME_NONNULL_BEGIN

// Keys
extern NSString *const kOrderNumber;
extern NSString *const kName;
extern NSString *const kDisplayName;
extern NSString *const kLatestAvailableIssueDate;
extern NSString *const kRegionalParentCID;
extern NSString *const kPRRegionalCIDs;
extern NSString *const kLocalizedTitle;
extern NSString *const kPRSections;
extern NSString *const kPRNightEdition;
extern NSString *const kPRParents;
extern NSString *const kPRCustomSupplementsList;
extern NSString *const kPRCustomCatalogTitle;

@class PRSubscription;
@class PRAccountItem;
@class PRTitleItemExemplar;
@class PRCountry;
@protocol PRTitleItemService;

typedef NSMutableDictionary<NSString *, NSMutableDictionary<NSString *, id> *> * PRTitleItemServiceSpecificProperties;

@interface PRTitleItem : PRSourceItem

- (instancetype)initFromDictionary:(NSDictionary *)dict service:(PRAccountItem *)accountItem;

- (BOOL)titleContains:(NSString*)filter;
- (BOOL)titleStartWith:(NSString*)filter;

- (void)resetServiceSpecificProperties;
- (void)saveToPersistentStore;
- (void)setNeedsSaveToPersistentStore;

@property (class, nonatomic, readonly) NSString *categoriesKey;
@property (class, nonatomic, readonly) NSInteger defaultDatesRequestLimit;

@property (nonatomic) CGFloat aspectRatio;
@property (nullable, nonatomic, strong) NSDate* latestAvailableIssueDate;
@property (nonatomic) NSInteger latestAvailableIssueVersion;
@property (nonatomic) NSInteger latestAvailableLayoutVersion;
@property (nonatomic) NSInteger latestAvailableExpungeVersion;

@property (nullable, nonatomic, strong) NSDate *activationTime;

@property (nonatomic, strong, readonly) NSArray<PRCountry *> *countries;
@property (nonatomic, strong, readonly) NSDictionary *countryRegions;
@property (nonatomic, copy, readonly) NSArray *categories;
@property (nonatomic, copy, readonly) NSArray *sections;
@property (nonatomic, readonly) NSString *Schedule;
@property (nonatomic, readonly) BOOL isRTL;
@property (nonatomic, readonly) NSString *paperFormat;
@property (nonatomic, readonly) NSString *hexPaperColor;
@property (nullable, nonatomic, readonly) NSArray<NSString *> *regionalCIDs;
@property (nonatomic, readonly) NSString *parentCID;
@property (nonatomic, copy, readonly) NSDictionary<NSString *, id> *properties;
@property (nonatomic, copy, readonly) NSMutableDictionary<NSString *, id> *mutableProperties;

@property (nullable, nonatomic, strong) NSDate *radioInfoIssueDate;

@property (nonatomic) NSInteger orderNumber;
@property (nullable, nonatomic, copy) NSArray<NSDate *> *availableDates;
@property (nullable, nonatomic, strong) NSDictionary<NSDate *, NSDictionary<NSString *, id> *> *availableVersions;
@property (nonatomic) BOOL newspaperRadioAvailable;
@property (nonatomic, readonly) NSArray *customSupplementCIDs;
@property (nonatomic, strong) PRTitleItemServiceSpecificProperties serviceSpecificProperties;

@property (nonatomic, readonly) PRTitleItemScheduleType scheduleType;
@property (nullable, nonatomic, strong) NSDate *availableDatesUpdateDate;

@end

// Purchase advise extension
@class PRMyLibraryItem;

@interface PRTitleItem (/*PurchaseAdvise*/)
@property (nullable, nonatomic, strong) PRMyLibraryItem *replacedLibraryItem;
@end

NS_ASSUME_NONNULL_END

#import "PRTitleItem+Subscription.h"
