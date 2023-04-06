//
//  GoogleAdProvider.h
//  PRiphone Production
//
//  Created by KeithC on 2021-03-16.
//  Copyright © 2021 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol PRAdProviderDelegate

- (void)didReceiveAdWithSize:(CGSize)size;

@end

@interface PRGoogleAdProvider : NSObject

+ (BOOL)isAvailable;

/// Does nothing if `isAvailable` is `false`
+ (void)setup;

- (void)loadAdForBannerAdSize:(CGSize)size
                       adView:(UIView *)adView
                     adUnitID:(NSString *)adUnitId
           rootViewController:(UIViewController *)vc
                    completed:(void (^_Nonnull)(BOOL success,
                                                __kindof UIView *adView,
                                                NSError * _Nullable error))completionBlock;

@property (nullable, nonatomic, weak) id<PRAdProviderDelegate> delegate;
@property (nonatomic, readonly) BOOL isEnabled;

@end

NS_ASSUME_NONNULL_END
