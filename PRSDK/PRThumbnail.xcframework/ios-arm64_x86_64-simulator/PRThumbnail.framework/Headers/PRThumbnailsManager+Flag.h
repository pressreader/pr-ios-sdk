//
//  PRThumbnailsManager+Flag.h
//  PRThumbnail
//
//  Created by Ivan Berezin on 11/07/2022.
//  Copyright © 2022 NewspaperDirect. All rights reserved.
//

#import <PRThumbnail/PRThumbnailsManager.h>
#import <PRThumbnail/PRThumbnailFlag.h>

NS_ASSUME_NONNULL_BEGIN

@interface PRThumbnailsManager (Flag)

- (PRThumbnailFlag *)flagThumbnailWithISO:(NSString *)ISO;

/// Returns image if it exists in cache, otherwise - nil (in this case completionBlock will be called when processing is done)
- (nullable UIImage *)getFlagImageWithISO:(NSString *)ISO
                                     size:(CGSize)size
                            renderingMode:(UIImageRenderingMode)renderingMode
                          completionBlock:(void(^)(UIImage * _Nullable image))completionBlock;

@end

NS_ASSUME_NONNULL_END
