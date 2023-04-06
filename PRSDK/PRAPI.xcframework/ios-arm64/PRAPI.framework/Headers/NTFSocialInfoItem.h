//
//  NTFSocialInfoItem.h
//  PRiphone
//
//  Created by Viacheslav Soroka on 5/4/17.
//  Copyright © 2017 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NTFFeedSectionItem.h"

@class PRSmartCommentPost;
@class PRSmartArticle;

@interface NTFSocialInfoItem : NSObject
@property (nonatomic, readonly) NSArray<PRSmartCommentPost *> *allComments;
@property (nonatomic, readonly) NSArray<PRSmartCommentPost *> *currentUserComments;
@property (nonatomic, readonly) NSArray<PRSmartCommentPost *> *followedUsersComments;
@property (nonatomic, readonly) NSArray<PRSmartCommentPost *> *otherComments;
@property (nonatomic, readonly) NSArray<NSDictionary *> *bookmarks;
@property (nonatomic, readonly) BOOL voted;
@property (nonatomic, readonly) NSString *opinionId;
@property (nonatomic, strong) NTFFeedSectionItem *feedSection;

+ (instancetype)itemWithJSON:(NSDictionary *)json article:(PRSmartArticle *)article;
+ (instancetype)itemWithPostJSON:(NSDictionary *)json article:(PRSmartArticle *)article;
+ (instancetype)itemWithCommentJSON:(NSDictionary *)json article:(PRSmartArticle *)article;
+ (instancetype)itemWithContextMetaJSON:(NSDictionary *)json section:(NTFFeedSectionItem *)section article:(PRSmartArticle *)article;

- (instancetype)initWithJSON:(NSDictionary *)json article:(PRSmartArticle *)article;
- (instancetype)initWithPostJSON:(NSDictionary *)json article:(PRSmartArticle *)article;
- (instancetype)initWithCommentJSON:(NSDictionary *)json article:(PRSmartArticle *)article;

- (BOOL)updateWithArticle:(PRSmartArticle *)article accountNumber:(NSInteger)accountNumber;
- (BOOL)isLinkedToOpinion;

@end
