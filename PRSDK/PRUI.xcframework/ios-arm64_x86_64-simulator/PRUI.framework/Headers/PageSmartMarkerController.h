//
//  PageSmartMarkerController.h
//  PRiphone
//
//  Created by devuser on 06/03/09.
//  Copyright 2009 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PRSmartMarkerViewController.h"

NS_ASSUME_NONNULL_BEGIN

@import PRAPI;

@protocol  PRPageSmartMarkerDelegate <PRSmartMarkerControllerDelegate>
- (BOOL)isFullScreenMode;
- (BOOL)isViewVisible;
@end

@class PRSmartArticle;
@protocol PRSmartLayoutItem;

@interface PageSmartMarkerController : NSObject

+ (CGRect) titleRectForArticle:(PRSmartArticle *)article viewPageOrigin:(CGPoint)origin pageScale:(CGFloat)scale;

- (instancetype)initWithSmart:(NSObject<PRSmartLayoutItem> *)smartLayoutItem
                    pageIndex:(NSUInteger)pageIdx
                         page:(nullable PRPage *)page
             commentsDisabled:(BOOL)commentsDisabled;

- (void) showSmartItemsInView:(UIView *)view pageOrigin:(CGPoint)pageOrigin pdfScale:(CGFloat)scale;
- (void) updateSmartItemsWithScale:(CGFloat)newScale;
- (void) hideSmartItems;
- (void) load;
- (nullable PRSmartMarkerViewController *) smartViewControllerByArtID:(NSString *)artID;
- (void)article:(NSString *)artID showCommentsCounter:(NSUInteger)numComments isNegativeVote:(BOOL)negative;
- (void)refreshArticleMarkers;

- (nullable PRSmartMarkerViewController *)biggestArticleMarkerInRect:(CGRect)rect;
- (nullable PRSmartMarkerViewController *)biggestArticleMarker;

@property (nullable, nonatomic, weak) id<PRPageSmartMarkerDelegate> delegate;
@property (nonatomic) BOOL pageViewZoomInProgress;

@end

NS_ASSUME_NONNULL_END
