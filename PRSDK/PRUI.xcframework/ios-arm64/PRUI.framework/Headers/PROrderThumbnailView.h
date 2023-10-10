//
//  PROrderThumbnailView.h
//  PRiphone
//
//  Created by Jackie Cane on 24/01/14.
//  Copyright (c) 2014 NewspaperDirect. All rights reserved.
//

#import "PRInfoBarView.h"
#import "PRProgressView.h"
@import PRAPI.PRTitleItemExemplar;
#import "PROrderThumbNailDelegate.h"
#import "PROrderInfoBarView.h"

NS_ASSUME_NONNULL_BEGIN

extern const CGFloat kPRCompactInfoBarHeight;
extern const CGFloat kPRFollowViewHeight;
extern const CGFloat kPRCompactSidePadding;
extern const CGFloat kPRFollowViewCompactPadding;

typedef NS_ENUM(uint8_t, PROrderThumbnailInfoBarStyle) {
    PROrderThumbnailInfoBarStyleRegular = 0,
    PROrderThumbnailInfoBarStyleCompact,
    PROrderThumbnailInfoBarStyleFollow,
    PROrderThumbnailInfoBarStyleEmpty
};

@class PRProgressButton;
@class PRSwitchButton;

@interface PROrderThumbnailView : UIView

+ (instancetype)viewWithCID:(NSString *)cid;

- (instancetype)initWithCID:(nullable NSString *)cid NS_DESIGNATED_INITIALIZER;

- (void)showActivityIndicator:(BOOL)show;
- (void)setThumbnailBackgroundColor:(UIColor *)thumbnailBackgroundColor;
- (void)setThumbnailImage:(UIImage *)thumbnailImage;

/// Prepares content for auto scaling based on given size.
- (void)adjustForInitialSize:(CGSize)size;

- (void)addHotzoneBanner:(UIView *)banner;
- (void)removeHotzoneBanner:(UIView *)banner;

@property (nonatomic, strong) NSString *CID;

@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *caption;

@property (nonatomic, assign, getter = isThumbnailHidden) BOOL thumbnailHidden;
@property (nonatomic, assign) BOOL hasScroll;
@property (nonatomic, assign) BOOL hasShadow;
@property (nonatomic, assign) BOOL useActityIndicator;
@property (nonatomic, assign) BOOL hasGradient;
@property (nonatomic, assign) PROrderThumbnailInfoBarStyle infoBarStyle;
@property (nonatomic, assign) BOOL infoBarHidden;
@property (nonatomic, assign) BOOL downloadButtonEnabled;
@property (nonatomic, readonly) BOOL needGradient;

@property (nonatomic, assign) NSInteger downloadProgress;
@property (nonatomic, assign) PRTitleItemExemplarState exemplarState;

@property (nonatomic, readonly) PRInfoBarView *infoBar;
@property (nonatomic, readonly) PROrderInfoBarView *compactInfoBar;
@property (nonatomic, readonly) UIButton *progressButton;

@property (nullable, nonatomic, weak) id <PROrderThumbNailDelegate> delegate;

@property (nonatomic, assign) CGFloat imageTopOffset;

@property (nonatomic) BOOL followable;
@property (nonatomic) BOOL following;
@property (nonatomic, copy) void(^followAction)(BOOL);

@property (nonatomic, readonly) UIView *titleView;

@end

NS_ASSUME_NONNULL_END
