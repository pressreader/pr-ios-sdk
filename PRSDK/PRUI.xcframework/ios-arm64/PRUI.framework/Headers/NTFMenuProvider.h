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

@protocol NTFMenuProvider <NSObject>

- (void)getActionMenuItemsWithPresentingVC:(UIViewController *)vc
                                    sender:(id)sender
                               fullVersion:(BOOL)fullVersion
                                completion:(void(^)(NSArray<PRMenuItem *> *items))completion;

- (void)getHorizontalActionMenuItemsWithPresentingVC:(UIViewController *)vc
                                              sender:(id)sender
                                         fullVersion:(BOOL)fullVersion
                                          completion:(void(^)(NSArray<PRMenuItem *> *items))completion;

- (void)preload:(void(^)(void))completion;

@property (nonatomic, copy, readonly) NSString *contextKey;
- (void)registerCommands:(NSArray<PRCommand *> *)commands
                 context:(NSDictionary *)context
    presentingController:(UIViewController *)vc;

- (PRMenuItem *)translateMenuItemWithOptions:(NTFMenuItemProviderOption)options;

@end
