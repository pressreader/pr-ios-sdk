//
//  PRCommandManager.h
//  PRiphone
//
//  Created by Oleg Stepanenko on 09.01.13.
//  Copyright (c) 2013 NewspaperDirect. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <PRUIKit/PRCommandNames.h>
@import PRProtocols;

#import "PRContext.h"
#import "PRCommand.h"

NS_ASSUME_NONNULL_BEGIN

@interface PRCommandManager : NSObject <Singleton>

- (PRContext *)createContext;
- (PRContext *)createContextWithKey:(id)key;
- (void)removeContext:(nullable PRContext *)context;
- (nullable PRContext *)contextByKey:(id)key;

- (void)registerCommand:(PRCommand *)command;
- (void)unregisterCommand:(PRCommandName)commandName;

- (nullable __kindof PRCommand *)command:(PRCommandName)commandName;

- (BOOL)executeCommand:(PRCommandName)commandName;
- (BOOL)executeCommand:(PRCommandName)commandName parameters:(nullable NSDictionary *)parameters;

@property (class, nonatomic, readonly) PRCommandManager *instance;

@end

@interface UIViewController (commandManager)

@property (nonatomic, readonly) PRCommandManager *commandManager;

- (nullable PRCommand *)commandWithName:(PRCommandName)commandName;
- (BOOL)isCommandEnabled:(PRCommandName)commandName;
- (BOOL)executeCommand:(PRCommandName)commandName;
- (BOOL)executeCommand:(PRCommandName)commandName parameters:(nullable NSDictionary *)parameters;

@property (nonatomic, readonly) PRContext *controllerContext;
@property (nonatomic, readonly) NSString *contextKey;
- (PRContext *)createControllerContext;
- (void)removeControllerContext;

@end

NS_ASSUME_NONNULL_END
