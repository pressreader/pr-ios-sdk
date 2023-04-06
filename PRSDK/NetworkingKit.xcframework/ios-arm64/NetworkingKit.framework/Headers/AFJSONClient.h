//
//  AFJSONClient.h
//  AFNetworking
//
//  Created by Vitali Bounin on 4/12/12.
//  Copyright (c) 2012 NewspaperDirect Inc. All rights reserved.
//

#import "AFHTTPClient.h"
#import "AFJSONRequestOperation.h"

@interface AFJSONClient : AFHTTPClient

+ (AFJSONClient *)clientWithBaseURL:(NSURL *)url;

@end
