//
//  PRSmartArticleOperations.h
//  PRiphone
//
//  Created by Vitali Bounin on 11/24/11.
//  Copyright (c) 2011 NewspaperDirect. All rights reserved.
//

@import UIKit;

@class PRSmartCommentPost;
@class PRMyLibraryItem;
@class PRSmartArticle;
@class NTFMyLibraryItemDataSource;

NS_ASSUME_NONNULL_BEGIN

extern NSString* const kAppleWebArchiveType;

@protocol PRSmartArticleVoteDelegate <NSObject>

- (void) votesUpdatedForArticle:(NSString *)artID userVote:(NSInteger)userVote likeitVotes:(NSUInteger)likeitVotes hateitVotes:(NSUInteger)hateitVotes;

@end

@interface PRSmartArticleTools : NSObject

- (instancetype)initWithMLI:(PRMyLibraryItem *)mli;

@property (nullable, nonatomic, weak) id<PRSmartArticleVoteDelegate> voteDelegate;
@property (nonatomic, unsafe_unretained, readonly) PRMyLibraryItem *mli;

- (void)printArticle:(NSString *)artID
        inController:(UIViewController *)presentingController
   fromBarButtonItem:(nullable UIBarButtonItem *)barButtonItem
            metaInfo:(NSDictionary *)metaInfo;
- (void)printArticles:(NSArray<PRSmartArticle *> *)articles
         inController:(UIViewController *)presentingController
    fromBarButtonItem:(nullable UIBarButtonItem *)barButtonItem;
- (void)printArticleAsImage:(NSString *)artID
               inController:(UIViewController *)presentingController
          fromBarButtonItem:(nullable UIBarButtonItem *)barButtonItem;
- (void)printArticlesAsImage:(NSArray *)articles
                inController:(UIViewController *)presentingController
           fromBarButtonItem:(nullable UIBarButtonItem *)barButtonItem;

- (void)copyArticleToClipboard:(NSString *)artID;
- (void)copyArticlesToClipboard:(NSArray *)articles;

- (void)listenArticle:(NSString *)artID inController:(UIViewController *)presentingController;
- (void)listenFromPage:(NSInteger)fromPage inController:(UIViewController *)presentingController;

- (void)shareArticle:(NSString *)artID inController:(UIViewController *)presentingController;
- (void)shareArticle:(NSString *)artID
                   to:(nullable NSString *)shareType
         inController:(UIViewController *)presentingController;
- (void)shareCommentPost:(PRSmartCommentPost *)commentPost
                 article:(NSString*)artID
                      to:(nullable NSString *)shareType
            inController:(UIViewController *)presentingController;
- (void)sharePage:(NSInteger)pageNo
               to:(nullable NSString *)shareType
     inController:(UIViewController *)presentingController;
- (void)sharePages:(NSSet<NSNumber *> *)pages
                to:(nullable NSString *)shareType
      inController:(UIViewController *)presentingController;

- (void)bookmarkArticle:(NSString *)artID;

- (void)voteForArticle:(NSString *)artID;
- (void)voteAgainstArticle:(NSString *)artID;
- (void)sendUpdateArticleVoteInfoRequest:(NSString *)artID;

//+ (void) copySFSelectedArticle;

@end

NS_ASSUME_NONNULL_END
