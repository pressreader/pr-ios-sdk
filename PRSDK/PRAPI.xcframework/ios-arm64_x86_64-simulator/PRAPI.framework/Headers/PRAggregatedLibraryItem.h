//
//  PRAggregatedLibraryItem.h
//  PRiphone
//
//  Created by Jackie Cane on 11/02/15.
//  Copyright (c) 2015 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PRAPI/PRCatalogItem.h>
#import <PRAPI/PROpenableItem.h>
@import PRCatalogModel.PRSourceItem_Basics;

@class PRMyLibraryItem;

@interface PRAggregatedLibraryItem : NSObject

- (instancetype)initWith:(id<PRCatalogItem, PROpenableItem>)libraryItem sourceType:(PRSourceType)sourceType;

@property (nonatomic, strong) NSString *libItemCID;
@property (nonatomic, strong) NSString *title;
@property (nonatomic, assign) PRSourceType sourceType;
@property (nonatomic, strong) NSMutableArray<PRCatalogItem, PROpenableItem> *libraryItems;

@end
