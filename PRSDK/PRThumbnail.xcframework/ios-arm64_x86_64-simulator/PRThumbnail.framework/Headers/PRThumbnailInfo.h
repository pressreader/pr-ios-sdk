//
//  PRThumbnailInfo.h
//  PRThumbnail
//
//  Created by berec on 06/02/2020.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>
@import CoreGraphics;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, PRThumbnailInfoImageSource) {
    PRThumbnailInfoImageSourceURL,
    PRThumbnailInfoImageSourceAsset
};

@interface PRThumbnailInfo : NSObject
@property (nonatomic) PRThumbnailInfoImageSource imageSource;
@property (nonatomic, strong) NSString *storagePath;
@property (nullable, nonatomic, strong) NSArray<NSString *> *downloadUrls;

@end

NS_ASSUME_NONNULL_END
