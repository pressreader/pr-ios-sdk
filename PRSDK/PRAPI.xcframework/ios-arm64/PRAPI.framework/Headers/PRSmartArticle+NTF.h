//
//  PRSmartArticle+NTF.h
//  PR-API
//
//  Created by berec on 01/06/2018.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import <PRSmart/PRSmart.h>

@class PRSubscription;

NS_ASSUME_NONNULL_BEGIN

@interface PRSmartArticle (NTF)

- (NSUInteger)numberOfCommentPosts;
- (NSUInteger)indexOCommentPost:(PRSmartCommentPost *)post;
- (PRSmartCommentPost *)commentPostAtIndex:(NSInteger)idx;
- (PRSmartCommentPost *)commentPostWithID:(NSInteger)postId;

- (void)sendVote:(NSInteger)vote
  forCommentPost:(NSInteger)postId
         issueId:(NSString *)issueId
    subscription:(PRSubscription *)subs
       completed:(void(^)(NSInteger currentVote, NSInteger likeItVotes,
                          NSInteger hateItVotes, NSError *error))completionBlock;

- (void)reportCommentPost:(NSInteger)postIndex
                   reason:(NSString *)reason
             subscription:(PRSubscription *)subs
                completed:(void(^)(NSError * _Nullable error))completionBlock;

- (void)saveToBookmarkCollections:(NSArray<NSString *> *_Nullable)collections
                     subscription:(PRSubscription *)subscription
                       completion:(void(^_Nullable)(NSError *_Nullable error))completion;
- (void)saveToBookmarkCollections:(NSArray<NSString *> *_Nullable)collections
                     subscription:(PRSubscription *)subscription
                           silent:(BOOL)silent
                       completion:(void(^_Nullable)(NSError *_Nullable error))completion;

@end

NS_ASSUME_NONNULL_END
