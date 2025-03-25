//
//  NSDictionaryCIWrapper.h
//  PR-API
//
//  Created by berec on 25/04/2018.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSUInteger, NSDictionaryCIWrapperOption) {
    NSDictionaryCIWrapperOptionDeepSearch = 1 << 0,
    /// when .acceptKeyPath option is set, wrapper interprets keyed subscript as a path with `keyPathSeparator`
    NSDictionaryCIWrapperOptionAcceptKeyPath = 1 << 1
};

typedef NSDictionary<NSString *, id> * CIWrapperDictionary;

/// Dictionary's wrapper that provides capitalisation insensitive access to the objects
@interface NSDictionaryCIWrapper : NSObject

+ (instancetype)CIWrapperForDictionary:(CIWrapperDictionary)dictionary;
+ (instancetype)CIWrapperForDictionary:(CIWrapperDictionary)dictionary
                               options:(NSDictionaryCIWrapperOption)options;

- (nullable id)objectForKeyedSubscript:(id)key;

@property (nonatomic, strong, readonly) CIWrapperDictionary dictionary;

/// default value is "/"
@property (nonatomic, strong) NSString *keyPathSeparator;

@end

@interface NSDictionary (CIWrapper)
- (NSDictionaryCIWrapper *)CIWrapper;

@end

NS_ASSUME_NONNULL_END
