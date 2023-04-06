//
//  PhotoGalleryVC.h
//  PRiphone
//
//  Created by Jackie Cane on 10/10/11.
//  Copyright 2011 NewspaperDirect. All rights reserved.
//
//  Loads images by provided (in init method) URLs.
//  Configures and displays the paging scroll view and handles tiling and page configuration.
//

#import <UIKit/UIKit.h>

@import PRAPI;

NS_ASSUME_NONNULL_BEGIN

extern NSString *kFrame;

@class ImageScrollView;
@class PRImageDetailsCaptionView;

typedef NS_OPTIONS (NSInteger, PRSlideShowStatus) {
    PRSlideShowStatusNotStarted,
    PRSlideShowStatusInProgress,
    PRSlideShowStatusPaused,
    PRSlideShowStatusComplete
};

@interface PhotoGalleryVC : UIViewController <UIScrollViewDelegate> {
    
    UIScrollView *pagingScrollView;
    
    NSMutableSet *recycledPages;
    NSMutableSet *visiblePages;

    // these values are stored off before we start rotation so we adjust 
    // our content offset appropriately during rotation
    int           firstVisiblePageIndexBeforeRotation;
    CGFloat       percentScrolledIntoFirstVisiblePage;
	
	UIBarButtonItem *previousBarButton;
	UIBarButtonItem *nextBarButton;
	UIBarButtonItem *playBarButton;
	
	NSInteger currentPageIndex;
	BOOL playSlideShow;

	NSMutableArray *images;

    // collection of NSURL's objects
    NSArray *imageURLs;
	
	// this set of images is necessary to avoid 
	// downloading object more than one at the same time
	NSMutableSet *downloadingImages;

@private
	NSOperationQueue *operationQueue_;
}

// init with collection of NSURL's objects
- (id)initWithPictureURLs:(NSArray *)pictureURLs;

- (void)refreshScrollView;
- (void)configurePage:(ImageScrollView *)page forIndex:(NSUInteger)index;
- (BOOL)isDisplayingPageForIndex:(NSUInteger)index;

- (CGRect)frameForPagingScrollView;
- (CGRect)frameForPageAtIndex:(NSUInteger)index;
- (CGSize)contentSizeForPagingScrollView;

- (void)tilePages;
- (ImageScrollView *)dequeueRecycledPage;

- (NSUInteger)imageCount;

- (void)hideBars:(BOOL)hide;
- (BOOL)barsAreHidden;
- (void)pagingScrollViewTouchObserver:(NSNotification *)notification;

- (void)previousBarButtonTouch;
- (void)nextBarButtonTouch;
- (void)playBarButtonTouch;
- (void)incrementCurrentPageIndex;
- (void)decrementCurrentPageIndex;
- (void)changeCurrentPageToIndex:(NSUInteger)index;
- (void)showPageWithIndex:(NSNumber *)index;
- (void)startSlideShow;
- (void)stopSlideShow;

- (void)downloadPhotoForImageDic:(NSMutableDictionary *)imageDic;
	
@property (nonatomic, strong) UIScrollView *pagingScrollView;
@property (nonatomic, strong) NSMutableSet *recycledPages;
@property (nonatomic, strong) NSMutableSet *visiblePages;
@property (nonatomic, strong) UIBarButtonItem *previousBarButton;
@property (nonatomic, strong) UIBarButtonItem *nextBarButton;
@property (nonatomic, strong) UIBarButtonItem *playBarButton;
@property (nonatomic, strong) PRImageDetailsCaptionView *captionView;
@property (nonatomic, strong) NSTimer *slideShowTimer;

@property (nonatomic, strong) NSMutableArray *images;
@property (nonatomic, strong) NSArray *imageURLs;
@property (nonatomic, strong) NSMutableSet *downloadingImages;
@property (nonatomic, strong, readonly) NSOperationQueue *operationQueue;;
@property (nonatomic) BOOL showStatusBarWhenToolbarsHidden;

@property (nonatomic, readonly) PRSlideShowStatus slideShowStatus;

@property (nullable, nonatomic, weak) id<IssueAnalyticsProvider> analyticsProvider;

@end

NS_ASSUME_NONNULL_END
