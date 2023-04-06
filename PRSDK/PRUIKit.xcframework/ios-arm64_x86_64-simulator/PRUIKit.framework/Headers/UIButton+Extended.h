//
//  UIButton+Extended.h
//  PRiphone
//
//  Created by Jackie Cane on 3/30/12.
//  Copyright (c) 2012 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIButton (Extended)

- (void)setupWithNormalImage:(NSString *)normalImageName 
              highlightImage:(NSString *)highlightImageName;

- (void)setupWithNormalImage:(NSString *)normalImageName 
              highlightImage:(NSString *)highlightImageName
                    capWidth:(CGFloat)capWidth;

/// set the amount of spacing to appear between image and title
- (void)setSpaceBetweenImageAndTitle:(CGFloat)spacing;

@end
