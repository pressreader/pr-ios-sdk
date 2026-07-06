//
//  NTFMenuProvider.h
//  PRiphone
//
//  Created by Viacheslav Soroka on 5/29/17.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

@class PRCommand;
@class PRMenuItem;

typedef NS_OPTIONS(NSUInteger, NTFMenuItemProviderOption) {
    NTFMenuItemProviderOptionNone = 0,
    NTFMenuItemProviderOptionHideIcon = 1 << 0
};

NS_ASSUME_NONNULL_BEGIN

@protocol NTFMenuProvider <NSObject>

- (NSArray<PRMenuItem *> *_Nullable)getActionMenuItemsWithPresentingVC:(UIViewController *)vc
                                                                sender:(id)sender
                                                           fullVersion:(BOOL)fullVersion;

- (NSArray<PRMenuItem *> *_Nullable)getHorizontalActionMenuItemsWithPresentingVC:(UIViewController *)vc
                                                                          sender:(id)sender
                                                                     fullVersion:(BOOL)fullVersion;

- (void)preloadWithCompletionHandler:(void(^_Nullable)(NSError *))completion;

- (PRMenuItem * __nullable)translateMenuItemWithOptions:(NTFMenuItemProviderOption)options;

@end

NS_ASSUME_NONNULL_END
