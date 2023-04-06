//
//  PRSDKUtil.h
//  PRUtils
//
//  Created by berec on 09/11/2020.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PRSDKUtil : NSObject
@property (class, nonatomic, readonly) id sdkInstance;
@property (class, nonatomic, readonly) BOOL isSDK;

@end

NS_ASSUME_NONNULL_END
