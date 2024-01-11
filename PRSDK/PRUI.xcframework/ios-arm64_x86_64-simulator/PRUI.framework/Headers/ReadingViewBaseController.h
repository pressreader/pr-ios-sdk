//
//  ReadingViewBaseController.h
//  PRiphone
//
//  Created by Dmitry Melnik on 10-11-15.
//  Copyright 2010 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

@class PRPDFScrollView;
#import "PRPageSlider.h"
@import PRUIKit;

#define SWITCH_TABBAR_HEIGHT 49
#define SWITCH_TABBAR_HEIGHT_COMPACT 35
#define SECTION_SLIDER_SHADOW_HEIGHT 5
#define READING_VC_SWITCH_DOUBLE_PAGE_BARBUTTON_TAG 4
#define HIDE_SMART_MARKERS_IN_FULLSCREEN_MODE NO

@class PRMyLibraryItem;
@class PRSmartFlowPreview;
@class PDFDoc;
@class NTFMyLibraryItemDataSource;
@class PRMenuBottomBar;
@class PRMenu;

@protocol ReadingViewItem, PRSmartLayoutItem;
@protocol PRCatalogItem;

@interface ReadingViewBaseController : PRVC <UIScrollViewDelegate, NavigationBarDismissable>
{
	BOOL			m_pageChangeFromEvent;
	BOOL			inAlert;
	BOOL			isClosed;
	BOOL            m_textViewIsReady;
    BOOL            m_sliderWasInited;
	NSUInteger		nextPageSeg;
	NSUInteger		prevPageSeg;
}

- (instancetype)initWithItem:(NSObject<ReadingViewItem> *)item;
- (void)switchToPage:(NSUInteger)page;
- (NSUInteger)currentPageIndex;
- (NSUInteger)numberOfPageViews;
- (void)showTextView:(NSInteger)page aID:(NSString*)aID animated:(BOOL)animated;
- (PRPDFScrollView *)dequeueRecycledPage;
- (PRPDFScrollView *)pageViewForIndex:(NSUInteger)index;
- (PRPDFScrollView *)currentPageView;
- (void)recyclePage:(PRPDFScrollView *)page;
- (BOOL)isDisplayingPageForIndex:(NSUInteger)index;
- (void)removeRecycledPages;
- (void)hideSmartMarkers:(BOOL)hide;
- (void)dismiss;

@property (nonatomic) NSUInteger currentPage;
@property (nonatomic) NSUInteger numberOfPages;

@property (nonatomic, readonly) BOOL isWaitingForDelayedBarsHiding;
- (void)hideBarsWithDelayIfAlreadyWaiting;

@property (nonatomic, copy) NSString * currentArtID;
@property (nonatomic, strong) PDFDoc *pdfDoc;
@property (nonatomic, strong) NSMutableSet<PRPDFScrollView *> *visiblePages;
@property (nonatomic, readwrite, strong) NSMutableSet<PRPDFScrollView *> *recycledPages;
@property (nonatomic, strong, readonly) NSObject<ReadingViewItem> *item;
@property (nonatomic, strong, readonly) NSObject<PRSmartLayoutItem> *smartLayoutItem;
@property (nonatomic, strong, readonly) PRMyLibraryItem *mli;

@property (nonatomic, strong) UIColor *defaultTintColor;
@property (nonatomic, strong) NSArray<NSArray *> *sections;
@property (nonatomic, strong) NSObject *sliderSyncronizator;
@property (nonatomic, strong) PRSmartFlowPreview *textPreview;
@property (nonatomic, assign, readonly) BOOL isViewVisible;
@property (nonatomic, assign, readonly) BOOL barsHidden;
@property (nonatomic) BOOL hideBarsOnAppear;
@property (nonatomic, strong, readonly) NTFMyLibraryItemDataSource *mliDataSource;
@property (nonatomic) BOOL shouldDismissBarsImmediately;
@property (nonatomic, readonly) PRMenu *bottomBarMenu;

@end

typedef enum {
    ReadingViewTypePDF = 0,
    ReadingViewTypeText
} ReadingViewType;

@interface ReadingViewBaseController (Slider) <PRPageSliderDelegate>

- (void)InitSlider;
- (void)deallocSlider;
- (void)offscreenSlider:(BOOL)offscreen;
- (void)updatePreviewPosition:(PRSmartFlowPreview *)preview;
- (void)displaySlider:(BOOL)makeVisible;
- (void)displaySlider:(BOOL)makeVisible animated:(BOOL)animated;
- (void)displayPageSlider:(BOOL)makeVisible;
- (void)displayPageSlider:(BOOL)makeVisible animated:(BOOL)animated;
- (void)switchToView:(ReadingViewType)viewId showParameters:(NSDictionary *)showParameters;
- (void)refreshBottomBar;

@property (nonatomic, readonly) BOOL isSliderVisible;
@property (nonatomic, readonly) PRMenuBottomBar *menuBottomBar;
@property (nonatomic, readonly) PRPageSlider *pageSlider;
@property (nonatomic, readonly) CGFloat bottomBarHeight;

@end

@interface ReadingViewBaseController (/*PROTECTED*/)

- (void)reloadBottomMenuBar;
- (void)cancelDelayedBarsHidding;
- (void)setBarsHidden:(BOOL)hidden animated:(BOOL)animated onUserTap:(BOOL)onUserTap;

@property (nonatomic, strong) UIButton *readingModeSwitchButton;

@end
