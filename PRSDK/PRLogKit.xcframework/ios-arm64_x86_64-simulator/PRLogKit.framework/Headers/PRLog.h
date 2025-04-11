//
//  PRLog.h
//  PRiphone
//
//  Created by Vitali Bounine on 5/13/13.
//  Copyright (c) 2013 NewspaperDirect. All rights reserved.
//

#ifndef PRiphone_PRLog_h
#define PRiphone_PRLog_h

#import <Foundation/Foundation.h>
#import <PRLogKit/PRLogFunctions.h>

NS_ASSUME_NONNULL_BEGIN

# undef LOG_INFO
# undef LOG_WARN
# undef LOG_VERBOSE

typedef NS_ENUM(NSUInteger, PRLogType) {
    PRLogTypeDebug,
    PRLogTypeInfo,
    PRLogTypeWarning,
    PRLogTypeError,
    PRLogTypeTrace,
    PRLogTypeVerbose
};

@interface PRLog : NSObject

+ (instancetype)sharedLog;

+ (void)resetServiceName;

- (void) setupLoggingWithDebugLevel:(NSInteger)debugLevel
                       debugContext:(NSInteger)context;
- (void) setDebugLevel:(NSInteger)debugLevel;
- (void) setDebugContext:(NSInteger)context;
- (void) flush;
- (void) releaseLogging;

@property (nonatomic, assign) BOOL logViewerLoggerEnabled;

#pragma mark - PRLog Swift Helpers

+ (void)LogVerbose:(NSString *)message
           context:(NSInteger)context
               tag:(id _Nullable)tag
              file:(const char *)file
          function:(const char *)function
              line:(NSUInteger)line NS_REFINED_FOR_SWIFT;

+ (void)LogDebug:(NSString *)message
         context:(NSInteger)context
             tag:(id _Nullable)tag
            file:(const char *)file
        function:(const char *)function
            line:(NSUInteger)line NS_REFINED_FOR_SWIFT;

+ (void)LogTrace:(NSString *)message
         context:(NSInteger)context
             tag:(id _Nullable)tag
            file:(const char *)file
        function:(const char *)function
            line:(NSUInteger)line NS_REFINED_FOR_SWIFT;

+ (void)LogInfo:(NSString *)message
        context:(NSInteger)context
            tag:(id _Nullable)tag
           file:(const char *)file
       function:(const char *)function
           line:(NSUInteger)line NS_REFINED_FOR_SWIFT;

+ (void)LogWarning:(NSString *)message
           context:(NSInteger)context
               tag:(id _Nullable)tag
              file:(const char *)file
          function:(const char *)function
              line:(NSUInteger)line NS_REFINED_FOR_SWIFT;

+ (void)LogError:(NSString *)message
         context:(NSInteger)context
             tag:(id _Nullable)tag
            file:(const char *)file
        function:(const char *)function
            line:(NSUInteger)line NS_REFINED_FOR_SWIFT;

+ (void)flushLog;

@end

#define LOG_CONTEXT_VERBOSE( context, tag, fmt, ... ) LogVerbose(context, LOG_LOCATION, tag, fmt, ##__VA_ARGS__)
#define LOG_VERBOSE( fmt, ... ) LOG_CONTEXT_VERBOSE(0, nil, fmt, ##__VA_ARGS__)

#define LOG_CONTEXT_DBG( context, tag, fmt, ... ) LogDebug(context, LOG_LOCATION, tag, fmt, ##__VA_ARGS__)
#define LOG_DBG( fmt, ... ) LOG_CONTEXT_DBG(0, nil, fmt, ##__VA_ARGS__)

#define LOG_CONTEXT_TRACE( context, tag, fmt, ... ) LogTrace(context, LOG_LOCATION, tag, fmt, ##__VA_ARGS__)
#define LOG_TRACE( fmt, ... ) LOG_CONTEXT_TRACE(0, nil, fmt, ##__VA_ARGS__)

#define LOG_CONTEXT_INFO( context, tag, fmt, ... ) LogInfo(context, LOG_LOCATION, tag, fmt, ##__VA_ARGS__)
#define LOG_INFO( fmt, ... ) LOG_CONTEXT_INFO(0, nil, fmt, ##__VA_ARGS__)

#define LOG_CONTEXT_WARN( context, tag, fmt, ... ) LogWarning(context, LOG_LOCATION, tag, fmt, ##__VA_ARGS__)
#define LOG_WARN( fmt, ... ) LOG_CONTEXT_WARN(0, nil, fmt, ##__VA_ARGS__)

#define LOG_CONTEXT_ERR( context, tag, fmt, ... ) LogError(context, LOG_LOCATION, tag, fmt, ##__VA_ARGS__)
#define LOG_ERR( fmt, ... ) LOG_CONTEXT_ERR(0, nil, fmt, ##__VA_ARGS__)

#define GWS_LOG_DEBUG(fmt, ...) LOG_CONTEXT_VERBOSE(2, nil, fmt, ##__VA_ARGS__)
#define GWS_LOG_VERBOSE(fmt, ...) LOG_CONTEXT_TRACE(2, nil, fmt, ##__VA_ARGS__)
#define GWS_LOG_INFO(fmt, ...) LOG_CONTEXT_INFO(2, nil, fmt, ##__VA_ARGS__)
#define GWS_LOG_WARNING(fmt, ...) LOG_CONTEXT_WARN(2, nil, fmt,##__VA_ARGS__)
#define GWS_LOG_ERROR(fmt, ...) LOG_CONTEXT_ERR(2, nil, fmt, ##__VA_ARGS__)
#define GWS_LOG_EXCEPTION(__EXCEPTION__) GWS_LOG_ERROR(@"WebServer exception:%@", __EXCEPTION__)

/// Short & Silent log macros. Prints only to console up to {messageLimit} characters message. Silent in non-DEBUG environment.
#ifdef DEBUG
    static int const messageLimit = 68;
    static NSString *_Nullable message;
#   define SLog(fmt, ...) message = [NSString stringWithFormat:(fmt), ##__VA_ARGS__]; NSLog(@"<%@:%d> %@", [[NSString stringWithUTF8String:__FILE__] lastPathComponent], __LINE__, message.length > messageLimit ? [message substringToIndex:messageLimit] : message);
#else
#   define SLog(...)
#endif

NS_ASSUME_NONNULL_END

#endif
