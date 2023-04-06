//
//  PRSmartPage.h
//  PRiphone
//
//  Created by Jackie Cane on 26/08/15.
//  Copyright (c) 2015 NewspaperDirect. All rights reserved.
//

#import "PRSmartBaseObject.h"

@class PRSmartArticle;
@class PRSmartArticleLink;
@class PRSmartPageLink;
@class PRSmartHyperLink;
@class PRSmartImageRegion;
@class PRSmartMediaRegion;
@class PRSmartRegion;

extern PRSmartObjectAttribute const PRSmartObjectAttributePageName;
extern PRSmartObjectAttribute const PRSmartObjectAttributePageNumber;
extern PRSmartObjectAttribute const PRSmartObjectAttributePageRect;

@interface PRSmartPage: PRSmartBaseObject

- (instancetype)initWithRoot:(PRSmartBaseObject *)root prevArticle:(PRSmartArticle *)article NS_DESIGNATED_INITIALIZER;

@property (nonatomic, readonly) NSArray<PRSmartArticle*>* articles;
@property (nonatomic, readonly) NSArray<PRSmartPageLink*>* pageLinks;
@property (nonatomic, readonly) NSArray<PRSmartHyperLink*>* hyperLinks;
@property (nonatomic, readonly) NSArray<PRSmartArticleLink*>* articleLinks;
@property (nonatomic, readonly) NSArray<PRSmartImageRegion*>* imageRegions;
@property (nonatomic, readonly) NSArray<PRSmartMediaRegion*>* mediaRegions;
@property (nonatomic, readonly) NSUInteger comments;

@property (nonatomic, readonly) PRSmartArticle *prevArticle;

- (void)addSmartRegion:(__kindof PRSmartRegion *)region;
- (void)removeSmartRegion:(__kindof PRSmartRegion *)region;

@end
