//
//  NTFGiftedIssueItem.h
//  PRiphone
//
//  Created by Viacheslav Soroka on 5/3/17.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

@import UIKit;

#import "NTFFeedItem+CoreDataClass.h"

typedef NS_ENUM(uint8_t, NTFGiftCampaignStatus) {
    NTFGiftCampaignStatusDraft      = 1,
    NTFGiftCampaignStatusPending    = 10,
    NTFGiftCampaignStatusRejected   = 20,
    NTFGiftCampaignStatusActive     = 40,
    NTFGiftCampaignStatusPaused     = 50,
    NTFGiftCampaignStatusStopped    = 60,
    NTFGiftCampaignStatusRevoked    = 70,
    NTFGiftCampaignStatusCompleted  = 100
};

typedef NS_ENUM(uint8_t, NTFGiftType) {
    NTFGiftTypeIssue    = 1,
    NTFGiftTypeBundle   = 2
};

typedef NS_ENUM(NSUInteger, NTFGiftUserStatus) {
    NTFGiftUserStatusDefault = 0,
    NTFGiftUserStatusCanManage = 1 << 0,
    NTFGiftUserStatusCanShare = 1 << 1,
    NTFGiftUserStatusClaimed = 1 << 2,
    NTFGiftUserStatusFollowing = 1 << 3,
    NTFGiftUserStatusHasAccess = 1 << 4
};

NS_ASSUME_NONNULL_BEGIN

@class NTFUserItem;

@interface NTFGiftedIssueItem : NTFFeedItem

+ (nullable instancetype)standaloneItemWithJSON:(NSDictionary<NSString *, id> *)json;

- (void)updateClaimed:(BOOL)claimed;

// calculated attributes
@property (nullable, readonly, nonatomic) NSURL *backgroundImageURL;
@property (nullable, readonly, nonatomic) UIColor *buttonsUIColor;
@property (nullable, readonly, nonatomic) UIColor *textUIColor;
@property (nullable, readonly, nonatomic) UIColor *backgroundUIColor;
@property (nullable, readonly, nonatomic) NSURL *logoImageURL;
@property (nullable, nonatomic, readonly) NSDictionary *videoAdParameters;

@end

NS_ASSUME_NONNULL_END

#import "NTFGiftedIssueItem+CoreDataProperties.h"
