//
//  PRMenu.h
//  PRiphone
//
//  Created by Oleg Stepanenko on 03.02.14.
//  Copyright (c) 2014 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "PRMenuItem.h"
#import "PRCommandMenuItem.h"
#import "PRCustomCellMenuItem.h"
#import "PRSwitcherMenuItem.h"

#import "PRMenuSection.h"

NS_ASSUME_NONNULL_BEGIN

@interface PRMenu : NSObject

+ (instancetype)menuWithSections:(NSArray<PRMenuSection *> *)sections;

- (void)selectByCommand:(PRCommandName)commandName;
- (void)selectByCommand:(PRCommandName)commandName data:(nullable id)data;

- (nullable PRMenuItem *)itemByCommand:(PRCommandName)commandName;
- (nullable PRMenuItem *)itemByCommand:(PRCommandName)commandName data:(nullable id)data;
- (nullable PRMenuItem *)itemByIndexPath:(NSIndexPath *)index;
- (nullable NSIndexPath *)indexPathForItem:(PRMenuItem *)item;
- (nullable NSIndexPath *)indexPathByCommand:(PRCommandName)commandName data:(nullable id)data;
- (nullable PRMenuItem *)deleteItemAtIndexPath:(NSIndexPath *)indexPath;

- (BOOL)hasEnabledItems;

- (void)setNeedRefreshSections;
- (void)refreshSections;
- (NSArray *)createSections;

- (BOOL)doAction:(NSIndexPath *)indexPath;

@property (nonatomic, copy) NSArray<PRMenuSection *> *sections;
@property (nonatomic, getter=isCompact) BOOL compact;
@property (nullable, nonatomic, readonly) PRMenuItem *selectedItem;
@property (nullable, nonatomic, copy) NSIndexPath *selectedIndex;
@property (nullable, nonatomic, copy) NSString *title;
@property (nonatomic, readonly, getter=isEmpty) BOOL empty;
@property (nonatomic, readonly) BOOL hasSubmenus;

/// Total number of items in all sections
@property (nonatomic, readonly) NSInteger numberOfItems;

@end

NS_ASSUME_NONNULL_END
