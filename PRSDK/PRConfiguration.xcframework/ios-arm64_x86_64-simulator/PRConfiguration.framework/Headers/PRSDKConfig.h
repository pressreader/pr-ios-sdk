//
//  PRSDKConfig.h
//  PRSharedData
//
//  Created by berec on 20/10/2020.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, PRSDKAuthType) {
    PRSDKAuthTypeJWTToken = 0,
    PRSDKAuthTypeServiceName
};

@interface PRSDKConfig : NSObject
@property (nonatomic, readonly) id sdkInstance;
@property (nonatomic, readonly) BOOL isSDK;

@property (nonatomic, readonly) NSString *exitButtonTitle;
@property (nonatomic, readonly) BOOL isExitButtonHidden;

@property (nonatomic, readonly) PRSDKAuthType authType;

@end

@interface PRSDKConfig (DEPRECATED)
@property (nonatomic, readonly) BOOL exitButtonInTopBar;
@property (nonatomic, readonly) BOOL exitButtonIsIcon;

@end

NS_ASSUME_NONNULL_END
