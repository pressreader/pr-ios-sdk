//
//  NTFGiftedIssueItem+CoreDataProperties.h
//  PRAPI
//
//  Created by berec on 05/03/2020.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//
//

#import "NTFGiftedIssueItem+CoreDataClass.h"


NS_ASSUME_NONNULL_BEGIN

@interface NTFGiftedIssueItem (CoreDataProperties)

+ (NSFetchRequest<NTFGiftedIssueItem *> *)fetchRequest;

@property (nullable, nonatomic, copy) NSNumber *backgroundColor;
@property (nullable, nonatomic, copy) NSString *backgroundImageUrl;
@property (nullable, nonatomic, copy) NSNumber *buttonsColor;
@property (nullable, nonatomic, copy) NSString *campaignId;
@property (nonatomic) int16_t campaignStatus;
@property (nullable, nonatomic, copy) NSString *descriptionText;
@property (nonatomic) float firstPageHeight;
@property (nonatomic) float firstPageWidth;
@property (nonatomic) int16_t giftType;
@property (nonatomic) int32_t giftUserStatus;
@property (nullable, nonatomic, copy) NSString *issueCid;
@property (nullable, nonatomic, copy) NSDate *issueDate;
@property (nullable, nonatomic, copy) NSString *issueKey;
@property (nullable, nonatomic, copy) NSString *logoImageUrl;
@property (nonatomic) int32_t minWatchingTime;
@property (nullable, nonatomic, copy) NSString *offerText;
@property (nonatomic) int32_t remainingClaims;
@property (nullable, nonatomic, copy) NSNumber *textColor;
@property (nullable, nonatomic, copy) NSData *videoAdParametersJSON;
@property (nullable, nonatomic, copy) NSString *videoAdProvider;

@end

NS_ASSUME_NONNULL_END
