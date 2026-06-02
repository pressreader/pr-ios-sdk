//
//  ReadingViewController.h
//  PressReader
//
//  Created by Vitali Bouinine on 20/09/10.
//  Copyright 2010 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <PRUI/PRPageSlider.h>

#import <PRUIKit/PRUIKit.h>

#import <MessageUI/MessageUI.h>
#import <PRUI/PageSmartMarkerController.h>

@class PRPDFScrollView;
@class PRMyLibraryItem;
@class PRSmartFlowPreview;
@class NTFMyLibraryItemDataSource;
@class PRMenuBottomBar;
@class PRProgressView;

@protocol ReadingViewItem;
@protocol PRCatalogItem;

NS_ASSUME_NONNULL_BEGIN

typedef NSObject<ReadingViewItem, PRCatalogItem>* PRReadableCatalogItem;

#define SWITCH_TABBAR_HEIGHT 49
#define SWITCH_TABBAR_HEIGHT_COMPACT 35
#define SECTION_SLIDER_SHADOW_HEIGHT 5
#define READING_VC_SWITCH_DOUBLE_PAGE_BARBUTTON_TAG 4
#define HIDE_SMART_MARKERS_IN_FULLSCREEN_MODE NO

@interface ReadingViewController : PRVC <UIScrollViewDelegate, NavigationBarDismissable, MFMailComposeViewControllerDelegate, PRPageSmartMarkerDelegate, UIPopoverPresentationControllerDelegate>
{
    BOOL            m_pageChangeFromEvent;
    BOOL            inAlert;
    BOOL            isClosed;
    BOOL            m_textViewIsReady;
    BOOL            m_sliderWasInited;
    NSUInteger      nextPageSeg;
    NSUInteger      prevPageSeg;
}

- (instancetype)initWithItem:(PRReadableCatalogItem)item;
- (void)switchToPage:(NSUInteger)page;
- (void)switchToPage:(NSUInteger)page withZoom:(CGFloat)scale alignToArticle:(NSString *)artID;

- (NSUInteger)numberOfPageViews;
- (void)showTextView:(NSInteger)page aID:(NSString *_Nullable)aID animated:(BOOL)animated;
- (PRPDFScrollView *_Nullable)currentPageView;

- (CGRect)frameForPageAtIndex:(NSUInteger)index;
- (CGSize)contentSizeForPagingScrollView;
- (NSUInteger)pageViewIndexForPage:(NSUInteger)page;
- (NSUInteger)pageViewIndexForPage:(NSUInteger)page doubleViewMode:(BOOL)doubleViewMode;
- (NSUInteger)pageViewSubIndexForPage:(NSUInteger)page doubleViewMode:(BOOL)doubleViewMode;
- (NSUInteger)pageNumberForPageViewIndex:(NSUInteger)pageIndex subIndex:(NSUInteger)subIndex doubleViewMode:(BOOL)doubleViewMode;
- (PRPDFScrollView *)pageViewForPageNo:(NSUInteger)page;

- (void)refreshContentSize;

@property (nonatomic) NSUInteger currentPage;
@property (nonatomic) NSUInteger numberOfPages;

@property (nullable, nonatomic, copy) NSString * currentArtID;
@property (nullable, nonatomic, strong) NSMutableSet<PRPDFScrollView *> *visiblePages;
@property (nonatomic, strong, readonly) PRReadableCatalogItem item;
@property (nullable ,nonatomic, strong, readonly) PRMyLibraryItem *mli;

@property (nullable, nonatomic, strong) NSArray<NSArray *> *sections;
@property (nullable, nonatomic, strong) NSObject *sliderSyncronizator;
@property (nullable, nonatomic, strong) PRSmartFlowPreview *textPreview;
@property (nonatomic, assign, readonly) BOOL barsHidden;
@property (nullable, nonatomic, readonly) NTFMyLibraryItemDataSource *mliDataSource;

@property (nonatomic, readonly) BOOL isInDoublePageMode;
@property (nonatomic, strong, readonly) UIScrollView *pagingScrollView;
@property (nullable, nonatomic, strong) UIImageView *mastheadImageView;
@property (nonatomic, readonly) BOOL pageViewLoaded;

@end

typedef enum {
    ReadingViewTypePDF = 0,
    ReadingViewTypeText
} ReadingViewType;

@interface ReadingViewController (Slider) <PRPageSliderDelegate>

- (void)initSlider;
- (void)deallocSlider;
- (void)offscreenSlider:(BOOL)offscreen;
- (void)updatePreviewPosition:(PRSmartFlowPreview * _Nullable)preview;
- (void)displaySlider:(BOOL)makeVisible;
- (void)displaySlider:(BOOL)makeVisible animated:(BOOL)animated;
- (void)displayPageSlider:(BOOL)makeVisible;
- (void)displayPageSlider:(BOOL)makeVisible animated:(BOOL)animated;
- (void)switchToView:(ReadingViewType)viewId showParameters:(NSDictionary * _Nullable)showParameters;
- (void)refreshBottomBar;

@property (nonatomic, readonly) BOOL isSliderVisible;
@property (nullable, nonatomic, readonly) PRMenuBottomBar *menuBottomBar;
@property (nullable, nonatomic, readonly) PRPageSlider *pageSlider;
@property (nullable, nonatomic, readonly) PRProgressView *progressView;
@property (nonatomic, readonly) CGFloat bottomBarHeight;

@end

@interface ReadingViewController (/*PROTECTED*/)

- (void)reloadBottomMenuBar;
- (void)cancelDelayedBarsHidding;
- (void)setBarsHidden:(BOOL)hidden animated:(BOOL)animated onUserTap:(BOOL)onUserTap;

- (void)configurePageView:(PRPDFScrollView *)pageView
                 forIndex:(NSUInteger)index
                    scale:(CGFloat)scale
                   offset:(CGPoint)offset;

- (PRPDFScrollView *)pdfScrollViewWithCurrentItem;
- (void)updateTitle;

@property (nullable, nonatomic, strong) UIButton *readingModeSwitchButton;
@property (nonatomic) BOOL shouldDismissBarsImmediately;
@property (nonatomic, readonly) BOOL isTextViewEnabled;
@property (nonatomic, readonly) BOOL isFullScreenDisabled;

@end

NS_ASSUME_NONNULL_END
