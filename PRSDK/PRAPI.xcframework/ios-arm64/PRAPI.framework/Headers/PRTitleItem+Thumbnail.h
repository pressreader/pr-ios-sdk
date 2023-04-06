//
//  PRTitleItem+Thumbnail.h
//  PRiphone
//
//  Created by Jackie Cane on 22/10/14.
//  Copyright (c) 2014 NewspaperDirect. All rights reserved.
//

#import "PRTitleItem.h"
#import <PRThumbnail/PRThumbnail.h>

@interface PRTitleItem (Thumbnail)

- (NSDate *)latestDownloadedThumbnailDate;
- (NSDate *)latestDownloadedThumbnailDateForSize:(CGSize)size;
- (void)setLatestDownloadedThumbnailDate:(NSDate *)latestDownloadedThumbnailDate size:(CGSize)size;

- (PRThumbnailSource *)thumbnailForIssueDate:(NSDate *)date size:(CGSize)size;
- (PRThumbnailSource *)thumbnailForIssueDate:(NSDate *)date size:(CGSize)size page:(NSInteger)pageNo;
- (PRThumbnailSource *)thumbnailForIssueDate:(NSDate *)date size:(CGSize)size page:(NSInteger)pageNo square:(BOOL)square;
- (PRThumbnailSource *)thumbnailForIssueDate:(NSDate *)date size:(CGSize)size useAvailable:(BOOL)useLatest;
- (PRThumbnailSource *)thumbnailForLastIssueWithSize:(CGSize)size;

@end
