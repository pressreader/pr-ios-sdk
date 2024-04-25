//
//  PRCatalog+RecentlyRead.h
//  PR-API
//
//  Created by berec on 17/01/2020.
//  Copyright © 2020 NewspaperDirect. All rights reserved.
//

#import "PRCatalog.h"

#import "PROptions.h"

NS_ASSUME_NONNULL_BEGIN

typedef NSArray<PRTitleItemExemplar *> PRExemplars;

@interface PRCatalog (RecentlyRead)

- (void)updateRecentlyReadWithExemplars:(NSArray<PRTitleItemExemplar *> *)exemplars;

// {cid:{date1:exemplar1, date2:exemplar2}, cid2:{date1:exemplar3}...}
@property (nonatomic, strong, readonly) NSDictionary *recentlyReadExemplarsByCID;

@property (nonatomic, strong, readonly) PRExemplars *recentlyReadExemplars;

@end

NS_ASSUME_NONNULL_END
