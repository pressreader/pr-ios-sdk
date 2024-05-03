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

NS_ASSUME_NONNULL_BEGIN

extern PRSmartObjectAttribute const PRSmartObjectAttributePageName;
extern PRSmartObjectAttribute const PRSmartObjectAttributePageNumber;
extern PRSmartObjectAttribute const PRSmartObjectAttributePageRect;
extern PRSmartObjectAttribute const PRSmartObjectAttributePageSection;

@interface PRSmartPage: PRSmartBaseObject

- (instancetype)initWithRoot:(nullable PRSmartBaseObject *)root
                 prevArticle:(nullable PRSmartArticle *)article NS_DESIGNATED_INITIALIZER;

- (void)addSmartRegion:(__kindof PRSmartRegion *)region;
- (void)removeSmartRegion:(__kindof PRSmartRegion *)region;

@property (nullable, nonatomic, readonly) NSArray<PRSmartArticle*>* articles;
@property (nullable, nonatomic, readonly) NSArray<PRSmartPageLink*>* pageLinks;
@property (nullable, nonatomic, readonly) NSArray<PRSmartHyperLink*>* hyperLinks;
@property (nullable, nonatomic, readonly) NSArray<PRSmartArticleLink*>* articleLinks;
@property (nullable, nonatomic, readonly) NSArray<PRSmartImageRegion*>* imageRegions;
@property (nullable, nonatomic, readonly) NSArray<PRSmartMediaRegion*>* mediaRegions;
@property (nonatomic, readonly) NSUInteger comments;

@property (nullable, nonatomic, readonly) PRSmartArticle *prevArticle;

@end

NS_ASSUME_NONNULL_END
