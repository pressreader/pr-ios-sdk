//
//  PRThumbnailsManager+LatestInfo.h
//  PRThumbnail
//
//  Created by berec on 30/01/2020.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <PRThumbnail/PRThumbnailsManager.h>

NS_ASSUME_NONNULL_BEGIN

@interface PRThumbnailsManager (LatestInfo)

- (nullable NSDate *)latestDownloadedThumbnailDateForCID:(NSString *)cid;
- (nullable NSDate *)latestDownloadedThumbnailDateForCID:(NSString *)cid
                                                    size:(CGSize)size;
- (BOOL)setLatestDownloadedThumbnailDate:(NSDate *)latestDownloadedThumbnailDate
                                    size:(CGSize)size
                                     cid:(NSString *)cid;

@end

NS_ASSUME_NONNULL_END
