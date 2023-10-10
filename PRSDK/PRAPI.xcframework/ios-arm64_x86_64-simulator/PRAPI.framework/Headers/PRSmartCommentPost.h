//
//  PRCommentPost.h
//  PRiphone
//
//  Created by Vitali Bounine on 2016-11-15.
//  Copyright © 2016 NewspaperDirect. All rights reserved.
//

#import <PRSmart/PRSmart.h>

#import <PRAPI/PRUserProfile.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(unsigned int, PRSmartCommentPostType) {
    PRSmartCommentPostTypeDefault = 0,
    PRSmartCommentPostTypeHomeFeed
};

typedef NS_ENUM(NSInteger, PRSmartCommentPostVoteRating) {
    PRSmartCommentPostVoteRatingNeutral = 0,
    PRSmartCommentPostVoteRatingNegative,
    PRSmartCommentPostVoteRatingPositive
};

@class PRSmartArticle, PRSmartArtifact;

@interface PRSmartCommentPost : PRSmartBaseObject

@property (nonatomic) PRSmartCommentPostType type;

@property (readonly, nonatomic) NSInteger postId;
@property (readonly, nonatomic) NSInteger parentPostId;
@property (readonly, nonatomic) BOOL isReply;
@property (readonly, nonatomic, nullable) NSArray<PRSmartCommentPost *> *replies;
@property (readonly, nonatomic, getter=isDeleted) BOOL deleted;
@property (readonly, nonatomic, nullable) NSArray<PRSmartArtifact *> *artifacts;
@property (readonly, nonatomic) NSDate *created;
@property (nonatomic) NSInteger currentVote;
@property (nonatomic) NSInteger likeItVotes;
@property (nonatomic) NSInteger hateItVotes;
@property (readonly, nonatomic) PRSmartCommentPostVoteRating votesRating;
@property (readonly, nonatomic) NSInteger authorVote;
@property (readonly, nonatomic, nullable) NSString *commentKey;
@property (readonly, nonatomic, nullable) NSString *subject;
@property (readonly, nonatomic, nullable) NSString *text;
@property (readonly, nonatomic, nullable) NSString *htmlText;
@property (readonly, nonatomic, nullable) NSAttributedString *attributedHTMLString;
@property (readonly, nonatomic) NSInteger userAccountNumber;

@property (nonatomic, strong, readonly) PRUserProfile *userProfile;

@property (nonatomic, readonly, nullable) NSString *articleId;
@property (nonatomic, readonly, nullable) PRSmartArticle *article;

// main method to build comments thread tree from response
+ (nullable NSArray<PRSmartCommentPost *> *) commentThreadWithPostData:(NSArray<NSDictionary<NSString *,id> *> *)postData article:(PRSmartArticle *)article;

- (void)addReply:(PRSmartCommentPost *)reply;

@end

NS_ASSUME_NONNULL_END
