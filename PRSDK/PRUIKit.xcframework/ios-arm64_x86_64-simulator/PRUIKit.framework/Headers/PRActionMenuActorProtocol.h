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
@property (nullable, nonatomic, copy) void (^menuDidDismissBlock)(void);

@end

@protocol PRActionMenuActor <NSObject>

- (instancetype)initWithPresentingVC:(UIViewController<UIPopoverPresentationControllerDelegate> *)vc
                             context:(nullable NSDictionary *)context;

- (UIViewController<PRActionMenu> *)showActionMenu:(PRMenu *)actionMenu sender:(id)sender;
- (UIViewController<PRActionMenu> *)showActionMenu:(PRMenu *)actionMenu sender:(id)sender menuHeader:(nullable UIView *)meuHeader;
- (UIViewController<PRActionMenu> *)showActionMenu:(PRMenu *)actionMenu sourceView:(UIView *)sourceView sourceRect:(CGRect)sourceRect;
- (UIViewController<PRActionMenu> *)showActionMenu:(PRMenu *)actionMenu sourceView:(UIView *)sourceView sourceRect:(CGRect)sourceRect arrowDirection:(UIPopoverArrowDirection)arrowDirection;
- (UIViewController<PRActionMenu> *)showActionMenu:(PRMenu *)actionMenu sourceView:(UIView *)sourceView sourceRect:(CGRect)sourceRect arrowDirection:(UIPopoverArrowDirection)arrowDirection menuHeader:(nullable UIView *)meuHeader;

@end

NS_ASSUME_NONNULL_END
