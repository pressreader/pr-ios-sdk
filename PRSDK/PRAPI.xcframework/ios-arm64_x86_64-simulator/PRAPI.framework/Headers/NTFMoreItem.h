//
//  NTFMoreItem.h
//  PR-API
//
//  Created by Viacheslav Soroka on 7/12/18.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "NTFSection.h"

NS_ASSUME_NONNULL_BEGIN

@class PRNavMenuFilter;

@interface NTFMoreItem : NSObject

+ (instancetype)itemWithSection:(id<NTFSection>)section defaultLocale:(nullable NSString *)defaultLocale;
- (instancetype)initWithSection:(id<NTFSection>)section defaultLocale:(nullable NSString *)defaultLocale;

- (void)getFilter:(void(^)(PRNavMenuFilter * _Nullable filter))completion;

@property (nonatomic, readonly) NSString *title;
/// If filter is nil, try to use getFilter: method.
@property (nullable, nonatomic, readonly) PRNavMenuFilter *filter;

@end

NS_ASSUME_NONNULL_END
