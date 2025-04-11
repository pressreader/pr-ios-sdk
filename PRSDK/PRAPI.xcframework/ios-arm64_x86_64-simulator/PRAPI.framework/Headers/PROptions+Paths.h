//
//  PROptions+Paths.h
//  PRAPI
//
//  Created by Vitali Bounine on 2021-03-25.
//  Copyright © 2021 NewspaperDirect. All rights reserved.
//

#import "PROptions.h"

NS_ASSUME_NONNULL_BEGIN

@interface PROptions (Paths)

@property (nonatomic, readonly) NSString *thumbnailsDirectoryPath;
@property (nonatomic, readonly) NSString *mastheadsDirectoryPath;
@property (nonatomic, readonly) NSString *appLogosDirectoryPath;
@property (nonatomic, readonly) NSString *documentsDirectoryPath;
@property (nonatomic, readonly) NSString *booksDirectoryPath;
@property (nullable, nonatomic, readonly) NSString *htmlBannersPath;
@property (nonatomic, readonly) NSString *storagePath;
@property (readonly) NSString *mliThumbnailPath;
@end

NS_ASSUME_NONNULL_END
