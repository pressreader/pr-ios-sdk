//
//  PRThumbnailAppLogo.h
//  PR-UI
//
//  Created by Viacheslav Soroka on 3/7/19.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import "PRThumbnailObject.h"
#import "PRThumbnailMasthead.h"

NS_ASSUME_NONNULL_BEGIN

@interface PRThumbnailAppLogo : PRThumbnailObject

extern NSString * _Nonnull const kPRAppLogoLocalResourceNameTemplate;
extern NSString * _Nonnull const kPRAppLogoLocalResourceNameColor;

+ (NSString *)keyWithStyle:(NTFMastheadStyle)style height:(CGFloat)height;

- (instancetype)initWithKey:(NSString *)key
                      style:(NTFMastheadStyle)style
                     height:(CGFloat)height
                       info:(PRThumbnailInfo *)info;

@end

NS_ASSUME_NONNULL_END
