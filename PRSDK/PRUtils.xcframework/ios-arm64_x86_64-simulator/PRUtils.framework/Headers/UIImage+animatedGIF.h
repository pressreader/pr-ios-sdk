#import <UIKit/UIKit.h>

@interface UIImage (animatedGIF)

+ (UIImage *)animatedImageWithAnimatedGIFData:(NSData *)data duration:(NSTimeInterval)duration;
+ (UIImage *)animatedImageWithAnimatedGIFData:(NSData *)data scale:(CGFloat)scale duration:(NSTimeInterval)duration;
+ (UIImage *)animatedImageWithAnimatedGIFURL:(NSURL *)url duration:(NSTimeInterval)duration;
+ (UIImage *)animatedImageWithAnimatedGIFURL:(NSURL *)url scale:(CGFloat)scale duration:(NSTimeInterval)duration;
@end
