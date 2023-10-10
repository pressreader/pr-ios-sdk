//
//  PRThumbnail.h
//  PRiphone
//
//  Created by Oleg Stepanenko on 14.12.12.
//  Copyright (c) 2012 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "PRThumbnailInfo.h"

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

/**
 If thumbnail is not downloaded or didn't start downloading yet, with `priority` set to YES
 this method removes current thumb from downloading stack and put it on the top of it.
 This way we achieve the functionality of downloading visible thumbnails first.
 @param priority set YES to increase thumb's priority in downloading stack
*/
- (void)getImageWithPriority:(BOOL)priority handlerKey:(NSString *)key handler:(PRThumbnailHandler)handler;
- (void)getImageWithHandlerKey:(NSString *)key handler:(PRThumbnailHandler)handler;

/// IMPORTANT. Not suitable for async-await API as handler isn't a completion handler and might be called multiple times.
- (void)getImage:(PRThumbnailHandler)handler;

- (void)removeHandlerForKey:(NSString *)key;

- (void)updateURLs;

// download|load|prepare|cache thumbnail
// return YES if thumbnail is ready to show
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
@property (nonatomic, readonly) UIImage *loadingPlaceholder;

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
