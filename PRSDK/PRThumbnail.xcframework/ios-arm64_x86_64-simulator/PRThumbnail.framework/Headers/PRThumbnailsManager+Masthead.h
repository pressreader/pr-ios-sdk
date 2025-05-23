//
//  PRThumbnailsManager+Masthead.h
//  PRThumbnail
//
//  Created by Ivan Berezin on 11/07/2022.
//  Copyright © 2022 NewspaperDirect. All rights reserved.
//

#import <PRThumbnail/PRThumbnailsManager.h>
#import <PRThumbnail/PRThumbnailMasthead.h>

NS_ASSUME_NONNULL_BEGIN

@interface PRThumbnailsManager (Masthead)

- (PRThumbnailMasthead *)thumbnailWithMastheadId:(NSString *)mastheadId height:(CGFloat)height NS_SWIFT_NAME(thumbnail(mastheadId:height:));

@end

NS_ASSUME_NONNULL_END
