//
//  PRLog.h
//  PRiphone
//
//  Created by Vitali Bounine on 5/13/13.
//  Copyright (c) 2013 NewspaperDirect. All rights reserved.
//

#ifndef PRiphone_PRLog_h
#define PRiphone_PRLog_h

#import <CocoaLumberjack/CocoaLumberjack.h>

NS_ASSUME_NONNULL_BEGIN

# undef LOG_INFO
# undef LOG_WARN
# undef LOG_VERBOSE

static const int ddLogLevel = 0xFFFF;
static NSString * _Nullable const _tag_ = nil;
static NSInteger const _context_ = 0;

@interface PRLog : NSObject

+ (instancetype) sharedLog;

+ (void)resetServiceName;

- (void) setupLoggingWithDebugLevel:(NSInteger)debugLevel debugContext:(NSInteger)context;
- (void) setDebugLevel:(NSInteger)debugLevel;
- (void) setDebugContext:(NSInteger)context;
- (void) flush;
- (void) releaseLogging;

@property (nonatomic, assign) BOOL logViewerLoggerEnabled;
@property (nullable, nonatomic, readonly) DDLog *ddSyncLog;

/**
 * Logging Primitive.
 *
 * This method is used by the macros or logging functions.
 * It is suggested you stick with the macros as they're easier to use.
 * Same as LOG_TAG_MACRO
 *
 *  @param asynchronous YES if the logging is done async, NO if you want to force sync
 *  @param level        the log level
 *  @param flag         the log flag
 *  @param context      the context (if any is defined)
 *  @param file         the current file
 *  @param function     the current function
 *  @param line         the current code line
 *  @param tag          potential tag
 *  @param format       the log format
 */
+ (void)log:(BOOL)asynchronous
      level:(DDLogLevel)level
       flag:(DDLogFlag)flag
    context:(NSInteger)context
       file:(const char *)file
   function:(const char *)function
       line:(NSUInteger)line
        tag:(nullable id)tag
     format:(NSString *)format, ... NS_FORMAT_FUNCTION(9,10);

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

@end

#define LOG_TAG_MACRO(async, lvl, flg, ctx, tag, frmt, ...) \
        LOG_MACRO_TO_DDLOG([DDLog sharedInstance], async, lvl, flg, ctx, tag, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__),\
        LOG_MACRO_TO_DDLOG([[PRLog sharedLog] ddSyncLog], NO, lvl, flg, ctx, tag, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)

# define LOG_CONTEXT_VERBOSE( ctx, fmt, ... ) LOG_TAG_MACRO(LOG_ASYNC_ENABLED, DDLogLevelAll, DDLogFlagVerbose, ctx, _tag_, fmt, ##__VA_ARGS__)
# define LOG_VERBOSE( fmt, ... ) LOG_CONTEXT_VERBOSE(_context_, fmt, ##__VA_ARGS__)
# define LOG_CONTEXT_DBG( context, fmt, ... ) LOG_TAG_MACRO(LOG_ASYNC_ENABLED, 1, DDLogFlagDebug, context, _tag_, fmt, ##__VA_ARGS__)
# define LOG_DBG( fmt, ... ) LOG_CONTEXT_DBG(_context_, fmt, ##__VA_ARGS__)
# define LOG_CONTEXT_TRACE( context, fmt, ... ) LOG_TAG_MACRO(LOG_ASYNC_ENABLED, 9, DDLogFlagDebug, context, _tag_, fmt, ##__VA_ARGS__)
# define LOG_TRACE( fmt, ... ) LOG_CONTEXT_TRACE(_context_, fmt, ##__VA_ARGS__)
# define LOG_DBG_IMG( context, img ) LOG_TAG_MACRO(LOG_ASYNC_ENABLED, 9, DDLogFlagDebug, context, img, @"")
# define LOG_DBG_IMG_DESC( context, img, fmt, ... ) LOG_TAG_MACRO(LOG_ASYNC_ENABLED, 9, DDLogFlagDebug, context, img, fmt, ##__VA_ARGS__)
# define LOG_DBG_DATA( context, data ) LOG_TAG_MACRO(LOG_ASYNC_ENABLED, 9, DDLogFlagDebug, context, data, @"")
# define LOG_CONTEXT_INFO( ctx, fmt, ... ) LOG_TAG_MACRO(LOG_ASYNC_ENABLED, DDLogLevelAll, DDLogFlagInfo, ctx, _tag_, fmt, ##__VA_ARGS__)
# define LOG_INFO( fmt, ... ) LOG_CONTEXT_INFO(_context_, fmt, ##__VA_ARGS__)
# define LOG_CONTEXT_WARN( ctx, fmt, ... ) LOG_TAG_MACRO(LOG_ASYNC_ENABLED, DDLogLevelAll, DDLogFlagWarning, ctx, _tag_, fmt, ##__VA_ARGS__)
# define LOG_WARN( fmt, ... ) LOG_CONTEXT_WARN(_context_, fmt, ##__VA_ARGS__)
# define LOG_CONTEXT_ERR( ctx, fmt, ... ) LOG_TAG_MACRO(NO, DDLogLevelAll, DDLogFlagError, ctx, _tag_, fmt, ##__VA_ARGS__)
# define LOG_ERR( fmt, ... ) LOG_CONTEXT_ERR(_context_, fmt, ##__VA_ARGS__)

# define GWS_LOG_DEBUG(fmt, ...) LOG_CONTEXT_VERBOSE(2, fmt, ##__VA_ARGS__)
# define GWS_LOG_VERBOSE(fmt, ...) LOG_CONTEXT_TRACE(2, fmt, ##__VA_ARGS__)
# define GWS_LOG_INFO(fmt, ...) LOG_CONTEXT_INFO(2, fmt, ##__VA_ARGS__)
# define GWS_LOG_WARNING(fmt, ...) LOG_CONTEXT_WARN(2, fmt,##__VA_ARGS__)
# define GWS_LOG_ERROR(fmt, ...) LOG_CONTEXT_ERR(2, fmt, ##__VA_ARGS__)
# define GWS_LOG_EXCEPTION(__EXCEPTION__) GWS_LOG_ERROR(@"WebServer exception:%@", __EXCEPTION__)

// Short & Silent log macros. Prints only to console up to {messageLimit} characters message. Silent in non-DEBUG environment.
#ifdef DEBUG
    static int const messageLimit = 68;
    static NSString *_Nullable message;
#   define SLog(fmt, ...) message = [NSString stringWithFormat:(fmt), ##__VA_ARGS__]; NSLog(@"<%@:%d> %@", [[NSString stringWithUTF8String:__FILE__] lastPathComponent], __LINE__, message.length > messageLimit ? [message substringToIndex:messageLimit] : message);
#else
#   define SLog(...)
#endif

NS_ASSUME_NONNULL_END

#endif
