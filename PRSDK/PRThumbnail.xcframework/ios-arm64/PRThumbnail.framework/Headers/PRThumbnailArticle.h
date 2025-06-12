//
//  PRThumbnailArticle.h
//  PR-API
//
//  Created by berec on 10/09/2018.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import "PRThumbnailObject.h"
@class PRArticleThumbnailInfo;

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(uint8_t, NTFThumbnailArticleOption) {
    NTFThumbnailArticleOptionLoadFromCacheOnly = 1 << 0, // currently not implemented
    NTFThumbnailArticleOptionIgnoreClosestImageAsPlaceholder = 1 << 1,
    NTFThumbnailArticleOptionShowVideoIndicator = 1 << 2
};

@interface PRThumbnailArticle : PRThumbnailObject

+ (NSString *)keyWithArticleId:(NSString *)articleId
                      regionId:(NSString *)regionId
                  scalePercent:(NSUInteger)scale
                       options:(NTFThumbnailArticleOption)options;

- (instancetype)initWithKey:(NSString *)key
                  articleId:(NSString *)articleId
                   regionId:(NSString *)regionId
                        url:(NSString *)url
                      scale:(NSUInteger)scale
               requiredSize:(CGSize)requiredSize
                 outputSize:(CGSize)outputSize
                    options:(NTFThumbnailArticleOption)options
                       info:(PRArticleThumbnailInfo *)info;

@end

NS_ASSUME_NONNULL_END
