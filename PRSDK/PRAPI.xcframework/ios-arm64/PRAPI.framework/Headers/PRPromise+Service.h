//
//  PRPromise+Service.h
//  PRiphone
//
//  Created by Viacheslav Soroka on 5/11/17.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//


#import "PRService_Constants.h"
@import PRPromiseKit;

typedef NS_ENUM(uint8_t, PRRequestType) {
    PRRequestTypePOST,
    PRRequestTypeGET,
    PRRequestTypePUT,
    PRRequestTypeUPDATE,
    PRRequestTypeDELETE
};

NS_ASSUME_NONNULL_BEGIN

@class PRAccountItem;

@interface PRPromise (Service)

+ (PRPromise *)postRequestWithPath:(NSString *)path;
+ (PRPromise *)getRequestWithPath:(NSString *)path;
+ (PRPromise *)getRequestWithPath:(NSString *)path parameters:(nullable NSDictionary *)parameters;
+ (PRPromise *)putRequestWithPath:(NSString *)path;
+ (PRPromise *)updateRequestWithPath:(NSString *)path;
+ (PRPromise *)deleteRequestWithPath:(NSString *)path;

+ (PRPromise *)requestWithPath:(NSString *)path type:(PRRequestType)type;

+ (PRPromise *)requestWithPath:(NSString *)path
                          type:(PRRequestType)type
                    parameters:(nullable NSDictionary *)parameters;

+ (PRPromise *)requestWithPath:(NSString *)path
                          type:(PRRequestType)type
                    parameters:(nullable NSDictionary *)parameters
                       options:(nullable NSDictionary<PRServiceRequestOption, id> *)options;

+ (PRPromise *)requestWithPath:(NSString *)path
                          type:(PRRequestType)type
                       account:(nullable PRAccountItem *)account
                    parameters:(nullable NSDictionary *)parameters
                       options:(nullable NSDictionary<PRServiceRequestOption, id> *)options;

+ (PRPromise *)requestWithPath:(NSString *)path
                          type:(PRRequestType)type
                       account:(nullable PRAccountItem *)account
       useMultipartFormRequest:(BOOL)useMultipartFormRequest
                    parameters:(nullable NSDictionary *)parameters
                       options:(nullable NSDictionary<PRServiceRequestOption, id> *)options;

+ (NSString *)stringForRequestType:(PRRequestType)type;
+ (NSDictionary<PRServiceRequestOption, id> *)defaultOptionsForRequest;

@property (class, nonatomic, readonly) NSDictionary<PRServiceRequestOption, id> *testRequestOptions;

@end

NS_ASSUME_NONNULL_END
