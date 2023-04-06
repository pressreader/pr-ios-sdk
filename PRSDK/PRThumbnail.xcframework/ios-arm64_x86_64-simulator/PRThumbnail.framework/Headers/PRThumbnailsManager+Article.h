//
//  PRThumbnailsManager+Article.h
//  PRThumbnail
//
//  Created by Ivan Berezin on 11/07/2022.
//  Copyright © 2022 NewspaperDirect. All rights reserved.
//

#import <PRThumbnail/PRThumbnailsManager.h>
#import <PRThumbnail/PRThumbnailArticle.h>

NS_ASSUME_NONNULL_BEGIN

@interface PRThumbnailsManager (Article)

- (PRThumbnailArticle *)thumbnailForArticleId:(NSString *)articleId
                                     regionId:(NSString *)regionId
                                 scalePercent:(NSUInteger)scalePercent
                                 requiredSize:(CGSize)requiredSize
                                   outputSize:(CGSize)outputSize
                                          url:(NSString *)url
                                      options:(NTFThumbnailArticleOption)options;

@end

NS_ASSUME_NONNULL_END
