//
//  PRSourceList+Info.h
//  PR-API
//
//  Created by berec on 17/01/2020.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import "PRSourceList.h"

//@import PRAPI.PRCountableValue;
//@import PRAPI.PRCountableCountry;
//@import PRAPI.PRCountableDictionary;
//@import PRAPI.PRCountableNumber;
//@import PRAPI.PRCountableString;
//@import PRAPI.PRCountry;

#import "PRCountableValue.h"
#import "PRCountableCountry.h"
#import "PRCountableDictionary.h"
#import "PRCountableNumber.h"
#import "PRCountableString.h"
#import "PRCountry.h"

NS_ASSUME_NONNULL_BEGIN

@interface PRSourceList (Info)

- (NSArray<PRCountableDictionary *> *)categoriesInListSortingByAlpha:(BOOL)isSorting;
- (NSArray<PRCountableDictionary *> *)sectionsSortedBy:(PRCatalogSortingOrder)order;

@property (nonatomic, readonly) NSArray<PRCountableNumber *> *typesInList;
@property (nonatomic, readonly) NSArray<PRCountableDictionary *> *categoriesInList;
@property (nonatomic, readonly) NSArray<PRCountableDictionary *> *sectionsInList;
@property (nonatomic, readonly) NSArray<PRCountableString *> *languagesInList;
@property (nonatomic, readonly) NSArray<PRCountableCountry *> *countriesInList;
@property (nullable, nonatomic, readonly) NSArray<PRCountableDictionary *> *countryRegionsInList;

@end

NS_ASSUME_NONNULL_END
