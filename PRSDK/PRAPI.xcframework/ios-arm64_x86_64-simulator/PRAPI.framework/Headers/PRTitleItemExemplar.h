//
//  PRTitleItemExemplar.h
//  PRiphone
//
//  Created by Jackie Cane on 27/02/14.
//  Copyright (c) 2014 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, PRTitleItemExemplarState) {
    PRTitleItemExemplarStateUnknown = 0,
    /// Issue is in store and available to order
    PRTitleItemExemplarStateReadyToBuy,
    /// Issue has been orderd by user
    PRTitleItemExemplarStateBought,
    /// Issue is in download progress
    PRTitleItemExemplarStateDownloading,
    /// Issue is in MyLibrary
    PRTitleItemExemplarStateDownloaded,
};

NS_ASSUME_NONNULL_BEGIN

@class PRThumbnailSource;
@class PRMyLibraryItem;
@class PRSubscription;
@protocol PRCatalogItem;

@interface PRTitleItemExemplar : NSObject

+ (nullable instancetype)titleItemExemplarWithCID:(NSString *)cid date:(nullable NSDate *)date
NS_SWIFT_NAME(item(cid:date:));

- (void)pauseDownload;
- (void)resumeDownload;
- (void)cancelDownload;

@property (nonatomic, strong, readonly) NSString *CID;
@property (nonatomic, strong, readonly) NSDate *issueDate;

@property (nonatomic, readonly) PRTitleItemExemplarState state;
@property (nullable, nonatomic, readonly) PRSubscription *subscription;

@end

NS_ASSUME_NONNULL_END
