//
//  PRGoogleAdManager.h
//  PRiphone Production
//
//  Created by KeithC on 2021-03-16.
//  Copyright © 2021 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

@class AdBannerInfo;
@class PRGoogleAdProvider;

NS_ASSUME_NONNULL_BEGIN

@interface PRGoogleAdManager : NSObject 

- (instancetype)initWithBannerInfo:(AdBannerInfo *)info;

- (BOOL)isEnabled;
- (BOOL)shouldDisplayInterstitialAdForArticleTitle:(NSString *)articleTitle;

@property (nonatomic, strong, readonly) NSArray<NSValue *> *supportedInterstitialAdSizes;
@property (nonatomic, strong, readonly) NSSet<NSValue *> *availableInterstitialAdSizes;

@end

@interface PRGoogleAdManager (/*PROTECTED*/)
@property (nullable, nonatomic, strong) PRGoogleAdProvider *adProvider;

@end

NS_ASSUME_NONNULL_END
