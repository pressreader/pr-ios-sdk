//
//  PRRadioManager.h
//  PRiphone
//
//  Created by Jackie Cane on 29/09/15.
//  Copyright © 2015 NewspaperDirect. All rights reserved.
//

@import UIKit;

NS_ASSUME_NONNULL_BEGIN

@protocol NTFArticle, PRRadioDataSource;
@class PRSourceItem;
@class PRSmartArticle;
@class PRMyLibraryItem;

@protocol PRRadioManagerDelegate <NSObject>

- (void)showPlayButtonEnabled:(NSNumber *)enabled;
- (void)showPauseButtonEnabled:(NSNumber *)enabled;
- (void)willDismissRadio;
- (void)pauseReading;
- (void)resumeReading;
- (void)radioWillPlayInDirection:(CGSize)direction;

@optional
- (void)updateProgress:(long)progress duration:(long)duration speechRateAvailable:(BOOL)speechRateAvaialbe;
- (void)audioStreamingErrorOccurred:(NSError *)error;
- (void)radioDidUpdateNumberOfArticles;

@end


@interface PRRadioManager : NSObject

- (instancetype)initWithSourceItem:(PRSourceItem *)sourceItem;
- (instancetype)initWithDataSource:(id<PRRadioDataSource>)dataSource;

/// must be called before releasing manager to finish remote command's observation
- (void)destroy;

- (void)updateNowPlayingInfo;
- (NSUInteger)pageNumberForArticle:(NSDictionary *)article;

- (void)play;
- (void)pause;
/// Seeks to a specific time (in seconds)
- (void)seekToTime:(NSTimeInterval)value;
/// Skip forward or backward (negative), in seconds
- (void)skipFor:(NSTimeInterval)interval;
- (void)setPlaybackRate:(float)rate;
- (void)stop;
- (void)playNextArticle;
- (void)playPrevArticle;

- (BOOL)canGoNext:(BOOL)canChangeSection;
- (BOOL)canGoPrevious:(BOOL)canChangeSection;
- (BOOL)canGoNextSection;
- (BOOL)canGoPreviousSection;

- (CGSize)goNextSection;
- (CGSize)goPreviousSection;
- (CGSize)goNext;
- (CGSize)goPrevious;
- (void)playInDirection:(CGSize)direction;

@property (nullable, nonatomic, weak) id<PRRadioManagerDelegate> delegate;
@property (nonatomic, strong) id<PRRadioDataSource> dataSource;
@property (nonatomic, strong) id<NTFArticle> beginningArticle;
@property (nonatomic, strong) NSString *beginningArticleUid;

/// `sourceItem` is nil if the class was initialized with `dataSource`
@property (nullable, nonatomic, strong) PRSourceItem *sourceItem;
@property (nullable, nonatomic, readonly) PRMyLibraryItem *libraryItem;

@property (nonatomic, readonly) BOOL isPlaying;
@property (nonatomic, readonly) BOOL isStreamingPlaying;

@property (nonatomic, readonly) PRSmartArticle *currentSmartArticle;

@property (nullable, nonatomic, strong, readonly) id<NTFArticle> currentFeedArticle;
@property (nonatomic, readonly) NSArray *currentSectionArticles;
@property (nonatomic, readonly) NSDictionary *currentArticle;
@property (nonatomic, readonly) NSString *currentArticleUid;
@property (nonatomic, readonly) NSString *currentLanguageISO;
@property (nonatomic, readonly) NSArray *sections;
@property (nonatomic, readonly) NSArray *pages;
@property (nonatomic, readonly) NSString *pageImageBaseUrl;

@property (nonatomic) NSUInteger currentSectionIndex;
@property (nonatomic) NSInteger currentArticleIndex;
@property (nonatomic) NSUInteger currentPageNumber;
@property (nullable, nonatomic, strong) UIImage *currentArticleImage;

@property (nonatomic, readonly) NSUInteger numberOfFreeArticlesToListen;
@property (nonatomic, readonly) NSTimeInterval freePlayDuration;

@end

NS_ASSUME_NONNULL_END
