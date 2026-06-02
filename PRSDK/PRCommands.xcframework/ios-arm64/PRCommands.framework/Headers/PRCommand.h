//
//  PRCommand.h
//  PRiphone
//
//  Created by Oleg Stepanenko on 09.01.13.
//  Copyright (c) 2013 NewspaperDirect. All rights reserved.
//

#import <PRCommands/PRCommandNames.h>
#import <PRCommands/PRContext.h>
#import <PRSyntacticSugar/PRSyntacticSugar.h>

NS_ASSUME_NONNULL_BEGIN

@interface PRCommand : NSObject

+ (instancetype)command;
+ (instancetype)commandWithName:(PRCommandName)name;
+ (BOOL)isEnabledForParameters:(NSDictionary *)parameters;

- (instancetype)initWithName:(PRCommandName)name NS_DESIGNATED_INITIALIZER;

- (void)invokeWithParameters:(nullable NSDictionary *)parameters NS_SWIFT_MAIN_ACTOR;

- (BOOL)isCheckedWithParameters:(NSDictionary *)parameters;
- (BOOL)isCheckable;
- (BOOL)isSelectable;
- (BOOL)isEnabledForParameters:(nullable NSDictionary *)parameters;

- (NSMutableDictionary *)combinedContextWithInvokeParameters:(nullable NSDictionary *)parameters;

@property (class, nonatomic, readonly) PRCommandName defaultCommandName;

@property (nonatomic, strong) PRCommandName name;
@property (nonatomic, readonly) BOOL isEnabled NS_SWIFT_MAIN_ACTOR;
@property (nullable, nonatomic, strong) id result;
@property (nullable, nonatomic, weak) PRContext *context;
@property (nullable, nonatomic, copy) PRCompletionBlock completionHandler;

@end

@interface PRCommand (Global)

+ (void)execute NS_SWIFT_MAIN_ACTOR;

+ (void)executeWithParameters:(nullable NSDictionary *)parameters
NS_SWIFT_NAME(execute(parameters:)) NS_SWIFT_MAIN_ACTOR;

+ (void)executeWithParameters:(nullable NSDictionary *)parameters
            completionHandler:(nullable PRCompletionBlock)completionHandler
NS_SWIFT_NAME(execute(parameters:completionHandler:)) NS_SWIFT_MAIN_ACTOR;

@property (class, nonatomic, readonly) BOOL isEnabled;

@end

NS_ASSUME_NONNULL_END
