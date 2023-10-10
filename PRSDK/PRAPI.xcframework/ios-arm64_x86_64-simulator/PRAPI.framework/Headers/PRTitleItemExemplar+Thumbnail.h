//
//  PRTitleItemExemplar+Thumbnail.h
//  PressReader
//
//  Created by Oleg Stepanenko on 30/01/17.
//  Copyright (c) 2017 PressReader. All rights reserved.
//

@import CoreGraphics;
#import "PRTitleItemExemplar.h"

@class PRThumbnailSource;

NS_ASSUME_NONNULL_BEGIN

@interface PRTitleItemExemplar (Thumbnail)

- (nullable PRThumbnailSource *)thumbnailWithSize:(CGSize)size;
- (nullable PRThumbnailSource *)thumbnailWithSize:(CGSize)size useAvailable:(BOOL)useLatest;

@end

NS_ASSUME_NONNULL_END
