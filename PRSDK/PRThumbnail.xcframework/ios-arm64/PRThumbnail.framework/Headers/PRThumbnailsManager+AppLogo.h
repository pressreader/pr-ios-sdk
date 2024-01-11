//
//  PRThumbnailsManager+AppLogo.h
//  PRThumbnail
//
//  Created by Ivan Berezin on 11/07/2022.
//  Copyright © 2022 NewspaperDirect. All rights reserved.
//

#import <PRThumbnail/PRThumbnailsManager.h>
#import <PRThumbnail/PRThumbnailAppLogo.h>

NS_ASSUME_NONNULL_BEGIN

@interface PRThumbnailsManager (AppLogo)

- (PRThumbnailAppLogo *)thumbnailForAppLogoWithStyle:(UIUserInterfaceStyle)style height:(CGFloat)height;
- (void)deleteAppLogoCaches;

@end

NS_ASSUME_NONNULL_END
