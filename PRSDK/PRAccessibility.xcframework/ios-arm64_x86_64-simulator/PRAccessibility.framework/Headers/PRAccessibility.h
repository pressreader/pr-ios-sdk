//
//  PRAccessibility.h
//  PRAccessibility
//
//  Created by berec on 30/04/2020.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

//! Project version number for PRAccessibility.
FOUNDATION_EXPORT double PRAccessibilityVersionNumber;

//! Project version string for PRAccessibility.
FOUNDATION_EXPORT const unsigned char PRAccessibilityVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <PRAccessibility/PublicHeader.h>

typedef NS_ENUM(NSInteger, PRTheme) {
    PRThemeUndefined = 0,
    PRThemeLight,
    PRThemeDark,
    PRThemeDarkBrand
};

#import <PRAccessibility/PRLaunchCommand.h>
