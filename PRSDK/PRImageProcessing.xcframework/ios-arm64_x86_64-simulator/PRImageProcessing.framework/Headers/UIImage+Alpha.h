// UIImage+Alpha.h
// Created by Trevor Harmon on 9/20/09.
// Free for personal or commercial use, with or without modification.
// No warranty is expressed or implied.

// Helper methods for adding an alpha layer to an image

//#ifdef PR_IOS
#import <UIKit/UIKit.h>
//#else
//#import <Cocoa/Cocoa.h>
//typedef NSImage UIImage;
//#endif

@interface UIImage (Alpha)
- (BOOL)hasAlpha;
- (UIImage *)imageWithAlpha;
- (UIImage *)imageByApplyingAlpha:(CGFloat)alpha;
- (UIImage *)transparentBorderImage:(NSUInteger)borderSize;
@end
