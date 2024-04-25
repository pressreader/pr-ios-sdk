//
//  PRSubscription+Store.h
//  PRAPI
//
//  Created by Jackie Cane on 10/18/12.
//  Copyright (c) 2012 NewspaperDirect. All rights reserved.
//

#import <PRAPI/PRSubscription.h>

NS_ASSUME_NONNULL_BEGIN

@interface PRSubscription (Store)

- (BOOL)saveJSONObject:(nullable id)object toFileName:(NSString *)name error:(NSError *_Nullable *)error;
- (nullable NSData *)restoreJSONObjectFromFileName:(NSString *)name;

- (void)saveCatalog;
- (nullable NSArray *)fetchCatalog;

- (void)saveContentCategories;
- (nullable NSArray *)fetchContentCategories;

- (void)saveGroups;
- (nullable NSArray *)fetchGroups;

- (void)saveContentRegions;
- (nullable NSArray *)fetchContentRegions;

- (void)saveFeaturedTitles;
- (nullable NSArray *)fetchFeaturedTitles;

- (void)saveLatestReadExemplars;
- (nullable NSArray *)fetchLatestReadExemplars;

- (void)saveReadingStatistics;
- (nullable NSMutableDictionary *)fetchReadingStatistics;

- (void)saveBookReadingStatistics;
- (nullable NSMutableDictionary *)fetchBookReadingStatistics;

@end

NS_ASSUME_NONNULL_END
