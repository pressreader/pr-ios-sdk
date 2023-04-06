//
//  PRMessageBar.m
//  PressReader
//
//  Created by Oleg Stepanenko on 05.02.16.
//  Copyright © 2016 NewspaperDirect. All rights reserved.
//

@import UIKit;
@import PRUIKit.PRGradientLayerView;

NS_ASSUME_NONNULL_BEGIN

@class PRMessageBar;

@protocol PRMessageBarDelegate <NSObject>

@optional
- (void)messageBar:(PRMessageBar *)bar didTouchLink:(NSURL *)url;
- (void)messageBarDidClose:(PRMessageBar *)bar;
- (void)messageBarDidTurnOn:(PRMessageBar *)bar;

@end

@interface PRMessageBar : PRGradientLayerView
@property (nullable, nonatomic, weak) id<PRMessageBarDelegate> delegate;

@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) NSAttributedString *attributedTitle;
@property (nonatomic, strong) NSString *message;
@property (nonatomic, strong) NSAttributedString *attributedMessage;
@property (nonatomic, strong) NSString *onButtonTitle;
@property (nonatomic, getter=isSwitchOn) BOOL switchOn;
@property (nonatomic, readonly) CGFloat viewHeight;

- (void)setCloseButtonTitle:(NSString*)string;
    
@end

NS_ASSUME_NONNULL_END
