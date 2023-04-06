//
//  PROptions+UserDefaults.h
//  PRAPI
//
//  Created by Viacheslav Soroka on 2022-04-04.
//  Copyright © 2022 NewspaperDirect. All rights reserved.
//

#import <PRAPI/PRAPI.h>

NS_ASSUME_NONNULL_BEGIN

@class PRSharedPreferences;

@interface PROptions (UserDefaults)

- (void)registerInstallationDefaults;
- (void)registerInstallationDefaults:(NSString *)installationVersion;
- (void)registerDefaults;

- (void)registerUserDefaults:(NSDictionary *)defaults;

@property (nonatomic, readonly) NSUserDefaults *standardDefaults;
@property (nonatomic, readonly) NSUserDefaults *sharedDefaults;

@end

NS_ASSUME_NONNULL_END
