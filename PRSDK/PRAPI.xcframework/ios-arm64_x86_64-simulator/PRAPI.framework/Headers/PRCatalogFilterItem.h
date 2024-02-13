//
//  PRCatalogFilterItem.h
//  PRAPI
//
//  Created by Jackie Cane on 05/05/15.
//  Copyright (c) 2015 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PRAPI/PRSourceListFilter.h>

@class PRSourceList;
@class PRCountableValue;

NS_ASSUME_NONNULL_BEGIN

@interface PRCatalogFilterItem : NSObject

+ (nullable instancetype)categoryFilterItemWithSourceList:(PRSourceList *)list;

@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) NSArray<PRCountableValue *> *filterValues;
@property (nonatomic, getter=isActivated) BOOL activated;
@property (nonatomic, strong, readonly) PRSourceList *sourceList;

@end

NS_ASSUME_NONNULL_END
