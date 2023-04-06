//
//  PRModel+API.h
//  PRiphone
//
//  Created by Jackie Cane on 11/20/12.
//  Copyright (c) 2012 NewspaperDirect. All rights reserved.
//

@import PRAPI.PRModel;

NS_ASSUME_NONNULL_BEGIN

@interface PRModel (API)

+ (void)startModelWithApplication:(UIApplication *)application
                    launchOptions:(nullable NSDictionary<UIApplicationLaunchOptionsKey, id> *)launchOptions;
+ (void)resumeModel;
+ (void)pauseModel;
+ (void)stopModel;
+ (void)fullReset;

@end

NS_ASSUME_NONNULL_END
