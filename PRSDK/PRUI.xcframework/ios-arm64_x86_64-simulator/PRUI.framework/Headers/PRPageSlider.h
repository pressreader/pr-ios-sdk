//
//  PRPageSlider.h
//  PRiphone
//
//  Created by Dmitry Melnik on 10-07-28.
//  Copyright 2010 NewspaperDirect. All rights reserved.
//

@import UIKit;

@class SectionLabel;
@class SliderSpreadPlace;
@class ThumbSpreadRenderTask;
@class ThumbsSpread;
@class SliderSpreadPlace;
@class PageSliderWrapperView;
@class PRMyLibraryItem;

extern NSNotificationName const PRPageChangeNotification;

extern NSNotificationName const PRPageSliderPageChangeNotification;
extern NSNotificationName const PRPageSliderActivityStartNotification;
extern NSNotificationName const PRPageSliderContentDidScrollNotification;

@protocol PRPageSliderDelegate <NSObject>
- (void)pageSliderWillAppear;
- (void)pageSliderWillDisappear;
@optional
- (void)pageSliderDidAppear;
- (void)pageSliderDidDisappear;
@end

@interface PRPageSlider : UIScrollView<UIScrollViewDelegate>

- (instancetype)initWithFrame:(CGRect)frame mli:(PRMyLibraryItem *)mli;

- (BOOL)changePage:(int)page;
- (void)cancelCurrentDecelerationIfAny;

- (void)activate:(BOOL)activate animated:(BOOL)animated;
- (BOOL)showPanelAnimated:(BOOL)animated completion:(void (^)(BOOL finished))completion;
- (BOOL)hidePanelAnimated:(BOOL)animated completion:(void (^)(BOOL finished))completion;

@property (nonatomic) CGFloat scrollOffset;
@property (nonatomic, weak) id<PRPageSliderDelegate> slideDelegate;
@property (nonatomic, assign) NSInteger curPage;
@property (nonatomic, assign) BOOL rightToLeft;
@property (nonatomic, readonly) NSInteger leftFilledSpreadPlace;
@property (nonatomic, readonly) NSInteger rightFilledSpreadPlace;
@property (nonatomic) BOOL isPlaceholder;
@property (nonatomic, weak) PageSliderWrapperView *wrapperView;
@property (nonatomic, assign, readonly) BOOL isActive;
@property (nonatomic, readonly) CGFloat fullHeight;

@end
