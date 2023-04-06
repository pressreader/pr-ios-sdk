//
//  NTFFeedDataSource+Search.h
//  PR-UI
//
//  Created by berec on 08/05/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//

#import "NTFFeedDataSource.h"

NS_ASSUME_NONNULL_BEGIN

@interface NTFFeedDataSource (Search)

/**
 * @brief returns one filtered feed item corresponds to filter criterias.
 * @param filters dictionary of attribute and values
 */
- (nullable __kindof NTFFeedItem *)feedItemWithAttributesAndValues:(nullable NSDictionary<NSString *, id> *)filters;
- (__kindof NTFFeedItem *)feedItemOfEntity:(NSString *)feedItemEntity
                       attributesAndValues:(NSDictionary<NSString *, id> *)filters;

- (NSArray<__kindof NTFFeedItem *> *)feedItemsWithAttributesAndValues:(NSDictionary<NSString *, id> *)filters;
- (nullable NSArray<__kindof NTFFeedItem *> *)feedItemsOfEntity:(NSString *)feedItemEntity
                                            attributesAndValues:(nullable NSDictionary<NSString *, id> *)filters
                                                     fetchLimit:(NSUInteger)fetchLimit;

- (nullable __kindof NTFFeedItem *)feedItemWithId:(NSString *)itemId;

@end

@interface NTFFeedDataSource (ArticleSearch)
- (nullable NTFArticleItem *)articleWithUid:(NSString *)itemId index:(NSInteger *_Nullable)index;
- (nullable NTFArticleItem *)articleWithSmartArticle:(PRSmartArticle *)smartArticle index:(NSInteger *_Nullable)index;

@end

NS_ASSUME_NONNULL_END
