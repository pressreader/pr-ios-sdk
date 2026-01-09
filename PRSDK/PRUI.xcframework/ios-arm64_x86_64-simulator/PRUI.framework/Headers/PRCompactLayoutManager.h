//
//  PRCompactLayoutManager.h
//  PRUI
//
//  Created by Viacheslav Soroka on 7/5/18.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import <PRUI/PRFeedLayoutManager.h>
@import CoreData;

NS_ASSUME_NONNULL_BEGIN

@class NTFFeedDataSource;
@protocol NTFSection;

@interface PRCompactLayoutManager : NSObject<PRFeedLayoutManager>

- (instancetype)initWithOptions:(NTFLayoutOption)options;

@property (nonatomic, readonly) BOOL needsRefreshBanners;

@property (nonatomic, strong) NSManagedObjectID *highlightedObjectID;

@end


@interface PRCompactLayoutManager (/*PROTECTED*/)

- (NSArray *)compileDataProviderWithItems:(NSArray *)items
                                  context:(nullable NSManagedObjectContext *)context
                            targetContext:(nullable NSManagedObjectContext *)targetContext
                               moreFollow:(BOOL)moreFollow;

- (void)insertMoreItemForSection:(id<NTFSection>)section
                    dataProvider:(NSMutableArray *)dataProvider
           preferredColumnsCount:(NSInteger)preferredColumnsCount;

@end

NS_ASSUME_NONNULL_END
