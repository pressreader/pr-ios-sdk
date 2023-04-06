//
//  NSLocale+PRExtensions.h
//  PR-API
//
//  Created by Viacheslav Soroka on 7/16/18.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSLocale (PRExtensions)

+ (nullable instancetype)localeWithLocaleCode:(NSString *)code;

@end

NS_ASSUME_NONNULL_END
