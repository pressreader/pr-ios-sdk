//
//  NTFDataSource+Analytics.h
//  PRUI
//
//  Created by berec on 14/05/2021.
//  Copyright © 2021 NewspaperDirect. All rights reserved.
//

#import <PRUI/NTFDataSource.h>

NS_ASSUME_NONNULL_BEGIN

@interface NTFDataSource (Analytics)

- (void)startReadingFrame;

- (void)readingFrameAddItem:(id)item
                   expanded:(BOOL)expanded
          visibleAreaOffset:(float)visibleAreaOffset  /// offset (percent of whole size) to the article part included in the frame
            visibleAreaSize:(float)visibleAreaSize    /// part of the article currently included in the frame
             visibilityRate:(float)visibilityRate;    /// what part of the frame taken by the specific item

- (void)startReadingFrameWithItem:(id)item
                         expanded:(BOOL)expanded
                visibleAreaOffset:(float)visibleAreaOffset
                  visibleAreaSize:(float)visibleAreaSize
                   visibilityRate:(float)visibilityRate;

- (void)pauseReadingFrame;
- (void)resumeReadingFrame;
- (void)suspendReadingFrameWithAction:(nullable NSString *)actionType target:(nullable NSString *)targetId;
- (void)finalizeReadingFrame;

- (void)reportArticle:(id<NTFArticle>)article viewType:(PRAnalyticsTextFlowType)viewType;
- (void)reportArticleClose:(id<NTFArticle>)article viewType:(PRAnalyticsTextFlowType)viewType;
- (void)reportCurrentArticleWithTextFlowType:(PRAnalyticsTextFlowType)viewType;

@end

NS_ASSUME_NONNULL_END
