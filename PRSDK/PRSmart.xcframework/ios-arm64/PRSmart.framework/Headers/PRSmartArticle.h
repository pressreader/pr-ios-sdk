//
//  PRSmartArticle.h
//  PRiphone
//
//  Created by Jackie Cane on 26/08/15.
//  Copyright (c) 2015 NewspaperDirect. All rights reserved.
//

#import "PRSmartComplexRegion.h"

@class PRSmartArticleLink;
@class PRSmartImageRegion;
@class PRSmartPageLink;
@class PRSmartHyperLink;
@class PRSmartCommentPost;
@class PRArticleBlock;

NS_ASSUME_NONNULL_BEGIN

extern NSNotificationName const PRSmartArticleCollectionsUpdatedNotification;

typedef NS_OPTIONS(NSUInteger, PRSmartArticleStatus) {
    PRSmartArticleStatusFulfilled = 1 << 0,
    PRSmartArticleStatusBookmarksRequested = 1 << 1,
    PRSmartArticleStatusFullContentRequested = 1 << 2
};

@interface PRSmartArticle : PRSmartComplexRegion
{
    PRSmartArticleLink *nextArticleLink;
    PRSmartArticleLink *previousArticleLink;
    NSMutableArray<PRSmartImageRegion *> *imageRegions;
    NSMutableArray<PRSmartImageRegion *> *onlineImageRegions;
    NSMutableArray<PRSmartPageLink *> *pageLinks;
    NSMutableArray<PRSmartHyperLink *> *hyperLinks;
    NSMutableDictionary *metaInfo;
@public
    PRSmartArticle *pnextArticle;
    PRSmartArticle *pprevArticle;
    int m_articleIndexOnPage;
}

+ (nullable NSString *)articleIdFromDictionary:(NSDictionary *)dictionary;
+ (nullable instancetype)cashedArticleWithId:(NSString *)articleKey;

+ (instancetype)articleWithDictionary:(NSDictionary *)dict;
+ (instancetype)articleWithDictionary:(NSDictionary *)dict
                          isoLanguage:(nullable NSString *)language
                          updateCache:(BOOL)updateCache;

+ (instancetype)articleWithType:(NSString *)type
                           page:(NSUInteger)page
                         parent:(PRSmartBaseObject *)parentObject
                 attributesDict:(NSDictionary *)dict;

- (void)addSmartRegion:(PRSmartRegion *)region;

- (void)setObject:(id)obj forKeyedSubscript:(id <NSCopying>)key;

- (NSMutableDictionary *)metaInfo;

- (void)setLikeItVotes:(NSUInteger)likeItVotes;
- (void)setHateItVotes:(NSUInteger)hateItVotes;
- (void)setComments:(NSUInteger)comments;
- (void)setBookmarkId:(NSString *)bookmarkId;
- (void)setBookmarkUrl:(NSString *)bookmarkUrl;
- (void)setDirectLinkUrl:(NSString *)directLinkUrl;
- (void)setAssignedCollections:(NSArray<NSDictionary<NSString *, id> *> *)assignedCollections;
- (void)setRate:(NSString *)rate;

@property (nullable, nonatomic, readonly) NSString *articleId;
@property (nullable, nonatomic, readonly) NSString *articleUid;
@property (nullable, nonatomic, readonly) NSString *articleUidOrId;
@property (nullable, nonatomic, readonly) NSString *articleIdOrRegionId;
@property (nullable, nonatomic, readonly) NSString *rootKey;
@property (nullable, nonatomic, readonly) NSString *rate;

- (NSString *)shortContentForLanguage:(NSString *)language;
@property (nonatomic, readonly) NSString *shortContent;

- (NSString *)title;
- (NSString *)titleForISOLanguage:(NSString *)language;

- (NSString *)subtitle;
- (NSString *)subtitleForISOLanguage:(NSString *)language;

- (NSString *)byline;
- (NSString *)bylineForISOLanguage:(NSString *)language;

- (NSString *)copyright;
- (NSString *)copyrightForISOLanguage:(NSString *)language;

- (nullable NSString *)author;
- (nullable NSString *)authorForISOLanguage:(NSString *)language;

- (NSString *)annotation;
- (NSString *)annotationForISOLanguage:(NSString *)language;

- (NSString*)paratitle;
- (NSString *)paratitleForISOLanguage:(NSString *)language;

- (NSArray<PRArticleBlock *> *)textBlocks;
- (NSArray<PRArticleBlock *> *)textBlocksWithISOLanguage:(NSString *)language;

- (NSString *)section;
- (NSString *)pageName;
- (NSUInteger)comments;
- (NSString *)bookmarkId;
- (NSString *)bookmarkUrl;
- (NSString *)directLinkUrl;
- (NSArray<NSDictionary<NSString *, id> *> *)assignedCollections;
- (BOOL)isAssignedToCollection:(NSString *)collectionName;
- (NSUInteger)numOfAssignedCollections;
- (NSArray<NSString *> *)assignedCollectionIds;
- (NSDate *)collectionsAssignmentDate;
- (NSUInteger)likeItVotes;
- (NSUInteger)hateItVotes;
- (NSInteger)currentVote;
- (BOOL)isVoteUpdated;
- (NSUInteger)similarsCount;

- (int)articleIndexOnPage;

- (PRSmartRegion *)titleRegion;
- (PRSmartArticleLink *)previousArticleLink;
- (PRSmartArticleLink *)nextArticleLink;

- (PRSmartArticle *)nextArticle;
- (PRSmartArticle *)previousArticle;

- (NSArray<PRSmartImageRegion *> *)imageRegions;
- (NSArray<PRSmartImageRegion *> *)onlineImageRegions;
- (NSArray<PRSmartPageLink *> *)pageLinks;
- (NSArray<PRSmartHyperLink *> *)hyperLinks;
- (id)objectForKeyedSubscript:(id)key;

- (BOOL)hasVisibleCollections;
- (BOOL)hasBookmarks;

- (void)updateShortContentWithInfo:(nullable NSDictionary *)info isoLanguage:(nullable NSString *)language;
- (void)resetToOriginalLanguage;

@property (nonatomic, assign, readonly) BOOL isLocked;
@property (nonatomic, readonly) BOOL isFullContentAvailable;
/// Legacy  article API returns a few text blocks and set `ArticleType: 1`.
@property (nonatomic, readonly) BOOL isPreviewType;
@property (nonatomic) PRSmartArticleStatus status;
@property (nonatomic, strong) NSArray<PRSmartCommentPost *> *posts;
@property (nonatomic, readonly) NSInteger commentsCount;
@property (nullable, nonatomic, strong, readonly) NSString *recentLanguage;
@property (nullable, nonatomic, strong, readonly) NSString *recentShortContentLanguage;
@property (nonatomic, readonly) CGRect textRect;

@property (nullable, nonatomic) NSDictionary<NSString *, id> *issueInfo;

@end

NS_ASSUME_NONNULL_END
