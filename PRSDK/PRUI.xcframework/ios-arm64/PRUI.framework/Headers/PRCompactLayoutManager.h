//
//  PRCompactLayoutManager.h
//  PR-UI
//
//  Created by Viacheslav Soroka on 7/5/18.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import <PRUI/PRFeedLayoutManager.h>
@import CoreData;

NS_ASSUME_NONNULL_BEGIN

@class NTFFeedDataSource;

@interface PRCompactLayoutManager : NSObject<PRFeedLayoutManager>

- (instancetype)initWithOptions:(NTFLayoutOption)options;

@property (nonatomic, readonly) BOOL needsRefreshBanners;

@property (nonatomic, strong) NSManagedObjectID *highlightedObjectID;

@end

NS_ASSUME_NONNULL_END

#import <PRUI/PRCompactLayoutManager_Protected.h>
