//
//  PRCatalogFilterItem.h
//  PRiphone
//
//  Created by Jackie Cane on 05/05/15.
//  Copyright (c) 2015 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

@import PRAPI.PRSourceListFilter;

@class PRSourceList;
@class PRCountableValue;

@interface PRCatalogFilterItem : NSObject

+ (instancetype)categoryFilterItemWithSourceList:(PRSourceList *)list;

@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) NSArray<PRCountableValue *> *filterValues;
@property (nonatomic, assign) PRSourceListFilterID sourceListFilterId;
@property (nonatomic, getter=isActivated) BOOL activated;

@end
