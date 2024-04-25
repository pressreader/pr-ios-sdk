//
//  PRThumbnailsManager.h
//  PRiphone
//
//  Created by Jackie Cane on 22/10/14.
//  Copyright (c) 2014 NewspaperDirect. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

extern NSNotificationName const PRLatestAvailableThumbnailChanged;

@protocol PRLatestThumbnailSourceInfo <NSObject>
@end

@class PRThumbnailInfo;
@class PRArticleThumbnailInfo;
@class PRThumbnailObject;

@interface PRThumbnailsManager : NSObject <PRLatestThumbnailSourceInfo>

/// @param storagePath file path to permanent cache directory for storing meta info and permanent thumbnails
/// @param thumbnailPath file path to temporary cache directory. Unlike `storagePath`, thumbnails stored in `thumbnailPath` will be purged after period of inactivity.
- (instancetype)initWithStoragePath:(NSString *)storagePath
                      thumbnailPath:(NSString *)thumbnailPath;
- (instancetype)init NS_UNAVAILABLE;

/// Removes cached files which were not in use
- (void)cleanCachesOlderThan:(NSTimeInterval)age;

- (void)cacheThumbnail:(PRThumbnailObject *)thumbnail key:(NSString *)key;

@property (nonatomic, strong, readonly) NSCache<NSString *, __kindof PRThumbnailObject *> *thumbnailsCache;
@property (nonatomic, strong, readonly) NSCache *imageCache;

@property (nonatomic, strong, readonly) NSString *storagePath;

@property (nonatomic, strong, readonly) PRThumbnailInfo *info;
@property (nonatomic, strong) PRThumbnailInfo *sourceThumbsInfo;
@property (nonatomic, strong) PRArticleThumbnailInfo *articleThumbsInfo;
@property (nonatomic, strong) PRThumbnailInfo *flagsThumbsInfo;
@property (nonatomic, strong) PRThumbnailInfo *mastheadsThumbsInfo;
@property (nonatomic, strong) PRThumbnailInfo *categoryThumbsInfo;
@property (nonatomic, strong) PRThumbnailInfo *appLogoWhiteThumbsInfo;
@property (nonatomic, strong) PRThumbnailInfo *appLogoColorThumbsInfo;
@property (nonatomic, strong) PRThumbnailInfo *catalogItemThumbsInfo;

@end

NS_ASSUME_NONNULL_END

#import <PRThumbnail/PRThumbnailsManager+LatestInfo.h>

#import <PRThumbnail/PRThumbnailsManager+AppLogo.h>
#import <PRThumbnail/PRThumbnailsManager+Article.h>
#import <PRThumbnail/PRThumbnailsManager+Category.h>
#import <PRThumbnail/PRThumbnailsManager+Flag.h>
#import <PRThumbnail/PRThumbnailsManager+LatestInfo.h>
#import <PRThumbnail/PRThumbnailsManager+Masthead.h>
#import <PRThumbnail/PRThumbnailsManager+Source.h>
