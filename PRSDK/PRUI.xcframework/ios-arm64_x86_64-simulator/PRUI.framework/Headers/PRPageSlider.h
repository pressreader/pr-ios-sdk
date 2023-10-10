//
//  PRPageSlider.h
//  PRiphone
//
//  Created by Dmitry Melnik on 10-07-28.
//  Copyright 2010 NewspaperDirect. All rights reserved.
//

@import UIKit;

#import "SliderControlProto.h"


@protocol PRPagesSliderProto
- (void) OnPageSelect:(int)index;
@optional
- (void) OnUpdate;
@end

@class SectionLabel;
@class SliderSpreadPlace;
@class ThumbSpreadRenderTask;
@class ThumbsSpread;
@class SliderSpreadPlace;
@class PageSliderWrapperView;

@protocol PRPagesSliderDelegate <NSObject>
- (void)pageSliderWillAppear;
- (void)pageSliderWillDisappear;
@optional
- (void)pageSliderDidAppear;
- (void)pageSliderDidDisappear;
@end

@interface PRPagesSlider : UIScrollView<UIScrollViewDelegate, SliderControlProto>

@property (nonatomic, weak) id<PRPagesSliderDelegate> slideDelegate;
@property (nonatomic, assign) NSInteger curPage;
@property (nonatomic, readonly) CGRect desiredFrame;
@property (nonatomic, readonly) CGRect zeroFrame;
@property (nonatomic, assign) BOOL rightToLeft;
@property (nonatomic, readonly) NSInteger leftFilledSpreadPlace;
@property (nonatomic, readonly) NSInteger rightFilledSpreadPlace;
@property (nonatomic) BOOL isPlaceholder;
@property (nonatomic, weak) PageSliderWrapperView *wrapperView;

// init
- (instancetype) initWithFrame:(CGRect)frame amli:(id)amli;
- (void)setupFrames:(CGRect)frame;

- (CGFloat) fullHeight;
- (BOOL)showPanelAnimated:(BOOL)animated completion:(void (^)(BOOL finished))completion;
- (BOOL)hidePanelAnimated:(BOOL)animated completion:(void (^)(BOOL finished))completion;

// events
- (void) OnSelectSpread:(id)sender;

@end
