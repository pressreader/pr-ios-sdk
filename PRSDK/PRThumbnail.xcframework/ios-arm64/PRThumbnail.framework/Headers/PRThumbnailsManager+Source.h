//
//  PRThumbnailsManager+Source.h
//  PRThumbnail
//
//  Created by Ivan Berezin on 11/07/2022.
//  Copyright © 2022 NewspaperDirect. All rights reserved.
//

#import <PRThumbnail/PRThumbnailsManager.h>
#import <PRThumbnail/PRThumbnailSource.h>

NS_ASSUME_NONNULL_BEGIN

@interface PRThumbnailsManager (Source) <PRThumbnailSourceDelegate>

- (PRThumbnailSource *)sourceThumbnailWithCID:(NSString *)CID
                                    issueDate:(NSDate *)date
                                        color:(UIColor *)color
                                         type:(PRThumbnailSourceType)type
                                         size:(CGSize)size
                                       square:(BOOL)square
                                 issueVersion:(NSInteger)issueVersion
                               expungeVersion:(NSString *)expungeVersion
                                       pageNo:(NSInteger)pageNo
                           permanentDirectory:(nullable NSString *)permanentDirectory;

- (PRThumbnailSource *)sourceThumbnailWithCID:(NSString *)CID
                                    issueDate:(NSDate *)date
                                        color:(UIColor *)color
                                         type:(PRThumbnailSourceType)type
                                         size:(CGSize)size
                                 issueVersion:(NSInteger)issueVersion
                               expungeVersion:(NSString *)expungeVersion;

- (PRThumbnailSource *)sourceThumbnailWithCID:(NSString *)CID
                                    issueDate:(NSDate *)date
                                       pageNo:(NSInteger)pageNo
                                         size:(CGSize)size;

@end

NS_ASSUME_NONNULL_END
