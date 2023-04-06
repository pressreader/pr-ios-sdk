//
//  NTFCoreDataController.h
//  PR-API
//
//  Created by berec on 30/04/2018.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import "PRCoreDataController.h"

@class NTFSession;
@class NTFChannelAccountItem;

NS_ASSUME_NONNULL_BEGIN

extern NSNotificationName const NTFOnlineSessionDidStartNotification;

@interface NTFCoreDataController : PRCoreDataController

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

#import "NTFCoreDataController+Session.h"
