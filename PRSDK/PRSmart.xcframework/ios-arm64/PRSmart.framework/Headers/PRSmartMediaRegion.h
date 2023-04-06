//
//  PRSmartMediaRegion.h
//  PRiphone
//
//  Created by Jackie Cane on 26/08/15.
//  Copyright (c) 2015 NewspaperDirect. All rights reserved.
//

#import "PRSmartRegion.h"

// keys
extern NSString *const kMediaContentRefType;
extern NSString *const kFormRefType;
extern NSString *const kThumbnail;
extern NSString *const kFiles;
extern NSString *const kCaptions;
extern NSString *const kCaption;
extern NSString *const kUrl;
extern NSString *const kMediaContent;

// values
extern NSString *const kAudioMediaContentType;
extern NSString *const kVideoMediaContentType;
extern NSString *const kImageMediaContentType;
extern NSString *const kWebMediaContentType;
extern NSString *const kImageMediaContentId;
extern NSString *const kWebMediaContentId;

@interface PRSmartMediaRegion : PRSmartRegion {
    NSString *MID;
}

- (instancetype)initWithType:(NSString*)aType page:(NSUInteger)page parent:(id)parentObject MID:(NSString *)aMID;
- (BOOL) parseMediaDescription:(NSData *)data;
- (BOOL) parseMediaDescriptionFromString:(NSString *)string;
- (BOOL) parseMediaDescriptionFile;

- (NSString *) mediaObjectId;
- (NSString *) mediaType;
- (BOOL)isYouTubeVideo;
- (BOOL)isVideoLink;
- (BOOL)isImageMediaContent;
- (BOOL)isWebMediaContent;
- (BOOL)isAudioMediaContent;
- (NSString *) youTubeVideoId;
- (NSString *) videoUrl;
- (NSString *) posterUrl;

@property (nonatomic, retain) NSString *MID;
@property (nonatomic, readonly) NSString *mediaContentType;
@property (nonatomic, readonly) NSMutableDictionary *mediaContent;

@end
