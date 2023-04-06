//
//  PRBannersConfig.h
//  PRSharedData
//
//  Created by Viacheslav Soroka on 5/5/20.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_CLOSED_ENUM(uint8_t, PRBannerType) {
    PRBannerTypeHotspotServices = 0,
    PRBannerTypePremiumSubscription,
    PRBannerTypeImproveExperience,
    PRBannerTypeBooks,
    PRBannerTypeBrazeContentCard
};

@interface PRBannersConfig : NSObject
@property (nonatomic, readonly) NSArray<NSNumber *> *bannersOrder;

@end

NS_ASSUME_NONNULL_END
