//
//  PRCommand.h
//  PRiphone
//
//  Created by Oleg Stepanenko on 09.01.13.
//  Copyright (c) 2013 NewspaperDirect. All rights reserved.
//

#import <PRUIKit/PRCommandNames.h>
#import <PRUIKit/PRContext.h>
#import <PRUIKit/PRAppPanel.h>


NS_ASSUME_NONNULL_BEGIN

@interface PRCommand : NSObject

+ (instancetype)command;
+ (instancetype)commandWithName:(PRCommandName)name;

- (instancetype)initWithName:(PRCommandName)name;

- (void)invokeWithParameters:(nullable NSDictionary *)parameters;

- (BOOL)isCheckedWithParameters:(NSDictionary *)parameters;
- (BOOL)isCheckable;
- (BOOL)isSelectable;
- (BOOL)isEnabledForParameters:(nullable NSDictionary *)parameters;

- (NSMutableDictionary *)combinedContextWithInvokeParameters:(NSDictionary *)parameters;

- (PRPanelId)panelIdForParameters:(NSDictionary *)parameters;

@property (class, nonatomic, readonly) PRCommandName defaultCommandName;

@property (nonatomic, strong) PRCommandName name;
@property (nonatomic, getter=isEnabled) BOOL enabled;
@property (nullable, nonatomic, strong) id result;
@property (nullable, nonatomic, weak) PRContext *context;
@property (nonatomic, readonly) PRPanelId panelID;

@end

@interface PRCommand (Global)

+ (void)executeWithParameters:(nullable NSDictionary *)parameters;
+ (void)execute;

@property (class, nonatomic, readonly) BOOL isEnabled;

@end

NS_ASSUME_NONNULL_END
