//
//  PRCountry.h
//  PRiphone
//
//  Created by Oleg Stepanenko on 12.09.13.
//  Copyright (c) 2013 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

#define COUNTRY_ISO_INTERNATIONAL @"_i"

NS_ASSUME_NONNULL_BEGIN

@interface PRCountry : NSObject

+ (instancetype)countryWithISO:(nullable NSString *)ISO name:(nullable NSString *)name;
+ (void)removeCountryWithISO:(NSString *)ISO;

+ (nullable instancetype)countryByISO:(NSString *)ISO;
+ (nullable instancetype)countryByName:(NSString *)name;

@property (nonatomic, strong, readonly) NSString *ISO;
@property (nonatomic, strong, readonly) NSString *name;
@property (nonatomic, strong, readonly) NSString *localizedName;

@end

NS_ASSUME_NONNULL_END
