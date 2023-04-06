//
//  NTFActionMenuProvider.h
//  PRiphone
//
//  Created by Vitali Bounine on 2016-09-07.
//  Copyright © 2016 NewspaperDirect. All rights reserved.
//

@import UIKit;
@import PRAPI;
@import PRUIKit;

#import "PRFlowArticle.h"
#import "NTFMenuProvider.h"

@class PRMenuItem;

NS_ASSUME_NONNULL_BEGIN

@interface NTFActionMenuProvider : NSObject

typedef NS_ENUM(NSInteger, NTFActionMenuMode) {
    NTFActionMenuModeText = 0,
    NTFActionMenuModePage,
    NTFActionMenuModeSimplified
};

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithPresentingViewController:(UIViewController *)presentingController
                                         context:(nullable NSDictionary *)context;

- (nullable NSArray<PRMenuItem *> *)actionMenuItemsForArticle:(id<PRFlowArticle>)article
                                                  fullVersion:(BOOL)fullVersion
                                                       sender:(nullable id)sender;
- (nullable NSArray<PRMenuItem *> *)actionMenuItemsWithContext:(NSDictionary *)context;
- (nullable NSArray<PRMenuItem *> *)horizontalActionMenuItemsForArticle:(id<PRFlowArticle>)article
                                                            fullVersion:(BOOL)fullVersion
                                                                 sender:(nullable id)sender;

- (nullable PRMenu *)actionMenuForArticle:(id<PRFlowArticle>)article
                              fullVersion:(BOOL)fullVersion
                                   sender:(nullable id)sender;
- (void)presentCommentsViewForForArticle:(id<PRFlowArticle>)article sender:(nullable id)sender;

- (nullable PRMenuItem *)translateMenuItemForArticle:(id<PRFlowArticle>)article options:(NTFMenuItemProviderOption)options;

@property (nonatomic) NTFActionMenuMode actionMenuMode;

@end

NS_ASSUME_NONNULL_END
