//
//  NTFArticleTextualCompactView.h
//  PR-UI
//
//  Created by berec on 06/07/2018.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

@import UIKit;
@import PRAPI.NTFArticle;
@import PRAccessibility;

#import <PRUI/NTFArticleCompactView_Constants.h>

NS_ASSUME_NONNULL_BEGIN

@class FeedItemAction;
@class MastheadView;
@class ArticleLabel;

@interface NTFArticleCompactTextualView : UIView

+ (CGFloat)mastheadHeight;

+ (UIFont *)defaultTitleFontForStyle:(NTFArticleCompactViewStyle)style
                             options:(NTFArticleCompactTextualViewOption)options;   

- (instancetype)initWithStyle:(NTFArticleCompactViewStyle)style
                      options:(NTFArticleCompactTextualViewOption)options
                        theme:(PRTheme)theme;

/// @param contentSize In most of the cases .height = 0 (if filling all content space with text is not a requirement).
- (void)setupWithArticleItem:(nullable id<NTFArticle>)articleItem
                      action:(nullable FeedItemAction *)action
                 contentSize:(CGSize)contentSize
      additionalHeightToFill:(CGFloat)additionalHeightToFill;

- (void)setOption:(NTFArticleCompactTextualViewOption)option set:(BOOL)set;

@property (nullable, nonatomic, strong, readonly) id<NTFArticle> articleItem;

@property (nonatomic) NTFArticleCompactViewBylineStyle bylineStyle;
@property (nonatomic) PRTheme theme;

@property (nonatomic, assign, readonly) NTFArticleCompactTextualViewOption options;

@property (nonatomic) BOOL offlineMode;

@property (nonatomic) NSUInteger textLinesCount;

@property (nullable, nonatomic, strong) NSArray<NSString *> *highlightedPhrases;

// UI Components
@property (nonatomic, strong, readonly) MastheadView *mastheadView;
@property (nonatomic, strong, readonly) ArticleLabel *titleLabel;

@end

NS_ASSUME_NONNULL_END
