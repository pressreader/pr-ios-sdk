//
//  PRThumbnail.h
//  PRiphone
//
//  Created by Oleg Stepanenko on 14.12.12.
//  Copyright (c) 2012 NewspaperDirect. All rights reserved.
//

@import UIKit;

@class PRThumbnailInfo;

/* UIImage will implement the resizing mode the fastest way possible while
 retaining the desired visual appearance.
 Note that if an image's resizable area is one point then UIImageResizingModeTile
 is visually indistinguishable from UIImageResizingModeStretch.
 */
typedef NS_ENUM(NSInteger, PRThumbnailState) {
    PRThumbnailStateNoImage,
    PRThumbnailStateWaitingForDownloadURL,
    PRThumbnailStateDownloading,
    PRThumbnailStatePreparing,
    PRThumbnailStateCaching,
    PRThumbnailStateReady,
    PRThumbnailStateDownloadError,
    PRThumbnailStatePrepareError
};


NS_ASSUME_NONNULL_BEGIN

/// Might be called multiple times  (f.e. first with placeholder, then with final image).
typedef void (^PRThumbnailHandler)(UIImage *_Nullable image, NSError *_Nullable error);
typedef void (^PRThumbnailGenerator)(void(^)(UIImage * _Nullable));

typedef NS_OPTIONS(NSUInteger, PRThumbnailOption) {
    /// Ignore usage of smaller image if available while required image is loading.
    PRThumbnailOptionIgnoreClosestImageAsPlaceholder = 1 << 0,
    /// Renders image in template rendering mode.
    PRThumbnailOptionTemplate = 1 << 1
};

extern NSNotificationName const PRThumbnailsInfoUpdated;
extern NSNotificationName const PRThumbnailDidDownloadFinish;
extern NSNotificationName const PRThumbnailDidDownloadError;

typedef NSString * PRThumbnailCacheFieSizeSuffix NS_TYPED_ENUM;
extern PRThumbnailCacheFieSizeSuffix const PRThumbnailCacheFieSizeSuffixNone;
extern PRThumbnailCacheFieSizeSuffix const PRThumbnailCacheFieSizeSuffixSize;
extern PRThumbnailCacheFieSizeSuffix const PRThumbnailCacheFieSizeSuffixScale;
extern PRThumbnailCacheFieSizeSuffix const PRThumbnailCacheFieSizeSuffixHeight;
extern PRThumbnailCacheFieSizeSuffix const PRThumbnailCacheFieSizeSuffixWidth;

@class PRDownload;

@interface PRThumbnailObject : NSObject

- (instancetype)initWithKey:(NSString *)key info:(PRThumbnailInfo *)info;

/// @param synchronously When set to YES, method attemts to prepare image synchronously with no delay if possible.
/// @warning Not suitable for async-await API as handler isn't a completion handler and might be called multiple times.
/// F.e. first time with low quality variant or a placeholder, second time  - requred one.
- (void)getImageSynchronously:(BOOL)synchronously handler:(PRThumbnailHandler)handler NS_SWIFT_NAME(getImage(synchronously:handler:));

/// Calls `getImageSynchronously:handler` with NO synchrony
- (void)getImage:(PRThumbnailHandler)handler;

- (void)getImageWithHandlerKey:(NSString *)key handler:(PRThumbnailHandler)handler;

- (void)removeHandlerForKey:(NSString *)key;

- (void)updateURLs;

/// download|load|prepare|cache thumbnail.
/// If thumbnail is not downloaded or didn't start downloading yet,
/// re-calling this method removes current thumb from downloading stack and put it on the top of it.
/// This way we achieve the functionality of downloading visible thumbnails first.
/// @param synchronously When set to YES, method attemts to prepare image synchronously with no delay if possible.
/// @return YES if thumbnail is ready to show
- (BOOL)prepareThumbnailSynchronously:(BOOL)synchronously;
/// Calls `prepareThumbnailSynchronously` with NO synchrony.
- (BOOL)prepareThumbnail;

- (BOOL)hasCacheFile;

/// Searches for bigger/smaller variants of the thumbnail
/// Override to return nil in subsclasses which don't support reusing of thumb variants.
- (nullable NSString *)bestAvailableSizeVariant:(nullable BOOL *)bigger;

@property (nonatomic, strong, readonly) NSString *key;
@property (atomic, readonly) PRThumbnailState state;
@property (nonatomic, strong) PRThumbnailInfo *info;

@property (nonatomic, strong) NSString *directoryPath;
@property (nonatomic, strong) NSString *permanentStoreDirectoryPath;

/// png by default
@property (nonatomic, strong) NSString *originalFileExtension;
/// png by default
@property (nonatomic, strong) NSString *cacheFileExtension;

/// Word that preceedes image size number and used for converting previously downloaded large images into smaller once if needed.
/// Default value is .size. In case thumbnail back-end supports only one size, use .none suffix.
@property (nonatomic, strong) PRThumbnailCacheFieSizeSuffix cacheFileSizeSuffix;

@property (nonatomic, strong, readonly) NSString *downloadFilePath;
@property (nonatomic, strong, readonly) NSString *cacheFilePath;
@property (nonatomic, strong, readonly) NSString *permanentStoreFilePath;

@property (nonatomic, strong) NSString *placeholderFilePath;
@property (nonatomic, assign) BOOL hasPlaceholderFile;

/// Generator is used instead of image downloading.
/// Performed in Global queue.
@property (nullable, nonatomic) PRThumbnailGenerator imageGenerator;

@property (nullable, nonatomic, strong, readonly) UIImage *image;
@property (nonatomic, strong, readonly) UIImage *imagePlaceholder;

@property (nonatomic) PRThumbnailOption options;

/// thumbnail's output size
@property (nonatomic) CGSize imageSize;
@property (nonatomic, strong, readonly) UIColor *color;
@property (nonatomic, strong) NSMutableDictionary *imageInfo;
@property (nonatomic, readonly) NSString *scaleSuffix; // @2x or @3x

@end


@interface PRThumbnailObject (/*Protected*/)
@property (nonatomic, strong) NSArray<NSString *> *urls;
@end

@interface PRThumbnailObject (/*Debug*/)
@property (nonatomic) BOOL logMe;
@end

NS_ASSUME_NONNULL_END

#import "PRThumbnail+Variant.h"
