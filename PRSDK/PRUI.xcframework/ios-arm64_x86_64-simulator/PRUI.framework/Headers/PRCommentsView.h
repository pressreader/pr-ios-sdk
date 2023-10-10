//
//  PRCommentsView.h
//  PR-UI
//
//  Created by Viacheslav Soroka on 5/29/18.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "PRCommentPostView.h"

@import PRAPI;

NS_ASSUME_NONNULL_BEGIN

@class PRCommentsView;

@protocol PRCommentsViewDelegate <PRCommentPostViewDelegate>

- (void)commentsViewDidUpdateComments:(PRCommentsView *)view reloaded:(BOOL)reloaded;
- (void)commentsViewDidReceiveShowFullDiscussionTap:(UIView *)sender;

@end

@interface PRCommentsView : UIView
@property (nonatomic, strong) id<FlowArticle> article;

@property (nonatomic, readonly) UIStackView *stackView;

@property (nonatomic, weak) id<PRCommentsViewDelegate> delegate;

- (void)setupInitialCommentStackViewWithContentWidth:(CGFloat)width
                                          hideFooter:(BOOL)hideFooter;

- (UIView *)commentPostButtonView;
- (void)updateCommentHeaderCount;

@end

NS_ASSUME_NONNULL_END
