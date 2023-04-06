//
//  AFXMLClient.h
//  AFNetworking
//
//  Created by Vitali Bounin on 4/12/12.
//  Copyright (c) 2012 NewspaperDirect Inc. All rights reserved.
//

#import "AFHTTPClient.h"

@interface AFHTTPClient (FreeFormatStringBody)

/**
 Creates an `NSMutableURLRequest` object with the specified method, path, content type and body.
 
 If the xmlBody is empty use HTTP method `GET`. Otherwise, use HTTP method `PUT` and the xmlBody will be encoded and set as the request body.
 
 @param path The path to be appended to the HTTP client's base URL and used as the request URL.
 @param body The xml structure to be encoded and set in the request HTTP body.
 
 @return An `NSMutableURLRequest` object
 */
- (NSMutableURLRequest *)requestWithMethod:(NSString *)method
                                      path:(NSString *)path
                               contentType:(NSString *)contentType
                                      body:(NSString *)body;

- (void)postPath:(NSString *)path
     contentType:(NSString *)contentType
            body:(NSString *)body
         success:(void (^)(AFHTTPRequestOperation *operation, id responseObject))success
         failure:(void (^)(AFHTTPRequestOperation *operation, NSError *error))failure;

@end
