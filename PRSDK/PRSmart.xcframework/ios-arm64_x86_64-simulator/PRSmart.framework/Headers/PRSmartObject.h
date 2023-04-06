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
	NSMutableDictionary<NSString*,PRSmartArticle*>* articlesByAID;
	NSMutableDictionary<NSString*,PRSmartArticle*>* articlesByRegionID;
    NSMutableDictionary<NSString*,PRSmartArticle*>* articlesByNewID;
    NSMutableDictionary<NSString*,NSMutableArray<PRSmartArticle*> *>* articlesByRootID;
	NSMutableArray<PRSmartPage*>* pages;
	NSString* sourceFile;
	NSMutableArray<NSArray*>* _sections;
	
	// XML parser state
	PRSmartBaseObject* current;
	NSMutableString* currentText;
	
	PRSmartArticle* prevArticle;
    int             m_articleIndexOnPage;
    BOOL            m_hyphenated;
    NSMutableDictionary*   m_zip;
}

- (instancetype)initWithData:(NSData*)data sourceZip:(NSString*)source MID:(NSString *)aMID;
- (void) addSmartArticle : (PRSmartArticle*)article;
- (void) setNewId:(NSString *)newId forArticle:(PRSmartArticle *)article;
- (void) setRootId:(NSString *)rootId forArticle:(PRSmartArticle *)article;
- (PRSmartPage *) pageAtIndex:(NSUInteger)pageIndex;
- (void) addSmartPage : (PRSmartPage*) page;

@property (nonatomic, retain) NSString *MID;

- (NSString*) issueTag:(NSString*)tagName;

- (NSUInteger) pageCount;
- (NSArray<PRSmartPage *> *)pages;
- (NSArray<NSArray*>*) sections;
- (NSArray<NSArray*>*) pageCollectionWithTag:(NSString*)tagName;
- (NSInteger) sectionIndexByPage:(NSInteger)page;
- (NSString*) pageTag:(NSString*)tagName forPage:(NSUInteger)pageNo;
- (NSString*) sectionNameForPage:(NSUInteger)pageNo;
- (NSArray<NSDictionary *> *) sectionsWithArticlesHavingMinimumTextLength:(NSInteger)minLength
                                                           includeOptions:(PRSmartArticleIncludeOptions)includeOptions;

- (BOOL) isLayoutHyphenated;

- (NSUInteger) smartCountForPage:(NSUInteger)pageNo;
- (NSArray*) articlesOnPage:(NSUInteger)pageNo;
- (NSArray*) articleLinksOnPage:(NSUInteger)pageNo;
- (NSArray*) hyperLinksOnPage:(NSUInteger)pageNo;
- (NSArray*) pageLinksOnPage:(NSUInteger)pageNo;
- (NSArray*) mediaRegionsOnPage:(NSUInteger)pageNo;
- (NSUInteger) commentsForPage:(NSUInteger)pageNo;
- (void) addObserver:(NSObject *)observer forCommentsOnPage:(NSUInteger)pageNo context:(void *)context;
- (void) removeObserver:(NSObject *)observer forCommentsOnPage:(NSUInteger)pageNo;

- (PRSmartArticle *)objectForKeyedSubscript:(id)key;
- (NSDictionary*) articles;
- (PRSmartArticle *) articleById:(NSString*)artID;
- (PRSmartArticle *) articleById:(NSString*)artID onPage:(NSUInteger)page;
- (NSArray<PRSmartArticle *> *) articlesById:(NSString*)artID onPage:(NSUInteger)page;
- (PRSmartArticle *) firstPartOfArticleById:(NSString *)artID;
- (PRSmartArticle *)nextPartOfArticleById:(NSString *)artID;
- (PRSmartArticle *)prevPartOfArticleById:(NSString *)artID;
- (NSArray<PRSmartArticle *>*) articlesLinkedById:(NSString*)artID;
- (NSArray<PRSmartArticle *>*) articlesLinkedById:(NSString*)artID currentArticleIndex:(NSUInteger *)pIndex;
- (NSArray<PRSmartArticle *>*) articlesLinkedByRootId:(NSString *)rootId;
- (NSString *)firstAvailableAnnotationForArticlesLinkedById:(NSString *)artID forISOLanguage:(NSString *)language;;
- (NSString *)firstAvailableBylineForArticlesLinkedById:(NSString *)artID forISOLanguage:(NSString *)language;
- (NSString*) textWithContinuationForArtId:(NSString*)artID continueDivider:(NSString *)divider;
- (NSString*) textWithContinuationForArticles:(NSArray*)articles continueDivider:(NSString *)divider;
- (NSString *) textWithContinuationForArticles:(NSArray *)articles continueDivider:(NSString *)divider hyphenated:(BOOL)hyphenated;
- (NSString*) textWithContinuationForArtId:(NSString*)artID continueDivider:(NSString *)divider hyphenated:(BOOL)hyphenated;
- (NSString*) htmlTextForArtId:(NSString*)artID hyphenated:(BOOL)hyphenated withContinuation:(BOOL)withContinuation lineBreakReplacement:(NSString *)br continueDivider:(NSString *)divider;
- (NSString*) htmlTextForArticles:(NSArray*)articles hyphenated:(BOOL)hyphenated lineBreakReplacement:(NSString *)br continueDivider:(NSString *)divider;
- (NSArray<PRSmartImageRegion *> *) imageRegionsInArticlesLinkedById:(NSString *)artID;
- (PRSmartImageRegion *) largestImageRegionInArticlesLinkedById:(NSString *)artID;
- (NSArray<PRSmartImageRegion *> *) onlineImageRegionsInArticlesLinkedById:(NSString *)artID;
- (PRSmartArticle *) smartRegionByPoint:(CGPoint)point onPage:(NSUInteger)pageNo;
- (PRSmartArticle *) smartArticleByPoint:(CGPoint)point onPage:(NSUInteger)pageNo includeImages:(BOOL)withImages;
- (NSArray *)textBlocksOnPage:(NSUInteger)pageNo clippingArea:(CGRect)clipRect;
- (NSArray *)columnBoundariesOnPage:(NSUInteger)pageNo clippingArea:(CGRect)clipRect;

@end
