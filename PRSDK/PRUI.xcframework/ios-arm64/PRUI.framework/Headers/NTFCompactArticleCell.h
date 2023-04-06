//
//  NTFCompactArticleCell.h
//  PR-UI
//
//  Created by berec on 29/05/2018.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import "NTFCompactFlowCell.h"

#import "NTFArticleCompactView.h"

NS_ASSUME_NONNULL_BEGIN

@interface NTFCompactArticleCell : NTFCompactFlowCell

- (void)setupWithArticleItem:(id<NTFArticle>)articleItem
                 action:(FeedItemAction *)action
                contentWidth:(CGFloat)contentWidth
                     options:(NTFArticleCompactViewOption)options;

@property (nonatomic, assign, readonly) NTFArticleCompactViewOption options;
@property (nonatomic, strong, readonly) id<NTFArticle> article;
@property (nonatomic) BOOL firstInSection;

@end

/// NTFCompactArticleCell with predefined style = .Large
@interface NTFArticleLargeCell : NTFCompactArticleCell
@end

/// NTFCompactArticleCell with predefined style = .LargeTwoColumns
@interface NTFArticleLargeTwoColumnsCell : NTFCompactArticleCell
@end

/// NTFCompactArticleCell with predefined style = .LargeThreeColumns
@interface NTFArticleLargeThreeColumnsCell : NTFCompactArticleCell
@end

/// NTFArticleLargeCell with firstInSection = YES
@interface NTFArticleFirstInSectionCell : NTFArticleLargeCell
@end

/// NTFCompactArticleCell with predefined style = .Wide
@interface NTFArticleWideCell : NTFCompactArticleCell
@end

/// NTFCompactArticleCell with predefined style = .WideNoImage
@interface NTFArticleWideNoImageCell : NTFCompactArticleCell
@end

NS_ASSUME_NONNULL_END
