//
//  PRCommandOpenArticle.h
//  PR-UI
//
//  Created by Viacheslav Soroka on 6/20/18.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

@import PRUIKit.PRCommand;
@import PRAPI.NTFArticle;
#import <PRUI/VerticalTextFlowVC.h>
#import <PRUI/PRArticleContainerVC.h>

NS_ASSUME_NONNULL_BEGIN

@interface PRCommandOpenArticle : PRCommand

+ (void)executeWithArticle:(id<NTFArticle>)article;

+ (void)executeWithArticle:(id<NTFArticle>)article
                    parent:(nullable id<NTFArticle>)parent
                  flowType:(NTFTextFlowType)flowType
                 presenter:(nullable UIViewController *)presenter;

+ (void)executeWithArticle:(id<NTFArticle>)article
                    parent:(nullable id<NTFArticle>)parent
                  flowType:(NTFTextFlowType)flowType
                 presenter:(nullable UIViewController *)presenter
                   options:(PRArticleContainerOption)options;

+ (void)executeWithArticle:(id<NTFArticle>)article
                    parent:(nullable id<NTFArticle>)parent
                  flowType:(NTFTextFlowType)flowType
                 presenter:(nullable UIViewController *)presenter
                   options:(PRArticleContainerOption)options
        highlightedPhrases:(nullable NSArray<NSString *> *)highlightedPhrases;

+ (void)executeWithArticleId:(NSString *)articleId;

+ (void)executeWithArticleId:(NSString *)articleId
                    flowType:(NTFTextFlowType)flowType
                   presenter:(nullable UIViewController *)presenter;

+ (void)executeWithArticleId:(NSString *)articleId
                    flowType:(NTFTextFlowType)flowType
                   presenter:(nullable UIViewController *)presenter
                     options:(PRArticleContainerOption)options
          highlightedPhrases:(nullable NSArray<NSString *> *)highlightedPhrases;

@property (class, nonatomic, weak, readonly) __kindof UIViewController *presentedController;

@end

NS_ASSUME_NONNULL_END
