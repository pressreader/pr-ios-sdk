//
//  PRSmartMarkerViewController.h
//  PRiphone
//
//  Created by devuser on 06/03/09.
//  Copyright 2009 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TouchViewController.h"

@protocol PRSmartMarkerControllerDelegate <NSObject, TouchViewControllerDelegate>
- (void)tapOnSmartObject:(id)smartObject fromView:(UIView *)view;
- (void)tapOnCommentCounter:(id)smartObject fromView:(UIView *)view;
@end

typedef enum {
    ArticleMarkerStyleDefault = 0,
    ArticleMarkerStylePale,
    ArticleMarkerStyleNone
} ArticleMarkerStyle;

@interface PRSmartMarkerViewController : TouchViewController
- (instancetype)initWithFrame:(CGRect)frame delegate:(id<PRSmartMarkerControllerDelegate>)delegate smartButtonType:(UIButtonType)type;
- (void)applyArticleMarkerStyle:(ArticleMarkerStyle)style;
- (void)applyHighlightAnimation;
- (void)setBackground:(UIColor*)color alpha:(CGFloat)alpha;
- (void)setGradientWithTopColor:(UIColor*)topColor bottomColor:(UIColor*)bottomColor;
- (void)setBorderWidth:(CGFloat)borderWidth color:(UIColor *)borderColor;
- (void)setBottomBorderWithColor:(UIColor *)borderColor;
- (void)setCornerRadius:(CGFloat)cornerRadius;
- (void)setShadowOffset:(CGSize)shadowOffset shadowColor:(UIColor *)shadowColor shadowOpacity:(CGFloat)shadowOpacity;
- (void)showPlayButton;
- (void)showMediaContentThumbnail:(UIImage *)image;
- (void)setCommentsCounter:(NSUInteger)numComments isNegativeVote:(BOOL)negative fontSize:(CGFloat)fontSize;
- (void)showCommentsCounter;
- (void)removeCommentsCounter;
- (void)updateCommentsCounterWithFontSize:(CGFloat)fontSize;

@property (nonatomic, assign) BOOL disappearOnTap;
@property (nonatomic, assign) BOOL useAnimation;

@end
