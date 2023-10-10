//
//  NSManagedObjectContext+Request.h
//  PR-API
//
//  Created by berec on 08/05/2018.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import <CoreData/CoreData.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSArray<__kindof NSManagedObject *> *_Nullable CDFetchResult;

@interface NSManagedObjectContext (Request)

- (NSUInteger)recordsCountForEntity:(NSString *)entityName
                          predicate:(nullable NSPredicate *)predicate;

- (CDFetchResult)fetchItemsForEntity:(NSString *)entityName
                           predicate:(nullable NSPredicate *)predicate
                     sortDescriptors:(nullable NSArray<NSSortDescriptor *> *)sortDescriptors
                              offset:(NSUInteger)fetchOffset
                               limit:(NSUInteger)fetchLimit;

- (CDFetchResult)fetchItemsForEntity:(NSString *)entityName
                           predicate:(nullable NSPredicate *)predicate
                     sortDescriptors:(nullable NSArray<NSSortDescriptor *> *)sortDescriptors
                               limit:(NSUInteger)fetchLimit;

- (CDFetchResult)fetchItemsForEntity:(NSString *)entityName
                           predicate:(nullable NSPredicate *)predicate
                     sortDescriptors:(nullable NSArray<NSSortDescriptor *> *)sortDescriptors;

- (CDFetchResult)fetchItemsForEntity:(NSString *)entityName
                           predicate:(nullable NSPredicate *)predicate;

- (nullable __kindof NSManagedObject *)fetchItemForEntity:(NSString *)entityName
                                                predicate:(nullable NSPredicate *)predicate
                                          sortDescriptors:(nullable NSArray<NSSortDescriptor *> *)sortDescriptors;

- (CDFetchResult)fetchItemsForEntity:(NSString *)entityName
                      primaryFilters:(NSDictionary<NSString *, id> *)primaryFilters
                    secondaryFilters:(nullable NSDictionary<NSString *, id> *)secondaryFilters
                          fetchLimit:(NSUInteger)fetchLimit;

@end

NS_ASSUME_NONNULL_END
