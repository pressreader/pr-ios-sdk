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

@class PRSubscription, PRAccountItem;

@interface PRSourceItem : NSObject

@property (nonatomic, retain, readonly) NSString *CID;
@property (nullable, nonatomic, retain, readonly) NSString *parentName;
@property (nullable, nonatomic, retain, readonly) NSString *supplementName;

@property (nonatomic, readonly) BOOL isFavoritable;
@property (nonatomic, readonly) BOOL isInCatalog;

@property (nullable, nonatomic, retain) NSDictionary<NSString *, id> * NS_SWIFT_SENDABLE newspaperRadioInfo;

@property (nullable, nonatomic, strong) NSString *originalMasthead;
@property (nullable, nonatomic, strong) NSString *templateMasthead;

@property (nonatomic, assign) BOOL allowCellularDownload;

- (instancetype)initWithCID:(NSString *)cid
                      title:(NSString *)title
                 parentName:(NSString *)parent
             supplementName:(NSString *)supplement;

@end

@interface PRSourceItem (/*PROTECTED*/)
@property (nullable, nonatomic, strong) NSString *title;
@property (nullable, nonatomic, strong) NSString *localizedTitle;
@property (nullable, nonatomic, strong) NSArray<NSValue *> *subscriptions;
@property (nullable, nonatomic, strong) NSArray *parentCIDs;

@end

NS_ASSUME_NONNULL_END

#import <PRAPI/PRIssueDownloadChecker.h>
