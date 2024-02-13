//
//  ArticleDetailsVerticalVC.h
//  PRiphone
//
//  Created by Vitali Bounine on 2016-07-26.
//  Copyright © 2016 NewspaperDirect. All rights reserved.
//

@import PRUIKit.PRVC;
#import "VerticalTextFlowArticleDetailsView.h"

@import PRAPI;

#import "PRArticleContainer.h"

@class PRDismissOnSwipeActor;
@class AdBannerPresentation;
@class TextFlowActivityVC;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(uint8_t, _PRNavigationBarState) {
    _PRNavigationBarStateUndefined = 0,
    _PRNavigationBarStateTransparent,
    _PRNavigationBarStateSolid,
    _PRNavigationBarStateSolidDecorated,
    _PRNavigationBarStateTransitional
};

typedef void(^PRScrollHandler)(UIScrollView *scrollView);

@interface VerticalTextFlowArticleDetailsVC : PRVC <PRArticleContainer>

- (instancetype)initWithArticleItem:(nullable id<FlowArticle>)articleItem;
- (instancetype)initWithArticleItem:(nullable id<FlowArticle>)articleItem highlightedPhrases:(nullable NSArray<NSString *> *)highlightedPhrases;
- (instancetype)initWithNibName:(nullable NSString *)nibNameOrNil
                         bundle:(nullable NSBundle *)nibBundleOrNil NS_UNAVAILABLE;
- (instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;

- (void)setupDefaultNavigationBarAppearance;
- (void)setupTransitionalNavigationBarAppearance;

- (PRMenu *)horizontalActionMenu;

@property (nullable, nonatomic, readonly) VerticalTextFlowArticleDetailsView *rootView;

@property (nonatomic, copy) PRScrollHandler didScrollHandler;
@property (nonatomic, copy) PRScrollHandler scrollFinishHandler;

@property (nonatomic, copy) void(^ _Nullable horizontalActionMenuDidUpdate)(PRMenu *);
@property (nonatomic, copy) void(^ _Nullable moveToNextItem)(void);
@property (nonatomic, copy) void(^ _Nullable moveToPrevItem)(void);

@property (nonatomic, assign) BOOL useParentNavigationItem;

@property (nullable, nonatomic, readonly) UIImage *prefImage;
@property (nullable, nonatomic, readonly) id<FlowArticle> articleItem;

@property (nonatomic, strong, readonly) PRDismissOnSwipeActor *dismissOnSwipeActor;

@property (nonatomic, assign) BOOL subscriptionRequiredToRead;

@property (nonatomic, assign) CGFloat topContentOffset;
@property (nullable, nonatomic, readonly) NSArray<NSString *> *highlightedPhrases;
@property (nonatomic, strong) NSArray<AdBannerPresentation *> *contentAds;

@end


@interface VerticalTextFlowArticleDetailsVC (/*Protected*/)

- (void)updateNavigationBarContent;

@property (nullable, nonatomic, strong) TextFlowActivityVC *activityVC;
@property (nonatomic, strong) UIImage *navigationBarBackgroundGradient;
@property (nonatomic, strong) UIImage *navigationBarBackgroundSemiBlank;

@end

NS_ASSUME_NONNULL_END
