//
//  NTFArticleItemProtocol.h
//  PR-API
//
//  Created by berec on 30/05/2018.
//  Copyright © 2018 NewspaperDirect. All rights reserved.
//

#import <Foundation/Foundation.h>

@import PRSmart;
#import <PRThumbnail/PRThumbnail.h>

#import "NTFDataSourcable.h"
#import "NTFAbstractArticle.h"

@class NTFArticleItem;
@class PRSubscription;
@class PRMyLibraryItem;

#define NTFArticleErrorDomain @"NTFArticleItemErrorDomain"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(uint8_t, NTFArticleErrorCode) {
    NTFArticleErrorCodeUnspecified = 0,
    NTFArticleErrorCodeBackendScaleLimitReached
};

typedef NS_ENUM(int16_t, NTFArticleItemPresentationType) {
    NTFArticleItemPresentationTypeUndefined = 0,
    NTFArticleItemPresentationTypeSingle,
    NTFArticleItemPresentationTypeGroupped,
    NTFArticleItemPresentationTypeHighlighted,
    NTFArticleItemPresentationTypeLikeHighlighted
};

@protocol NTFCommentHolder <NSObject>

- (BOOL)allowComments;
- (void)requestComments:(void(^)(NSError* _Nullable error))completionBlock;
- (void)sendVote:(NSInteger)vote forCommentPost:(NSInteger)postId completed:(void(^)(NSInteger currentVote, NSInteger likeItVotes, NSInteger hateItVotes, NSError *error))completionBlock;
- (BOOL)isAuthorOfCommentPost:(PRSmartCommentPost *)post;
- (void)deleteCommentPost:(NSInteger)postId completed:(void(^)(NSError * _Nullable error))completionBlock;
- (void)reportCommentPost:(NSInteger)postIndex reason:(NSString *)reason completed:(void(^)(NSError * _Nullable error))completionBlock;
- (void)createCommentPostWithParentPost:(NSInteger)parentPostId
                                   body:(nullable NSString *)body
                              artifacts:(nullable NSArray<NSString *> *)artifactIds
                              completed:(void (^)(NSError * _Nullable error))completionBlock;
- (void)editCommentPost:(PRSmartCommentPost *)post
                   body:(nullable NSString *)body
              artifacts:(nullable NSArray<NSString *> *)artifactIds
              completed:(void(^)(NSError * _Nullable error))completionBlock;
@end

@protocol NTFThumbnailHolder <NSObject>

- (NSUInteger)numberOfImages;

- (CGSize)loadImageAtIndex:(NSInteger)imageIdx
                   maxSize:(CGSize)maxSize
                   options:(NTFThumbnailArticleOption)options
                completion:(void (^)(UIImage * _Nullable img, NSError * _Nullable err)) completionBlock; //CGSizeZero

- (CGFloat)loadImageAtIndex:(NSInteger)imageIdx
                    minSize:(CGSize)size
                  criteria:(nullable PRImageValidationCriteria *)criteria
                    options:(NTFThumbnailArticleOption)options
                 completion:(void(^)(UIImage * _Nullable img, NSError * _Nullable err))completion; //0.0f

- (void)loadThumbnailWithOptions:(NTFThumbnailArticleOption)options
                            size:(CGSize)size
                      completion:(void(^)(UIImage * _Nullable img, NSError * _Nullable err))completion;

- (int)prefImageIndex; // -1

- (void)cancelLoadingPrefImageWithMinSize:(CGSize)size;

- (nullable NSString *)captionForImageAtIndex:(NSInteger)imageIdx; //nil

- (PRSmartImageRegion *)imageRegionAtIndex:(NSInteger)index;

@property (nullable, nonatomic, strong) NSDictionary<NSString *, NSNumber *> *numImagesByScale;
@property (nonatomic, readonly) NSArray<PRSmartImageRegion *> *imageRegions;
@property (nonatomic, readonly) NSArray<PRSmartImageRegion *> *actualImageRegions;

@end

@protocol NTFArticleInfo <NSObject>

- (NSString *)title;
- (nullable NSString *)subtitle;
- (nullable NSString *)text;
/// article short preview
- (nullable NSString *)textSnippet;

- (nullable NSDate *)creationDate;
- (nullable NSString *)issueTitle;

@end

@protocol NTFArticle <NTFArticleInfo, NTFCommentHolder, NTFThumbnailHolder, NTFDataSourcable>

- (nullable NSString *)issueCID;

- (BOOL)updateInfo:(void(^)(void))completionBlock;

- (NSDictionary<NSString *, id> *)collectionWithId:(NSString *)collectionId;

- (NSDictionary *)articleContext;

- (nullable NSString *)issueId;
- (nullable NSDate *)issueDate;
- (nullable NSString *)issueCountryCode;
- (nullable NSString *)byline;
- (nullable NSString *)bylineWithLineBreak:(BOOL)lineBreak;
- (nullable NSString *)shortByline;
- (nullable NSString *)annotation;
- (NSString *)startingTitle;
- (NSString *)resolvedTitle;

- (BOOL)updateVotes:(void(^)(void))completionBlock;

/// Based on old API "bookmarkId" key.
- (BOOL)bookmarked;

/**
 Replcae specific item from online services with content translated to requested language
 
 @param language ISO code of language to translate to, if nil use original language
 @param completionBlock called after request completed with parameter `updated` specifiying if item data changed
 @return NO if data already avaialable and completion block called before returning from method
 */
- (BOOL)updateItemWithLanguage:(nullable NSString *)language completion:(void(^)(BOOL updated, NSError * __nullable error))completionBlock;
- (void)updateShortContentWithLanguage:(NSString *)language
                               relatedSmartArticleToUpdate:(void(^)(PRSmartArticle * smartArticle))updateSmartArticle;
- (void)updateWithSmartArticle:(PRSmartArticle *)article isoLanguage:(nullable NSString *)language;
- (void)reportAnalyticsExpanded:(BOOL)expanded;

@property (nonatomic, strong, readonly) NTFAbstractArticle *abstract;
@property (nullable, nonatomic, readonly) NTFArticleItem *feedArticle;

@property (nonatomic, readonly) PRSubscription *defaultSubscription;
@property (nonatomic, readonly) PRSubscription *preferredSubscription;
@property (nonatomic, readonly) PRAccountItem *defaultAccount;

@property (nonatomic, readonly) NSDictionary *context;
@property (nonatomic, getter=isRead) BOOL read;

@property (nonatomic, readonly) PRSmartArticle *smartArticle;
@property (nullable, nonatomic, readonly) PRMyLibraryItem *mli;

@property (nonatomic, readonly) NSString *language;
@property (nonatomic, readonly) NSString *originalLanguage;
@property (nonatomic, readonly) NSString *shortContentLanguage;

@optional
@property (nonatomic) NTFArticleItemPresentationType presentationType;

@end

NS_ASSUME_NONNULL_END
