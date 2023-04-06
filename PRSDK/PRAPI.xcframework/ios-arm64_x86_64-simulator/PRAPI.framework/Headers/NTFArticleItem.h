//
//  NTFArticleItem.h
//  PRiphone
//
//  Created by Viacheslav Soroka on 3/30/17.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

#import "NTFFeedItem+CoreDataClass.h"
#import "NTFArticle.h"

@class PRSmartArticle;
@class PRMyLibraryItem;
@class PRSmartImageRegion;
@class PRSmartCommentPost;
@class NTFSocialInfoItem;
@class NTFUserItem;
@class PRAnalyticsProfileBase;
@class NTFFeedSectionItem;
@class ArticleLink;

NS_ASSUME_NONNULL_BEGIN

extern NSString * const kPRPopularArticlesKey;

@interface NTFArticleItem : NTFFeedItem <NTFArticle>

+ (instancetype)itemWithJSON:(NSDictionary *)json isoLanguage:(nullable NSString *)language section:(NTFFeedSectionItem *)feedSection;

@property (nonatomic, readonly) NSString *text;
@property (nullable, nonatomic, readonly) NSString *bylineForDisplay;
@property (nullable, nonatomic, readonly) NSString *bylineForDisplayWithLineBreak;

// computed
@property (nonatomic, readonly) PRSmartArticle *smartArticle;
@property (nullable, nonatomic, readonly) PRMyLibraryItem *mli;
@property (nullable, nonatomic, readonly) NTFSocialInfoItem *socialInfo;
@property (nonatomic, readonly) NSArray<PRAnalyticsProfileBase *> *analyticsProfiles;
@property (nonatomic, readonly) BOOL featuredSection;
@property (nullable, nonatomic, readonly) NTFUserItem *source;
@property (nonatomic, readonly) BOOL isUserPost;
@property (nonatomic, readonly) BOOL isPublicationPost;
@property (nonatomic, readonly) NSDictionary *articleContext;
@property (nonatomic, readonly) PRSubscription *preferredSubscription;
@property (nonatomic, readonly) NSString *shortContentLanguage;

// computed properties from smart-article
@property (nonatomic, readonly) NSString *title;
@property (nonatomic, readonly) NSString *byline;
@property (nonatomic, readonly) NSString *subtitle;
@property (nonatomic, readonly) NSString *annotation;
@property (nonatomic, readonly) NSArray<PRSmartImageRegion *> *imageRegions;
@property (nonatomic, readonly) NSArray<PRSmartImageRegion *> *feedImageRegions;

- (void)updateWithSocialInfo:(NTFSocialInfoItem *)socialInfo;
- (BOOL)updateSocialInfoWithAccountNumber:(NSInteger)accountNumber;
- (void)reportAnalyticsExpanded:(BOOL)expanded;

- (nullable NSString *)channelCollectionNameWithPreferredCollectionId:(nullable NSString *)preferredCollectionId;

@end

NS_ASSUME_NONNULL_END

#import "NTFArticleItem+CoreDataProperties.h"
