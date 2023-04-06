//
//  PRHotzoneBannerVC.h
//  PRiphone
//
//  Created by Oleg Stepanenko on 01.10.14.
//  Copyright (c) 2014 NewspaperDirect. All rights reserved.
//

@import UIKit;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(uint8_t, PROrderBannerType) {
    PROrderBannerTypeNone = 0,
    PROrderBannerTypeHotZone
};

@interface PROrderBannerVC : UIViewController

- (void)refresh;
- (void)showBanner:(NSAttributedString *)bannerMessage;
- (void)hideBannerAnimated:(BOOL)animated;
- (BOOL)isBannerAllowed;

@property (nonatomic, strong) NSString *CID;
@property (nonatomic, readonly) PROrderBannerType orderBannerType;

@end

NS_ASSUME_NONNULL_END
