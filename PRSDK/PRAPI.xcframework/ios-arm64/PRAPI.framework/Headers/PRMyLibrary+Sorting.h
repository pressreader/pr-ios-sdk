//
//  PRMyLibrary+Sorting.h
//  PR-API
//
//  Created by Viacheslav Soroka on 4/3/19.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import "PRMyLibrary.h"

@class PRMyLibraryItem;

NS_ASSUME_NONNULL_BEGIN

@interface PRMyLibrary (Sorting)
@property (nonatomic, readonly) NSArray<PRMyLibraryItem *> *mliItemsSortedByDate;

@end

NS_ASSUME_NONNULL_END
