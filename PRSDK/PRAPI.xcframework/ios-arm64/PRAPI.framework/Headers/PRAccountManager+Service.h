//
//  PRAccounts+Service.h
//  PRiphone
//
//  Created by Jackie Cane on 6/27/12.
//  Copyright (c) 2012 NewspaperDirect. All rights reserved.
//

#import "PRAccountManager.h"
#import "PRService_Constants.h"

NS_ASSUME_NONNULL_BEGIN

@class SPNode;
@class DeviceActivation;

@interface PRAccountManager (Service)

- (void)sendRegisterDeviceRequest:(NSString*)serviceName completion:(void(^ _Nullable)(BOOL success, NSError *error))completion;
- (void)SendAuthRequest:(NSString*)usr pwd:(NSString*)pwd devName:(NSString*)devName serviceName:(NSString*)serviceName;
- (void)sendAuthRequestForSocialID:(NSString *)socialID;
- (void)sendAuthRequestForSocialID:(NSString *)socialID
                        singnature:(nullable NSString *)signature
                             stamp:(nullable NSString *)stamp;
- (void)sendAuthRequestForSocialID:(NSString *)socialID
                         signature:(nullable NSString *)signature
                             stamp:(nullable NSString *)stamp
                        socialData:(nullable NSString *)socialData
                        completion:(void(^_Nullable)(BOOL success, NSError * _Nullable error))completion;
- (void)sendAuthorizeUserByExternalAuthTicketRequest:(NSString *)externalAuthTicket isNewUser:(BOOL)isNewUser onComplete:(void(^)(BOOL success, NSError *error))onCompleteBlock;

- (void)deauthorizeAccount:(PRAccountItem *)ai
                   options:(PRAccountDeauthorizationOption)options
                completion:(void(^ _Nullable)(BOOL success, NSError * _Nullable error))completion;

- (void)sendSignUpRequestForUser:(NSString *)usr pwd:(NSString *)pwd firstName:(NSString *)firstName lastName:(NSString *)lastName success:(void (^)(void))success failure:(void (^)(NSError *error))failure;

- (void)pingAccount:(PRAccountItem *)ai;
- (void)pingAccount:(PRAccountItem *)ai
  completionHandler:(void(^ _Nullable)(BOOL success, NSError * _Nullable error))completionHandler;
- (void)requestAccountSubscriptionStatus:(PRAccountItem *)ai;
- (void)requestAccountSubscriptionStatus:(PRAccountItem *)ai
                       completionHandler:(void(^ _Nullable)(BOOL success, NSError * _Nullable error))completionHandler;
- (void)requestUserProfileInt:(PRAccountItem *)ai
              completionBlock:(void(^ _Nullable)(BOOL success, NSError * _Nullable error))completionBlock;
- (void)performExternalAuthRequest:(NSString *)request
                           account:(nullable PRAccountItem *)ai
                        parameters:(nullable NSDictionary *)parameters
                           options:(nullable NSDictionary<PRServiceRequestOption, id> *)options
                            method:(nullable NSString *)method
                           success:(void(^)(id response))success
                           failure:(void(^ _Nullable)(NSError *error))failure;

- (void)getExternalAuthKeyWithCompletion:(void(^)(NSString * _Nullable key, NSError * _Nullable error))completion;
- (void)authorizeExternalAuthKey:(NSString *)key
                           token:(NSString *)token
                        provider:(NSString *)provider
                      completion:(void(^ _Nullable)(BOOL success, NSError * _Nullable error))completion;

- (void)performRequest:(NSString *)request
               account:(nullable PRAccountItem *)ai
            parameters:(nullable NSDictionary *)parameters
               options:(nullable NSDictionary<PRServiceRequestOption, id> *)options
                method:(nullable NSString *)method
               success:(void(^ _Nullable)(id _Nullable response))successBlock
               failure:(void(^ _Nullable)(NSError * _Nullable error))failureBlock;

- (PRPromise *)performRequest:(NSString *)request
                      account:(nullable PRAccountItem *)ai
                   parameters:(nullable NSDictionary *)parameters
                      options:(nullable NSDictionary *)options
                       method:(nullable NSString *)method
      useMultipartFormRequest:(BOOL)useMultipartFormRequest;

- (void)performRequest:(NSString *)request
               account:(nullable PRAccountItem *)ai
            parameters:(nullable NSDictionary *)parameters
               options:(nullable NSDictionary<PRServiceRequestOption, id> *)options
                method:(nullable NSString *)method
useMultipartFormRequest:(BOOL)useMultipartFormRequest
               success:(void (^)(id response))successBlock
               failure:(void (^)(NSError *error))failureBlock;

- (void)sendDownloadCompletedRequest:(NSString *)accountName;
- (void)requestHotZoneStatusForAccount:(PRAccountItem *)accountItem;
- (void)requestHotZoneStatusForAccount:(PRAccountItem *)accountItem
                                forced:(BOOL)forced
                            completion:(void(^ _Nullable)(BOOL success, NSError * _Nullable error))completion;
- (void)deleteRadiantHotSpotForAccount:(PRAccountItem *)accountItem;

- (void)requestGiftedAccessWithCompletion:(void(^ _Nullable)(BOOL success, NSError *error))completion;
- (void)requestGiftedAccessWithToken:(NSString *)token
                          completion:(void(^)(BOOL success, NSError *error))completion;
- (void)requestDevicesWithAccount:(PRAccountItem *)account
                       completion:(void (^)(NSError *_Nullable error, NSArray<DeviceActivation *> * models))completionBlock;
- (void)deauthorizeDeviceWith:(NSString *)username
             activationNumber:(NSString *)activationNumber
                 clientNumber:(NSString *)clientNumber
              completionBlock:(void(^)(BOOL success, NSError *_Nullable error))completionBlock;

@end

NS_ASSUME_NONNULL_END
