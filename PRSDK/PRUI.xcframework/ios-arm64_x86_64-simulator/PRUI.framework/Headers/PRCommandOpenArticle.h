//
//  PRCommandOpenArticle.h
//  PR-UI
//
//  Created by Viacheslav Soroka on 6/20/18.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

@import UIKit;

@class CommandOpenArticleParameters;
@protocol NTFArticle;

NS_ASSUME_NONNULL_BEGIN

typedef void(^PRCommandOpenArticleCompletion)(UIViewController *);

@interface PRCommandOpenArticle : NSObject

+ (void)executeWithArticleId:(NSString *)articleId
                  parameters:(nullable CommandOpenArticleParameters *)parameters;
+ (void)executeWithArticleId:(NSString *)articleId
                  parameters:(nullable CommandOpenArticleParameters *)parameters
                  completion:(nullable PRCommandOpenArticleCompletion)completion;


+ (void)executeWithArticle:(id<NTFArticle>)article
                parameters:(nullable CommandOpenArticleParameters *)parameters;
+ (void)executeWithArticle:(id<NTFArticle>)article
                parameters:(nullable CommandOpenArticleParameters *)parameters
                completion:(nullable PRCommandOpenArticleCompletion)completion;

@property (class, nonatomic, weak, readonly) __kindof UIViewController *presentedController;

@end

NS_ASSUME_NONNULL_END
