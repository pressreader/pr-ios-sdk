//
//  NSArray+Extended.h
//  PRiphone
//
//  Created by Jackie Cane on 13/03/14.
//  Copyright (c) 2014 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSArray<ObjectType> (Extended)

- (ObjectType)randomObject;

- (NSArray *)mappedArrayUsingBlock:(id _Nullable(NS_NOESCAPE ^)(ObjectType object))mapObjectBlock;
- (NSArray *)mapWithBlock:(id _Nullable(NS_NOESCAPE ^)(NSUInteger ndx,
                                             ObjectType object,
                                             BOOL *stop))mapObjectBlock;
- (NSArray<ObjectType> *)reversed;

@end

NS_ASSUME_NONNULL_END
