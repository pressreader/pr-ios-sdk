//
//  PRiphoneAppDelegate.h
//  PRiphone
//
//  Created by Vitali Bounine on 27/08/08.
//  Copyright NewspaperDirect 2008. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface PRiphoneAppDelegate : NSObject <UIApplicationDelegate>

- (void)checkAppVersion;

// Utils
@property (nonatomic) BOOL onLaunch;
@property (nonatomic, readonly) NSString *backgroundAppRefreshIdentifier;

@end

NS_ASSUME_NONNULL_END
