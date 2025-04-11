//
//  PRCommand.h
//  PRiphone
//
//  Created by Oleg Stepanenko on 09.01.13.
//  Copyright (c) 2013 NewspaperDirect. All rights reserved.
//

#import <PRCommands/PRCommandNames.h>
#import <PRCommands/PRContext.h>

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

@property (class, nonatomic, readonly) PRCommandName defaultCommandName;

@property (nonatomic, strong) PRCommandName name;
@property (nonatomic, readonly) BOOL isEnabled;
@property (nullable, nonatomic, strong) id result;
@property (nullable, nonatomic, weak) PRContext *context;

@end

@interface PRCommand (Global)

+ (void)executeWithParameters:(nullable NSDictionary *)parameters;
+ (void)execute;

@property (class, nonatomic, readonly) BOOL isEnabled;

@end

NS_ASSUME_NONNULL_END
