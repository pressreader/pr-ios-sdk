//
//  PRHost.h
//  PRiphone
//
//  Created by Vitali Bounine on 1/12/10.
//  Copyright 2010 NewspaperDirect. All rights reserved.
//

@import Foundation;
@class PRPromise;

NS_ASSUME_NONNULL_BEGIN

@interface PRHost : NSObject

- (void)requestWebTemplate:(NSString *)name locale:(NSString *)locale;
- (void)updateBaseServicesInfo;
- (void)discoverDQHostName:(void (^)(NSString *dqHostName, NSError *error))completionBlock;

@property (nonatomic, readonly) NSString *defaultServiceName;
@property (nonatomic, readonly) NSString *serviceName;
@property (nonatomic, strong, readonly) PRPromise *baseServicesUpdate;

@end

NS_ASSUME_NONNULL_END
