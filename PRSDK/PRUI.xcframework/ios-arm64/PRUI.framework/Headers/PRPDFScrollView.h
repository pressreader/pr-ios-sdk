//
//  PdfScrollView.h
//  PressReader
//
//  Created by Vitali Bounine on 20/09/10.
//  Copyright 2010 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ReadingMapFrame.h"
#import "PageSmartMarkerController.h"

@class PRSmartMarkerViewController;

NS_ASSUME_NONNULL_BEGIN

@class PRMyLibraryItem;

extern const CGFloat OFFSET_LEFT_PAGE_LEFT_ALIGNED;
extern const CGFloat OFFSET_LEFT_PAGE_RIGHT_ALIGNED;
extern const CGFloat OFFSET_LEFT_PAGE_CENTERED;
extern const CGFloat OFFSET_RIGHT_PAGE_LEFT_ALIGNED;
extern const CGFloat OFFSET_RIGHT_PAGE_RIGHT_ALIGNED;
extern const CGFloat OFFSET_RIGHT_PAGE_CENTERED;

extern NSString *const PageViewReadyNotificaton;
extern NSString *const PageViewMenuButtonTouchedNotification;
extern NSString *const PageViewBeginZoomingNotification;
extern NSString *const PageViewBeginDraggingNotification;
extern NSString *const PageViewHiddenNotification;
extern NSString *const PageViewRemovedNotification;

typedef enum _PAGE_CONTENT_MODE {
	PAGE_CONTENT_ASPECT_FIT = 0,
	PAGE_CONTENT_WIDTH_FIT,
	PAGE_CONTENT_HEIGHT_FIT
} PAGE_CONTENT_MODE;

@class BasePDFView, PageSmartMarkerController, PDFDoc, PageView;

@interface PRPDFScrollView : UIScrollView <UIScrollViewDelegate, ReadingMapOperations, UIGestureRecognizerDelegate> 

@property (nonatomic, readonly, strong) NSObject<ReadingViewItem> *item;
@property (nonatomic, readonly, strong) PRMyLibraryItem *mli;

// Base view contains all other views
// and zoom is always applied to that view
@property (nullable, nonatomic, strong) UIView *baseView;
@property (nonatomic, strong) NSCache *images;
@property (nullable, nonatomic, strong) PDFDoc *pdfDoc;

@property (nonatomic) BOOL doublePageMode;
@property (nonatomic, readonly) CGFloat scale;
@property (nonatomic, readonly) NSUInteger index;
@property (nonatomic, readonly) NSUInteger numberOfPages;

@property (nonatomic, assign) BOOL active;
@property (nonatomic, assign) BOOL visible;

@property (assign) PAGE_CONTENT_MODE pageContentMode;

@property (nonatomic) BOOL smartHidden;
@property (nonatomic) BOOL allowZoomingIfNotActive;
@property (nullable, nonatomic, copy) NSString *artIDtoZoom;
@property (nonatomic) CGFloat initialZoom;

@property (assign) CGPoint restorePoint;
@property (nonatomic, readonly) PRSmartMarkerViewController *biggestArticleMarker;

- (instancetype)initWithItem:(NSObject<ReadingViewItem> *)item;

- (CGRect)frameForPage:(NSUInteger)page inBounds:(CGSize)boundSize scale:(CGFloat)scale;
- (void)loadPage:(NSUInteger)pageIndex withFrame:(CGRect)frame scale:(CGFloat)scale offset:(CGPoint)offset smartMarkerDelegate:(id<PRPageSmartMarkerDelegate>)newDelegate;
- (void)setNewFrame:(CGRect)frame;
- (void)setNewFrame:(CGRect)frame newOffset:(CGPoint)newOffset;
- (void)switchToDoublePageMode:(BOOL)isDblPageMode index:(NSInteger)index  subIndex:(NSInteger)subIndex frame:(CGRect)newFrame;
- (void)unloadPdfPage;

- (BOOL)isContentReady;
- (BOOL)isSmartViewVisible;
- (void)hideSmartView;
- (void)showSmartView;
- (void)refreshArticleMarkers;
- (void)setSmartViewHidden:(BOOL)hideView;
- (void)loadSmartMarker;

- (void)setMaxMinZoomScalesForCurrentBounds;
- (CGFloat)defaultZoomScale;
- (void)zoomToOffset:(CGPoint)offset withScale:(CGFloat)scale animated:(BOOL)animated;
- (void)zoomToPoint:(CGPoint)zoomPoint withScale:(CGFloat)scale animated:(BOOL)animated;
- (BOOL)zoomToArticle:(PRSmartArticle *)article withScale:(CGFloat)scale animated:(BOOL)animated;
- (void)defaultZoomToPoint:(CGPoint)zoomPoint animated:(BOOL)animated;
- (void) defaultZoomToArticle:(PRSmartArticle *)article animated:(BOOL)animated;

- (CGPoint)pointToCenterAfterRotation;
- (CGFloat)scaleToRestoreAfterRotation;
- (void)restoreScale:(CGFloat)scale;
- (void)restoreCenterPoint:(CGPoint)oldCenter scale:(CGFloat)oldScale;
- (CGPoint) offsetToArticle:(NSString *)artID;
- (NSUInteger) pageNoByPoint:(CGPoint)point;
- (PRSmartArticle *)smartArticleByPoint:(CGPoint)point;
- (PRSmartArticle *)smartArticleByPoint:(CGPoint)point textOnly:(BOOL)textOnly;
- (NSArray *)smartArticlesOnPageByPoint:(CGPoint)point;
- (CGRect)smartArticleFrame:(PRSmartArticle *)article textOnly:(BOOL)textOnly;
- (CGPoint) smartArticleOriginByPoint:(CGPoint)point textOnly:(BOOL)textOnly;
- (BOOL)isMostVisiblePageIsRight;
- (BOOL)isUsingTiledPdfView;
- (BOOL)isBlockingScreenshots;

- (void) removeTiledPdfViews;

// printing support
- (void)printPageWithTitle:(NSString *)title footer:(NSString *)footer asBitmap:(BOOL)useBitmap justVisible:(BOOL)justVisibleBox fromBarButtonItem:(nullable UIBarButtonItem *)item;

- (NSUInteger)pageNum;
- (NSUInteger)leftPageNum;
- (NSUInteger)rightPageNum;

- (CGRect)framesForDoublePageWithScale:(CGFloat)scale
                             leftFrame:(nullable CGRect *)pLeftFrame
                            rightFrame:(nullable CGRect *)pRightFrame;
- (PageView *)createViewWithFrame:(CGRect)frame forPage:(NSUInteger)page adjustFrameToFit:(BOOL)adjustFrameToFit;
- (CGFloat)setupSinglePageViewWithScale:(CGFloat)scale;
- (CGFloat)setupDoublePageViewWithScale:(CGFloat)scale;
- (void)scrollViewDidEndZooming:(UIScrollView *)scrollView withView:(nullable UIView *)view atScale:(CGFloat)scale;
- (void)processZoomingForScrollView:(UIScrollView *)scrollView scale:(CGFloat)scale;

- (PRSmartMarkerViewController *)biggestArticleMarkerInRect:(CGRect)rect;

- (void)updateCurrentPageViewsHasCollectionStatus;

@end

@interface PRPDFScrollView (/*PROTECTED*/)
@property (nonatomic, assign) CGFloat scale;
@property (nonatomic) NSUInteger index;

- (NSUInteger)singlePageNum;

@end

NS_ASSUME_NONNULL_END
