//
//  VerticalTextFlowVC_Protected.h
//  PRiphone
//
//  Created by Viacheslav Soroka on 3/22/17.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

#ifndef VerticalTextFlowVC_Protected_h
#define VerticalTextFlowVC_Protected_h

#import <PRUI/VerticalTextFlowVC.h>

#import "VerticalTextFlowBaseCell.h"
#import "VerticalTextFlowView.h"

#import "NTFArticleCompactView.h"

@class PRBlockHandlersQueue;

#import "NTFActionMenuProvider.h"

#import "PRScrollSpeedTracker.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSUInteger, VerticalTextFlowVCPreference) {
    VerticalTextFlowVCPreferenceNone = 0,
    //VerticalTextFlowVCPreferenceLayoutV2 = 1 << 0,
    VerticalTextFlowVCPreferenceSingleIssue = 1 << 1,
    VerticalTextFlowVCPreferenceLayoutSectional = 1 << 2,
    VerticalTextFlowVCPreferenceArticleBylineStyleTraditional = 1 << 3,
    VerticalTextFlowVCPreferenceContentPartialRenderingOptimisationDisabled = 1 << 4,
    VerticalTextFlowVCPreferenceDataSilentLoadingDisabled = 1 << 5,
    VerticalTextFlowVCPreferenceRefreshControlEnabled = 1 << 6,
    VerticalTextFlowVCPreferenceBottomBarHidden = 1 << 7,
    VerticalTextFlowVCPreferenceScrollAnimationEnabled = 1 << 8
};

@class PRActionMenuVC;
@class FeedItemAction;
@class TranslationView;

@interface VerticalTextFlowVC () <UITableViewDelegate, UITableViewDataSource,
                                  UIPopoverPresentationControllerDelegate,
                                  VerticalTextFlowViewDelegate>

- (void)showActionMenu:(UIBarButtonItem *)actionButton;
- (void)setupDefaultValues;

// Cells
- (void)registerCells;
- (BOOL)isIndexPathForMoreCell:(NSIndexPath *)indexPath;
- (UITableViewCell *)loadMoreCellForTableView:(UITableView *)tableView;

// Notification handlers
- (void)registerObservers;
- (void)contentSizeCategoryChanged:(NSNotification *)notification;

// Activity indicator
- (void)showActivityIndicator;
- (void)hideActivityIndicator;

// Actions
- (void)onRefreshControl:(UIRefreshControl *)sender;
- (void)fontSliderValueChanged:(UISlider *)slider;

- (void)presentDetailsVCForArticle:(id<NTFArticle>)item NS_SWIFT_NAME(presentDetailsVC(item:));

- (void)refreshBottomBar;
- (void)processSizeChange;
- (void)onLayoutDidChange;

- (PRActionMenuVC *)showActionMenu:(PRMenu *)actionMenu sender:(id)sender;
- (PRActionMenuVC *)showActionMenu:(PRMenu *)actionMenu arrowDirection:(UIPopoverArrowDirection)arrowDirection sender:(id)sender;

@property (nonatomic, copy) NSString *(^cellIdProvider)(NSInteger rowIdx);

@property (nonatomic, copy) void(^willBeginDraggingHandler)(UIScrollView *scrollView);
@property (nonatomic, copy) void(^didScrollHandler)(UIScrollView *scrollView);
@property (nonatomic, copy) void(^didEndDraggingHandler)(UIScrollView *scrollView, BOOL decelerate);

@property (nonatomic, strong) FeedItemAction *feedItemAction;

@property (nonatomic) VerticalTextFlowVCPreference preferences;
@property (nonatomic, readonly) NTFArticleCompactViewOption articleCompactViewOptions;

@property (nonatomic, strong) PRBlockHandlersQueue *endDecelerationHandlers;

@property (nonatomic, strong) PRScrollSpeedTracker *speedTracker;

@property (nonatomic, strong) NSDictionary<NSNumber *, NSString *> *cellIds;

@property (nonatomic, strong) NTFActionMenuProvider *actionMenuProvider;

/// default value is 1 sec to prevent multiple clicks effect
@property (nonatomic) NSTimeInterval updateBookmarkStatusDelay;

@property (nonatomic, readonly) BOOL shouldHideBarsOnSwipe;
@property (nonatomic, readonly) BOOL isCompact;
@property (nonatomic, readonly) BOOL firstCellNeedsTopInset;
@property (nonatomic) BOOL isLoadingInProgress;

@property (nullable, nonatomic, strong) NSString *currentLanguageISOCode;
@property (nullable, nonatomic, strong, readonly) TranslationView *translationView;

@end

NS_ASSUME_NONNULL_END

#endif /* VerticalTextFlowVC_Protected_h */
