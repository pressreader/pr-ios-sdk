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
- (PRSmartPage *)pageAtIndex:(NSUInteger)pageIndex;
- (void)addSmartPage:(PRSmartPage *)page;

@property (nonatomic, retain) NSString *MID;

- (NSString *)issueTag:(NSString *)tagName;

- (NSUInteger) pageCount;
- (NSArray<PRSmartPage *> *)pages;
- (NSArray<NSArray *> *)sections;
- (NSArray<NSArray *> *)pageCollectionWithTag:(NSString *)tagName;
- (NSInteger)sectionIndexByPage:(NSInteger)page;
- (NSString *)pageTag:(NSString *)tagName forPage:(NSUInteger)pageNo;
- (NSString *)sectionNameForPage:(NSUInteger)pageNo;
- (NSString *)pageNameWithPageNumber:(NSUInteger)pageNo;
- (NSString *)pageFullNameWithPageNumber:(NSUInteger)pageNo NS_SWIFT_NAME(pageFullName(pageNumber:));
- (NSArray<NSDictionary *> *)sectionsWithArticlesHavingMinimumTextLength:(NSInteger)minLength
                                                          includeOptions:(PRSmartArticleIncludeOptions)includeOptions;

- (BOOL)isLayoutHyphenated;

- (NSUInteger)smartCountForPage:(NSUInteger)pageNo;
- (NSArray<PRSmartArticle *> *)articlesOnPage:(NSUInteger)pageNo;
- (NSArray<PRSmartArticleLink *> *)articleLinksOnPage:(NSUInteger)pageNo;
- (NSArray<PRSmartHyperLink *> *)hyperLinksOnPage:(NSUInteger)pageNo;
- (NSArray<PRSmartPageLink *> *)pageLinksOnPage:(NSUInteger)pageNo;
- (NSArray<PRSmartMediaRegion *> *)mediaRegionsOnPage:(NSUInteger)pageNo;
- (NSUInteger)commentsForPage:(NSUInteger)pageNo;
- (void)addObserver:(NSObject *)observer forCommentsOnPage:(NSUInteger)pageNo context:(void *)context;
- (void)removeObserver:(NSObject *)observer forCommentsOnPage:(NSUInteger)pageNo;

- (PRSmartArticle *)objectForKeyedSubscript:(id)key;
- (NSDictionary<NSString *,PRSmartArticle *> *)articles;
- (PRSmartArticle *)articleById:(NSString *)articleID;
- (PRSmartArticle *)articleById:(NSString *)articleID onPage:(NSUInteger)page;
- (NSArray<PRSmartArticle *> *)articlesById:(NSString *)articleID onPage:(NSUInteger)page;
- (PRSmartArticle *)firstPartOfArticleById:(NSString *)articleID;
- (PRSmartArticle *)nextPartOfArticleById:(NSString *)articleID;
- (PRSmartArticle *)prevPartOfArticleById:(NSString *)articleID;
- (NSArray<PRSmartArticle *> *)articlesLinkedById:(NSString *)articleID;
- (NSArray<PRSmartArticle *> *)articlesLinkedById:(NSString *)articleID currentArticleIndex:(NSUInteger *)pIndex;
- (NSArray<PRSmartArticle *> *)articlesLinkedByRootId:(NSString *)rootId;
- (NSString *)firstAvailableAnnotationForArticlesLinkedById:(NSString *)articleID forISOLanguage:(NSString *)language;
- (NSString *)firstAvailableBylineForArticlesLinkedById:(NSString *)articleID forISOLanguage:(NSString *)language;
- (NSString *)textWithContinuationForArtId:(NSString *)articleID continueDivider:(NSString *)divider;
- (NSString *)textWithContinuationForArticles:(NSArray *)articles continueDivider:(NSString *)divider;
- (NSString *)textWithContinuationForArticles:(NSArray *)articles continueDivider:(NSString *)divider hyphenated:(BOOL)hyphenated;
- (NSString *)textWithContinuationForArtId:(NSString *)articleID continueDivider:(NSString *)divider hyphenated:(BOOL)hyphenated;
- (NSString *)htmlTextForArticleId:(NSString *)articleID hyphenated:(BOOL)hyphenated withContinuation:(BOOL)withContinuation lineBreakReplacement:(NSString *)breakReplacement continueDivider:(NSString *)divider;
- (NSString *)htmlTextForArticles:(NSArray<PRSmartArticle *> *)articles hyphenated:(BOOL)hyphenated lineBreakReplacement:(NSString *)breakReplacement continueDivider:(NSString *)divider;
- (NSArray<PRSmartImageRegion *> *)imageRegionsInArticlesLinkedById:(NSString *)articleID;
- (PRSmartImageRegion *)largestImageRegionInArticlesLinkedById:(NSString *)articleID;
- (NSArray<PRSmartImageRegion *> *)onlineImageRegionsInArticlesLinkedById:(NSString *)artID;
- (PRSmartArticle *)smartRegionByPoint:(CGPoint)point onPage:(NSUInteger)pageNo;
- (PRSmartArticle *)smartArticleByPoint:(CGPoint)point onPage:(NSUInteger)pageNo includeImages:(BOOL)withImages;
- (NSArray *)textBlocksOnPage:(NSUInteger)pageNo clippingArea:(CGRect)clipRect;
- (NSArray *)columnBoundariesOnPage:(NSUInteger)pageNo clippingArea:(CGRect)clipRect;

@end
