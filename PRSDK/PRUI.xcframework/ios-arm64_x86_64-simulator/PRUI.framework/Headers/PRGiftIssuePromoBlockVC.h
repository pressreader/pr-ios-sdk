//
//  PRGiftIssuePromoBlockVC.h
//  PR-UI
//
//  Created by Vitali Bounine on 2018-06-04.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>
@class NTFGiftedIssueItem;

NS_ASSUME_NONNULL_BEGIN

@interface PRGiftIssuePromoBlockVC : UIViewController

- (instancetype) initWithGiftedIssueItem:(NTFGiftedIssueItem *)giftedIssueItem;

@property (nonatomic, readonly) NSString *campaignId;
@property (nonatomic, readonly) NSInteger videoPlayedDuration;

@end

NS_ASSUME_NONNULL_END
