//
//  PRSubscription+Store.h
//  PRiphone
//
//  Created by Jackie Cane on 10/18/12.
//  Copyright (c) 2012 NewspaperDirect. All rights reserved.
//

#import "PRSubscription.h"

@interface PRSubscription (Store)

- (void)saveCatalog;
- (NSArray *)restoreCatalog;

- (void)saveContentCategories;
- (NSArray *)restoreContentCategories;

- (void)saveGroups;
- (NSArray *)restoreGroups;

- (void)saveContentRegions;
- (NSArray *)restoreContentRegions;

- (void)saveFeaturedTitles;
- (NSArray *)restoreFeaturedTitles;

- (void)saveLatestReadExemplars;
- (NSArray *)restoreLatestReadExemplars;

- (void)saveReadingStatistics;
- (NSMutableDictionary *)restoreReadingStatistics;

- (void)saveBookReadingStatistics;
- (NSMutableDictionary *)restoreBookReadingStatistics;

@end
