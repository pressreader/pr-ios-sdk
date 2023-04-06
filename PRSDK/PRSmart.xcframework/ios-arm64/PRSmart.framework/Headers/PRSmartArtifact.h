//
//  PRSmartArtifact.h
//  PRiphone
//
//  Created by Vitali Bounine on 2016-11-15.
//  Copyright © 2016 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "PRSmartBaseObject.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, PRSmartArtifactVideoType) {
    PRSmartArtifactVideoTypeYoutube = 1,
    PRSmartArtifactVideoTypeVimeo,
};

@interface PRSmartArtifact : PRSmartBaseObject

@property (nonatomic, readonly) NSInteger artifactId;
@property (nonatomic, readonly) NSString *objectId;
@property (nonatomic, readonly) NSString *previewUrl;
@property (nonatomic, readonly) CGSize previewSize;
@property (nonatomic, readonly) BOOL isVideo;
@property (nonatomic, readonly, nullable) NSString *videoId;
@property (nonatomic, readonly) PRSmartArtifactVideoType videoType;
@property (nonatomic, readonly, nullable) NSString *videoUrl;

- (NSString *) previewURLWithWidth:(NSInteger)width;
- (NSString *) previewURLWithHeight:(NSInteger)height;
@end

NS_ASSUME_NONNULL_END

