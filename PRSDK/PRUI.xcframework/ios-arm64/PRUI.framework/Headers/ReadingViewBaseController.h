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
@import PRUIKit.PRNavigationBarManagementProtocol;
@import PRUIKit.PRVC;

#define SWITCH_TABBAR_HEIGHT 58
#define SWITCH_TABBAR_HEIGHT_COMPACT 40
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

@interface ReadingViewBaseController : PRVC <UIScrollViewDelegate, PRNavigationBarManagementProtocol>
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
@property (nonatomic, getter=isViewVisible) BOOL viewVisible;
@property (nonatomic, getter = areBarsHidden) BOOL barsHidden;
@property (nonatomic) BOOL hideBarsOnAppear;
@property (nonatomic, strong, readonly) NTFMyLibraryItemDataSource *mliDataSource;
@property (nonatomic) BOOL shouldDismissBarsImmediately;
@property (nonatomic, readonly) PRMenu *bottomBarMenu;

@end

typedef enum {
    ReadingViewTypePDF = 0,
    ReadingViewTypeText
} ReadingViewType;

@interface ReadingViewBaseController (Slider) <PRPagesSliderDelegate>

- (void)InitSlider;
- (void)deallocSlider;
- (void)offscreenSlider:(BOOL)offscreen;
- (void)displaySlider:(BOOL)makeVisible;
- (void)updatePreviewPosition:(PRSmartFlowPreview *)preview;
- (void)displaySlider:(BOOL)makeVisible animated:(BOOL)animated;
- (void)switchToView:(ReadingViewType)viewId showParameters:(NSDictionary *)showParameters;
- (void)refreshBottomBar;

@property (nonatomic) BOOL isSliderVisible;
@property (nonatomic, readonly) UIView *bottomBar;
@property (nonatomic, readonly) PRMenuBottomBar *menuBottomBar;

@end

@interface ReadingViewBaseController (/*PROTECTED*/)

- (void)reloadBottomMenuBar;

@property (nonatomic, strong) UIButton *readingModeSwitchButton;

@end
