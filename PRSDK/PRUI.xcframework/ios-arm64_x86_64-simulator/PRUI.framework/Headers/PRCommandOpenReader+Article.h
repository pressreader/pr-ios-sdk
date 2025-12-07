//
//  PRCommandOpenReader+Article.h
//  PRUI
//
//  Created by Ivan Berezin on 01/04/2025.
//  Copyright © 2025 NewspaperDirect. All rights reserved.
//

#import <PRUI/PRCommandOpenReader.h>
#import <PRAPI/NTFArticle.h>
@import PRUtils;

NS_ASSUME_NONNULL_BEGIN

@interface PRCommandOpenReader (Article)
+ (BOOL)isEnabledForArticle:(id<NTFArticle>)article;
+ (void)executeWithArticle:(id<NTFArticle>)article completion:(nullable PRCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
