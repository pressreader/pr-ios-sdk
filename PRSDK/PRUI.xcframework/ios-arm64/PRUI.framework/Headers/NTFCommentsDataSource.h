//
//  NTFCommentsDataSource.h
//  PRiphone
//
//  Created by Viacheslav Soroka on 9/12/17.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "NTFDataSourceBase.h"

NS_ASSUME_NONNULL_BEGIN

@protocol NTFCommentsDataSource <NTFDataSourceBase>

#ifndef PRVideoLinkType
typedef NSString * PRVideoLinkType NS_STRING_ENUM;
#endif
extern PRVideoLinkType const PRVideoLinkTypeYoutube;
extern PRVideoLinkType const PRVideoLinkTypeVimeo;
- (void)uploadImageAttachment:(UIImage *)image
                    completed:(void(^)(NSString *artifactId, NSString *url, NSError *error))completionBlock;
- (void)addVideoLink:(NSString *)videoUrl
                type:(PRVideoLinkType)videoType
           completed:(void(^)(NSString *artifactId, NSString *previewUrl, NSError *error))completionBlock;

@end

NS_ASSUME_NONNULL_END
