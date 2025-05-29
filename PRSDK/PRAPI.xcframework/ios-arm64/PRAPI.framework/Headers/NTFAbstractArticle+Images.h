//
//  NTFAbstractArticle+Images.h
//  PR-API
//
//  Created by berec on 24/08/2020.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import "NTFAbstractArticle.h"

@import PRThumbnail.PRThumbnailArticle;

@class PRImageValidationCriteria;
@class PRSmartImageRegion;

NS_ASSUME_NONNULL_BEGIN

@interface NTFAbstractArticle (Images)

- (int)selectPrefImage;

- (NSUInteger)numberOfImagesForMinWidth:(CGFloat)minWidth;

- (NSUInteger)numberOfImagesForSize:(CGSize)size
                           criteria:(PRImageValidationCriteria *)criteria;

- (CGFloat)imageHeightAtIndex:(NSInteger)imageIdx
                      minSize:(CGSize)size
                     criteria:(nullable PRImageValidationCriteria *)criteria;

- (CGFloat)imageHeightAtIndex:(NSInteger)imageIdx minWidth:(CGFloat)width;

- (BOOL)isValidImageAtIndex:(NSInteger)index
                    forSize:(CGSize)size
                   criteria:(PRImageValidationCriteria *)criteria;

- (BOOL)isValidImageAtIndex:(NSInteger)index forSize:(CGSize)size;

- (CGFloat)prefImageHeightForSize:(CGSize)size;

/**
 *  @param size set size.height = 0 for dynamic height
 */
- (CGFloat)loadPrefImageWithMinSize:(CGSize)size
                            options:(NTFThumbnailArticleOption)options
                         completion:(void (^_Nullable)(UIImage *_Nullable img, NSError *_Nullable err))completionBlock;//0.0f;

- (NSString *)bylineForImageAtIndex:(NSInteger)imageIdx;//nil

- (BOOL)isImageVideoPreviewForIndex:(NSInteger)imageIdx; //no
- (nullable NSString *)videoURLForImageAtIndex:(NSInteger)imageIdx; //nil

@property (nonatomic, readonly) BOOL hasPrefImage;

@end

NS_ASSUME_NONNULL_END
