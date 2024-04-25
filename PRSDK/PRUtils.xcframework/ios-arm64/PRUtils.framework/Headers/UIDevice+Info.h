//
//  UIDevice+Info.h
//  PRComponents
//
//  Created by Jackie Cane on 6/7/12.
//  Copyright (c) 2012 Noname. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

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

+ (UInt64)currentWifiBSSID;
+ (PRDeviceVersion)deviceVersion;

- (void)resetUDIDPersistentCache;

@property (class, nonatomic, readonly) BOOL isPhone;
@property (class, nullable, nonatomic, readonly) NSDictionary *currentWifiInfo;
@property (class, nullable, nonatomic, readonly) NSString *currentWifiSSID;
@property (class, nullable, nonatomic, readonly) NSString *rawSystemInfoString;
@property (nullable, nonatomic, readonly) NSString *appSpecificUDID;
@property (nullable, nonatomic, readonly) NSString *platform;
@property (nullable, nonatomic, readonly) NSString *platformString;
@property (nullable, nonatomic, readonly) NSString *UDID;
@property (nullable, nonatomic, readonly) NSString *advertisingIdentifier;
@property (nonatomic, readonly) NSString *macAddr;

@end

NS_ASSUME_NONNULL_END

