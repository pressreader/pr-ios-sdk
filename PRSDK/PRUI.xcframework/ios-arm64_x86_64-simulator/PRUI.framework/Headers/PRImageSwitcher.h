//
//  PRImageSwitcher.h
//  PR-UI
//
//  Created by Vitali Bounine on 2018-12-28.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(uint8_t, PRImageSwitcherAnimationStyle) {
    PRImageSwitcherAnimationStyleNone = 0,
    PRImageSwitcherAnimationStyleLeft,
    PRImageSwitcherAnimationStyleRight
};

@interface PRImageSwitcher: UIView
- (void) switchImageWithID:(id)imageID animationStyle:(PRImageSwitcherAnimationStyle)style loadImage:(void(^)(void(^)(UIImage * _Nullable)))loadingBlock;
@property (nonatomic, copy, nullable) void(^tapHandler)(__kindof PRImageSwitcher *);
@property (nonatomic, strong) UIColor *placeholderBackgroundColor;
@end


NS_ASSUME_NONNULL_END
