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

@property (nullable, nonatomic, copy) void(^tapHandler)(__kindof PRImageSwitcher *) NS_UNAVAILABLE;
@property (nullable, nonatomic, copy) void(^tapActionHandler)(PRSimpleBlock);

@end

NS_ASSUME_NONNULL_END
