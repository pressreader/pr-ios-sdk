//
//  NSDictionary+Parsing.h
//  PR-API
//
//  Created by berec on 22/03/2018.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS (NSUInteger, PRDictionaryParsingOption) {
    PRDictionaryParsingOptionCIKey = 1 << 0,
    PRDictionaryParsingOptionDeepKey = 1 << 1
};

@interface NSDictionary<__covariant KeyType, __covariant ObjectType> (Parsing)

- (nullable id)objectForKey:(id)key options:(PRDictionaryParsingOption)options;
- (nullable id)objectForKeyPath:(NSArray<id> *)keyPath options:(PRDictionaryParsingOption)options;

@end

NS_ASSUME_NONNULL_END
