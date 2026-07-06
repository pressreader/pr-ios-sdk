//
//  ModalVideoPlayerVC.h
//  PR-UI
//
//  Created by KeithC on 2019-10-16.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVKit/AVPlayerViewController.h>

#import "PRImageDetailsCaptionView.h"

#import <PRAPI/PRAPI.h>

NS_ASSUME_NONNULL_BEGIN

@interface ModalVideoPlayerVC : UIViewController

- (instancetype)initWithVideoId:(NSString *)videoId
                      viewClass:(Class)viewClass;
- (instancetype)initWithAVPlayerVC:(AVPlayerViewController *)avPlayerVC;

@property (nullable, nonatomic, weak) id<IssueAnalyticsProvider> analyticsProvider;
@property (nonatomic, strong, readonly) PRMediaDetailsCaptionView *captionView;
@property (nonatomic, strong, readonly) NSDictionary *metadata;

@end

@interface ModalVideoPlayerVC (/*Protected*/)

@property (nonatomic) CGFloat totalDuration;
@property (nonatomic) CGFloat currentPlayTime;

@end

NS_ASSUME_NONNULL_END
