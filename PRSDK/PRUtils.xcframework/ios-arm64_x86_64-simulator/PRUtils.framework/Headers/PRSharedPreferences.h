//
//  PRSharedOptions.h
//  PR-API
//
//  Created by berec on 07/12/2018.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PRSharedPreferences : NSObject

- (instancetype)initWithPreferencesByService:(NSDictionary<NSString *, NSDictionary *> *)preferencesByService;

// services preferences
- (id)valueForKey:(NSString *)key service:(NSString *)serviceName;
- (void)setValue:(id)value forKey:(NSString *)key service:(NSString *)serviceName;

- (NSString *)selectedCountryForService:(NSString*)serviceName;
- (void)setSelectedCountry:(NSString *)value forService:(NSString*)serviceName;

// subscripting support
- (id)objectForKeyedSubscript:(NSString *)key;
- (void)setObject:(nullable id)object forKeyedSubscript:(NSString *)key;

@property (nonatomic, strong, readonly) NSUserDefaults *appGroupDefaults;

@end

NS_ASSUME_NONNULL_END
