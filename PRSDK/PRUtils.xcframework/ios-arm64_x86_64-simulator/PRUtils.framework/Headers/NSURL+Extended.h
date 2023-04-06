//
//  NSURL+Extended.h
//  PRiphone
//
//  Created by Jackie Cane on 3/27/13.
//  Copyright (c) 2013 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSURL (Extended)

/// Translates query string into dictionary
+ (NSMutableDictionary *)queryStringParameters:(NSString *)queryString;

- (NSString *)valueOfQueryParameter:(NSString *)parameterName;

/// URL query parameters ordered as they set in original URL
- (NSArray<NSURLQueryItem *> *)queryItems;

/// URL query parameters presented as dictionary
- (NSDictionary<NSString *,NSString *> *)queryDictionary;

- (NSURL *)urlByAppendingURLParameters:(NSArray<NSString *> *)params;

@end
