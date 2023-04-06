//
//  PRMyLibraryItem+Service.h
//  PRiphone
//
//  Created by Jackie Cane on 6/27/12.
//  Copyright (c) 2012 NewspaperDirect. All rights reserved.
//

#import <PRAPI/PRMyLibraryItem.h>

@import PRUtils.PRDownload;

@class PRBackgroundDownloadSession;

NS_ASSUME_NONNULL_BEGIN

@interface PRMyLibraryItem (Service) <PRDownloadDelegate>

- (void) deleteDownload;
- (void) resetDownload;

- (void)cancelDownload;
- (void)cancelDownloadWithReason:(PRIssueDownloadCancelReason)reason;

- (void) resetImagePackDownload;
- (void) resetImagePack2Download;
- (void) resetSmartDownload;
- (void) cancelPdnDownloadForPageRange:(NSRange)range;
- (void) cancelSmartDownload;
- (void) resetIndexDownload;
- (void) cancelIndexDownload;
- (void) cancelThumbDownload;
- (void) downloadPdn;
- (void) downloadPdnRange:(NSRange)pageRange;
- (void) downloadSmart;
- (void) downloadIndex;
- (void) downloadImages;
- (BOOL) downloadImgPack;
- (BOOL) downloadImgPack2;
- (void) downloadThumbnailForWidth:(NSInteger)width;
//- (void) unpackImages;

// helpers
- (void)checkTitleName;

// DQ
- (void) getArtAudioUrlInt:(NSString*)artID completed:(void (^)(NSString * url))completionBlock;
- (void) requestArticlesDynamicInfoInt:(NSString*)requestType completed:(void (^)(SPNode *))completionBlock;
- (void) SendVoteInt:(NSInteger)userVote forArticle:(NSString *)artID __deprecated_msg("DQ for Vote deprecated, use `sendVoteInt:forArticle:` instead");
- (void) sendVoteInt:(NSInteger)userVote forArticle:(PRSmartArticle *)article;
- (void) requestVoteForArticleInt:(PRSmartArticle *)article completed:(void(^)(NSError *error))completionBlock;

// Online Service
- (void) updateArticleDataInt:(PRSmartArticle *)article
                     language:(NSString *)language
                    completed:(void(^)(BOOL updated, NSError *error))completionBlock;
- (void) requestCommentsDataForPages:(NSArray *)pages
                             success:(void (^)(NSArray * articleIDs))success
                             failure:(void (^)(NSError *error))failure;

- (void) commentsCounterChangedForArticle:(NSString *)artID value:(id)value;

- (void) downloadSession:(PRBackgroundDownloadSession *)downloadSession asset:(NSString *)assetType version:(NSString *)assetVersion totalBytesWritten:(int64_t)totalBytesWritten totalBytesExpectedToWrite:(int64_t)totalBytesExpectedToWrite;
- (void) downloadSession:(PRBackgroundDownloadSession *)downloadSession asset:(NSString *)assetType version:(NSString *)assetVersion downloadedToURL:(NSURL *)destinationURL;
- (void) downloadSession:(PRBackgroundDownloadSession *)downloadSession asset:(NSString *)assetType version:(NSString *)assetVersion completedWithError:(NSError *)error;
- (void) downloadSession:(PRBackgroundDownloadSession *)downloadSession asset:(NSString *)assetType version:(NSString *)assetVersion didResumeAtOffset:(int64_t)fileOffset expectedTotalBytes:(int64_t)expectedTotalBytes;

- (void)requestDownloadLicense:(void(^ _Nullable)(BOOL, NSError * _Nullable))completion;

@end

NS_ASSUME_NONNULL_END
