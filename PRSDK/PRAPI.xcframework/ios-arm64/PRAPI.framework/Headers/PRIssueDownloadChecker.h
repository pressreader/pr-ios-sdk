//
//  PRIssueDownloadChecker.h
//  PRAPI
//
//  Created by berec on 25/11/2020.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PRAPI/PRCatalogItem.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, PRIssueDownloadCancelReason) {
    PRIssueDownloadCancelReasonNone,
    PRIssueDownloadCancelReasonAccountReachability,
    PRIssueDownloadCancelReasonNetworkReachability,
    PRIssueDownloadCancelReasonNetworkLimitation,
    PRIssueDownloadCancelReasonExpired
};

extern NSString *const kPRIssueDownloadCancelReason;

@interface PRIssueDownloadChecker: NSObject

+ (BOOL)isReadyToDownload:(id<PRCatalogItem>)item reason:(PRIssueDownloadCancelReason *_Nullable)reason;
+ (BOOL)isReadyToDownload:(id<PRCatalogItem>)item NS_SWIFT_NAME(isReadyToDownload(_:));

@end

NS_ASSUME_NONNULL_END
