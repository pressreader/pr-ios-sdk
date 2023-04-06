//
//  PRSwitchButton.h
//  PR-UI
//
//  Created by Viacheslav Soroka on 4/4/19.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface PRSwitchButton : UIButton
@property (nonatomic, getter=isOn) BOOL on;

- (void)switchValue;

- (void)setBackgroundImage:(nullable UIImage *)image forSwitchState:(BOOL)state;
- (nullable UIImage *)backgroundImageForSwitchState:(BOOL)state;

- (void)setImage:(nullable UIImage *)image forSwitchState:(BOOL)state;
- (nullable UIImage *)imageForSwitchState:(BOOL)state;

- (void)setBackgroundColor:(nullable UIColor *)backgroundColor forSwitchState:(BOOL)state;
- (nullable UIColor *)backgroundColorForSwitchState:(BOOL)state;

- (void)setTintColor:(nullable UIColor *)tintColor forSwitchState:(BOOL)state;
- (nullable UIColor *)tintColorForSwitchState:(BOOL)state;

- (void)setTitle:(nullable NSString *)title forSwitchState:(BOOL)state;
- (nullable NSString *)titleForSwitchState:(BOOL)state;

- (void)setTitleColor:(nullable UIColor *)tintColor forSwitchState:(BOOL)state;
- (nullable UIColor *)titleColorForSwitchState:(BOOL)state;

@end

NS_ASSUME_NONNULL_END
