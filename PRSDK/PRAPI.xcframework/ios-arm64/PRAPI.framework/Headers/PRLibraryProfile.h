//
//  PRLibraryProfile.h
//  PR-API
//
//  Created by Viacheslav Soroka on 3/14/18.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PRLibraryProfile : NSObject
@property (nullable, nonatomic, readonly) NSString *externalId;
@property (nullable, nonatomic, readonly) NSString *provider;

@property (nonatomic, readonly, getter=isEmpty) BOOL empty;

+ (instancetype)profileWithJSON:(NSDictionary *)json;
- (instancetype)initWithJSON:(NSDictionary *)json;

@end

NS_ASSUME_NONNULL_END
