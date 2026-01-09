//
//  PRLatestIssuesList.h
//  PRAPI
//
//  Created by Viacheslav Soroka on 12/3/19.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import <PRConfiguration/PRCatalogConfig.h>
#import <PRAPI/PRCatalogItem.h>
#import <PRAPI/PRTitleItemExemplar.h>

NS_ASSUME_NONNULL_BEGIN

@class PRLatestIssuesList;

@protocol PRLatestIssuesListDelegate <NSObject>
- (void)latestIssuesListDidUpdate:(PRLatestIssuesList *)list;
@end

@interface PRLatestIssuesList : NSObject

- (instancetype)initWithCIDs:(nullable NSArray<NSString *> *)cids
                       order:(PRCatalogSortingOrder)order;

- (instancetype)initWithCIDs:(nullable NSArray<NSString *> *)cids
                       order:(PRCatalogSortingOrder)order
                         mix:(BOOL)mix;

- (instancetype)initWithCID:(NSString *)cid;

@property (nullable, nonatomic, strong) NSArray<CID> *cids;
@property (nullable, nonatomic, strong, readonly) NSArray<PRTitleItemExemplar *> *list;
@property (nonatomic, assign, readonly) BOOL isReady;
@property (nonatomic, weak) id<PRLatestIssuesListDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
