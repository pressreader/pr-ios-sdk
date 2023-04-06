//
//  PRNavMenuFilter.h
//  PR-API
//
//  Created by Viacheslav Soroka on 1/26/18.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PRNavMenuRowItem;

@interface PRNavMenuFilter : NSObject

+ (nullable instancetype)filterWithNavMenuItem:(PRNavMenuRowItem *)item;
+ (nullable instancetype)filterWithValue:(id)value;

- (nullable instancetype)initWithValue:(id)value;

- (BOOL)isCorrespondsToNavMenuItem:(PRNavMenuRowItem *)item;
- (BOOL)isEqualToFilter:(nullable PRNavMenuFilter *)filter;

@property (nonatomic, readonly) id value;
@property (nullable, nonatomic, readonly) PRNavMenuRowItem *rowItem;
@property (nullable, nonatomic, readonly) NSDictionary *sectionJSON;

@property (nonatomic) NSInteger preferredColumnsCount;

@end

NS_ASSUME_NONNULL_END
