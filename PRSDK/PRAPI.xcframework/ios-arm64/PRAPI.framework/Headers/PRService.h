//
//  PRService.h
//  PRiphone
//
//  Created by Dmitry Melnik on 02/09/08.
//  Copyright 2008 NewspaperDirect. All rights reserved.
//

@import Foundation;
@import NetworkingKit.AFHTTPClient;
#import <PRAPI/PRService_Constants.h>

#define NODE_SERVICE_NAME @"service-name"
#define NODE_DISPLAY_SERVICE_NAME @"display-service-name"
#define NODE_ACTIVATION_NUMBER @"activation-number"
#define NODE_ACTIVATION_ID @"activation-id"
#define NODE_USER_NAME @"user-name"
#define NODE_LOGON_NAME @"logon-name"
#define NODE_FIRST_NAME @"first-name"
#define NODE_LAST_NAME @"last-name"
#define NODE_ACCOUNT_STATUS @"account-status"
#define NODE_SERVICE_URL @"service-url"
#define NODE_USER_PROFILE @"user-profile"
#define NODE_ASK_PROFILE_INFO @"ask-profile-info"

@class SPNode;
@class PRAccountItem;
@class PRPromise;

@interface ServiceHelper: NSObject

+ (NSString *)FormServerCommand:(PRAccountItem*)ai requestType:(NSString*)requestType additional:(NSString*)additional;
+ (NSString*)FormServerCommand:(NSString*)requestType additional:(NSString*)additional;
+ (NSString *)clientInfo;

@property (nonatomic, class, readonly) NSDictionary *defaultServiceOptions;

@end

#pragma mark -

@interface PRServiceClientLogger : NSObject
+ (void) enableDebugLogForRequestType:(NSString *)reqType;
+ (void) disableDebugLogForRequestType:(NSString *)reqType;
+ (void) removeDebugLogForRequestType:(NSString *)reqType;
+ (BOOL) isDebugLogEnabledForRequestType:(NSString *)reqType;
@end

@interface PRServiceClient : AFHTTPClient

@end

@interface PRDeliveryQueueClient : PRServiceClient

+ (PRDeliveryQueueClient *)sharedClient;

- (void)postRequest:(NSString *)requestType
         accountItem:(PRAccountItem *)ai
         requestData:(NSString *)xmlFragment
      responseFields:(NSMutableDictionary *)dict
             options:(NSDictionary<PRServiceRequestOption, id> *)options
             success:(void (^)(AFHTTPRequestOperation *, SPNode *))success
             failure:(void (^)(AFHTTPRequestOperation *, NSError *))failure;

- (void)postRequest:(NSString *)requestType
        accountItem:(PRAccountItem *)ai
        requestData:(NSString *)xmlFragment
     responseFields:(NSMutableDictionary *)dict
            options:(NSDictionary<PRServiceRequestOption, id> *)options
         completion:(void (^)(SPNode *response, NSError *error))completion;

- (void) getPath:(NSString *)path
      parameters:(NSDictionary *)parameters
     requestType:(NSString *)requestType
  responseFields:(NSMutableDictionary *)dict
         options:(NSDictionary *)options
         success:(void (^)(AFHTTPRequestOperation *, SPNode *))success
         failure:(void (^)(AFHTTPRequestOperation *, NSError *))failure;
@end

@interface PROnlineServiceClient : PRServiceClient

+ (PRPromise *)sharedClient;

- (void)getPath:(NSString *)path
     parameters:(NSDictionary *)parameters
        options:(NSDictionary *)options
        success:(void (^)(AFHTTPRequestOperation *operation, id responseObject))success
        failure:(void (^)(AFHTTPRequestOperation *operation, NSError *error))failure;

- (void)postPath:(NSString *)path
      parameters:(NSDictionary *)parameters
         options:(NSDictionary *)options
         success:(void (^)(AFHTTPRequestOperation *operation, id responseObject))success
         failure:(void (^)(AFHTTPRequestOperation *operation, NSError *error))failure;

- (void) putPath:(NSString *)path
      parameters:(NSDictionary *)parameters
         options:(NSDictionary *)options
         success:(void (^)(AFHTTPRequestOperation *operation, id responseObject))success
         failure:(void (^)(AFHTTPRequestOperation *operation, NSError *error))failure;

- (void)getResource:(NSString *)resourcePath
              token:(NSString *)token
         parameters:(NSDictionary *)parameters
            options:(NSDictionary *)options
            success:(void (^)(AFHTTPRequestOperation *operation, id responseObject))success
            failure:(void (^)(AFHTTPRequestOperation *operation, NSError *error))failure;

- (void)postResource:(NSString *)resourcePath
               token:(NSString *)token
          parameters:(NSDictionary *)parameters
             options:(NSDictionary *)options
useMultipartFormRequest:(BOOL)useMultipartFormRequest
             success:(void (^)(AFHTTPRequestOperation *operation, id responseObject))success
             failure:(void (^)(AFHTTPRequestOperation *operation, NSError *error))failure;

- (void) putResource:(NSString *)resourcePath
               token:(NSString *)token
          parameters:(NSDictionary *)parameters
             options:(NSDictionary *)options
useMultipartFormRequest:(BOOL)useMultipartFormRequest
             success:(void (^)(AFHTTPRequestOperation *operation, id responseObject))success
             failure:(void (^)(AFHTTPRequestOperation *operation, NSError *error))failure;

- (void)performRequest:(NSString *)resourcePath
                method:(NSString *)method
                 token:(NSString *)token
            parameters:(NSDictionary *)parameters
               options:(NSDictionary *)options
useMultipartFormRequest:(BOOL)useMultipartFormRequest
               success:(void (^)(AFHTTPRequestOperation *operation, id responseObject))success
               failure:(void (^)(AFHTTPRequestOperation *operation, NSError *error))failure;

@end
