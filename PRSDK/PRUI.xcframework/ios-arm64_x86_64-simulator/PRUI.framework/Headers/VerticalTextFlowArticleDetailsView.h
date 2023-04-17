//
//  VerticalTextFlowArticleDetailsView.h
//  PR-UI
//
//  Created by Viacheslav Soroka on 5/29/18.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

@import UIKit;
@import WebKit;

#import "PRCommentsView.h"
#import "PRPhotoCollage.h"
#import <PRUI/PRFlowArticle.h>

NS_ASSUME_NONNULL_BEGIN

@class PRMenuVC;
@class FeedItemAction;
@class Interest;
@class AdBannerPresentation;
@class TranslationView;

extern CGFloat const kPRArticleSidePadding;
extern CGFloat const kPRMaxTextWidth;

@protocol VerticalTextFlowArticleDetailsViewDelegate <NSObject>

- (void)updateNavigationBarAppearance;
- (void)adjustNavBarDismissalOnSwipe;
- (void)handleImageTap:(UITapGestureRecognizer *)tapGestureRecognizer;
- (void)pushFullDiscussionVC:(UIView *)sender;
- (void)orderCurrentArticle:(void(^_Nullable)(void))completion;
- (void)requestFullArticle;
- (void)dismiss;
- (BOOL)showCommentsButton;
- (void)reloadView;
- (BOOL)processTapOnByline;
- (void)getMastheadForByline:(void(^)(UIImage * _Nullable))completion;
- (void)discloseInterest:(Interest *)interest;

@property (nonatomic, readonly) FeedItemAction *feedItemAction;
@property (nonatomic, readonly) CGFloat topContentOffset;
@property (nullable, nonatomic, readonly) NSArray<NSString *> *textToHighlight;

@end

@interface VerticalTextFlowArticleDetailsView : UIView <UIGestureRecognizerDelegate>

+ (CGFloat)textWidthWithViewSize:(CGSize)viewSize;

- (void)setLoadingArticleContent:(BOOL)loadingArticleContent error:(nullable NSError *)error;

- (void)loadStackViewWithNavBarHeight:(CGFloat)navBarHeight
                           isUserPost:(BOOL)isUserPost
                    isPublicationPost:(BOOL)isPublicationPost
                             viewSize:(CGSize)viewSize;

- (void)loadHorizontalActionMenu;
- (void)removeStackView;

- (void)onViewDidAppear;

- (void)updateActionVote;
- (void)updateTitleText;
- (void)updateCommentsCounter;

- (void)adjustFonts;
- (void)contentSizeCategoryChanged;
- (void)fontSliderValueChanged;

- (void)onScrollViewDidScroll;
- (void)bouncePrefImageViewWithContentOffset:(CGPoint)contentOffset;
- (void)resetPrefImageViewTransform;

- (void)toggleCommentPostButton;

- (BOOL)navigationBarShouldBeTransparent;

- (void)updateContentInsets;

@property (nonatomic) BOOL prefersTransparentNavigationBar;
@property (nullable, nonatomic, strong) id<PRFlowArticle> article;
@property (nullable, nonatomic, strong) NSArray<AdBannerPresentation *> *ads;

@property (nullable, nonatomic, weak) UIViewController<VerticalTextFlowArticleDetailsViewDelegate> *delegate;
@property (nullable, nonatomic, weak) id<UIScrollViewDelegate> scrollViewDelegate;
@property (nullable, nonatomic, weak) id<PRCommentsViewDelegate> commentsDelegate;
@property (nullable, nonatomic, weak) id<PRPhotoCollageDelegate> photoCollageDelegate;
@property (nullable, nonatomic, weak) UIViewController<UIPopoverPresentationControllerDelegate> *actionMenuPresenter;

@property (nonatomic, readonly) CGSize prefImageViewSize;
@property (nullable, nonatomic, readonly) UIImage *prefImage;

@property (nonatomic, readonly) UIScrollView *scrollView;
@property (nonatomic, readonly) PRMenuVC *horizontalActionMenuVC;

@property (nonatomic, getter=isSubscriptionRequired) BOOL subscriptionRequired;

@property (nonatomic, strong, readonly) TranslationView *translationView;

@end


@class PRAnnotationView;
@class PRAlignedImageView;
@class PRTextViewWithViewAttachment;

@interface VerticalTextFlowArticleDetailsView (/*PROTECTED*/)

- (PRAnnotationView *)annotationViewWithText:(NSString *)text
                                    viewSize:(CGSize)viewSize;

- (void)setNeedsUpdateBodyText;
- (UITapGestureRecognizer *)tapGestureRecognizerWithSelector:(SEL)selector;

- (NSAttributedString *)stringWithAttachment:(UIView *)view
                      appendVerticalPaddings:(BOOL)appendVerticalPaddings;

@property(nonatomic, readonly) NSTextAlignment textAlignment;
@property (nonatomic, readonly) CGFloat lineHeightMultiple;

@property (nonatomic, readonly) BOOL isAuthorizationRequiredToRead;

@property (nullable, nonatomic, strong) UIFont *bodyFont;
@property (nullable, nonatomic, strong) UIFont *fontForCaption;

@property (nullable, nonatomic, strong) NSString *dropcap;
@property (nullable,nonatomic, strong) NSString *textBlockWithDropcap;

@property (nonatomic, strong) NSArray<PRAnnotationView *> *bodyAnnotationViews;
@property (nonatomic, strong) NSArray<UIView *> *bodyPlaceholders;
@property (nonatomic, strong) NSArray<WKWebView *> *bodyWebViews;
@property (nonatomic, strong) NSArray<UIView *> *bodyAds;

@property (nonatomic, weak) PRAlignedImageView *prefImageView;
@property (nonatomic) CGSize viewSize;
@property (nonatomic) CGFloat textWidth;
@property (nonatomic) CGFloat bodyImageWidth;
@property (nonatomic, weak) PRTextViewWithViewAttachment *bodyTextView;

@property (nonatomic, readonly) CGPoint offscreenOrigin;

@end

NS_ASSUME_NONNULL_END
