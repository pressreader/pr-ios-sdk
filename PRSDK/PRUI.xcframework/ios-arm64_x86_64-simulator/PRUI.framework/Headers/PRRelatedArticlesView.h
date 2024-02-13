//
//  PRRelatedArticlesView.h
//  PRUI
//
//  Created by Viacheslav Soroka on 6/7/18.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "PRAnimatableOnScroll.h"

NS_ASSUME_NONNULL_BEGIN

@class NTFArticleItem;
@class FeedItemAction;

@interface PRRelatedArticlesView : UIView <PRAnimatableOnScroll>

+ (instancetype)viewWithType:(NSString *)viewType;

- (void)fillWithArticle:(NTFArticleItem *)article
                 action:(nullable FeedItemAction *)action;

@property (nonatomic) NSInteger fitToWidthColumnsCount;
@property (class, nonatomic, readonly) CGFloat anchorHeight;
@property (nonatomic) UIEdgeInsets collectionViewContentInset;
@property (nullable, nonatomic, weak) UIViewController *articlePresenter;

@end

NS_ASSUME_NONNULL_END
