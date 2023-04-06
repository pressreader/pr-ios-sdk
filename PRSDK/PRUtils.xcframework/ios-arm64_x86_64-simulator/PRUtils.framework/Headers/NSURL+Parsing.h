//
//  NSURL+Parsing.h
//  PRiphone
//
//  Created by Viacheslav Soroka on 8/8/17.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSURL (Parsing)

+ (BOOL)isYoutubeVideoLink:(NSString *)link;
+ (BOOL)isVimeoVideoLink:(NSString *)link;

+ (nullable NSString *)youtubeVideoIdFromLink:(NSString *)link;
+ (nullable NSString *)vimeoVideoIdFromLink:(NSString *)link;

- (BOOL)isYoutubeVideoURL;
- (BOOL)isVimeoVideoURL;

- (nullable NSString *)youtubeVideoId;
- (nullable NSString *)vimeoVideoId;

@end

NS_ASSUME_NONNULL_END
