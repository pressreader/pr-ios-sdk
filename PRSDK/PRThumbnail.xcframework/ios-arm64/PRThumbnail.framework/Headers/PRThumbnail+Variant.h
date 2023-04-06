//
//  PRThumbnail+Variant.h
//  PR-API
//
//  Created by berec on 13/02/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import "PRThumbnailObject.h"

NS_ASSUME_NONNULL_BEGIN

@interface PRThumbnailObject (Variant)

- (nullable NSString *)sizeVariantForThumbnailFileName:(NSString *)fileName bigger:(nullable BOOL *)bigger;

@end

NS_ASSUME_NONNULL_END
