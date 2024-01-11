//
//  PRCatalogFilterItem.h
//  PRAPI
//
//  Created by Jackie Cane on 05/05/15.
//  Copyright (c) 2015 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PRAPI/PRSourceListFilter.h>

@protocol CatalogFacade;
@class PRCountableValue;

NS_ASSUME_NONNULL_BEGIN

@interface PRCatalogFilterItem : NSObject

+ (nullable instancetype)categoryFilterItemWithSourceList:(id<CatalogFacade>)list;

@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) NSArray<PRCountableValue *> *filterValues;
@property (nonatomic, getter=isActivated) BOOL activated;
@property (nonatomic, strong, readonly) id<CatalogFacade> sourceList;

@end

NS_ASSUME_NONNULL_END
