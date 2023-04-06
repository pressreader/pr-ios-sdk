//
//  NTFPageSetItem+Images.h
//  PRAPI
//
//  Created by Vitalii Hudenko on 11.08.2021.
//  Copyright © 2021 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "NTFPageSetItem.h"

NS_ASSUME_NONNULL_BEGIN

@interface NTFPageSetItem(Images)

+ (CGSize)loadThumbnailForPageNo:(NSUInteger)pageNo
                            item:(id)anItem
                            size:(CGSize)thumbSize
                   fromCacheOnly:(BOOL)cacheOnly
                      completion:(void(^)(UIImage *img, NSError *err))completionBlock;

+ (CGSize)sizeOfThumbnailForPageNo:(NSUInteger)pageNo item:(id)item height:(CGFloat)height;

+ (void)cancelLoadingThumbnailForPageNo:(NSUInteger)pageNo item:(id)anItem height:(CGFloat)height;

@end

NS_ASSUME_NONNULL_END
