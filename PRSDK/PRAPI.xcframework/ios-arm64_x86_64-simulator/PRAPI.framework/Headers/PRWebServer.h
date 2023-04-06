//
//  PRWebServer.h
//  PRiphone
//
//  Created by Vitali Bounine on 2016-05-11.
//  Copyright © 2016 NewspaperDirect. All rights reserved.
//

@import GCDWebServers.GCDWebServer;

NS_ASSUME_NONNULL_BEGIN

@interface PRWebServer : GCDWebServer

- (void)startIfNotRunning;

- (nullable NSURL *)urlWithResource:(NSString *)resourcePath;
- (nullable NSURL *)urlWithResource:(NSString *)resourcePath query:(nullable NSString *)query;

@end

NS_ASSUME_NONNULL_END
