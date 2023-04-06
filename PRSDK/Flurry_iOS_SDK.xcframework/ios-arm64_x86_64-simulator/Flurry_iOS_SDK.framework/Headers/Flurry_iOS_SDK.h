//
//  Flurry_iOS_SDK.h
//  Flurry_iOS_SDK
//
//  Created by Vitali Bounine on 2022-05-15.
//  Copyright © 2022 NewspaperDirect. All rights reserved.
//

/// This framework is provided as Dynamic framework around static Flurry library v 12.0.1 along with its dependency, custom PLCrashReporter,  distributed via CocoaPods.
/// Public headers are declared directly from embedded static Flurry framework
/// To avoid compilation conflicts between embedded custom PLCrashReported and one used by PressReader project this framwork should be prebuilt via Dependency cache.

#import <Foundation/Foundation.h>

//! Project version number for Flurry_iOS_SDK.
FOUNDATION_EXPORT double Flurry_iOS_SDKVersionNumber;

//! Project version string for Flurry_iOS_SDK.
FOUNDATION_EXPORT const unsigned char Flurry_iOS_SDKVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <Flurry_iOS_SDK/PublicHeader.h>

#import "FlurryUmbrella.h"
