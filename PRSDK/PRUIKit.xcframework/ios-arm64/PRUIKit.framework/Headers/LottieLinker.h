//
//  LottieLinker.h
//  PRUI
//
//  Created by berec on 07/07/2020.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface LottieLinker : NSObject

+ (nullable UIView *)lottieAnimationViewWithJSON:(NSString *)name
                                        progress:(CGFloat)progress;

@end

NS_ASSUME_NONNULL_END
