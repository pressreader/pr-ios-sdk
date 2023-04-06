//
//  NTFUserItem.h
//  PRiphone
//
//  Created by Viacheslav Soroka on 4/26/17.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

#import "PRUserProfile.h"

NS_ASSUME_NONNULL_BEGIN

@class NTFChannelAccountItem;

typedef NS_ENUM(NSUInteger, NTFUserItemType) {
    NTFUserItemTypeDefault = 0,
    NTFUserItemTypePublication
};

@interface NTFUserItem : NSObject
@property (nullable, nonatomic, readonly) PRUserProfile *userProfile;

/// channel held by main queue managed object context
@property (nonatomic, readonly) NTFChannelAccountItem *channel;

+ (instancetype)itemWithJSON:(NSDictionary *)json;
+ (instancetype)itemWithJSON:(NSDictionary *)json updateCache:(BOOL)update;
+ (instancetype)itemWithSourceJSON:(NSDictionary *)json;
+ (instancetype)itemWithUserProfile:(PRUserProfile *)userProfile;

- (instancetype)initWithJSON:(NSDictionary *)json;
- (instancetype)initWithSourceJSON:(NSDictionary *)json;
- (instancetype)initWithUserProfile:(PRUserProfile *)userProfile;

- (void)setPhotoWithSize:(CGSize)size
             toImageView:(UIImageView *)imageView
              completion:(void(^)(UIImage *image))completion;

- (void)setPhotoWithSize:(CGSize)size
             toImageView:(UIImageView *)imageView
             placeholder:(nullable UIImage *)placeholder
              completion:(void(^)(UIImage *image))completion;

- (void)fillWithFollowInfo:(NSDictionary *)info;
- (void)fillWithDetailedJSON:(NSDictionary *)json;
- (void)fillWithSourceJSON:(NSDictionary *)json;

@property (nonatomic) NTFUserItemType type;

@end

NS_ASSUME_NONNULL_END
