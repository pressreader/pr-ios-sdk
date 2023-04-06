//
//  UIFont+CoreTextExtensions.h
//  CoreTextWrapper
//
//  Created by Adrian on 4/24/10.
//  Copyright 2010 akosma software. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreText/CoreText.h>

@interface UIFont (CoreTextExtensions)

+ (void)registerFontAtPath:(NSString *)path;
+ (void)registerFontsInDirectoryAtPath:(NSString *)fontsDirectoryPath;

@property (nonatomic, readonly) CTFontRef CTFont;

@end
