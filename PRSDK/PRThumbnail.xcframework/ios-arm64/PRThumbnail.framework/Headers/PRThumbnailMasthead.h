//
//  PRThumbnailMasthead.h
//  PR-API
//
//  Created by berec on 25/09/2018.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import "PRThumbnailObject.h"

NS_ASSUME_NONNULL_BEGIN

@interface PRThumbnailMasthead : PRThumbnailObject

+ (NSString *)keyWithMastheadId:(NSString *)mastheadId height:(CGFloat)height;

- (instancetype)initWithKey:(NSString *)key
                 mastheadId:(NSString *)mastheadId
                     height:(CGFloat)height
                       info:(PRThumbnailInfo *)info;

@end

NS_ASSUME_NONNULL_END
