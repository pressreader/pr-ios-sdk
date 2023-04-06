//
//  PRSourceItem+Readiness.h
//  PRAPI
//
//  Created by berec on 25/11/2020.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import <PRAPI/PRSourceItem.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, PRIssueDownloadCancelReason) {
    PRIssueDownloadCancelReasonNone,
    PRIssueDownloadCancelReasonAccountReachability,
    PRIssueDownloadCancelReasonNetworkReachability,
    PRIssueDownloadCancelReasonNetworkLimitation,
    PRIssueDownloadCancelReasonIssueDate,
    PRIssueDownloadCancelReasonExpired
};

extern NSString *const kPRIssueDownloadCancelReason;

@interface PRSourceItem (Readiness)

- (BOOL)isReadyForDownload:(PRIssueDownloadCancelReason *_Nullable)reason;

@property (nonatomic, readonly) BOOL isReadyForDownload;

@end

NS_ASSUME_NONNULL_END
