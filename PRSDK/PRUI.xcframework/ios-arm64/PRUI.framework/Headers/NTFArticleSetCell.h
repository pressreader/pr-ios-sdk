//
//  NTFArticleSetCell.h
//  PR-UI
//
//  Created by berec on 26/05/2018.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import "NTFCompactFlowCell.h"

#import "NTFArticleCompactView.h"
#import "NTFArticleCompactView_Constants.h"

NS_ASSUME_NONNULL_BEGIN

typedef NSArray<id<NTFItem>> * NTFItems;

@interface NTFArticleSetCell : NTFCompactFlowCell

+ (instancetype)cellWithNumberOfItems:(NSUInteger)itemsCount
                              options:(NTFArticleCompactViewOption)options
                      reuseIdentifier:(NSString *)reuseIdentifier;

- (instancetype)initWithCoder:(NSCoder *)coder NS_UNAVAILABLE;

- (void)setupWithItems:(NTFItems)items
             contentWidth:(CGFloat)contentWidth
                   action:(FeedItemAction *)action
                  options:(NTFArticleCompactViewOption)options;

@property (nonatomic, strong, readonly) NTFItems feedItems;
@property (nonatomic, assign, readonly) NSUInteger itemsCount;

@end

@interface NTFArticleSetCell (/*PROTECTED*/)

- (void)setupCells;
- (NTFArticleCompactView *)createCellWithStyle:(NTFArticleCompactViewStyle)style;

@property (nonatomic, strong) UIStackView *hStackView;
@property (nonatomic, strong) NSArray<UIView<NTFItemCompactView> *> *cells;
@property (nonatomic, readonly) NSUInteger columnsCount;
@property (nonatomic, readonly) NTFArticleCompactViewStyle articleStyle;
@property (nonatomic) NTFArticleCompactViewOption options;
@property (nonatomic, readonly) NTFArticleCompactTextualViewOption textOptions;

@property (nonatomic, readonly) NSUInteger textLinesCount;
@property (nonatomic, readonly) NSUInteger textLinesCountWithoutImage;

@end

NS_ASSUME_NONNULL_END
