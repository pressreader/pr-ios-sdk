//
//  AFJSONClient.h
//  AFNetworking
//
//  Created by Vitali Bounin on 4/12/12.
//  Copyright (c) 2012 NewspaperDirect Inc. All rights reserved.
//

#import <NetworkingKit/AFHTTPClient.h>
#import <NetworkingKit/AFJSONRequestOperation.h>

@interface AFJSONClient : AFHTTPClient

+ (AFJSONClient *)clientWithBaseURL:(NSURL *)url;

@end
