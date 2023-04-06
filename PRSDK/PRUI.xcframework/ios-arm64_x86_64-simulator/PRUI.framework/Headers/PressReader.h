//
//  PressReader.h
//  PressReader
//
//  Created by Jackie Cane on 7/2/12.
//  Copyright (c) 2012 Noname. All rights reserved.
//

#import "PRiphoneAppDelegate.h"
#import <PRUI/PRModel+API.h>

@class PRCatalog;

NS_ASSUME_NONNULL_BEGIN

/// Notification's userInfo contains:
/// `stateType`: PRStateType;
/// `oldValue`: Bool wrapped into NSNumber;
/// `newValue`: Bool wrapped into NSNumber;
/// `error`: NSError describes occured error responsible for negative `newValue`.
extern NSNotificationName PressReaderStateDidChange;

typedef NS_ENUM(NSUInteger, PRStateType) {
    PRStateTypeRunning = 0,
    PRStateTypeActivated,
    PRStateTypeCatalogLoaded
};

typedef NS_OPTIONS(NSUInteger, PRState) {
    PRStateRunning = 1 << PRStateTypeRunning,
    PRStateActivated = 1 << PRStateTypeActivated,
    PRStateCatalogLoaded = 1 << PRStateTypeCatalogLoaded
};

/// Main interface of PressReader framework.
@interface PressReader : PRiphoneAppDelegate

/// PressReader performs its activation during the very first launch on a new device.
/// In regular situation you won't need to call this method mannually.
/// It makes sense only if state hasn't turned to .activated due to a network error.
- (void)reactivate;

/// PressReader performs loading and update of the catalog automatically.
/// In regular situation you won't need to call this method mannually.
/// It makes sense only if state hasn't turned to .catalogLoaded  due to a network error.
- (void)reloadCatalog;

@property (class, nonatomic, readonly) NSString *serviceName;
@property (class, nonatomic, readonly) BOOL isLocalService;
@property (class, nonatomic, readonly) BOOL isEdition;

/// Assign before first time accessing PressReader singleton `instance` when it's create or after calling `dismiss` class method
@property (class, nullable, nonatomic, copy) NSDictionary<UIApplicationLaunchOptionsKey, id> *launchOptions;

@property (nonatomic, assign, readonly) PRState state;
@property (nonatomic, readonly) PRCatalog *catalog;

@property (nonatomic, strong, readonly) UIViewController *rootViewController;

@property (nonatomic) BOOL removeAllContent;

@end


@interface PressReader (Destructive)
/// Resets authorisation and removes all content. Must be called before initialisation.
+ (void)fullReset;

@end


@interface PressReader (/*PRIVATE*/)
- (void)stop;
@end

NS_ASSUME_NONNULL_END

#import "PRiphoneAppDelegate+Commands.h"
