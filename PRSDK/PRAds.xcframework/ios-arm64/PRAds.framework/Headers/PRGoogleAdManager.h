//
//  PRGoogleAdManager.h
//  PRiphone Production
//
//  Created by KeithC on 2021-03-16.
//  Copyright © 2021 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

@class AdBannerInfo;

NS_ASSUME_NONNULL_BEGIN

@interface PRGoogleAdManager : NSObject 

- (instancetype)initWithBannerInfo:(AdBannerInfo *)info;

- (BOOL)isEnabled;
- (BOOL)shouldDisplayInterstitialAdForArticleTitle:(NSString *)articleTitle;

- (void)loadAdForBannerAdSize:(CGSize)size
                       adView:(UIView *)adView
                     adUnitID:(NSString *)adUnitId
           rootViewController:(UIViewController *)vc
                    completed:(void (^_Nonnull)(BOOL success,
                                                __kindof UIView *adView,
                                                NSError * _Nullable error))completionBlock;

@property (nonatomic, strong, readonly) NSArray<NSValue *> *supportedInterstitialAdSizes;
@property (nonatomic, strong, readonly) NSSet<NSValue *> *availableInterstitialAdSizes;

@end

NS_ASSUME_NONNULL_END
