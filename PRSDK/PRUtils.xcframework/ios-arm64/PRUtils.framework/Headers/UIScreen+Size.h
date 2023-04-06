//
//  UIScreen+Size.h
//  PRiphone
//
//  Created by Jackie Cane on 7/5/12.
//  Copyright (c) 2012 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIScreen (Size)

/**
 Screen pixels density

 @return Screen pixels density or 0 if unknown model or simulator
 */
+ (CGFloat)pixelsPerInch;

/**
 Physical screen diagonal in inches
 
 @return Physical screen diagonal in inches or approxymate value if unknown model or simulator
 */
+ (CGFloat)screenDiagonale;

@end
