//
//  PRMyLibraryItem.h
//  PRiphone
//
//  Created by Jackie Cane on 10/18/12.
//  Copyright (c) 2012 NewspaperDirect. All rights reserved.
//

#import "PRSourceItem.h"
#import "PRTitleObject.h"
#import "OpenedItem.h"
#import "ReadingViewItem.h"

@class PRSmartObject, PRDownload;
@class SPNode;
@class SPXML;
@class PDFDoc;
@class PRSmartArticle, PRSmartPageset;
@class PRPage;

NS_ASSUME_NONNULL_BEGIN

extern NSString *const kOrderDateParameter;
extern NSString *const kLockedParameter;

extern NSString *const kHotSpotIdKey;
extern NSString *const kHotSpotNameKey;
extern NSString *const kHotSpotIndustryKey;

// Notifications
extern NSNotificationName const PRLibraryItemWiFiDownloadNotAvailableNotification;
extern NSNotificationName const PRLibraryItemCurrentArticleDidChange;
extern NSNotificationName const PRLibraryItemGotoPage;

@interface PRMyLibraryItem : PRSourceItem <PRTitleObject, _ReadingViewItem, PRSmartLayoutItem>

+ (NSString *)cidFromIssueId:(NSString *)issueId;
+ (NSString *)issueDateStringFromIssueId:(NSString *)issueId;
+ (nullable NSDate *)issueDateFromIssueId:(NSString *)issueId;

- (id)getParameter:(NSString*)pname;
- (void)setParameter:(NSString*)name value:(nullable id)v;
- (void)removeParameter:(NSString*)name;

- (id)getItemParameter:(NSString*)pname;
- (void)setItemParameter:(NSString*)name value:(id)v;
- (void)removeItemParameter:(NSString*)name;

// searches for parameter in both parameters and itemParameters dictionaries
- (nullable id)findParameter:(NSString*)pname;

@property (nonatomic, readonly) PRTitleItemExemplar *exemplar;
@property (nonatomic, readonly) NSDate *expirationDateAndTime;

@property (nonatomic) BOOL isReading;

- (NSString*)getStringParameter:(NSString*)pname;
- (NSString*) messageType;
- (NSString*) GetIssueDate;
- (NSString*) IssueId;
- (NSString*) IssueKey;
- (NSString*) ExpungeVersion;
- (NSString*) Status;
- (NSDate*) ExpirationDate;
- (BOOL)rightToLeft;
- (BOOL)titleContains:(NSString*)searchText;
- (BOOL)titleStartsWith:(NSString*)searchText;

- (BOOL)isPurchaseAdvise;
- (BOOL)isAutoDelivery;
- (BOOL)isEqualToMLI:(PRMyLibraryItem *)mli;
- (BOOL)inProcess;
- (BOOL)inThumbProcess;
- (BOOL)requestingLicense;
- (BOOL)isSuspended;
- (BOOL)isForced;
- (BOOL)isWordIndexAvailable;
- (BOOL)isSampleIssue;
- (BOOL)isFreeIssue;
- (BOOL)failed;
- (BOOL)readyToOpen;
- (BOOL)preparedToOpen;
- (BOOL)indexDone;
- (BOOL)indexDownloaded;
- (BOOL)imgPacksDone;
- (BOOL)imgPackDone;
- (BOOL)imgPack2Done;
- (BOOL)imgPacksDownloaded;
- (BOOL)pdnFailed;
- (BOOL)imgPacksFailed;
@property (nonatomic, readonly) BOOL hasErrorStatus;
- (BOOL) isUnauthorized;

- (NSRange)downloadableRangeForPage:(NSUInteger)pageNumber;
- (BOOL)pdnFailedForPage:(NSUInteger)pageNumber;
- (BOOL)pdnDownloadingForPage:(NSUInteger)pageNumber;
- (BOOL)pdnCompletedForPage:(NSUInteger)pageNumber;

- (NSDictionary<NSString *, id> *)pageRangeProperty:(NSString *)property forAsset:(NSString *)assetType;
- (NSDictionary<NSString *, id> *)pageRangeStatusPropertyForAsset:(NSString *)assetType;

- (BOOL)isDownloaded;
- (BOOL)isLicenseAvailable;
- (BOOL)isRadioAvailableForArticle:(NSString *)articleId;
- (BOOL)isTextFlowViewAvailable;
- (BOOL)translationDisabled;
- (BOOL)isTranslationSupported;
- (BOOL)smartFlowDisabled;
- (BOOL)voteDisabled;
- (BOOL)commentsDisabled;
- (BOOL)isSharingRestricted;
- (BOOL)emailSharingDisabled;
- (BOOL)twitterSharingDisabled;
- (BOOL)facebookSharingDisabled;
- (BOOL)instapaperSharingDisabled;
- (BOOL)evernoteSharingDisabled;
- (BOOL)onenoteSharingDisabled;
- (BOOL)diggitSharingDisabled;
- (BOOL)deliciousSharingDisabled;
- (BOOL)livejournalSharingDisabled;
- (BOOL)wordpressSharingDisabled;
- (BOOL)sharingDisabled;
- (BOOL)copyToPasteboardDisabled;
- (BOOL)printingAsBitmap;
- (NSString *)licenseStatus;

@property (nullable, nonatomic, readonly) NSString *errorMessage;
@property (nonatomic, readonly) NSString *statusMessage;
@property (nonatomic, readonly) NSString *progressMessage;
@property (nonatomic) BOOL isMarkedToDeleteContent;

- (int) pdnPercents;
- (int) totalPercents;
- (int) avgSpeed;
- (long long) pdnLength;
- (long long) pdnCurrent;
- (long long) totalLength;
- (long long) totalCurrent;
- (float) partDownloaded;
- (long long) pdnLengthForPageRange:(NSRange)pageRange;
- (long long) pdnCurrentForPageRange:(NSRange)pageRange;

- (NSProgress *) imgpackProgress;
- (NSProgress *) imgpack2Progress;
- (NSProgress *) smartProgress;
- (NSProgress *) indexProgress;
- (NSProgress *) thumbProgress;
- (NSProgress *) pdnProgressForPageRange:(NSRange)pageRange;

- (nullable NSDictionary *) artInfoById:(NSString *)artID;
- (NSString*) GetImagesFolderPath;
- (id) LoadDocument;
- (NSArray *)sections;
- (NSInteger)sectionIndexByPage:(NSInteger)pageNumber;
- (int) maxPageHeight;
- (BOOL) isOpen;
- (NSString *) currentArtIdToListen;
- (void) setCurrentArtIdToListen:(NSString *)artID;

- (BOOL) processSmart;
- (void) getArtAudioUrl:(NSString*)artID completed:(void (^)(NSString * url))completionBlock;

- (NSString*)defaultImagePathForPage:(NSUInteger)page;
- (NSString*)imagePathForPage:(NSUInteger)page width:(CGFloat)width;
- (NSString*)imagePathForPage:(NSUInteger)page type:(int)type size:(CGFloat)size; // type:0 - by width, 1 - by height
- (UIImage*) GetPageImage:(NSUInteger)page fg:(BOOL)fg;
- (UIImage*) GetPageImage:(NSUInteger)page fg:(BOOL)fg type:(int)type size:(int)size;
- (UIImage*) imageFromPdfPage:(NSUInteger)pageNo
                       pdfRect:(CGRect)pdfRect
                         width:(CGFloat)width
            contentScaleFactor:(CGFloat)contentScale
                         error:(NSError **)error;
- (UIImage *) imageFromPdfPage:(NSUInteger)pageNo
                       pdfRect:(CGRect)pdfRect
                        height:(CGFloat)height
            contentScaleFactor:(CGFloat)contentScale
                         error:(NSError **)error;
- (UIImage *) imageFromPdfPage:(NSUInteger)pageNo
                       pdfRect:(CGRect)pdfRect
                         scale:(CGFloat)scale
            contentScaleFactor:(CGFloat)contentScale
                         error:(NSError **)error;

- (void)DidStateChanged:(id)delegate;

- (void) startDownload;
- (void) restartDownload;
- (void) pauseResumeDownload;

- (void) RequestArticlesDynamicInfo:(NSString*)requestType completed:(void (^)(SPNode *))completionBlock;
- (void) updateArticleData:(NSString *)artID
                  language:(NSString *)language
                 completed:(void(^)(BOOL updated, NSError *error))completionBlock;
- (void) SendVote:(NSInteger)userVote forArticle:(NSString *)artID;
- (void) requestVoteForArticle:(NSString *)artID completed:(void(^)(NSError *error))completionBlock;
- (void) getDirectLinkForArticle:(NSString *)artID
                         success:(void (^)(NSString *articleURL))success
                         failure:(void (^)(NSError *error))failure;
- (void) getDirectLinkForPage:(NSUInteger)pageNo
                      success:(void (^)(PRSmartPageset *pageset, NSString *))success
                      failure:(void (^)(NSError *))failure;
- (void) getDirectLinkForPages:(NSSet<NSNumber *> *)pageSet
                        success:(void (^)(PRSmartPageset *pageset, NSString *))success
                        failure:(void (^)(NSError *))failure;
- (void) loadPagesetsWithSuccess:(nullable void(^)(NSArray<PRSmartPageset *> *pagesets))success
                         failure:(nullable void(^)(NSError *error))failure;
- (void) newPagesetWithPages:(NSSet<NSNumber *> *)pageSet
                     success:(void(^)(PRSmartPageset * pageset))success
                     failure:(void(^)(NSError *error))failure;
- (void) updatePageset:(PRSmartPageset *)pageset withPages:(NSSet<NSNumber *> *)pages
               success:(void(^)(void))success
               failure:(void(^)(NSError *error))failure;
- (void) getOrCreatePagesetWithPages:(NSSet<NSNumber *> *)pages
                             success:(nullable void (^)(PRSmartPageset * pageset))success
                             failure:(nullable void (^)(NSError *error))failure;
- (void) getCollectionsForPageset:(PRSmartPageset *)pageset
                          success:(nullable void(^)(NSArray<NSString *> *collectionIds))success
                          failure:(nullable void(^)(NSError *error))failure;
- (void) addPageset:(PRSmartPageset *)pageset
       toCollection:(NSString *)collectionId
            success:(nullable void (^)(void))success
            failure:(nullable void (^)(NSError *error))failure;
- (void) savePageset:(PRSmartPageset *)pageset
       toCollections:(NSArray<NSString*>*)collectionIds
          completion:(void(^)(NSError *error))completionBlock;

- (void) getCollectionsForPages:(NSSet<NSNumber *> *)pageSet
                        success:(void(^)(NSArray<NSString *> *collectionIds))success
                        failure:(void(^)(NSError *error))failure;
- (void) getCollectionsForPage:(NSUInteger)pageNo
                       success:(void(^)(NSArray<NSString *> *collectionIds))success
                       failure:(void(^)(NSError *error))failure;
- (BOOL) hasCollectionsForPage:(NSUInteger)pageNo;
- (BOOL) hasPageSetForPage:(NSUInteger)pageNo;
- (void) addPages:(NSSet<NSNumber *> *)pageSet
    toCollections:(NSArray<NSString *> *)collectionIds
          success:(void (^)(void))success
          failure:(void (^)(NSError *error))failure;
- (void) removeFromAllCollectionsPages:(NSSet<NSNumber *> *)pageSet
                               success:(void (^)(void))success
                               failure:(void (^)(NSError *error))failure;

- (void) updateMetaDataForPages:(nullable NSArray *)pages
                      completed:(nullable void (^)(NSArray * articleIDs))completedBlock;

- (NSDictionary*) GetIssue;


- (instancetype) initFromFile:(NSString*)filePath;
- (void) setSuspended:(BOOL)val;
- (void) markForDeletion;
- (BOOL) iOS7BackgroundDownload;

- (NSString*) GetGregorianIssueDateWithFormat:(NSString*)format;
- (NSString*) pathToPdn;
- (NSString*) pdnFolderPath;
- (NSString*) pathToPdnInPageRange:(NSRange)pageRange;

- (BOOL) stateDone:(NSString*)stateName;
- (NSString *) stateNameForAsset:(NSString *)assetName;
- (BOOL) stateCompleted:(NSString *)stateName;
- (BOOL) stateFailed:(NSString*)stateName;
- (BOOL) hasFailedState;
- (BOOL) assetsDownloadCompleted;
- (BOOL) isDownloadSuspendedOrCompleted;
- (void) setForced:(BOOL)val;
- (void)lock:(BOOL)locked;

- (NSComparisonResult) issueDateComparator:(PRMyLibraryItem *) aMli;
- (void)setupFromCatalog;

- (void)getAspectRatio:(void(^ _Nullable)(CGFloat))completion;

- (nullable NSDateComponents *)licenseDurationInUnits:(NSCalendarUnit)unit;

@property (nonatomic, assign, readonly) NSString *IssueIdDate;
@property (nonatomic, readonly) NSInteger issueVersion;
@property (nonatomic, readonly) NSInteger smartVersion;
@property (nonatomic, assign) NSDate *originalOrderDate;
@property (nonatomic, readonly) NSDate *availableInDQDate;
@property (nonatomic, readonly) NSDate *deliveryDate;
@property (nullable, nonatomic, strong, readonly) PRSmartObject *smart;
@property (nullable, nonatomic, strong, readonly) PRSmartObject *processedSmart;
@property (nonatomic, readonly) NSInteger downloadProgress;
@property (nonatomic, readonly) NSInteger downloadProgressUnedited;
@property (nonatomic, readonly) BOOL urlExpired;
@property (nonatomic, getter = isThumbSizeUpdated) BOOL thumbSizeUpdated;
@property (nonatomic, readonly) BOOL isSupplement;
@property (nonatomic, readonly) BOOL isOpen;
@property (nonatomic, readonly) BOOL done;
@property (nonatomic, readonly) unsigned long long itemSizeBytes;
@property (nonatomic) BOOL wasDownloaded;
@property (nonatomic, readonly) NSString *accountName;
@property (nonatomic) BOOL isSelected; // transient property for ediding the library
@property (nonatomic, readonly) BOOL isLocked;
@property (nonatomic, strong, readonly) NSProgress* progress;
@property (nonatomic, copy, readonly) NSString *MID;
@property (nonatomic, strong, readonly) NSArray<PRSmartPageset *> *pagesets;
@property (nullable, nonatomic, strong) NSArray<NSString *> *analyticsProfileIDs;
@property (nonatomic) BOOL requestingRadioInfo;
@property (nonatomic, readonly) CGFloat aspectRatio;

@property (nullable, nonatomic, strong) NSString *currentArticleUid;

@property (nonatomic, readonly) BOOL isDownloaded;
@property (nonatomic, readonly) BOOL isLicenseLimited;

@end

@interface PRMyLibraryItem (Reader)
+ (void)reader:(NSString *)mid gotoPage:(NSUInteger)pageNo article:(NSString *)articleId;
- (void)readerGotoPage:(NSUInteger)pageNo;
- (void)readerGotoPage:(NSUInteger)pageNo article:(nullable NSString *)articleId;
@end

@interface PRMyLibraryItem (CustomAnalytics)
- (void) reportCustomAnalyticsIssueDownload;
- (void) reportCustomAnalyticsIssueOpen;
- (void) reportCustomAnalyticsPageView:(NSInteger)page;
- (void) reportCustomAnalyticsArticleView:(NSString *)artId;
- (void) reportCustomAnalyticsArticleView:(NSString *)artId expanded:(BOOL)expanded;
@end

NS_ASSUME_NONNULL_END

#import "PRMyLibraryItem_Extension.h"
#import "PRMyLibraryItem+ScreenshotProtection.h"
#import "PRMyLibraryItem+Print.h"
