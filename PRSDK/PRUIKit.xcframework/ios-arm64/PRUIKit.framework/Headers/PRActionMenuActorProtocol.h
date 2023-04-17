//
//  PRActionMenuActorProtocol.h
//  PRUIKit
//
//  Created by Viacheslav Soroka on 12/10/18.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol PRActionMenu <NSObject>

@property (nullable, nonatomic, strong) PRMenu *menu;
@property (nonatomic) CGFloat maximumWidth;
@property (nullable, nonatomic, copy) void (^onMenuDidDismiss)(void);

@end

@protocol PRActionMenuActor <NSObject>

- (instancetype)initWithPresentingVC:(UIViewController<UIPopoverPresentationControllerDelegate> *)vc
                             context:(nullable NSDictionary *)context;

- (void)showActionMenu:(PRMenu *)actionMenu sender:(id)sender;
- (void)showActionMenu:(PRMenu *)actionMenu sender:(id)sender menuHeader:(nullable UIView *)meuHeader;
- (void)showActionMenu:(PRMenu *)actionMenu sourceView:(UIView *)sourceView sourceRect:(CGRect)sourceRect;
- (void)showActionMenu:(PRMenu *)actionMenu sourceView:(UIView *)sourceView sourceRect:(CGRect)sourceRect arrowDirection:(UIPopoverArrowDirection)arrowDirection;

- (void)showActionMenu:(PRMenu *)actionMenu
            sourceView:(UIView *)sourceView
            sourceRect:(CGRect)sourceRect
        arrowDirection:(UIPopoverArrowDirection)arrowDirection
            completion:(nullable void(^)(UIViewController<PRActionMenu> *))completion;

- (void)showActionMenu:(PRMenu *)actionMenu
            sourceView:(UIView *)sourceView
            sourceRect:(CGRect)sourceRect
        arrowDirection:(UIPopoverArrowDirection)arrowDirection
          maximumWidth:(CGFloat)maximumWidth
  popoverLayoutMargins:(UIEdgeInsets)popoverLayoutMargins
            completion:(nullable void(^)(UIViewController<PRActionMenu> *))completion;

- (void)showActionMenu:(PRMenu *)actionMenu
            sourceView:(UIView *)sourceView
            sourceRect:(CGRect)sourceRect
        arrowDirection:(UIPopoverArrowDirection)arrowDirection
            menuHeader:(nullable UIView *)meuHeader;

- (void)showActionMenu:(PRMenu *)actionMenu
            sourceView:(UIView *)sourceView
            sourceRect:(CGRect)sourceRect
        arrowDirection:(UIPopoverArrowDirection)arrowDirection
            menuHeader:(nullable UIView *)meuHeader
            completion:(nullable void(^)(UIViewController<PRActionMenu> *))completion;

@end

NS_ASSUME_NONNULL_END
