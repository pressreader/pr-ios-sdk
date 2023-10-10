//
//  PRArticleIssueThumbnail.h
//  PRUI
//
//  Created by Viacheslav Soroka on 10/11/18.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import "PRImageSwitcher.h"
@import PRSyntacticSugar;

@protocol NTFArticle;

NS_ASSUME_NONNULL_BEGIN

@interface PRArticleIssueThumbnail : PRImageSwitcher

- (instancetype)init;
- (instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;

- (void)updateWithArticle:(nullable id<NTFArticle>)article animationStyle:(PRImageSwitcherAnimationStyle)style;

@property (nullable, nonatomic, strong, readonly) id<NTFArticle> article;

@end

NS_ASSUME_NONNULL_END
