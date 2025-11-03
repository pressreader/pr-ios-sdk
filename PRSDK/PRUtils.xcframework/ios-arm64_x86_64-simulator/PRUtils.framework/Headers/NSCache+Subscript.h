//
//  NSCache+Subscript.h
//  PRUtils
//
//  Created by Ivan Berezin on 11/10/2024.
//  Copyright © 2024 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSCache<KeyType, ObjectType> (Subscript)

- (nullable ObjectType)objectForKeyedSubscript:(KeyType)key;
- (void)setObject:(nullable ObjectType)obj forKeyedSubscript:(KeyType)key;

@end

NS_ASSUME_NONNULL_END
