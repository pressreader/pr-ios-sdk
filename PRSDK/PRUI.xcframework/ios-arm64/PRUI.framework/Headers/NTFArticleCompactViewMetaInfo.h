//
//  NTFArticleCompactViewMetaInfo.h
//  PRUI
//
//  Created by berec on 21/01/2021.
//  Copyright © 2021 NewspaperDirect. All rights reserved.
//

@import UIKit;

@import PRAPI.NTFArticle;
@import PRAccessibility;

#import <PRUI/NTFArticleCompactView_Constants.h>

@class PRSwitchButton;
@class PRSimilarsTipButton;
@class UITextViewWithLinks;
@class FeedItemAction;

NS_ASSUME_NONNULL_BEGIN

@interface NTFArticleCompactViewMetaInfo : NSObject

@property (nullable, nonatomic, strong) FeedItemAction *action;
@property (nonatomic, strong) id<NTFArticle> articleItem;

@property (nonatomic) BOOL offlineMode;

@property (nonatomic) NTFArticleCompactViewStyle style;
@property (nonatomic) NTFArticleCompactViewBylineStyle bylineStyle;
@property (nonatomic) NTFArticleCompactTextualViewOption options;

@property (nonatomic) CGSize contentSize;

@property (nonatomic, readonly) UIStackView *stackView;
@property (nonatomic, readonly) CGFloat stackViewEstimatedHeight;

// UI Components
@property (nonatomic, strong, readonly) UILabel *dateLabel;
@property (nonatomic, strong, readonly) PRSwitchButton *menuButton;
@property (nonatomic, strong, readonly) UITextViewWithLinks *tagsView;
@property (nonatomic, strong, readonly) UIStackView *listenDurationView;

@end

NS_ASSUME_NONNULL_END
