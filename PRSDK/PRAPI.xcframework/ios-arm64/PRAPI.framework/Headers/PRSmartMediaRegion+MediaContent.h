//
//  PRSmartMediaRegion+MediaContent.h
//  PRiphone
//
//  Created by Jackie Cane on 10/27/11.
//  Copyright (c) 2011 NewspaperDirect. All rights reserved.
//

#import <PRSmart/PRSmart.h>

NS_ASSUME_NONNULL_BEGIN

@interface PRSmartMediaRegion (MediaContent)

- (NSString *)localStoragePathForMediaFile:(NSString *)file;
- (nullable NSURL *)mediaServiceURLForFile:(NSString *)file;
- (nullable NSData *)dataFromLocalStorageMediaFile:(NSString *)file;
- (nullable NSError *)parseMediaContent:(NSData *)data;
- (BOOL)isMediaFileLoaded:(NSString *)file;
- (void)saveMediaContentToLocalStorage;
- (void)saveMediaData:(NSData *)data toLocalStorageFile:(NSString *)file;

@property (nullable, nonatomic, readonly) NSURL *thumbnailURL;
@property (nullable, nonatomic, readonly) NSArray *mediaFiles;
@property (nullable, nonatomic, readonly) NSArray *mediaCaptions;
@property (nullable, nonatomic, readonly) NSString *mediaCaption;
@property (nullable, nonatomic, readonly) NSString *mediaContentThumbnailFileName;
@property (nullable, nonatomic, readonly) NSString *mediaContentURLPath;
@property (nullable, nonatomic, readonly) NSString *audioURLPath;
@property (nullable, nonatomic) UIImage *mediaContentThumbnail;

@end

NS_ASSUME_NONNULL_END
