//
//  PRArticleTextProvider.h
//  PRSmart
//
//  Created by Viacheslav Soroka on 11/20/18.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PRSmartArticle;
@class PRArticleBlock;

typedef NSAttributedString *_Nullable(^PRAttributedStringGenerator)(NSString *text);
typedef NSAttributedString *_Nullable(^PRArticleBlockGenerator)(PRArticleBlock *block);
typedef NSArray<NSAttributedString *> *_Nullable(^PRArticleBlockProcessor)(NSArray<NSAttributedString *> *blocks);

@interface PRArticleTextProvider : NSObject

+ (instancetype)providerWithArticle:(PRSmartArticle *)article
                                cid:(nullable NSString *)cid
                               date:(nullable NSDate *)date;

- (nullable NSString *)text;
- (nullable NSString *)textWithLanguage:(NSString *)language;

- (nullable NSAttributedString *)attributedTextWithLanguage:(NSString *)language
                                              bodyGenerator:(PRArticleBlockGenerator)bodyGenerator
                                         paratitleGenerator:(PRAttributedStringGenerator)paratitleGenerator
                                        annotationGenerator:(PRAttributedStringGenerator)annotationGenerator
                                              htmlGenerator:(PRAttributedStringGenerator)htmlGenerator
                                           snippetGenerator:(PRAttributedStringGenerator)snippetGenerator
                                              postprocessor:(nullable PRArticleBlockProcessor)postprocessor;

@property (class, nonatomic, readonly) NSString *snippetEnding;

/// provider limits whole to a snippet when YES
@property (nonatomic) BOOL isSnippet;
@property (nonatomic) NSInteger snippetMaxLength;

@end

NS_ASSUME_NONNULL_END
