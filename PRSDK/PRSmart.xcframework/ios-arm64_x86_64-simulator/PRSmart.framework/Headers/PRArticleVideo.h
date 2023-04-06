//
//  PRArticleVideo.h
//  PRiphone
//
//  Created by Viacheslav Soroka on 8/2/17.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface PRArticleVideo : NSObject
@property (nonatomic, readonly) NSString *title;
@property (nonatomic, readonly) NSString *url;
@property (nonatomic, readonly) NSString *thumbnailURL;

+ (instancetype)itemWithJSON:(NSDictionary *)json;
+ (instancetype)itemWithTitle:(NSString *)title
                          url:(NSString *)url
                 thumbnailURL:(NSString *)thumbnailURL
                         size:(CGSize)size;

- (instancetype)initWithJSON:(NSDictionary *)json;
- (instancetype)initWithTitle:(NSString *)title
                          url:(NSString *)url
                 thumbnailURL:(NSString *)thumbnailURL
                         size:(CGSize)size;

@end
