//
//  PRArticleThumbnailInfo.h
//  PRThumbnail
//
//  Created by berec on 06/02/2020.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import "PRThumbnailInfo.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM (NSUInteger, PRArticleThumbnailURLType) {
    PRArticleThumbnailURLTypeFull = 0,
    PRArticleThumbnailURLTypeRegionKey,
    PRArticleThumbnailURLTypeSubpath,
};

@interface PRArticleThumbnailInfo : PRThumbnailInfo
@property (nonatomic) PRArticleThumbnailURLType urlType;
@property (nonatomic) CGFloat scaleLimit;

@end

NS_ASSUME_NONNULL_END
