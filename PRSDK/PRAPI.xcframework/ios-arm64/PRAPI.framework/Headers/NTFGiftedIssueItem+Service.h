//
//  NTFGiftedIssueItem+Service.h
//  PRiphone
//
//  Created by Viacheslav Soroka on 5/11/17.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

#import "NTFGiftedIssueItem+CoreDataClass.h"

@class PRPromise;

@interface NTFGiftedIssueItem (Service)

+ (PRPromise *)requestGiftedIssueItemWithCampaignId:(NSString *)campaignId showLoadingHUD:(BOOL)showLoadingHUD;

+ (PRPromise *)directURLWithCampaignId:(NSString *)campaignId;

+ (PRPromise *)claimWithCampaignId:(NSString *)campaignId;
+ (PRPromise *)claimWithCampaignId:(NSString *)campaignId profileId:(NSString *)profileId cid:(NSString *)cid;

- (PRPromise *)directURL;

- (PRPromise *)claim;
- (PRPromise *)claimWithProfileId:(NSString *)profileId cid:(NSString *)cid;

@end
