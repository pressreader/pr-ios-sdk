//
//  PRAccountItem+Service.h
//  PRiphone
//
//  Created by Jackie Cane on 6/27/12.
//  Copyright (c) 2012 NewspaperDirect. All rights reserved.
//

#import "PRAccountItem.h"

NS_ASSUME_NONNULL_BEGIN

@class SPNode;
@class PRPromise;

@interface PRAccountItem (Service)

- (instancetype)initFromXmlItem:(SPNode*)xmlItem userName:(NSString*)user clientName:(NSString*)client;

- (void)requestHotZoneStatus;
- (void)requestHotZoneStatusForced:(BOOL)forced
                        completion:(void(^_Nullable)(BOOL success,
                                                     NSError *error,
                                                     NSTimeInterval repeatInterval))completion;

/// `then` block will provide NSString *ticket
- (PRPromise *)getAuthTicket;
- (void)processAccountStatusResponse:(SPNode*)resp;
- (void)processAccountStatusWithResponse:(SPNode*)resp;
- (void)processAccountStatusWithResponse:(SPNode*)resp keysForReplace:(nullable NSArray<NSString *> *)keys;
- (void)processBundlesWithResponse:(SPNode*)resp;
- (void)processAccountAdditionalInfoWithResponse:(SPNode *)resp;
- (void)sendDownloadCompletedRequest;
- (void)uploadPicture:(UIImage *)picture onComplete:(nullable void (^)(BOOL success, NSError * _Nullable error))onCompleteBlock;
- (void)requestProfile:(nullable void(^)(id _Nullable responseObject, NSError *_Nullable error))completionBlock;
- (void)updateProfile:(NSDictionary *)properties completionBlock:(nullable void(^)(id _Nullable responseObject, NSError * _Nullable error))completionBlock;
- (void)updateEmail:(NSString *)email completionBlock:(nullable void(^)(id _Nullable responseObject, NSError * _Nullable error))completionBlock;
- (void)updatePassword:(nullable NSString *)currentPassword newPassword:(NSString *)password completionBlock:(nullable void(^)(id _Nullable responseObject, NSError * _Nullable error))completionBlock;
- (void)requestNotificationSettings:(nullable void(^)(id _Nullable responseObject, NSError * _Nullable error))completionBlock;
- (void)updateNotificationSettings:(NSDictionary *)properties completion:(nullable void(^)(id _Nullable responseObject, NSError * _Nullable error))completionBlock;
- (void)requestUserProfile:(nullable void(^)(BOOL success, NSError * _Nullable error))completionBlock;
- (void) requestPremiumTrialEligibility;

@end

NS_ASSUME_NONNULL_END

