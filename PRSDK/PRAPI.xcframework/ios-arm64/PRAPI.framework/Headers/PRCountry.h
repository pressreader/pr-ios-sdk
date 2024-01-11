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
@property (nonatomic, strong, readonly) NSString *ISO;
@property (nonatomic, strong, readonly) NSString *name;
@property (nonatomic, strong, readonly) NSString *localizedName;

+ (instancetype)countryWithISO:(NSString *)ISO Name:(NSString *)name;
+ (void)removeCountryWithISO:(NSString *)ISO;

+ (instancetype)countryByISO:(NSString *)ISO;
+ (instancetype)countryByName:(NSString *)name;

- (instancetype)initWithISO:(NSString *)ISO Name:(NSString *)name;
@end

NS_ASSUME_NONNULL_END
