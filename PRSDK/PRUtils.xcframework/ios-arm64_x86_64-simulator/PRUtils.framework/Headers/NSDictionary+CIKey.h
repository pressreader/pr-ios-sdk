//
//  NSDictionary+CIKey.h
//  PRDataUtils
//
//  Created by berec on 18/10/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSDictionary<__covariant KeyType, __covariant ObjectType> (CIKey)

/// Returns object for Capitalisation Insensitive Key. F.e. in case of key = "accessKey" it checks "AccessKey" variant if original key doesn't contain any value.
- (nullable ObjectType)objectForCIKey:(NSString *)key;

/// Returns first match of Capitalisation Insensitive Key from array to an object
- (nullable ObjectType)objectForCIKeys:(NSArray<NSString *> *)keys;

/// Returns object for Same Case Insensitive Key. F.e. in case of key = "9Fce" it also checks both uppercase "9FCE" lowercase "9fce" variants if original key doesn't contain any value.
- (nullable ObjectType)objectForSCKey:(NSString *)key;

@end

NS_ASSUME_NONNULL_END
