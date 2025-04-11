//
//  PRMenuItem.h
//  PRiphone
//
//  Created by Jackie Cane on 15/01/15.
//  Copyright (c) 2015 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>

@class PRMenu;
@class AccessibilityId;

NS_ASSUME_NONNULL_BEGIN

@interface PRMenuItem : NSObject

+ (instancetype)itemWithTitle:(nullable NSString *)title
                      details:(nullable NSString *)details
                         icon:(nullable NSString *)icon;

+ (instancetype)itemWithTitle:(nullable NSString *)title
                      details:(nullable NSString *)details
                        icon:(nullable NSString *)icon
               executionBlock:(nullable void(^)(void))executionBlock;

+ (instancetype)itemWithTitle:(nullable NSString *)title
                      details:(nullable NSString *)details
                        icon:(nullable NSString *)icon
                    checkable:(BOOL)checkable
               executionBlock:(nullable void(^)(void))executionBlock;

+ (instancetype)itemWithTitle:(nullable NSString *)title
                      details:(nullable NSString *)details
                        icon:(nullable NSString *)icon
                      submenu:(nullable PRMenu *)submenu;

- (instancetype)initWithTitle:(nullable NSString *)title
                      details:(nullable NSString *)details
                        icon:(nullable NSString *)icon;

- (instancetype)initWithTitle:(nullable NSString *)title
                      details:(nullable NSString *)details
                        icon:(nullable NSString *)icon
                discloseBlock:(nullable void(^)(__kindof UIViewController * menuVC, PRMenuItem *menuItem))disclose;

- (BOOL)act;

@property (nullable, nonatomic, copy) NSString *analyticsId;
@property (nullable, nonatomic, strong) AccessibilityId *accessibilityId;
@property (nullable, nonatomic, copy) NSString *title;
@property (nonatomic, assign) BOOL hideTitleForSubmenu;
@property (nullable, nonatomic, copy) NSString *details;
@property (nullable, nonatomic, strong) NSString *icon;
@property (nullable, nonatomic, strong) NSDictionary *parameters;

@property (nonatomic) UIImageRenderingMode iconRenderingMode;
@property (nullable, nonatomic, copy) NSString *iconURL;
@property (nonatomic, assign) BOOL iconNotDimmed;
@property (nonatomic, assign) BOOL iconInCircle;
@property (nullable, nonatomic, strong) UIColor *iconTintColor;
@property (nullable, nonatomic, copy) void(^imageProvider)(void(^)(UIImage *));

@property (nullable, nonatomic, strong) PRMenu *submenu;

@property (nonatomic) BOOL shouldUseSubTitleStyle;
@property (nonatomic) BOOL useCustomViewBackgroundColor;

@property (nonatomic, getter=isEnabled) BOOL enabled;

@property (nonatomic, getter=isCheckable) BOOL checkable;
@property (nonatomic, getter=isChecked) BOOL checked;
@property (nonatomic, getter=isSelectable) BOOL selectable;
@property (nonatomic, getter=isDisclosable) BOOL disclosable;
@property (nonatomic, getter=isDeletable) BOOL deletable;

/// If `YES`, menu item should be hidden under `More` menu item.
@property (nonatomic) BOOL isFolded;

@property (nullable, nonatomic, copy) void(^executionBlock)(void);
@property (nullable, nonatomic, copy) void(^disabledExecutionBlock)(void);
@property (nullable, nonatomic, copy) void(^deletedExecutionBlock)(void);
@property (nullable, nonatomic, copy) void(^discloseMenuItemBlock)(__kindof UIViewController *menuVC, PRMenuItem* menuItem);
@property (nullable, nonatomic, copy) void(^didDismissSubmenuBlock)(__kindof UIViewController *submenuVC, PRMenuItem* submenuItem);

@end

NS_ASSUME_NONNULL_END
