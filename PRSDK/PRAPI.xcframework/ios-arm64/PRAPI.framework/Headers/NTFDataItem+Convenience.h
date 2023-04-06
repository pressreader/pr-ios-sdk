//
//  NTFDataItem+Convenience.h
//  PR-API
//
//  Created by berec on 14/11/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import "NTFDataItem+CoreDataClass.h"

@class NTFUserItem;

NS_ASSUME_NONNULL_BEGIN

@interface NTFDataItem (Convenience)

/// standalone objects create outside feed context
+ (instancetype)itemWithJSON:(NSDictionary *)json;
+ (instancetype)itemWithJSON:(NSDictionary *)json isoLanguage:(nullable NSString *)language;

@property (nullable, nonatomic, strong) NTFUserItem *owner;

@end

NS_ASSUME_NONNULL_END
