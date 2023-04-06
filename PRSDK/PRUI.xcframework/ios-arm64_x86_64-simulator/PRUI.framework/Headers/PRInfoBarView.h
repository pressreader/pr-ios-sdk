//
//  InfoBarView.h
//  PRiphone
//
//  Created by berec on 12/29/12.
//  Copyright (c) 2012 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum {
    PRInfoBarViewStyleDefault = 0,
    PRInfoBarViewStyleValue1,
    PRInfoBarViewStyleSubtitle,
    PRInfoBarViewStyleSubtitleWithMultilineTitle,
    PRInfoBarViewStyleSubtitleWithMultilineTitleBig,
    PRInfoBarViewStyleKiosk,
    PRInfoBarViewStyleMini
}PRInfoBarViewStyle;

@class PRInfoBarView;

@protocol PRInfoBarDelegate <NSObject>
@optional
- (void)infoBar:(PRInfoBarView *)infoBar recommendedHeightChanged:(CGFloat)recommendedHeight;
@end

@interface PRInfoBarView : UIView

- (instancetype)initWithFrame:(CGRect)frame style:(PRInfoBarViewStyle)style;
- (CGFloat)recommendedHeight;
- (void)switchDetailsComponents;

@property (nonatomic, strong) NSString *titleText;
@property (nonatomic, strong) NSString *detailsText;
@property (nonatomic, strong) NSAttributedString *titleAttributedText;
@property (nonatomic, strong) NSAttributedString *detailsAttributedText;
@property (nonatomic, strong) NSArray *detailsAttributedTextComponents;
@property (nonatomic, strong) NSArray *detailsAttributedTextComponents2;
@property (nonatomic, assign) NSInteger numberOfDetailsLine;
@property (nonatomic) BOOL useDetailComponents2;
@property (nonatomic, strong) UIColor *titleColor;
@property (nonatomic) BOOL touchesAllowed;
@property (nonatomic) PRInfoBarViewStyle style;
@property (nonatomic, copy) NSArray *accessoryViews;
@property (nonatomic, strong) UIView *indicatorView;
@property (nonatomic, strong) UIView *indicatorView2;
@property (nonatomic, readonly) CGRect titleLabelFrame;
@property (nonatomic, readonly) CGRect detailLabelFrame;
@property (nonatomic, strong) UIButton *downloadButton;
@property (nonatomic, strong) UIView *progressView;
@property (nonatomic, weak) id<PRInfoBarDelegate> delegate;
@property (nonatomic, assign) UIEdgeInsets contentInsets;
@property (nonatomic) CGFloat rowDelimiterHeight;

// for adjusting accessory view's position
@property (nonatomic) CGFloat accessoryViewRightOffset;

@end


@interface PRInfoBarView  (/*ImageView*/)
@property (nonatomic, strong) UIImageView *imageView;
@property (nonatomic, strong) UIImage *image;
@property (nonatomic, assign) CGSize imageSize;
@property (nonatomic, assign) UIEdgeInsets imageInsets;
@property (nonatomic, strong) UIView *ribbonView;
@end
