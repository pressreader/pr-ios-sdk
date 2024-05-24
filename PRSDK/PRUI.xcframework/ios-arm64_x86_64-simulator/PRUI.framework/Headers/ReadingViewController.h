//
//  ReadingViewController.h
//  PressReader
//
//  Created by Vitali Bouinine on 20/09/10.
//  Copyright 2010 NewspaperDirect. All rights reserved.
//

#import "ReadingViewBaseController.h"

#import <MessageUI/MessageUI.h>
#import <PRUI/PageSmartMarkerController.h>

@class PRTitleToolbar;
@class NTFActionMenuProvider;

NS_ASSUME_NONNULL_BEGIN

@interface ReadingViewController : ReadingViewBaseController <MFMailComposeViewControllerDelegate, PRPageSmartMarkerDelegate, UIPopoverPresentationControllerDelegate>

- (void)switchToPage:(NSUInteger)page;
- (void)switchToPage:(NSUInteger)page withZoom:(CGFloat)scale alignToArticle:(NSString *)artID;
- (BOOL)isDislpayingPage:(NSUInteger)page;
- (BOOL)actionButtonEnabled;

- (BOOL) translationSupported;
- (CGRect)frameForPageAtIndex:(NSUInteger)index;
- (CGSize)contentSizeForPagingScrollView;
- (NSUInteger)pageViewIndexForPage:(NSUInteger)page;
- (NSUInteger)pageViewIndexForPage:(NSUInteger)page doubleViewMode:(BOOL)doubleViewMode;
- (NSUInteger)pageViewSubIndexForPage:(NSUInteger)page doubleViewMode:(BOOL)doubleViewMode;
- (NSUInteger)pageNumberForPageViewIndex:(NSUInteger)pageIndex subIndex:(NSUInteger)subIndex doubleViewMode:(BOOL)doubleViewMode;
- (PRPDFScrollView *)pageViewForPageNo:(NSUInteger)page;
- (void)showPages;

// For preview actions
- (void) ListenArticleWithID:(NSString *)articleID;
- (void) printAsTextArticleWithID:(NSString *)articleID;
- (void) printAsImageArticleWithID:(NSString *)articleID;

- (void)refreshContentSize;

@property (nonatomic, readonly) BOOL isInDoublePageMode;
@property (nonatomic, readonly) BOOL isTranslateActionAvailableInActionSheet;
@property (nonatomic, readonly) UIScrollView *pagingScrollView;
@property (nonatomic, strong) NSUserActivity *activity;
@property (nonatomic, strong, readonly) NTFActionMenuProvider *actionMenuProvider;

@end

@interface ReadingViewController (/*PROTECTED*/)

- (void)configurePageView:(PRPDFScrollView *)pageView
                 forIndex:(NSUInteger)index
                    scale:(CGFloat)scale
                   offset:(CGPoint)offset;
- (PRPDFScrollView *)pdfScrollViewWithCurrentItem;

@property (nonatomic, readonly) BOOL isFullScreenDisabled;

@end

NS_ASSUME_NONNULL_END
