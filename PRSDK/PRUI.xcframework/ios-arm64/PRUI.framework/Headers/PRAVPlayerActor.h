//
//  PRAVPlayerActor.h
//  PRiphone
//
//  Created by Viacheslav Soroka on 8/4/17.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVKit/AVPlayerViewController.h>

@import PRAPI;

NS_ASSUME_NONNULL_BEGIN

extern NSInteger const kAVPlayerViewTag;

@interface PRAVPlayerActor : NSObject
@property (nonatomic, readonly) AVPlayerViewController *avPlayerVC;

+ (instancetype)actorWithVC:(UIViewController *)vc;
- (instancetype)initWithVC:(UIViewController *)vc;

- (void)playWithURL:(NSString *)path fromView:(nullable UIView *)view;

- (void)playYoutubeVideoWithVideoId:(NSString *)videoId
                           fromView:(UIView *)view
                         fullScreen:(BOOL)fullScreen;

- (void)playVimeoVideoWithVideoId:(NSString *)videoId
                         fromView:(UIView *)view
                       fullScreen:(BOOL)fullScreen;

- (void)dismiss;

- (void)updateCaptionWithString:(NSString*)caption;

@property (nullable, nonatomic, weak) id<IssueAnalyticsProvider> analyticsProvider;
@property (nullable, nonatomic, readonly) NSString *mediaTypePlayerPlaying;

@end

NS_ASSUME_NONNULL_END
