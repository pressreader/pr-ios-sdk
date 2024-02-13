//
//  NTFArticleItem+CoreDataProperties.h
//  PR-API
//
//  Created by berec on 10/10/2019.
//  Copyright © 2019 NewspaperDirect. All rights reserved.
//
//

#import "NTFArticleItem.h"

NS_ASSUME_NONNULL_BEGIN

@interface NTFArticleItem (CoreDataProperties)

+ (NSFetchRequest<NTFArticleItem *> *)fetchRequest;
/// Associated with PRSmartArticle.articleId
@property (nullable, nonatomic, copy) NSString *articleUUID;
@property (nullable, nonatomic, copy) NSDate *creationDate;
@property (nullable, nonatomic, copy) NSString *issueId;
@property (nullable, nonatomic, copy) NSString *issueUid;
@property (nullable, nonatomic, copy) NSString *issueCID;
@property (nullable, nonatomic, copy) NSString *issueMastheadColour;
@property (nullable, nonatomic, copy) NSString *issueMastheadTemplate;
@property (nullable, nonatomic, copy) NSString *issueTitle;
@property (nonatomic) int16_t prefImageIndex;
@property (nonatomic) int16_t listenDuration;
@property (nonatomic) NTFArticleItemState state;
@property (nonatomic) NTFArticleItemPresentationType presentationType;
@property (nullable, nonatomic, copy) NSString *textSnippet;
@property (nullable, nonatomic, retain) NTFFeedSectionItem *feedSection;
@property (nullable, nonatomic, retain) NSSet<NTFArticleItem *> *parentArticles;
@property (nullable, nonatomic, retain) NSOrderedSet<NTFArticleItem *> *relatedArticles;
@property (nullable, nonatomic, retain) NSOrderedSet<ArticleLink *> *links;

@end

@interface NTFArticleItem (CoreDataGeneratedAccessors)

- (void)addParentArticlesObject:(NTFArticleItem *)value;
- (void)removeParentArticlesObject:(NTFArticleItem *)value;
- (void)addParentArticles:(NSSet<NTFArticleItem *> *)values;
- (void)removeParentArticles:(NSSet<NTFArticleItem *> *)values;

- (void)insertObject:(NTFArticleItem *)value inRelatedArticlesAtIndex:(NSUInteger)idx;
- (void)removeObjectFromRelatedArticlesAtIndex:(NSUInteger)idx;
- (void)insertRelatedArticles:(NSArray<NTFArticleItem *> *)value atIndexes:(NSIndexSet *)indexes;
- (void)removeRelatedArticlesAtIndexes:(NSIndexSet *)indexes;
- (void)replaceObjectInRelatedArticlesAtIndex:(NSUInteger)idx withObject:(NTFArticleItem *)value;
- (void)replaceRelatedArticlesAtIndexes:(NSIndexSet *)indexes withRelatedArticles:(NSArray<NTFArticleItem *> *)values;
- (void)addRelatedArticlesObject:(NTFArticleItem *)value;
- (void)removeRelatedArticlesObject:(NTFArticleItem *)value;
- (void)addRelatedArticles:(NSOrderedSet<NTFArticleItem *> *)values;
- (void)removeRelatedArticles:(NSOrderedSet<NTFArticleItem *> *)values;

- (void)insertObject:(ArticleLink *)value inLinksAtIndex:(NSUInteger)idx;
- (void)removeObjectFromLinksAtIndex:(NSUInteger)idx;
- (void)insertLinks:(NSArray<ArticleLink *> *)value atIndexes:(NSIndexSet *)indexes;
- (void)removeLinksAtIndexes:(NSIndexSet *)indexes;
- (void)replaceObjectInLinksAtIndex:(NSUInteger)idx withObject:(ArticleLink *)value;
- (void)replaceLinksAtIndexes:(NSIndexSet *)indexes withLinks:(NSArray<ArticleLink *> *)values;
- (void)addLinksObject:(ArticleLink *)value;
- (void)removeLinksObject:(ArticleLink *)value;
- (void)addLinks:(NSOrderedSet<ArticleLink *> *)values;
- (void)removeLinks:(NSOrderedSet<ArticleLink *> *)values;

@end

NS_ASSUME_NONNULL_END
