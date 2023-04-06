//
//  NSURLSession+PRPromise.h
//  PRPromiseKit
//
//  Created by Vitali Bounine on 2018-03-17.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PRPromise;

NS_ASSUME_NONNULL_BEGIN

extern NSString * const PRURLErrorFailingURLResponseNodeKey;
extern NSString * const PRURLErrorFailingURLResponseKey;
extern NSString * const PRURLErrorFailingDataKey;
extern NSString * const PRURLErrorFailingStringKey;
extern NSString * const PRJSONErrorJSONObjectKey;

@interface NSURLSession (PRPromise)

/**
 Creates a task that retrieves the contents of a URL based on the
 specified URL request object.

 The method automatically deserializes the raw HTTP data response into the
 appropriate rich data type based on the mime type the server provides.
 Thus if the response is JSON you will get the deserialized JSON response.
 The method supports decoding into strings, JSON and UIImages.

 However if your server does not provide a rich content-type, you will
 just get `NSData`.

 PRPromise category of NSURLSession dataTask goes to quite some lengths
 to provide good `NSError` objects for error conditions at all stages
 of the HTTP to rich-data type pipeline. We provide the following additional
 `userInfo` keys as appropriate:

 - `PRURLErrorFailingDataKey`
 - `PRURLErrorFailingStringKey`
 - `PRURLErrorFailingURLResponseKey`

 [[NSURLConnection sharedSession] promiseDataTaskWithRequest:rq].then(^(NSDictionary *response){
     // response is probably an NSDictionary deserialized from JSON
 });

 @param request The URL request.

 @return A promise that resolves with three parameters:

 1) The deserialized data response.
 2) The `NSHTTPURLResponse`.
 3) The raw `NSData` response.

 */
- (PRPromise *)promiseDataTaskWithRequest:(NSURLRequest *)request;
- (PRPromise *)promiseDataTaskWithRequest:(NSURLRequest *)request id:(nullable id)key;
- (PRPromise *)promiseDataTaskWithRequest:(NSURLRequest *)request
                                       id:(nullable id)key
                        expirationTimeout:(NSTimeInterval)expirationTimeout;

@end

NS_ASSUME_NONNULL_END
