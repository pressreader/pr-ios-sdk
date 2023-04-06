//
//  PRUserProfile.h
//  PRiphone
//
//  Created by Jackie Cane on 27/02/15.
//  Copyright (c) 2015 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class PRPromise;

typedef NS_ENUM(NSInteger, PRUserProfilePhotoOption) {
    PRUserProfilePhotoOptionNone = 0,
    PRUserProfilePhotoOptionUsePlaceholder = 1 << 0,
    PRUserProfilePhotoOptionUseInitials = 1 << 1,
    PRUserProfilePhotoOptionRound = 1 << 2,
};

@interface PRUserProfile : NSObject

+ (instancetype)getCached:(NSString *)key;
+ (void)addToCache:(PRUserProfile *)profile;
+ (void)removeCache:(NSString *)key;

+ (instancetype)currentUserProfile;
+ (instancetype)userProfileWithName:(NSString *)profileName;
+ (instancetype)userProfileWithInfo:(NSDictionary *)info;
- (instancetype)initWithProfileName:(NSString *)profileName;
- (void)setupWithInfo:(NSDictionary *)info;

- (void)getPhotoWithSize:(CGSize)size completion:(void(^)(UIImage *image))completion;
- (void)getPhotoWithSize:(CGSize)size options:(PRUserProfilePhotoOption)options completion:(void(^)(UIImage *image))completion;
- (void)getPhotoWithSize:(CGSize)size options:(PRUserProfilePhotoOption)options textForInitials:(NSString*)placeholder completion:(void(^)(UIImage *image))completion;

- (PRPromise *)follow:(BOOL)isFollowed;

@property (nonatomic, strong) NSString *channelId;
@property (nonatomic, strong) NSString *encryptedChannelId;
@property (nonatomic, strong) NSString *profileName;
/// aka nickname
@property (nonatomic, strong) NSString *username;
@property (nonatomic, strong) NSString *photoUrl;
@property (nonatomic, strong) NSString *location;
@property (nonatomic, strong) NSArray *opinionTrends;
@property (nonatomic, readonly) NSString *nameInitials;
@property (nonatomic, getter=isFollowedByCurrentUser) BOOL followedByCurrentUser;
@property (nonatomic) NSInteger followersCount;
@property (nonatomic) NSInteger numberOfRecruitedPeople;
@property (nonatomic) NSInteger totalNumberOfRecruitedPeople;
@property (nonatomic, strong) NSDate *joinedOn;
@property (nonatomic, assign) NSInteger numberOfUpdatesForCurrentUser;

@property (nonatomic, readonly, getter=isCurrentUser) BOOL currentUser;

/// only to access existing property; to obtain/generate photo use getPhotoWithSize:onResult method.
@property (nonatomic, strong) NSCache *imagesForSize;

@end
