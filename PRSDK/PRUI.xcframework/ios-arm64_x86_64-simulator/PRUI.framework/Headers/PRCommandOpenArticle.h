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

@interface PRCommandOpenArticle : NSObject

+ (void)executeWithArticle:(id<NTFArticle>)article
                completion:(void(^_Nullable)(UIViewController *))completion;

+ (void)executeWithArticle:(id<NTFArticle>)article
                    parent:(nullable id<NTFArticle>)parent
                  flowType:(NTFTextFlowType)flowType
                 presenter:(nullable UIViewController *)presenter
                completion:(void(^_Nullable)(UIViewController *))completion;

+ (void)executeWithArticle:(id<NTFArticle>)article
                    parent:(nullable id<NTFArticle>)parent
                  flowType:(NTFTextFlowType)flowType
                 presenter:(nullable UIViewController *)presenter
                   options:(PRArticleContainerOption)options
                completion:(void(^_Nullable)(UIViewController *))completion;

+ (void)executeWithArticle:(id<NTFArticle>)article
                    parent:(nullable id<NTFArticle>)parent
                  flowType:(NTFTextFlowType)flowType
                 presenter:(nullable UIViewController *)presenter
                   options:(PRArticleContainerOption)options
        highlightedPhrases:(nullable NSArray<NSString *> *)highlightedPhrases
                completion:(void(^_Nullable)(UIViewController *))completion;

+ (void)executeWithArticleId:(NSString *)articleId
                  completion:(void(^_Nullable)(UIViewController *))completion;

+ (void)executeWithArticleId:(NSString *)articleId
                    flowType:(NTFTextFlowType)flowType
                   presenter:(nullable UIViewController *)presenter
                  completion:(void(^_Nullable)(UIViewController *))completion;

+ (void)executeWithArticleId:(NSString *)articleId
                    flowType:(NTFTextFlowType)flowType
                   presenter:(nullable UIViewController *)presenter
                     options:(PRArticleContainerOption)options
          highlightedPhrases:(nullable NSArray<NSString *> *)highlightedPhrases
                  completion:(void(^_Nullable)(UIViewController *))completion;

@property (class, nonatomic, weak, readonly) __kindof UIViewController *presentedController;

@end

NS_ASSUME_NONNULL_END
