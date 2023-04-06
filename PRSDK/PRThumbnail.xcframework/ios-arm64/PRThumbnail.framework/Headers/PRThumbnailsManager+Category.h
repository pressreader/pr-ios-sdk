//
//  PRThumbnailsManager+Category.h
//  PRThumbnail
//
//  Created by Ivan Berezin on 11/07/2022.
//  Copyright © 2022 NewspaperDirect. All rights reserved.
//

#import <PRThumbnail/PRThumbnailsManager.h>
#import <PRThumbnail/PRThumbnailCategory.h>

NS_ASSUME_NONNULL_BEGIN

@interface PRThumbnailsManager (Category)

- (PRThumbnailCategory *)categoryThumbnailWithID:(NSString *)ID;
- (void)prepareThumbnailsWithCategories:(NSArray*)categories reload:(BOOL)reload;

@end

NS_ASSUME_NONNULL_END
