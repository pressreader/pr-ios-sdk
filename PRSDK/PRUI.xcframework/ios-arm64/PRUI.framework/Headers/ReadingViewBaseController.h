//
//  ReadingViewBaseController.h
//  PRiphone
//
//  Created by Dmitry Melnik on 10-11-15.
//  Copyright 2010 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <PRUI/PRPageSlider.h>

@import PRUIKit;

@class PRPDFScrollView;

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

NS_ASSUME_NONNULL_BEGIN

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

- (instancetype)initWithItem:(NSObject<ReadingViewItem> * _Nonnull)item;
- (void)switchToPage:(NSUInteger)page;
- (NSUInteger)currentPageIndex;
- (NSUInteger)numberOfPageViews;
- (void)showTextView:(NSInteger)page aID:(NSString* _Nullable)aID animated:(BOOL)animated;
- (PRPDFScrollView * _Nullable)dequeueRecycledPage;
- (PRPDFScrollView * _Nullable)pageViewForIndex:(NSUInteger)index;
- (PRPDFScrollView * _Nullable)currentPageView;
- (void)recyclePage:(PRPDFScrollView *)page;
- (BOOL)isDisplayingPageForIndex:(NSUInteger)index;
- (void)removeRecycledPages;
- (void)hideSmartMarkers:(BOOL)hide;
- (void)dismiss;

@property (nonatomic) NSUInteger currentPage;
@property (nonatomic) NSUInteger numberOfPages;

@property (nonatomic, readonly) BOOL isWaitingForDelayedBarsHiding;
- (void)hideBarsWithDelayIfAlreadyWaiting;

@property (nullable, nonatomic, copy) NSString * currentArtID;
@property (nullable, nonatomic, strong) PDFDoc *pdfDoc;
@property (nullable, nonatomic, strong) NSMutableSet<PRPDFScrollView *> *visiblePages;
@property (nullable, nonatomic, readwrite, strong) NSMutableSet<PRPDFScrollView *> *recycledPages;
@property (nonatomic, strong, readonly) NSObject<ReadingViewItem> *item;
@property (nullable, nonatomic, strong, readonly) NSObject<PRSmartLayoutItem> *smartLayoutItem;
@property (nullable ,nonatomic, strong, readonly) PRMyLibraryItem *mli;

@property (nullable, nonatomic, strong) UIColor *defaultTintColor;
@property (nullable, nonatomic, strong) NSArray<NSArray *> *sections;
@property (nullable, nonatomic, strong) NSObject *sliderSyncronizator;
@property (nullable, nonatomic, strong) PRSmartFlowPreview *textPreview;
@property (nonatomic, assign, readonly) BOOL isViewVisible;
@property (nonatomic, assign, readonly) BOOL barsHidden;
@property (nonatomic) BOOL hideBarsOnAppear;
@property (nullable, nonatomic, readonly) NTFMyLibraryItemDataSource *mliDataSource;
@property (nonatomic) BOOL shouldDismissBarsImmediately;
@property (nullable, nonatomic, readonly) PRMenu *bottomBarMenu;

@end

typedef enum {
    ReadingViewTypePDF = 0,
    ReadingViewTypeText
} ReadingViewType;

@interface ReadingViewBaseController (Slider) <PRPageSliderDelegate>

- (void)InitSlider;
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
@property (nonatomic, readonly) CGFloat bottomBarHeight;

@end

@interface ReadingViewBaseController (/*PROTECTED*/)

- (void)reloadBottomMenuBar;
- (void)cancelDelayedBarsHidding;
- (void)setBarsHidden:(BOOL)hidden animated:(BOOL)animated onUserTap:(BOOL)onUserTap;

@property (nullable, nonatomic, strong) UIButton *readingModeSwitchButton;

@end

NS_ASSUME_NONNULL_END
