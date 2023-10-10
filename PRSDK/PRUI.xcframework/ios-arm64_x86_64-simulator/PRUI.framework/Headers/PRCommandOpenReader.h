//
//  PRCommandOpenReader.h
//  PRiphone
//
//  Created by Oleg Stepanenko on 26.11.13.
//  Copyright (c) 2013 NewspaperDirect. All rights reserved.
//

@import PRUIKit.PRCommand;
@import PRAPI.NTFArticle;
@import PRUtils;

NS_ASSUME_NONNULL_BEGIN

@interface PRCommandOpenReader : PRCommand

+ (void)executeWithArticle:(id<NTFArticle>)article completion:(nullable PRSimpleBlock)completion;
+ (void)executeWithParameters:(NSDictionary *)parameters completion:(nullable PRSimpleBlock)completion;

@end

NS_ASSUME_NONNULL_END
