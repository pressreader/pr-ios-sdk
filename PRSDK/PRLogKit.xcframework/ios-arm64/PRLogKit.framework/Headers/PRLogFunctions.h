//
//  PRLogFunctions.h
//  PRLogKit
//
//  Created by Ivan Berezin on 08/07/2024.
//  Copyright © 2024 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef struct {
    const char *file;
    const char *_Nullable function;
    NSUInteger line;
} LogLocation;

#define LOG_LOCATION (LogLocation){ __FILE__, __PRETTY_FUNCTION__, __LINE__ }

void LogVerbose (NSInteger context, LogLocation location, NSString *_Nullable tag, NSString *fmt, ...);
void LogDebug   (NSInteger context, LogLocation location, NSString *_Nullable tag, NSString *fmt, ...);
void LogTrace   (NSInteger context, LogLocation location, NSString *_Nullable tag, NSString *fmt, ...);
void LogError   (NSInteger context, LogLocation location, NSString *_Nullable tag, NSString *fmt, ...);
void LogWarning (NSInteger context, LogLocation location, NSString *_Nullable tag, NSString *fmt, ...);
void LogInfo    (NSInteger context, LogLocation location, NSString *_Nullable tag, NSString *fmt, ...);

NS_ASSUME_NONNULL_END
