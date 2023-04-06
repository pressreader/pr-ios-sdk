//
//  PRAggregatedLibraryItem.h
//  PRiphone
//
//  Created by Jackie Cane on 11/02/15.
//  Copyright (c) 2015 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>
@import PRCatalogModel.PRSourceItem_Basics;

@class PRMyLibraryItem;
@protocol PRCatalogItem;
@protocol OpenedItem;

@interface PRAggregatedLibraryItem : NSObject

+ (instancetype)aggregatedLibraryItemFor:(PRMyLibraryItem *)myLibraryItem;
- (instancetype)initWith:(id<PRCatalogItem, OpenedItem>)libraryItem sourceType:(PRSourceType)sourceType;

@property (nonatomic, strong) NSString *libItemCID;
@property (nonatomic, strong) NSString *title;
@property (nonatomic, assign) PRSourceType sourceType;
@property (nonatomic, strong) NSMutableArray<PRCatalogItem, OpenedItem> *libraryItems;

@end
