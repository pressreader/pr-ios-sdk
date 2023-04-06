//
//  PRBackgroundDownloadSession.h
//  PRiphone
//
//  Created by Vitali Bounine on 11/27/13.
//  Copyright (c) 2013 PressReader. All rights reserved.
//

#import <Foundation/Foundation.h>
@class PRBackgroundDownloadSession;

@protocol PRBackgroundDownloadSessionDelegate <NSObject>

- (void) downloadSession:(PRBackgroundDownloadSession *)downloadSession task:(NSString *)taskId totalBytesWritten:(int64_t)totalBytesWritten totalBytesExpectedToWrite:(int64_t)totalBytesExpectedToWrite;
- (void) downloadSession:(PRBackgroundDownloadSession *)downloadSession task:(NSString *)taskId downloadedToURL:(NSURL *)destinationURL;
- (void) downloadSession:(PRBackgroundDownloadSession *)downloadSession task:(NSString *)taskId completedWithError:(NSError *)error;
- (void) downloadSession:(PRBackgroundDownloadSession *)downloadSession task:(NSString *)taskId didResumeAtOffset:(int64_t)fileOffset expectedTotalBytes:(int64_t)expectedTotalBytes;

@end

NS_CLASS_AVAILABLE_IOS(7_0)
@interface PRBackgroundDownloadSession : NSObject<NSURLSessionDownloadDelegate>

@property (nonatomic, weak, readonly) NSURLSession* session;
@property (nonatomic, weak) id<PRBackgroundDownloadSessionDelegate> delegate;
@property (nonatomic, readonly) NSString * sessionId;
@property (copy) void (^backgroundSessionCompletionHandler)(void);
@property (nonatomic) BOOL needReloadSessionWhenBecomeInvalidated;

+ (PRBackgroundDownloadSession *) sharedDownloadSession;

- (id) initWithSessionId:(NSString *)sessionId;
- (void) invalidateSession;
- (void) reloadSessionWithCompletionHandler:(void (^)(void)) completionHandler;

// task properties
- (NSError *) completionErrorForTask:(NSString *)taskId;
- (NSURL *) destinationURLForTask:(NSString *)taskId;
- (NSProgress *)progressForTask:(NSString *)taskId;
- (NSURLSessionDownloadTask *) downloadTaskWithId:(NSString *)taskId;
- (NSArray *)allTasks;

// task operations
- (NSURLSessionDownloadTask *) startDownloadTask:(NSString *)taskId from:(NSURL *)downloadURL to:(NSURL *)destinationURL;
- (void) suspendDownloadTask:(NSString *)taskId;
- (void) cancelDownloadTask:(NSString *)taskId;
- (void) removeDownloadTask:(NSString *)taskId;

@end

