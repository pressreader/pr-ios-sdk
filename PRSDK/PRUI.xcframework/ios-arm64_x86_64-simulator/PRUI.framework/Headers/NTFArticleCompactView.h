//
//  NTFArticleCompactView.h
//  PR-UI
//
//  Created by berec on 03/07/2018.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import "NTFArticleCompactTextualView.h"
#import "NTFItemCompactView.h"

@import PRUIKit;

@class PRAlignedImageView;
@class FeedItemAction;
@class NTFArticleCompactViewMetaInfo;

typedef NS_OPTIONS(NSUInteger, NTFArticleCompactViewOption) {
    NTFArticleCompactViewOptionNone = 0,
    NTFArticleCompactViewOptionBEStyling = 1 << 0,
    NTFArticleCompactViewOptionDynamicThumbnailHeight = 1 << 1,
    /// display set byline as is instead of masthead + date combination
    NTFArticleCompactViewOptionDisplayTraditionalByline = 1 << 2,
    NTFArticleCompactViewOptionHideSimilarStories = 1 << 3,
    NTFArticleCompactViewOptionHideMasthead = 1 << 4,
    NTFArticleCompactViewOptionDisplayFirstInSectionSeparatorIfNeeded = 1 << 5,
    /// disables additional top padding when `firstInSection` is true
    NTFArticleCompactViewOptionDisableFirstInSectionTopPadding = 1 << 6,
    NTFArticleCompactViewOptionHideDate = 1 << 7,
    NTFArticleCompactViewOptionShowImagePlaceholder = 1 << 8
};

NS_ASSUME_NONNULL_BEGIN

@interface NTFArticleCompactView : UIView <NTFItemCompactView>

+ (CGSize)thumbSizeForContentWidh:(CGFloat)width
                            style:(NTFArticleCompactViewStyle)style
                     columnsCount:(NSUInteger)columnsCount;

- (instancetype)initWithStyle:(NTFArticleCompactViewStyle)style;
- (instancetype)initWithCoder:(NSCoder *)coder NS_UNAVAILABLE;

- (void)setupWithArticleItem:(nullable id<NTFArticle>)articleItem
                      action:(nullable FeedItemAction *)anAction
                     options:(NTFArticleCompactViewOption)options
                contentWidth:(CGFloat)contentWidth
                columnsCount:(NSUInteger)columnsCount;

@property (class, nonatomic, readonly) CGFloat intercolumnSpacing;

@property (nonatomic) BOOL firstInSection;
@property (nullable, nonatomic, strong, readonly) id<NTFArticle> articleItem;
@property (nullable, nonatomic, strong, readonly) FeedItemAction *action;

@property (nonatomic, readonly) NTFArticleCompactViewStyle style;
@property (nonatomic) BOOL offlineMode;
@property (nullable, nonatomic, weak) NTFArticleCompactView *anchorArticleView;
@property (nonatomic, readonly) NTFArticleCompactViewOption options;


// UI Components
@property (nonatomic, strong, readonly) NTFArticleCompactTextualView *textualView;
@property (nonatomic, strong, readonly) NTFArticleCompactViewMetaInfo *metaInfo;

@end


@interface NTFArticleCompactView (/*PROTECTED*/)

- (void)setupConstraints;
- (void)configurePlaceholder;
- (void)setThumbnailImage:(nullable UIImage *)image;

@property (nonatomic, strong) PRAlignedImageView *imageView;

@end

NS_ASSUME_NONNULL_END
