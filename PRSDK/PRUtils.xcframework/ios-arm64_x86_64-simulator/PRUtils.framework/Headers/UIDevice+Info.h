//
//  UIDevice+Info.h
//  PRComponents
//
//  Created by Jackie Cane on 6/7/12.
//  Copyright (c) 2012 Noname. All rights reserved.
//

#import <UIKit/UIKit.h>

#pragma mark Device Info Extensions

/*
 *  System Versioning Preprocessor Macros
 */ 

#define SYSTEM_VERSION_EQUAL_TO(v)                  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedSame)
#define SYSTEM_VERSION_GREATER_THAN(v)              ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedDescending)
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN(v)                 ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(v)     ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedDescending)

typedef struct {
    /// Major device model. e.g. 2 for iPhone2,1
    NSUInteger major;
    /// Minor device model. e.g. 1 for iPhone2,1
    NSUInteger minor;
} PRDeviceVersion;

@interface UIDevice (Info)

+ (NSDictionary *)currentWifiInfo;
+ (NSString *)currentWifiSSID;
+ (UInt64)currentWifiBSSID;
+ (PRDeviceVersion)deviceVersion;
+ (NSString *)rawSystemInfoString;

- (NSString *)platform;
- (NSString *)platformString;
- (NSString *)UDID;
- (NSString *)appSpecificUDID;
- (void)resetUDIDPersistentCache;
- (NSString *)macAddr;

@property (class, nonatomic, readonly) BOOL isPhone;

@end



