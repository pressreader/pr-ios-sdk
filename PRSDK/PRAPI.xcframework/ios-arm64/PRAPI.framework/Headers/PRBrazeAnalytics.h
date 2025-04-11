//
//  PRBrazeAnalytics.h
//  PRAPI
//
//  Created by berec on 15/10/2020.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

@import UIKit;

NS_ASSUME_NONNULL_BEGIN

@interface PRBrazeAnalytics: NSObject

+ (void)setUserEmail:(nullable NSString *)value overwrite:(BOOL)overwrite;
+ (void)setUserFirstName:(nullable NSString *)value overwrite:(BOOL)overwrite;
+ (void)setUserLastName:(nullable NSString *)value overwrite:(BOOL)overwrite;

+ (void)debugLog:(NSString *)log;

@property (class, nonatomic, readonly) PRBrazeAnalytics *instance;
@property (class, nullable, nonatomic, readonly) NSString *apiKey;
@property (class, nonatomic, readonly) NSString *userDefaultPropertyPrefix;

@end

NS_ASSUME_NONNULL_END
