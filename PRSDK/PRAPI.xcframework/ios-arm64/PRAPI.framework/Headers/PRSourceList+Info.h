//
//  PRSourceList+Info.h
//  PR-API
//
//  Created by berec on 17/01/2020.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import "PRSourceList.h"

#import <PRAPI/PRCountableValue.h>
#import <PRAPI/PRCountableCountry.h>
#import <PRAPI/PRCountableDictionary.h>
#import <PRAPI/PRCountableNumber.h>
#import <PRAPI/PRCountableString.h>
#import <PRAPI/PRCountry.h>

NS_ASSUME_NONNULL_BEGIN

@interface PRSourceList (Info)

- (NSArray<PRCountableDictionary *> *)categoriesSortedByAlpha:(BOOL)isSorting;
- (NSArray<PRCountableDictionary *> *)sectionsSortedBy:(PRCatalogSortingOrder)order;

- (void)enumerateThroughTitleItems:(BOOL(^)(PRTitleItem *item))block;

@property (nonatomic, readonly) NSArray<PRCountableDictionary *> *categories;
@property (nonatomic, readonly) NSArray<PRCountableDictionary *> *sections;
@property (nonatomic, readonly) NSArray<PRCountableString *> *languages;
@property (nonatomic, readonly) NSArray<PRCountableCountry *> *countries;
@property (nullable, nonatomic, readonly) NSArray<PRCountableDictionary *> *countryRegions;

@end

NS_ASSUME_NONNULL_END
