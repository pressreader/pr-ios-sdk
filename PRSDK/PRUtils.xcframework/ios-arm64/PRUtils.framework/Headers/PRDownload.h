//
//  PRDownload.h
//  PRiphone
//
//  Created by Dmitry Melnik on 02/09/08.
//  Copyright 2008 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class PRDownload, PRPromise;

@protocol PRDownloadDelegate <NSObject>

@required
- (void)onDownloadError:(PRDownload *)d;
- (void)onDownloadFinished:(PRDownload *)d;

@optional
- (void)onDownloadProgress:(PRDownload*)d;

@end

@interface PRDownload : NSObject {
    UIBackgroundTaskIdentifier m_bgTask;
}

@property (nullable, nonatomic, strong) id userdata;

@property (nonatomic, assign) uint64_t fileLength;
@property (nonatomic, assign) uint64_t currentLength;
@property (nullable, nonatomic, weak) NSObject<PRDownloadDelegate> *delegate;
@property (nonatomic, assign) BOOL deleteFileOnDealloc;
@property (nonatomic, assign) BOOL deleteFileOnError;

@property (nonatomic, readonly, copy) NSString *filePath;
@property (nullable, nonatomic, readonly) NSError *error;
@property (nonatomic, readonly) unsigned long long currentDownloadLength;
@property (nullable, nonatomic, readonly) NSDate *startTime;
@property (nullable, nonatomic, readonly) NSDate *stopTime;
@property (nonatomic, readonly) double speed;
@property (nonatomic, readonly) NSProgress *progress;

@property (nullable, nonatomic, copy) void(^progressBlock)(PRDownload *d);

+ (nullable instancetype)getActiveDownloadWithFile:(NSString *)filePath andUrls:(NSArray<NSString *> *)urls;

- (instancetype)initWithFile:(NSString *)filePath;
- (instancetype)initWithExpectedTotalLength:(unsigned long long)totalLength;

- (BOOL)downloadFile:(NSString *)filePath fromUrls:(NSArray<NSString *> *)urls;
- (PRPromise *)downloadTo:(NSString *)filePath from:(NSArray<NSString *> *)urls;
- (void)cancel;

@end

NS_ASSUME_NONNULL_END
