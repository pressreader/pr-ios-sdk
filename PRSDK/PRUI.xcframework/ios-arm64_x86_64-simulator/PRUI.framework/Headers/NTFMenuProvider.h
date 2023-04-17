//
//  NTFMenuProvider.h
//  PRiphone
//
//  Created by Viacheslav Soroka on 5/29/17.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

@import UIKit;

@class PRCommand;
@class PRMenuItem;

typedef NS_OPTIONS(NSUInteger, NTFMenuItemProviderOption) {
    NTFMenuItemProviderOptionNone = 0,
    NTFMenuItemProviderOptionHideIcon = 1 << 0
};

NS_ASSUME_NONNULL_BEGIN

@protocol NTFMenuProvider <NSObject>

- (void)getActionMenuItemsWithPresentingVC:(UIViewController *)vc
                                    sender:(id)sender
                               fullVersion:(BOOL)fullVersion
                                completion:(void(^)(NSArray<PRMenuItem *> *_Nullable items))completion;

- (void)getHorizontalActionMenuItemsWithPresentingVC:(UIViewController *)vc
                                              sender:(id)sender
                                         fullVersion:(BOOL)fullVersion
                                          completion:(void(^)(NSArray<PRMenuItem *> *_Nullable items))completion;

- (void)preload:(void(^_Nullable)(void))completion;

- (PRMenuItem * __nullable)translateMenuItemWithOptions:(NTFMenuItemProviderOption)options;

@end

NS_ASSUME_NONNULL_END
