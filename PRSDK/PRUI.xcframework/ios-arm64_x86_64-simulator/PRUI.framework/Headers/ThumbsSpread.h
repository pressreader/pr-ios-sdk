//
//  ThumbsSpread.h
//  PRiphone
//
//  Created by Dmitry Melnik on 10-07-28.
//  Copyright 2010 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

@class PRMyLibraryItem;
@class SliderSpreadPlace;
@class TipBalloon;
@class PRFocusableView;
@class ThumbSpreadRenderTask;

@interface ThumbsSpread : UIImageView

@property (nonatomic, assign) BOOL twoPages;
@property (nonatomic, assign) BOOL rightToLeft;
@property (nonatomic, assign) CGFloat thumbHeight;
@property (atomic, retain) UIImage* rendered; // It made atomic on purpose. It can be reassigned from back thread.

- (instancetype)initWithMli:(PRMyLibraryItem *)amli paperColor:(UIColor *)paperColor;

- (void)setupWithSpreadPlace:(SliderSpreadPlace *)sp;
- (void)cancelCurrentBackgroundOp;

- (BOOL)IsSelected;
- (void)Select:(BOOL)dosel;

- (CGFloat)GetPageX:(int)page leftEdge:(BOOL)leftEdge;

@end
