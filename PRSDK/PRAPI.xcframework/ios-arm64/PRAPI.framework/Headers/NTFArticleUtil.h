//
//  NTFArticleUtil.h
//  PR-API
//
//  Created by berec on 22/07/2018.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <PRAPI/NTFArticle.h>

NS_ASSUME_NONNULL_BEGIN

@interface NTFArticleUtil : NSObject

+ (NSString *)resolvedTitleForArtcle:(id<NTFArticle>)article;

+ (nullable NSString *)textSnippetForArticle:(id<NTFArticle>)article;

+ (NSString *)titleSnippetForArtcle:(id<NTFArticle>)article
                      numberOfLines:(NSUInteger)numberOfLines
                             length:(NSUInteger)length;

+ (void)addVideoIconToImage:(nonnull UIImage *)img
                      cache:(nullable id)imageCache
                   cacheKey:(nullable NSString *)cacheKey
                 completion:(void(^_Nonnull)(UIImage *imageWithVideoIcon))completion;

@end

NS_ASSUME_NONNULL_END
