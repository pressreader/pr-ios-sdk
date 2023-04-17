//
//  PRAppPanelManager.h
//  PRiphone
//
//  Created by Jackie Cane on 09/09/15.
//  Copyright (c) 2015 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>
@import PRUIKit.PRAppPanel;
@import PRAPI.PROptions;

NS_ASSUME_NONNULL_BEGIN

@class PRPromise;

@interface PRAppPanelsManager : NSObject

- (PRAppPanel *)addPanel:(PRPanelId)anId content:(id) content;
- (BOOL)removePanel:(PRPanelId)anId;
- (nullable PRAppPanel *)panelById:(PRPanelId)anId;

- (void)didReceiveMemoryWarning;

- (PRPromise *)updateFirstPanelWhenReady;

- (void)openPreferredPanel;
- (void)openPreferredPanelForced:(BOOL)forced;
- (void)setCurrentPanelId:(PRPanelId)current popToRootIfSame:(BOOL)popToRoot;

@property (nonatomic) PRPanelId currentPanelId;
@property (nonatomic) PRAppPanelID defaultPanelIdToOpenOnce;
@property (nullable, nonatomic, readonly) PRAppPanel *currentPanel;

@property (nullable, nonatomic, copy) void(^openFirstPanelPreprocessor)(void);

@end

NS_ASSUME_NONNULL_END
