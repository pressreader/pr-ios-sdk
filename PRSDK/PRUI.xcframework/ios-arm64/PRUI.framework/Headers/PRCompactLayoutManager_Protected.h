//
//  PRCompactLayoutManager_Protected.h
//  PRiphone
//
//  Created by Viacheslav Soroka on 1/29/19.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#ifndef PRCompactLayoutManager_Protected_h
#define PRCompactLayoutManager_Protected_h

#import "PRCompactLayoutManager.h"
@import PRAPI.NTFSection;

NS_ASSUME_NONNULL_BEGIN

@class NTFArticleItem;
@class AbstractFeedLayoutItem;

typedef NSObject<NTFArticle> * PRArticle;

@interface PRCompactLayoutManager ()

- (void)updateHighlightedPropertyForArticle:(PRArticle)article
                                      index:(NSUInteger)idx
                             itemAtIndex:(id _Nullable(^)(NSInteger index))itemAtIndex
                        previousArticle:(PRArticle _Nullable(^)(void))previousArticle;

- (void)insertMoreItemForSection:(id<NTFSection>)section
                    dataProvider:(NSMutableArray *)dataProvider
         preferredColumnsCount:(NSInteger)preferredColumnsCount;

- (NSArray *)compileDataProviderWithItems:(NSArray *)items
                                  context:(nullable NSManagedObjectContext *)context
                            targetContext:(nullable NSManagedObjectContext *)targetContext
                               moreFollow:(BOOL)moreFollow;

- (BOOL)isArticleCoupleEligible:(PRArticle)articleItem;

- (AbstractFeedLayoutItem *)coupleLookupForArticle:(PRArticle)article
                                             index:(NSInteger)idx
                                        totalCount:(NSInteger)totalCount
                                     targetContext:(nullable NSManagedObjectContext *)targetContext
                                    articleAtIndex:(PRArticle _Nullable(^)(NSInteger index))articleAtIndex;

@property (nullable, nonatomic, strong) NSManagedObjectID *lastSectionId;

@end

NS_ASSUME_NONNULL_END

#endif /* PRCompactLayoutManager_Protected_h */
