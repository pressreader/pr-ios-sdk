//
//  PRTitleItemExemplar.h
//  PRiphone
//
//  Created by Jackie Cane on 27/02/14.
//  Copyright (c) 2014 NewspaperDirect. All rights reserved.
//

#import "PRTitleObject.h"

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

@interface PRTitleItemExemplar : NSObject <PRTitleObject>

+ (nullable instancetype)titleItemExemplarWithCID:(NSString *)cid
                                             date:(nullable NSDate *)date;

+ (nullable PRTitleItemExemplar *)titleItemExemplarFromItem:(id)item;

- (void)pauseDownload;
- (void)resumeDownload;
- (void)cancelDownload;

@property (nonatomic, strong, readonly) NSString *CID;
@property (nonatomic, strong, readonly) NSDate *date;

@property (nonatomic, strong, readonly) NSString *formattedDate;
@property (nonatomic, strong, readonly) NSString *shortFormattedDate;
@property (nonatomic, readonly) NSString *alternativeNames;
@property (nonatomic, readonly) PRTitleItemExemplarState state;
@property (nonatomic, readonly) BOOL isRecentlyRead;
@property (nonatomic, readonly) PRSubscription *subscription;
@property (nonatomic, readonly) BOOL isLatestExemplar;

@property (nonatomic, readonly) BOOL hasRadio;

@end

NS_ASSUME_NONNULL_END

#import "PRTitleItemExemplar+Thumbnail.h"
