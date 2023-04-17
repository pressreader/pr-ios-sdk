//
//  UIButton+Extended.h
//  PRiphone
//
//  Created by Jackie Cane on 3/30/12.
//  Copyright (c) 2012 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>
@import PRSyntacticSugar;

typedef void (^PRButtonConfigurationBlock)(UIButtonConfiguration * _Nonnull config);

@interface UIButton (Extended)

- (void)setupWithNormalImage:(NSString *_Nullable)normalImageName
              highlightImage:(NSString *_Nullable)highlightImageName;

- (void)setupWithNormalImage:(NSString *_Nullable)normalImageName
              highlightImage:(NSString *_Nullable)highlightImageName
                    capWidth:(CGFloat)capWidth;

- (void)configure:(PRButtonConfigurationBlock _Nonnull )block PR_NON_SWIFT;

@end
