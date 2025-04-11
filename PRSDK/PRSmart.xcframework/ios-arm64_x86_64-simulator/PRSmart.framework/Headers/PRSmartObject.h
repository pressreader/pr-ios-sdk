//
//  PRSmart.h
//  PRiphone
//
//  Created by devuser on 09/03/09.
//  Copyright 2009 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "PRSmartBaseObject.h"

@class PRSmartArticle;
@class PRSmartPage;
@class PRSmartArticleLink;
@class PRSmartPageLink;
@class PRSmartHyperLink;
@class PRSmartMediaRegion;
@class PRSmartImageRegion;

typedef NS_ENUM(NSInteger, PRSmartArticleIncludeOptions) {
    PRSmartArticleIncludeOptionsAll = 0,
    PRSmartArticleIncludeOptionsOncePerSection,
    PRSmartArticleIncludeOptionsOncePerIssue
};

NS_ASSUME_NONNULL_BEGIN

@interface PRSmartObject : PRSmartBaseObject <NSXMLParserDelegate> {
	NSMutableDictionary<NSString *, PRSmartArticle *> *articlesByAID;
	NSMutableDictionary<NSString *, PRSmartArticle *> *articlesByRegionID;
    NSMutableDictionary<NSString *, PRSmartArticle *> *articlesByNewID;
    NSMutableDictionary<NSString *, NSMutableArray<PRSmartArticle *> *> *articlesByRootID;
	NSMutableArray<PRSmartPage *> *pages;
	NSString *sourceFile;
	NSMutableArray<NSArray<NSString *> *> *_sections;
	
	// XML parser state
	PRSmartBaseObject *current;
	NSMutableString *currentText;
	
	PRSmartArticle *prevArticle;
    int             m_articleIndexOnPage;
    BOOL            m_hyphenated;
    NSMutableDictionary *m_zip;
}

- (instancetype)initWithData:(NSData *)data sourceZip:(NSString *)source MID:(NSString *)aMID;
- (void)addSmartArticle:(PRSmartArticle *)article;
- (void)setNewId:(NSString *)newId forArticle:(PRSmartArticle *)article;
- (void)setRootId:(NSString *)rootId forArticle:(PRSmartArticle *)article;
- (nullable PRSmartPage *)pageAtIndex:(NSUInteger)pageIndex;
- (void)addSmartPage:(PRSmartPage *)page;

@property (nonatomic, retain) NSString *MID;

- (NSString *)issueTag:(NSString *)tagName;

- (NSUInteger) pageCount;
- (nullable NSArray<PRSmartPage *> *)pages;
- (nullable NSArray<NSArray *> *)sections;
- (NSArray<NSArray *> *)pageCollectionWithTag:(NSString *)tagName;
- (NSInteger)sectionIndexByPage:(NSInteger)page;
- (nullable NSString *)pageTag:(NSString *)tagName forPage:(NSUInteger)pageNo;
- (nullable NSString *)sectionNameForPage:(NSUInteger)pageNo;
- (nullable NSString *)pageNameWithPageNumber:(NSUInteger)pageNo;
- (nullable NSString *)pageFullNameWithPageNumber:(NSUInteger)pageNo NS_SWIFT_NAME(pageFullName(pageNumber:));
- (nullable NSArray<NSDictionary *> *)sectionsWithArticlesHavingMinimumTextLength:(NSInteger)minLength
                                                          includeOptions:(PRSmartArticleIncludeOptions)includeOptions;

- (BOOL)isLayoutHyphenated;

- (NSUInteger)smartCountForPage:(NSUInteger)pageNo;
- (nullable NSArray<PRSmartArticle *> *)articlesOnPage:(NSUInteger)pageNo;
- (nullable NSArray<PRSmartArticleLink *> *)articleLinksOnPage:(NSUInteger)pageNo;
- (nullable NSArray<PRSmartHyperLink *> *)hyperLinksOnPage:(NSUInteger)pageNo;
- (nullable NSArray<PRSmartPageLink *> *)pageLinksOnPage:(NSUInteger)pageNo;
- (nullable NSArray<PRSmartMediaRegion *> *)mediaRegionsOnPage:(NSUInteger)pageNo;
- (NSUInteger)commentsForPage:(NSUInteger)pageNo;
- (void)addObserver:(NSObject *)observer forCommentsOnPage:(NSUInteger)pageNo context:(nullable void *)context;
- (void)removeObserver:(NSObject *)observer forCommentsOnPage:(NSUInteger)pageNo;

- (PRSmartArticle *)objectForKeyedSubscript:(id)key;
- (nullable NSDictionary<NSString *,PRSmartArticle *> *)articles;
- (nullable PRSmartArticle *)articleById:(NSString *)articleID;
- (nullable PRSmartArticle *)articleById:(NSString *)articleID onPage:(NSUInteger)page;
- (nullable NSArray<PRSmartArticle *> *)articlesById:(NSString *)articleID onPage:(NSUInteger)page;
- (nullable PRSmartArticle *)firstPartOfArticleById:(NSString *)articleID;
- (nullable PRSmartArticle *)nextPartOfArticleById:(NSString *)articleID;
- (nullable PRSmartArticle *)prevPartOfArticleById:(NSString *)articleID;
- (nullable NSArray<PRSmartArticle *> *)articlesLinkedById:(NSString *)articleID;
- (nullable NSArray<PRSmartArticle *> *)articlesLinkedById:(NSString *)articleID currentArticleIndex:(nullable NSUInteger *)pIndex;
- (nullable NSArray<PRSmartArticle *> *)articlesLinkedByRootId:(NSString *)rootId;
- (nullable NSString *)firstAvailableAnnotationForArticlesLinkedById:(NSString *)articleID forISOLanguage:(NSString *)language;
- (nullable NSString *)firstAvailableBylineForArticlesLinkedById:(NSString *)articleID forISOLanguage:(NSString *)language;
- (nullable NSString *)textWithContinuationForArtId:(NSString *)articleID continueDivider:(NSString *)divider;
- (nullable NSString *)textWithContinuationForArticles:(NSArray *)articles continueDivider:(NSString *)divider;
- (nullable NSString *)textWithContinuationForArticles:(NSArray *)articles continueDivider:(NSString *)divider hyphenated:(BOOL)hyphenated;
- (nullable NSString *)textWithContinuationForArtId:(NSString *)articleID continueDivider:(NSString *)divider hyphenated:(BOOL)hyphenated;
- (nullable NSString *)htmlTextForArticleId:(NSString *)articleID
                                 hyphenated:(BOOL)hyphenated
                           withContinuation:(BOOL)withContinuation
                       lineBreakReplacement:(nullable NSString *)breakReplacement
                            continueDivider:(NSString *)divider;
- (NSString *)htmlTextForArticles:(NSArray<PRSmartArticle *> *)articles
                       hyphenated:(BOOL)hyphenated
             lineBreakReplacement:(nullable NSString *)breakReplacement
                  continueDivider:(NSString *)divider;
- (nullable NSArray<PRSmartImageRegion *> *)imageRegionsInArticlesLinkedById:(NSString *)articleID;
- (nullable PRSmartImageRegion *)largestImageRegionInArticlesLinkedById:(NSString *)articleID;
- (nullable NSArray<PRSmartImageRegion *> *)onlineImageRegionsInArticlesLinkedById:(NSString *)artID;
- (nullable PRSmartArticle *)smartRegionByPoint:(CGPoint)point onPage:(NSUInteger)pageNo;
- (nullable PRSmartArticle *)smartArticleByPoint:(CGPoint)point onPage:(NSUInteger)pageNo includeImages:(BOOL)withImages;
- (nullable NSArray *)textBlocksOnPage:(NSUInteger)pageNo clippingArea:(CGRect)clipRect;
- (nullable NSArray *)columnBoundariesOnPage:(NSUInteger)pageNo clippingArea:(CGRect)clipRect;

@end

NS_ASSUME_NONNULL_END
