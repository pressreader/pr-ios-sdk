//
//  PRBackgroundDownloadManager.h
//  PRiphone
//
//  Created by Vitali Bounine on 07/22/14.
//  Copyright (c) 2013 PressReader. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PRBackgroundDownloadSession.h"

@interface PRBackgroundDownloadManager : NSObject

+ (instancetype) sharedDownloadManager;

- (PRBackgroundDownloadSession *)createSessionWithSessionId:(NSString *)sessionId delegate:(id<PRBackgroundDownloadSessionDelegate>)delegate;
- (PRBackgroundDownloadSession *)sessionWithSessionId:(NSString *)sessionId delegate:(id<PRBackgroundDownloadSessionDelegate>)delegate;
- (PRBackgroundDownloadSession *)sessionWithSessionId:(NSString *)sessionId;
- (NSDictionary *)allSessions;
- (void) invalidateAndRemoveSession:(NSString *)sessionId;

- (void) handleEventsForBackgroundURLSession:(NSString *)identifier completionHandler:(void (^)(void))completionHandler;

@end
