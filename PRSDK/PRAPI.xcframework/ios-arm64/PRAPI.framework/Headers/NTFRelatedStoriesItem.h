//
//  NTFRelatedStoriesItem.h
//  PR-API
//
//  Created by Viacheslav Soroka on 6/27/18.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class NTFArticleItem;

@interface NTFRelatedStoriesItem : NSObject
@property (nonatomic, readonly) NTFArticleItem *article;

+ (instancetype)itemWithArticle:(NTFArticleItem *)article;
- (instancetype)initWithArticle:(NTFArticleItem *)article;

@end

NS_ASSUME_NONNULL_END
